from lxml import etree
from copy import deepcopy
import codecs
#from 4 to 65
MyDic=etree.Element("Language");
MyDic.set("Name","German");
for t in range(169,179):#129~139
    root1=etree.fromstring(u"<Lemma><Stichwort/><zusammengesetzteW\xf6rter/><Synonymegruppe/><Antonymegruppe/><Kollokationen/><AllgemeineErl\xe4uterungen/></Lemma>")
    if(t<10):
        f=open('D:/ProjectNote/GermaData/einheit10/{0}.xml'.format(t))
    elif(t<100):
        f=open('D:/QtTest/ODBC-build-desktop/NounEntryFormat0{0}.xml'.format(t))
    else:
        f=open('D:/QtTest/ODBC-build-desktop/NounEntryFormat{0}.xml'.format(t))
        
    print t
    root=etree.fromstring(f.read());
    f.close()


    #parse basic information
    for i in range(0,1):
            root1.set("LemmaSign",root[0].text)
            root1[0].set("category","Substantiv");
            root1[0].set("Einheit",root[1].text);
            root1[0].set("Anteil",root[2].text);
            root1[0].set("Genus",root[3].text);
            root1[0].set("Pluralform",root[4].text);
            if(root[5].text):
                root1[0].set("GenitivSingular",root[5].text);
            else:
                root1[0].set("GenitivSingular","");
            root1[1].append(etree.Element("KompositaCollection"))
            root1[1].append(etree.Element(u"abgeleiteteW\xf6rter"))


    #compound words parser
    for i in root[6][0]:
            root1[1][0].append(etree.Element(i.tag))

    for i in range(0,len(root[6][0])):
            if(root[6][0][i].text):
                root1[1][0][i].set("Wort",root[6][0][i].text)
            else:
                root1[1][0][i].set("Wort","")
                

    #derivative words parser
    for i in range(0,len(root[6][1])):
        root1[1][1].append(etree.Element("hierzu"))
        root1[1][1][i].set("category",root[6][1][i].get("category"))
        if(root[6][1][i].get("category")==""):
            root1[1][1][i].set("category","Substantiv");
        if(root[6][1][i].text):
            root1[1][1][i].set("hierzu",root[6][1][i].text)


    #synonyme parser
    for i in range(0,len(root[7])):
        root1[2].append(etree.Element("Sym"))
        if(root[7][i].text):
            root1[2][i].set("Synonym",root[7][i].text)
        else:
            root1[2][i].set("Synonym","")

    #antonym parser	
    for i in range(0,len(root[8])):
        root1[3].append(etree.Element("Anm"))
        if(root[8][i].text):
            root1[3][i].set("Antonym",root[8][i].text)
        else:
            root1[3][i].set("Antonym","")
            
    #collocation parser
    for i in range(0,len(root[9])):
        root1[4].append(etree.Element("K"))
        if(root[9][i].text):
            root1[4][i].set("Wort",root[9][i].text)
        else:
            root1[4][i].set("Wort","")
            
    #explanation parser
    for j in range(0,len(root[10])):
            root1[5].append(etree.Element("Eintrag"))
            root1[5][j].append(etree.Element("Chinesisch"))
            root1[5][j][0].set("TE",root[10][j][0].text)
            root1[5][j].append(etree.Element("BeispielSammlung"))
            for i in range(0,len(root[10][j][1])):
                root1[5][j][1].append(etree.Element("Beispiel"))
                root1[5][j][1][i].append(etree.Element("Satz"))
                if(root[10][j][1][i][0].text):
                    root1[5][j][1][i][0].set("Satz",root[10][j][1][i][0].text)
                else:
                    root1[5][j][1][i][0].set("Satz","")
                root1[5][j][1][i].append(etree.Element(u'\xdcbersetzung'))
                if(root[10][j][1][i][1].text):
                    root1[5][j][1][i][1].set("TE",root[10][j][1][i][1].text)
                else:
                    root1[5][j][1][i][1].set("TE","")    


    MyDic.append(deepcopy(root1))
    
MyDic1=etree.Element("Dictionary")
MyDic1.append(MyDic)
f=codecs.open("D:/ProjectNote/GermaData/source/MyDic.xml",'w','utf-8')
f.write(etree.tostring(MyDic1,encoding="unicode"))
f.close()
            
