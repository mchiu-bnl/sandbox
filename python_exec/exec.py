import sys
import time
from subprocess import Popen,PIPE

#try:
#p = Popen(["./test.sh"], stdin=PIPE, stdout=PIPE,stderr=PIPE)
p = Popen(["./test.sh"], stdin=PIPE )

#except OSError as e:
#    sys.exit("failed to run 'test.sh': %s" % (str(e)))

time.sleep(1)
print("xxx\n")
p.stdin.write("aa\n")
p.stdin.flush()
time.sleep(1)
print("yyy\n")
p.stdin.write("bb\n")
p.stdin.flush()
print("zzz\n")

time.sleep(1)
input = "q"
(out,err) = p.communicate(input)

