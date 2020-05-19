from nltk.corpus import wordnet
st=wordnet.synsets('history')
def WordData(word):
        print [word.name(),word.pos(),word.definition(),word.lemma_names(),word.examples()]


for i in range(5): # range(5)=[0,1,2,3,4]
	WordData(st[i])

WordData(st[1].hypernyms()[0])



	


		
		





