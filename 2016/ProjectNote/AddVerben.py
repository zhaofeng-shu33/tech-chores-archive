import pyodbc
import codecs
from lxml import etree
##DBfile='D:/QtTest/NounDicWithDb/NounLib.mdb'
##conn = pyodbc.connect('DRIVER={Microsoft Access Driver (*.mdb)};DBQ='+DBfile)
##cursor=conn.cursor()
from lxml import etree
#cursor.execute('select * from Verb')
#Ls=cursor.fetchall()
import os
os.chdir('Deutsch-Lernen/xmlverben')
preSt='<?xml version="1.0" encoding="UTF-8"?><!DOCTYPE Entry SYSTEM "VerbenModel.dtd"><?xml-stylesheet type="text/xsl" href="VerbRenderTemplate.xslt"?>'
Sein=['bin','bist','ist','sind','seid','sind']
Haben=['habe','hast','hat','haben','habt','haben']

for tt in range(3,100):
    f=open('../Wort/V%d.xml'%tt,'rb')
    st=f.read()
    root=etree.fromstring(st)
    wort=root[0].text
    wort=wort+'.xml'
    find_wort=0
    import glob
    for name in glob.glob("*.xml"):
            if(name==wort):
                    f=open(name,'r')
                    find_wort=1
    if(find_wort):
        st=f.read()
        wortConjugation=etree.fromstring(st)
        for i in range(2):
            for j in range(6):
                root[3][i][j].text=wortConjugation[i+2][j].text
        Ls=wortConjugation[4].text.split(' ')
        for j in range(6):
            if(Ls[0]=='ist'):
                    root[3][2][j].text=Sein[j]+' '+Ls[1]
            else:
                    root[3][2][j].text=Haben[j]+' '+Ls[1]
        if(Ls[0]=='ist'):
            root[3][2].set('hilfsverb','sein')
        else:
            root[3][2].set('hilfsverb','haben')
    else:
        print "not found"+wort

    f=codecs.open("D:\\ProjectNote\\GermaData\\DicTest\\Deutsch-Lernen\\Wort\\V%d.xml"%tt,'w','utf-8')
    f.write(preSt+etree.tostring(root,encoding="unicode",pretty_print=True))
    f.close()


##WordList=etree.Element('Wordlist')
##for i in range(1,163):
##    f=open('Wort/V%d.xml'%i,'rb')
##    st=f.read()
##    root=etree.fromstring(st)
##    WordList.append(etree.Element('Word'))
##    WordList[i].text=root[0].text
##    WordList[i].set('address','%d.xml'%i)
##st_prepend='<?xml version="1.0" encoding="UTF-8"?>\
##<!DOCTYPE Entry SYSTEM "VerbenModel.dtd">\
##<?xml-stylesheet type="text/xsl" href="VerbRenderTemplate.xslt"?>'
##
##for i in range(1,12):
##    root=etree.fromstring(st)
##    root[0].text=Ls[i][1]#Stichwort
##    root[1].text=str(int(Ls[i][2]))#Einheit
##    root[2].text=Ls[i][5]#Anteil
##    root[8][0][0].text=Ls[i][7]#Chinesisch
##    root[8][0][1][0][0].text=Ls[i][0]#Satz
##    f=codecs.open("V%d.xml"%i,'w','utf-8')
##    f.write(st_prepend+etree.tostring(root,encoding="unicode"))
##    f.close()
