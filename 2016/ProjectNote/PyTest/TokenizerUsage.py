#connect to dababase
def ShowGenitivAndPlural(NL,box):
        if box[2]==' -(e)s' or box[2]=='-(e)s':
                NL[0].append(box[0]+'s');
                NL[0].append(box[0]+'es');
        elif box[2].count(',')==0 and box[2].count('-')==1:
                if (box[2][0]==' '):
                        NL[0].append(box[0]+box[2].lstrip(' -'))
                else:
                        NL[0].append(box[0]+box[2].lstrip('-'))
        elif box[2]==' ' or box[2]=='':
                pass;
        elif box[2].count(',')==1 and (box[3]=='geschr' or box[3]=='lit' or box[3]=='hum' or box[3]=='iron' or box[3]=='pej' or box[3]=='euph' or box[3]=='hist'):
                tmpLt=box[2].split(',');
                box[2]=tmpLt[0];
                box[3]=tmpLt[1];
                ShowGenitivAndPlural(NL,box);
                return;
        else:
                print 'error!';
        

        if box[3]=='nur Sg' or box[3]==' nur Sg' or box[3]=='Pl' or box[3]==' Pl' or box[3]=='':
                pass;
        elif box[3].count('-')==1:
                if box[3][0]==' ':
                        NL[1].append(box[0]+box[3].lstrip(' -'));
                else:
                        NL[1].append(box[0]+box[3].lstrip(' -'));
        else:
                print 'error2!';
        return;

def GetGenitivAndPlural(myID):
	global cursor
	cursor.execute('select wordform,gender,genitiv,plural from Noun where ID=%d'% myID)
	box=cursor.fetchone()
	if(box):
		NL=[[],[],box[0],box[1]]
		ShowGenitivAndPlural(NL,box)
		return NL
	else:
		raise "box is empty"

def WriteToNounRevise(startID,endID):
        for i in xrange(startID,endID):
                MyNL=GetGenitivAndPlural(i);
                cursor.execute(u"insert into NounRevise(wordform, gender, genitiv, plural) values('%s','%s','%s','%s')"% (MyNL[2],MyNL[3],','.join(MyNL[0]),','.join(MyNL[1])))
                
                

import pyodbc
DBfile='D:/ProjectNote/Quizer/Wort1.mdb'
conn = pyodbc.connect('DRIVER={Microsoft Access Driver (*.mdb)};DBQ='+DBfile)
cursor=conn.cursor()
#tokenize
import nltk
sent_detector=nltk.data.load('tokenizers/punkt/german.pickle')
import codecs
f=codecs.open('D:\\ProjectNote\\GermaData\\Sprichwort\\Einheit10-U2.txt','r','utf-8')
st1=f.read()
st1=st1.lstrip(u'\ufeff')#remove BOM
result=sent_detector.tokenize(st1)
for i in xrange(len(result)):
        result[i]=nltk.word_tokenize(result[i]);

import StanfordTagger
        
myTagger = nltk.tag.StanfordPOSTagger('german-hgc.tagger')
myoutput=myTagger.tag_sents(result)

#extract all the common nouns
Ls=[w[0] for j in myoutput for w in j if w[1]==u'NE']
#WriteToNounRevise(316,339)#Abfahrt
##result_n=[[u'Informatik'], [u'Studentenwohnheim'], [u'T\xfcr', u'Zimmer'], [u'Fenster', u'Schreibtisch'], [u'Schreibtisch', u'Drehstuhl'], [u'Schreibtisch', u'Lampe'],
##          [u'Gegen\xfcber', u'Schreibtisch', u'Bett'], [u'Bett', u'Nachttisch'], [u'Nachttisch', u'Tischlampe'], [u'Bett', u'Bild', u'Wand'], [u'Schreibtisch', u'Ecke', u'Regal'], [u'Sachen', u'Ordnung'], [u'Laptop', u'Schreibtisch'],
##          [u'Stecker', u'Steckdose'], [u'B\xfccher', u'Regal'], [u'Koffer'], [u'Kleidung', u'Schrank'], [u'Wecker', u'Nachttisch'], [u'Koffer', u'Bett'], [u'Ordnung']]
