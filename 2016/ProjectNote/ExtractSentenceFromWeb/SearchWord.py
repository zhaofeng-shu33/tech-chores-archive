import urllib,urllib2
word='Arm'
#values={"dictCode":'german-english','q':'Abend'}
#values={"dictCode":'german-english','q':'Abend'}
values={"inputword":word}
data=urllib.urlencode(values)
#req=urllib2.Request("http://www.collinsdictionary.com/search/",data)
req=urllib2.Request("http://www.godic.net/",data)
page=urllib2.urlopen(req)
st=page.read()

from bs4 import BeautifulSoup
soup=BeautifulSoup(st)
#st1=soup.text

#import codecs
#f=codecs.open('D:\out1.txt','w','utf-8')
#f.write(st1)
#f.close()
#can search some limited g-e translation for the complilation of g-dic.
