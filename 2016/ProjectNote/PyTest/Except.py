import sys
import traceback
def division(a=1, b=1):
    if b==0:
         print 'b eq 0'
         sys.exit(1)
    else:
         return a/b

import traceback
try:
    1/0
except:
    print 'division failed'
    traceback.print_exc()

