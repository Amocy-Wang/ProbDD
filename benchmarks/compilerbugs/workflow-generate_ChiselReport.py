import os
import sys
logfilename = sys.argv[1]
targets = ['gcc-66375','gcc-66186','clang-31259','clang-22382']
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
