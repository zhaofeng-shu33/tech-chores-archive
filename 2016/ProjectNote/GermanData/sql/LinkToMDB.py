import pyodbc
DBfile='D:/QtTest/NounDicWithDb/NounLib.mdb'
conn = pyodbc.connect('DRIVER={Microsoft Access Driver (*.mdb)};DBQ='+DBfile)
cursor=conn.cursor()
from lxml import etree
f=open('D:\\ProjectNote\\GermaData\\KlickAufDeutschEins\\Vokabeln6-1.xml','r')
root=etree.fromstring(f.read())
f.close()
cnt=1
for i in range(5):
    for j in range(len(root[i])):
        if(root[i][j].tag=='word'):
            root[i][j].set('audio','Vokabeln6_1/Introduction_0%d.wav'%cnt)
            cnt+=1
for i in range(5):
    root[i].find('example').set('audio','IntroductionExample_0%d.wav'%(i+1))
f=open('D:\\ProjectNote\\GermaData\\KlickAufDeutschEins\\Vokabeln6-1_1.xml','wb')
f.write(etree.tostring(root,encoding='utf-8',pretty_print=True))
f.close()
