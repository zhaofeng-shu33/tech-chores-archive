from nltk.corpus import wordnet
st=wordnet.synsets('history')
print st[1].hypernyms()
