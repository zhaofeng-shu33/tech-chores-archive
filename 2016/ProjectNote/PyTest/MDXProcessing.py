from readmdict import MDX
import re
import MyUtility
def ConstructNounList(NounList):#pass the argument NounList=[]
    global items,kl
    for i in xrange(len(kl)):
        if(MyUtility.FindNoun(items[i][1])):
            NounList.append(kl[i].decode('utf-8'))


mdx=MDX('D://QtTest//MDictPC//Grosswortherbuch.mdx')
kl=list(mdx.keys())
#st=' '.join(kl)
#re.findall(r'(Abend[a-z|\xc3\xa4|\xc3\xbc]*)',st)
items=list(mdx.items())
#give Abend***
#\xc2\xb7 is utf-8 encoded seperate dots
#mydef=items[kl.index('Abend')]
#we should take the `4`A\xc2\xb7bend out
#st=mydef[1]
#m=re.search(u'`4`([A-Z|\xdc][a-z|\xdf|\e4|\xf6|\xfc|\xb7]+)',st)
#\xc3\xa4  a.. unicode:\xe4
#\xc3\xb6  o..  \xf6
#\xc3\xbc u..   \xfc
#\xc3\x9c U..   \xdc
#\xc3\x9f ss..  \xdf
##def MyCursor(t1,t2):#used to write noun data to sqlite database
##	global NounList;
##        for i in NounList[t1:t2]:
##            c.execute(u"select rowid from WordList where wordform='{0}'".format(i));
##            entry=c.fetchall();
##            if(entry):
##                    myID=entry[0][0];
##                    c.execute(u"update WordList set POS='Substantiv' where rowid={0}".format(myID));
##            else:
##                    c.execute(u"insert into WordList(wordform, POS) values('{0}','Substantiv')".format(i));

