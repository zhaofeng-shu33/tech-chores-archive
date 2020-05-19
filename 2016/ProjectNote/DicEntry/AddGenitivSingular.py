from lxml import etree
filename="D:\QtTest\ODBC-build-desktop\NounEntryFormat010.xml"
f=open(filename,'r')
st=f.read()
root=etree.fromstring(st)
wordform=root.xpath("/Eintrag/Stichwort")[0].text
gender=root.xpath("/Eintrag/Genus")[0].text
if gender=='die':
    root.xpath("/Eintrag/GenitivSingular")[0].text=wordform
else:
    root.xpath("/Eintrag/GenitivSingular")[0].text=(wordform+'s')

st=etree.tostring(root,encoding='utf-8')
f=open(filename,'w')
f.write(st)
f.close()
