from lxml import etree
import codecs
f=open('D:\\ProjectNote\\GermaData\\source\\ExportCow.xml');
st=f.read();
f.close();#root1.tag=Dictionary
root1=etree.fromstring(st)
for r in range(0,len(root1[0])):
    root=root1[0][r]
    MyDic=etree.Element('Eintrag')
    MyDic.set('category','Substantiv')

    #parse basic information
    MyDic.append(etree.Element('Stichwort'))
    MyDic[0].text=root.get('LemmaSign')
    MyDic.append(etree.Element('Einheit'))
    MyDic[1].text=root[0].get('Einheit')
    MyDic.append(etree.Element('Anteil'))
    MyDic[2].text=root[0].get('Anteil')
    MyDic.append(etree.Element('Genus'))
    tmp=root[0].get('Genus');
    if(tmp=='2'):
        MyDic[3].text='der';
    elif(tmp=='3'):
        MyDic[3].text='die';
    else:
        MyDic[3].text='das';
        
    MyDic.append(etree.Element('Pluralform'))
    MyDic[4].text=root[0].get('Pluralform')
    MyDic.append(etree.Element('GenitivSingular'))
    if(root[0].get('GenitivSingular')):
        MyDic[5].text=root[0].get('GenitivSingular')

    #compound words parser
    MyDic.append(etree.Element(u'zusammengesetzteW\xf6rter'))
    MyDic[6].append(etree.Element('KompositaCollection'))
    cnt=0;
    for i in range(0,len(root[1][0])):
        if(root[1][0][i].get('Wort')):
            MyDic[6][0].append(etree.Element(root[1][0][i].tag))
            MyDic[6][0][cnt].text=root[1][0][i].get('Wort')
            cnt=cnt+1;

    #derivative words parser
    MyDic[6].append(etree.Element(u"abgeleiteteW\xf6rter"))
    for i in range(0,len(root[1][1])):
            if(root[1][1][i].get('hierzu')):
                MyDic[6][1].append(etree.Element('hierzu'))
                if(root[1][1][i].get('category')=='9'):
                    MyDic[6][1][i].set('category','Verben')
                elif(root[1][1][i].get('category')=='8'):
                    MyDic[6][1][i].set('category','Adjektiv')
                else:
                    MyDic[6][1][i].set('category','Substantiv')
                MyDic[6][1][i].text=root[1][1][i].get('hierzu')

    #synonyme parser
    MyDic.append(etree.Element('Synonymegruppe'))
    for i in range(0,len(root[2])):
            if(root[2][i].get('Synonym')):
                MyDic[7].append(etree.Element('Sym'))
                MyDic[7][i].text=root[2][i].get('Synonym')
            
    #antonym parser
    MyDic.append(etree.Element('Antonymegruppe'))
    for i in range(0,len(root[3])):
            if(root[3][i].get('Antonym')):
                MyDic[8].append(etree.Element('Anm'))
                MyDic[8][i].text=root[3][i].get('Antonym')
            
    #collocation parser
    MyDic.append(etree.Element('Kollokationen'))
    for i in range(0,len(root[4])):
            if(root[4][i].get('Wort')):
                MyDic[9].append(etree.Element('K'))
                MyDic[9][i].text=root[4][i].get('Wort')
            
    #explanation parser
    MyDic.append(etree.Element(u'AllgemeineErl\xe4uterungen'))
    for i in range(0,len(root[5])):
            MyDic[10].append(etree.Element('Eintrag'))
            MyDic[10][i].append(etree.Element('Chinesisch'))
            MyDic[10][i][0].text=root[5][i][0].get('TE')
            MyDic[10][i].append(etree.Element('BeispielSammlung'))
            for j in range(0, len(root[5][i][1])):
                MyDic[10][i][1].append(etree.Element('Beispiel'))
                MyDic[10][i][1][j].append(etree.Element('Satz'))
                MyDic[10][i][1][j][0].text=root[5][i][1][j][0].get('Satz')
                MyDic[10][i][1][j].append(etree.Element(u'\xdcbersetzung'))
                MyDic[10][i][1][j][1].text=root[5][i][1][j][1].get('TE')

    f=codecs.open("D:/ProjectNote/GermaData/ForceMemo/{0}.xml".format(str(r+1)),'w','utf-8')
    st='<?xml version="1.0" encoding="utf-8" standalone="yes"?>'
    f.write(st+etree.tostring(MyDic,encoding="unicode"))
    f.close()            
