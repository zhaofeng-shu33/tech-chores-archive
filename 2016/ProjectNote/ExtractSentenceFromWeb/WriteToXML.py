f2=open('findTranslationSetence.py','r')
exec(f2.read())
f2.close()

from lxml import etree
root=etree.Element("Word")
root.attrib['Wordform']=word
for i in range(0,len(g)):
    etree.SubElement(root,"ExampleCollection_"+str(i))

for i in range(0,len(g)):
	etree.SubElement(root[i],"German")
	etree.SubElement(root[i],"Chinese")

for i in range(0,len(g)):
	root[i][0].text=g[i]
	root[i][1].text=t[i]

st=etree.tostring(root,xml_declaration=True,encoding='utf-8',pretty_print=True)
f3=open('D:/QtTest/ODBC-build-desktop/'+word+'.xml','w')
f3.write(st)
f3.close()
