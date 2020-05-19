from lxml import etree
import codecs
f=codecs.open('D:\\ProjectNote\\GermaData\\DicTest\\Wordlist.txt','r','utf-8');
st=f.read();
lst=st.split('\r\n');
Wordlst=etree.Element('Wordlist')
for i in range(1,len(lst)):
	Wordlst.append(etree.Element('Word'))
	Wordlst[i-1].set('address','{0}.xml'.format(str(i)))
	Wordlst[i-1].text=lst[i]

f=codecs.open("D:/ProjectNote/GermaData/source/Wordlist.xml",'w','utf-8')
st='<?xml version="1.0" encoding="UTF-8"?><?xml-stylesheet type="text/xsl" href="navigation.xslt"?>'
f.write(st+etree.tostring(Wordlst,encoding="unicode"))
f.close()      

