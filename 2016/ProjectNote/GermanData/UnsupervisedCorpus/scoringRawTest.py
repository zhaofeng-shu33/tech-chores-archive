import codecs
import nltk
def ReadText(fileName,encoding='utf-8'):
	f=codec.open(fileName,'r',encoding)
	st=f.read()
	if(encoding=='utf-8'):
		st=st.lstrip(u'\ufeff')
	return st

def ToLower(st5):
	if(st5[0].isupper()):
		st5=st5[0].lower()+st5[1:len(st5)];
	return st5


def GetScore(wordL):
	score=0;
	for i in range(len(wordL)):
		if(mDic.has_key(ToLower(wordL[i]))):
			score+=mDic[ToLower(wordL[i])]
	score=score*100.0/len(wordL)
	return score
wordList=[]
for i in range(9):
    f=codecs.open('D:/ProjectNote/GermaData/TextByKai/Text/Text{0}-A.txt'.format(str(i+1)),'r','utf-16')
    st3=f.read()
    for x in nltk.word_tokenize(st3):
        wordList.append(x)
    f=codecs.open('D:/ProjectNote/GermaData/TextByKai/Text/Text{0}-B.txt'.format(str(i+1)),'r','utf-16')
    st3=f.read()
    for x in nltk.word_tokenize(st3):
        wordList.append(x)
    
fdist1=nltk.FreqDist(wordList)
