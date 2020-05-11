# 2020/5/6
import json
from datetime import datetime
f = open('shuoshuo_00000-00039.json')
js = json.load(f)
msg_1 = js['msglist']
f = open('shuoshuo_00040-00057.json')
js = json.load(f)
msg_2 = js['msglist']
msg_1.extend(msg_2)
msg = msg_1
Ls = []
for i in msg:
    a = datetime.fromtimestamp(i['created_time'])
    Ls.append([i['content'], a])
Ls.sort(key=lambda x:x[1])
cnt = 0
st = ''
last_year=Ls[0][1].year
for i in Ls:
    current_year = i[1].year
    if current_year > last_year:
        cnt = 1
        last_year = current_year
    else:
        cnt += 1
    st += '## Untitled %d\n' % cnt
    st += '%d/%d/%d' %(i[1].year, i[1].month, i[1].day)
    st += '\n\n%s\n\n' % i[0]

print(st)
f = open('export_1.txt','w')
f.write(st)
f.close()
