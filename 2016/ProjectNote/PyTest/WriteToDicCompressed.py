Ls2=[]
from struct import pack,unpack
f=open('D:/ProjectNote/GermaData/DicTest/Dict_Info.xml','rb')
dict_info=f.read()
import re
numOfWords=int(re.findall('<Words>([0-9]+)</Words>',dict_info)[0])
Ls2.append(pack('>I',len(dict_info)))
Ls2.append(dict_info)
f=open('D:/ProjectNote/GermaData/DicTest/Wordlist.txt','rb')
wordList=f.read()
wordList=wordList.replace('\r\n','\n')
wordList=wordList.lstrip('\xef\xbb\xbf')
from zlib import compress,decompress
wordList_compress=compress(wordList)
Ls2.append(pack('>I',len(wordList_compress)))
Ls2.append(pack('>I',len(wordList)))
Ls2.append(wordList_compress)
st5='';
for i in xrange(numOfWords):
    f=open('D:/ProjectNote/GermaData/DicTest/Wort/%d.xml'%(i+1),'rb')
    st4=f.read()    
    st5=st5+pack('>I',len(st4))+st4
st5_compress=compress(st5)
Ls2.append(pack('>Q',len(st5_compress)))
Ls2.append(pack('>Q',len(st5)))
Ls2.append(st5_compress)

stFinal=''.join(Ls2)
f=open('D:/ProjectNote/GermaData/DicTest/DicCompressed_1.txt','wb')
f.write(stFinal)
f.close()
#f=open('D:/ProjectNote/GermaData/DicTest/DicCompressed.txt','rb')
#stFinal_1=f.read()
def un(st1,d):
	if(d==4):
		return unpack('>I',st1)
	return unpack('>Q',st1)
    
def un4(off):
	global record
	return un(record[off:off+4],4)[0]

f=open('D:/ProjectNote/GermaData/DicTest/DicCompressed_1.txt','rb')
offset=45+4+8+981+16
source=f.read()
record=decompress(source[offset:offset+32085])
mDic={}
Ls=wordList.split('\n')
cnt=0
myOff=0
while(cnt<len(Ls) and myOff<len(record)):
    mDic[Ls[cnt]]=record[myOff+4:myOff+4+un4(myOff)]
    cnt+=1
    myOff+=(4+un4(myOff))
    

