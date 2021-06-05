import os
import sys
import subprocess

def getTokNum(logline):
  return logline.strip().split(':')[1]

def getTime(logline):
  return logline.strip().split(':')[1].rstrip('s').strip()
  

def genPath(subjects):
  logpath = []
  for s in subjects:
    if 'gzip' in s:
      logpath.append(s)
    else:
      logpath.append(s+'/merged')
  return logpath

def getInfo(logname,subjects):
  oriTokNum = []
  redTokNum = []
  redTime = []
  logpath = genPath(subjects)
  for cnt in range(len(subjects)):
    logfile = logpath[cnt]+'/'+logname
    logf = open(logfile,'r')
    lines = logf.readlines()
    redTokLine = lines[-2]
    oriTokLine = lines[-3]
    redTimeLine = lines[-13]
    oriTokNum.append(getTokNum(oriTokLine))
    redTokNum.append(getTokNum(redTokLine))
    redTime.append(getTime(redTimeLine))
    logf.close()
  return oriTokNum, redTokNum, redTime
  

def logParser(orilogname,subjects): 
  oriTokNum, redTokNum, redTime = getInfo(orilogname,subjects)
  for wcnt in range(len(subjects)):
    print(subjects[wcnt] + ',' + oriTokNum[wcnt] + ',' + redTokNum[wcnt] + ',' + redTime[wcnt])

def genCMD(fname):
  return "/countTokens/build/bin/chisel" + " " + fname + " " + fname


logfilename = sys.argv[1]
allsubjects = ['benchmark/mkdir-5.2.1','benchmark/grep-2.19']
logfile_path = [i+'/'+logfilename for i in genPath(allsubjects)]


def splitset(logfile_path, subjects):
    subjects_ok = []
    subjects_timeout = []
    for logfile in logfile_path:
        if os.path.exists(logfile):
            getsubjectname = 'benchmark/' + logfile.split('/')[1]
            f = open(logfile,'r')
            if "***" in f.readlines()[-1]:
                subjects_timeout.append(getsubjectname)
            else:
                subjects_ok.append(getsubjectname)
    return subjects_ok, subjects_timeout

def genReport(subjects):
    logParser(logfilename, subjects)

def gentimeoutReport(subjects):
  tmp_dirname = "chisel-out"
  tmp_path = [i+'/'+tmp_dirname for i in genPath(subjects)]
  res = []
  for subpath in tmp_path:
    dir_list = list(filter(lambda x : True if 'success' in x else False, os.listdir(subpath)))
    dir_list = sorted(dir_list,key=lambda x: os.path.getmtime(os.path.join(subpath, x)))
    file2stat = '/benchmarks/chisel-bench/' + subpath + '/' + dir_list[-1]
    proc = os.popen(genCMD(file2stat))
    res.append(list(filter(lambda x : True if 'original tokens:' in x else False, proc.readlines())))
  for idx in range(len(subjects)):
    print(subjects[idx]+','+res[idx][-1].strip().split(':')[-1])

subjects_ok, subjects_timeout = splitset(logfile_path, allsubjects)
print(subjects_ok,subjects_timeout)
genReport(subjects_ok)
gentimeoutReport(subjects_timeout)
