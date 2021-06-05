import os
import sys
logfilename = sys.argv[1]
targets = ['gcc-71626','gcc-70586','gcc-70127','gcc-66375','gcc-66186','gcc-65383','gcc-64990','gcc-61917','gcc-61383','gcc-60116','gcc-59903','clang-31259','clang-27747','clang-27137','clang-26760','clang-25900','clang-23353','clang-23309','clang-22704','clang-22382']
outputfile = 'resfile.csv'
avgTime=0
avgSize=1
fout = open(outputfile,'w')
fout.write('subject, reduced size, time\n')
targets.reverse()
for i in targets:
    print i
    resfile = i+'/'+logfilename
    with open(resfile,'r') as fp:
        lines = fp.readlines()
        time = lines[-11].strip().split(':')[1].strip('s').strip()
        size = lines[-1].strip().split(':')[1].strip()
        avgTime = avgTime + float(time)
        avgSize = avgSize * float(size)
        fout.write(i+', '+size+', '+time+'\n')
fout.close()
