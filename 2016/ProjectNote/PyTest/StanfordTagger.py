import os
os.environ["CLASSPATH"]="G:/Python2.7/nltk_data/taggers/stanford-postagger"
#environment variable of parser is set
os.environ["STANFORD_MODELS"]="G:/Python2.7/nltk_data/taggers/stanford-postagger/models"
#environment variable of training data is set
os.environ["JAVAHOME"]="C:/Program Files/Java/jre1.8.0_91"
#general Java environment variable is set
# the above three environs should be set before the POStagger of Stanford can
# be used.
from nltk.tag import StanfordPOSTagger
#st = StanfordPOSTagger('english-bidirectional-distsim.tagger') 
#a=st.tag('I read these words over and over again.'.split())
