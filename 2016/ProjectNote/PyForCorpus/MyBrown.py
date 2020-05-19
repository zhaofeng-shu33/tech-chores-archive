from nltk.corpus import brown
Ls=[' '.join(i) for i in brown.sents('cp08')]
st='\n'.join(Ls)
f=open('D:\\ProjectNote\\GermaData\\ForceMemo\\ca.txt','w')
f.write(st)
f.close()
