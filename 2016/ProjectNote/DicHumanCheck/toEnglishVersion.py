from lxml import etree
for i in range(14,63):
    f=open("D:\QtTest\ODBC-build-desktop\NounEntryFormat0{0}.xml".format(i),'r')
    st=f.read()
    root=etree.fromstring(st)
    root.tag='Entry'
    root[1].clear()
    root[2].clear()
    root[0].tag='Wordform'
    root[3].tag='Gender'
    root[6].tag='CompositeWords'
    root[6][0].tag='Compounds'
    root[6][1].tag='Derivatives'
    root[9].tag='Collocations'
    root[10].tag='Explanations'
    f=open(u'D:\\ProjectNote\\DicHumanCheck\\{0}.xml'.format(root[0].text),'w')
    st=etree.tostring(root,encoding='utf-8')
    f.write(st)
    f.close()
