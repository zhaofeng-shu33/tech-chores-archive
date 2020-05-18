import os
st = 'set -e -x\n'
st += 'mkdir -p build\n'
for i in os.listdir('./'):
    if i.find('.cpp') > 0:
        st += 'g++ %s -o build/a\n' % i

print(st)

