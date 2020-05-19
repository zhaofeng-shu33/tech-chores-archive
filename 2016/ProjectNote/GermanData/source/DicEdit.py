import re
def unescape_entities(text):
        text = text.replace('<', '&lt;')
        text = text.replace('>', '&gt;')
        return text

def CommonAdd(addedSt,addSt,delimiter=6):
	st_1='<font color="#697C15">'+unescape_entities(addSt[0:delimiter])+'</font>'
	st_2='<font color="saddlebrown">'+addSt[delimiter:len(addSt)]+'</font>'
	addedSt=addedSt+st_1+st_2+'<br/>&nbsp;&nbsp;'+'\n'
	return addedSt

class Noun:
    def __init__(self,wordform=""):
        self.wordform=wordform #(original,with morpheme splitting)
        self.gender=""
        self.genitiveAndPlural=""
        self.collocation=[]#[[collectionList for meaning1],...]
        self.Synonyme=[]#[[synonymeCollection for meaning1],...]
        self.Antonyme=[]#[[AntonymeCollection for meaning1],...]
        self.example=[]#[[exampleList for meaning1],...]
        self.meaning=[]#[(meaning1,explanation1),(meaning2,explanation2),...]
        self.compoundPreK=[]#[(K-,compoundCollection for meaning1),...]
        self.compoundAftK=[]
        self.NB=[]
        #self.ID=[]#[(ID_1,explanation1),...]
        self.derivative=[]#[(meaning_1,word_1,pos_1)]
    def derivativeSearch(self):
        for i in range(len(self.derivative)):
            if(self.derivative[i]!='nan'):
                print self.derivative[i]
                
    def exampleSearch(self):
        for i in range(len(self.example)):
            if(self.example[i]!='nan'):
                print (i+1),self.example[i]
		
    def meaningSearch(self):
        for i in MyNoun.meaning:
            print i

f=open('D:/ProjectNote/GermaData/source/NounKindSource_2.txt')
st=f.read()
st=st.decode('utf-8')
st=st.lstrip(u'\ufeff')
Ls=st.split('\n')
MyNoun=Noun()
for i in range(len(Ls)-1):
    Ls_1=Ls[i].split('\t')
    MyNoun.compoundAftK.append(Ls_1[1])
    MyNoun.compoundPreK.append(Ls_1[0])
    MyNoun.NB.append(Ls_1[2])
    MyNoun.derivative.append(Ls_1[3])
    MyNoun.Synonyme.append(Ls_1[4])
    MyNoun.Antonyme.append(Ls_1[5])
    MyNoun.example.append(Ls_1[6])
    MyNoun.collocation.append(Ls_1[7])
    MyNoun.meaning.append(Ls_1[8])



    
Ls=[]
for j in range(len(MyNoun.meaning)):
    st=MyNoun.meaning[j].lstrip('%d '%(j+1))
    preSt='<li><font color="#000088">'+unescape_entities(st)+'</font><br/>&nbsp;&nbsp;'+'\n'
    if(MyNoun.collocation[j][0:3]!='nan'):
        if(MyNoun.collocation[j].count(';')>0):
                collocationList=MyNoun.collocation[j].split(';')
                for i in range(len(collocationList)):
                        if(collocationList[i][0]==' '):
                                collocationList[i]=collocationList[i].lstrip(' ');
                        if(i>0 and i<len(collocationList)-1):
                            collocationList[i]='<'+collocationList[i]+'>'
                        elif(i>0):
                            collocationList[i]='<'+collocationList[i]
                        else:
                            collocationList[i]=collocationList[i]+'>'
        else:
                collocationList=[MyNoun.collocation[j]];
        for i in range(len(collocationList)):
                preSt=preSt+'<font color="#004400">'+unescape_entities(collocationList[i])+'</font><br/>&nbsp;&nbsp;'+'\n'    
    if(MyNoun.example[j][0:3]!='nan'):
        st=MyNoun.example[j].lstrip(':');
        exampleCollection=st.split(';');
        for i in exampleCollection:
            preSt=preSt+'<i>'+i+'</i><br/>&nbsp;&nbsp;\n'
    if(MyNoun.Synonyme[j][0:3]!='nan'):
        preSt=CommonAdd(preSt,MyNoun.Synonyme[j].replace('=','&asymp;'),7);
    if(MyNoun.Antonyme[j][0:3]!='nan'):
        preSt=CommonAdd(preSt,MyNoun.Antonyme[j],4)
    if(MyNoun.compoundPreK[j][0:3]!='nan'):
        preSt=CommonAdd(preSt,MyNoun.compoundPreK[j])
    if(MyNoun.compoundAftK[j][0:3]!='nan'):
        preSt=CommonAdd(preSt,MyNoun.compoundAftK[j])
    if(MyNoun.NB[j][0:3]!='nan'):
        preSt=CommonAdd(preSt,MyNoun.NB[j])
    Ls.append(preSt+'</li>')
f=open('D:\ProjectNote\GermaData\source\LinieFirst.html','wb')
f.write('<html><meta http-equiv="Content-Type" content="text/html"; charset="UTF-8"><body><ol>'+'\n\n'.join(Ls).encode('utf-8')+'</ol></body></html>')
f.close()


