#include "IntegrationManager.h"

#include <fstream>
#include <map>
#include <sstream>
#include <libgen.h>
#include <unistd.h>

#include <spdlog/spdlog.h>

#include "llvm/ADT/APInt.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Process.h"
#include "llvm/Support/Program.h"
#include "llvm/Support/raw_ostream.h"

#include "FileManager.h"
#include "OptionManager.h"

IntegrationManager *IntegrationManager::Instance;

std::vector<llvm::StringRef> getAllEnv() {
  std::vector<llvm::StringRef> Env;
  for (char **p = environ; *p != 0; p++)
    Env.push_back(*p);
  return Env;
}

std::vector<std::string> stringToVector(std::string &Str, char dilim) {
  std::vector<std::string> Vec;
  std::stringstream SS(Str);
  std::string Token;
  while (getline(SS, Token, dilim))
    Vec.push_back(Token);
  return Vec;
}

bool endsWith(const std::string &Main, const std::string &Match) {
  if (Main.size() >= Match.size() &&
      Main.compare(Main.size() - Match.size(), Match.size(), Match) == 0)
    return true;
  else
    return false;
}

void clean(std::string &Program) {
  if (endsWith(Program, "make")) {
    std::vector<llvm::StringRef> Args;
    Args.push_back("make");
    Args.push_back("clean");
    llvm::sys::ExecuteAndWait(Program, Args, llvm::None, {}, 0, 0, nullptr);
  }
}

// Run build commands and capture compile options
void IntegrationManager::capture() {
  llvm::Optional<std::string> OldPathOpt = llvm::sys::Process::GetEnv("PATH");
  std::string OldPath;
  if (OldPathOpt.hasValue())
    OldPath = OldPathOpt.getValue();
  else
    OldPath = "";
  std::string ExtendedPath = WrapperDir + ":" + OldPath;

  std::string ChiselOldPath = "CHISEL_OLD_PATH=" + OldPath;
  std::string Path = "PATH=" + ExtendedPath;
  std::string ChiselOutputDir = "CHISEL_OUTPUT_DIR=" + OptionManager::OutputDir;

  std::vector<llvm::StringRef> Env = getAllEnv();
  Env.push_back(ChiselOldPath);
  Env.push_back(Path);
  Env.push_back(ChiselOutputDir);

  std::vector<llvm::StringRef> Args;
  for (auto &Arg : OptionManager::BuildCmd)
    Args.push_back(Arg);

  std::vector<std::string> PathVec = stringToVector(ExtendedPath, ':');
  std::vector<llvm::StringRef> PathVecRef;
  for (auto &Path : PathVec)
    PathVecRef.push_back(Path);

  llvm::ErrorOr<std::string> Program = llvm::sys::findProgramByName(
      OptionManager::BuildCmd[0], llvm::ArrayRef<llvm::StringRef>(PathVecRef));
  if (Program) {
    // Clean up the repository (e.g., make clean). Delete files that were
    // generated by the initial running of the test script in OptionManager
    clean(Program.get());
    std::string Msg;
    int Status = llvm::sys::ExecuteAndWait(
        Program.get(), Args,
        llvm::Optional<llvm::ArrayRef<llvm::StringRef>>(Env), {}, 0, 0, &Msg);
    if (Status) {
      llvm::errs() << "Error: Capture failed: " << Msg << "\n";
      exit(1);
    }
  } else {
    llvm::errs() << "Error: Unsupported build system "
                 << OptionManager::BuildCmd[0] << "\n";
    exit(1);
  }
}

void IntegrationManager::buildCompilationDB() {
  std::string Line;
  std::ifstream CaptureFile(CaptureFilePath);
  if (!CaptureFile.is_open()) {
    llvm::errs() << "Error: Unable to open capture.txt\n";
    exit(1);
  }

  while (getline(CaptureFile, Line)) {
    std::stringstream SS(Line);
    std::string Token;
    int i = 0;
    std::string SourceFile;
    std::vector<std::string> Args;
    while (getline(SS, Token, ',')) {
      // the first token means compiler
      if (i > 0) {
        if (endsWith(Token, ".c"))
          SourceFile = Token;
        else
          Args.push_back(Token);
      }
      i++;
    }
    if (!SourceFile.empty())
      CompilationDB[SourceFile] = Args;
  }
  CaptureFile.close();

  for (auto &E : CompilationDB)
    OptionManager::InputFiles.push_back(E.first);
}

void IntegrationManager::Initialize() {
  Instance = new IntegrationManager();
  Instance->CaptureFilePath = OptionManager::OutputDir + "/capture.txt";
  Instance->WrapperDir =
      FileManager::Dirname(OptionManager::BinFile) + "/../lib/wrappers";
  spdlog::get("Logger")->debug("Wrapper Directory: {}", Instance->WrapperDir);
  if (OptionManager::Build) {
    llvm::sys::fs::remove(Instance->CaptureFilePath);
    Instance->capture();
    Instance->buildCompilationDB();
  }
  for (auto &File : OptionManager::InputFiles) {
    std::string Origin = File + ".origin.c";
    Instance->Origins.push_back(Origin);
    llvm::sys::fs::copy_file(File, Origin);
  }
}

std::vector<const char *>
IntegrationManager::getCC1Args(std::string &FileName) {
  std::vector<const char *> Args;
  bool Record = false;
  for (auto &Arg : CompilationDB[FileName]) {
    if (Arg.find("-I") == 0 || Arg.find("-D") == 0) {
      Args.push_back(Arg.c_str());
      Record = true;
    } else if (Arg.find("-") == 0) {
      Record = false;
    } else if (Record) {
      Args.push_back(Arg.c_str());
    } else if (endsWith(Arg, ".o")) {
      Record = false;
    }
  }
  return Args;
}

void IntegrationManager::Finalize() {
  for (auto &File : OptionManager::InputFiles) {
    std::string Origin = File + ".origin.c";
    llvm::sys::fs::copy_file(File, File + ".chisel.c");
    llvm::sys::fs::copy_file(Origin, File);
  }
  delete Instance;
}
