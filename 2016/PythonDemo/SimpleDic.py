wordform=[]
import codecs
for line in codecs.open('D:/PythonDemo/wordform.txt','r','utf-8'):
    wordform.append(line.strip('\r\n'))

meaning=[]               
for line in codecs.open('D:/PythonDemo/meaning.txt','r','utf-8'):
    meaning.append(line.strip('\r\n'))

Example=[]               
for line in codecs.open('D:/PythonDemo/Example.txt','r','utf-8'):
    Example.append(line.strip('\r\n'))

import sqlite3
conn = sqlite3.connect('example.db')
c=conn.cursor()
n=len(wordform)
for i in range(163):
	c.execute(u"insert into WordList values('{0}','{1}','{2}')"
                  .format(wordform[i],meaning[i],Example[i]))

conn.commit() # save the changes

def WordData(word):
	c.execute(u"select * from WordList where wordform = '{0}'".format(word))
	entry=c.fetchone()
	for element in entry:
		print element

		
