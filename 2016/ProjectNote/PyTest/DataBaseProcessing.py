import pyodbc
DBfile='D:/QtTest/NounDicWithDb/NounLib.mdb'
conn = pyodbc.connect('DRIVER={Microsoft Access Driver (*.mdb)};DBQ='+DBfile)
cursor=conn.cursor()
from lxml import etree
cursor.execute('select * from Result')
Ls=cursor.fetchall()
Ls.sort(key=lambda x:x[1])
root=etree.Element('WordList')
j=0;
root.append(etree.Element('WordGroup'))
for	i	in range(len(Ls)):
				k=etree.Element('word')
				if(Ls[i][4]):
					k.set('Property',Ls[i][4]);
				k.set('Level',str(Ls[i][5]));
				k.append(etree.Element('description'))
				k.append(etree.Element('wordform'))
				k[1].append(etree.Element('or'))
				k[1][0].text=Ls[i][0]
				k[1].append(etree.Element('reflectiveChange'))
				if(Ls[i][6]):
					k[1][1].text=Ls[i][6]
				else:
					k[1][1].text=''
				k.append(etree.Element('TE'))
				k[2].text=Ls[i][3]
				root[j].append(k)
				if(i==len(Ls)-1):
					continue;
				if(abs(Ls[i][1]-Ls[i+1][1])<0.5):
					continue;
				example=etree.Element('example')
				example.text=Ls[i][2]
				root[j].append(example)
				j+=1
				root.append(etree.Element('WordGroup'))
##a=['Tor','Torte','Tourist',u'T\xfcr','Vermieterin']
##for i in range(0,5):
##    cursor.execute(u"select * from Noun where wordform='{0}'".format(a[i]))
##    result=cursor.fetchall()
##    f=open('D:/ProjectNote/GermaData/DicTest/Format.xml','rb')
##    st=f.read()
##    st=st.replace('</Stichwort>',a[i].encode('utf-8')+'</Stichwort>')
##    st=st.replace('</Einheit>',str(result[0][-3])+'</Einheit>')
##    st=st.replace('</Anteil>',result[0][-2].encode('utf-8')+'</Anteil>')
##    st=st.replace('</Genus>',result[0][2].encode('utf-8')+'</Genus>')
##    st=st.replace('</Pluralform>',result[0][3].encode('utf-8')+'</Pluralform>')
##    st=st.replace('</Satz>',result[0][5].encode('utf-8')+'</Satz>')
##    st=st.replace('</Chinesisch>',result[0][6].encode('utf-8')+'</Chinesisch>')
##    f=open('D:/ProjectNote/GermaData/DicTest/Wort/%d.xml'%(i+261),'wb')
##    f.write(st)
##    f.close()
#print etree.tostring(root,encoding='utf-8',pretty_print=True)
f=open('D:/ProjectNote/GermaData/KlickAufDeutschEins/VokabelnText.xml','wb')
f.write('<?xml version="1.0" encoding="utf-8"?>'+etree.tostring(root,encoding='utf-8',pretty_print=True))
f.close()
##for i in root:
##	if(len(i)>1):
##		print i[0][1]
