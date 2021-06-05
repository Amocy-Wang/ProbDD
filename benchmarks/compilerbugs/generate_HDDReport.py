import os
import sys

subjects = ['clang-22382','clang-22704','clang-23309','clang-23353','clang-25900','clang-26760','clang-27137','clang-27747','clang-31259','gcc-59903','gcc-60116','gcc-61383','gcc-61917','gcc-64990','gcc-65383','gcc-66186','gcc-66375','gcc-70127','gcc-70586','gcc-71626']
main_dir = "/benchmarks/compilerbugs"
tmp_dirname = main_dir + "/results/"

def genCMD(fname):
  return "/countTokens/build/bin/chisel" + " " + fname + " " + fname

def getFiles(target):
  all_files = []
  for root, dirs, files in os.walk(target):
    for f in files:
      targetfile = str(os.path.join(root,f)).strip()
      if 'small.c' in targetfile and ('assert' not in targetfile and 'empty' not in targetfile):
        all_files.append(targetfile)
  return all_files

def getFile2Stat(subpath):
  dir_list = getFiles(subpath)
  dir_list = sorted(dir_list,key=lambda x: os.path.getmtime(os.path.join(subpath, x)))
  return dir_list[-1]

for subpath in subjects:
  collect_path = tmp_dirname + subpath + "-hdd"
  if os.path.isfile(collect_path + "/small.c"):
    proc = os.popen(genCMD(collect_path + "/small.c"))
    token_str = list(filter(lambda x : True if 'original tokens:' in x else False, proc.readlines()))
    token_num = token_str[-1].strip().split(":")[-1]
    log_file = main_dir + "/log_hdd_" + subpath 
    fopen = open(log_file,'r')
    lines = fopen.readlines()
    time_line = lines[-1]
    strtime = time_line.strip().split(":")[-1].strip().rstrip('s')
    print(subpath+","+token_num+","+strtime)
  else:
    tests_path = collect_path + "/tests"
    proc = os.popen(genCMD(getFile2Stat(tests_path)))
    token_str = list(filter(lambda x : True if 'original tokens:' in x else False, proc.readlines()))
    token_num = token_str[-1].strip().split(":")[-1]
    print(subpath+","+token_num+","+"")
