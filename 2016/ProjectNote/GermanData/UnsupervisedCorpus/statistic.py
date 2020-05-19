import codecs
import sys
from nltk import word_tokenize
f=codecs.open('D:\\ProjectNote\\GermaData\\Sprichwort\\zusammen.txt','r','utf-8')
st=f.read()
#lt=st.split('\n')
#myToken=sorted(set(w for w1 in lt for w in w1.split()))
tokens0=word_tokenize(st,'german')
tokens=sorted(set(tokens0))#cmp=lambda x,y: cmp(x[0], y[0]
firstLetter=0;
for i in tokens:
	if(i[0]=='A'):
		firstLetter=tokens.index(i)
		break

if(tokens.count(u'``')):
        tokens.remove(u'``');

tokens=tokens[firstLetter:len(tokens)]
from nltk.stem import snowball
stemmer=snowball.GermanStemmer()
tokens1=[stemmer.stem(w) for w in tokens]
tokens1=sorted(set(tokens1))
##firstBig=0;
##for i in tokens:
##	if(ord(i[0])>=65):
##		firstBig=tokens.index(i)
##		break
##
##
##sys.path.append('D:/ProjectNote/PyTest')
##import MDXProcessing
##NounList=[]
##MDXProcessing.ConstructNounList(NounList)
##
##tokens1=[]
##for i in xrange(firstBig,firstLetter):
##	if(NounList.count(tokens[i])): #also remove all the plural form of noun
##		tokens1.append(tokens[i])
##
##for i in xrange(firstLetter,len(tokens)):
##	tokens1.append(tokens[i])
tokens2=[]
for i in tokens1:
	tokens2.append([i])
for i in tokens:
        pos=tokens1.index(stemmer.stem(i))
        tokens2[pos].append(i)

stat=[sum([tokens0.count(w) for w in j[1:len(j)]]) for j in tokens2]
totalNum=sum(stat)
for i in xrange(len(stat)):
	tokens2[i].append(str(stat[i]))
	per=('%.5f' % (stat[i]*100.0/totalNum))
	tokens2[i].append(per)

f=codecs.open('D:\\ProjectNote\\GermaData\\Sprichwort\\StatisticsPremierVonZusammen3.csv','w','utf-8')

##f=codecs.open('D:\\ProjectNote\\GermaData\\Sprichwort\\StatisticsPremierVonZusammen2.txt','w','utf-8')
##for i in tokens2:
##        f.write(' '.join(i)+'\n')
##f.close()
