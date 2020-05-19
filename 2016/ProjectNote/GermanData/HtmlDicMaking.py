import re
import codecs
pattern=u'^<b>(.*?)</b>'
pattern1=u'href="entry://(.*?)">'
pattern2=u'name="(.*?)">'
id1=0;
id2=0;
def replaceFuc(matchobj):
    global pattern
    tmpSt=matchobj.group(0)
    tmpSt=re.findall(pattern,tmpSt)[0]
    return u'<a name="{0}">{0}</a>'.format(tmpSt)

def replaceFuc1(matchobj):
    global pattern1
    tmpSt=matchobj.group(0)
    tmpSt=re.findall(pattern1,tmpSt)[0]
    if tmpSt[0]!='#':
        return u'href="#{0}">'.format(tmpSt)
    else:
        global id1
        id1=id1+1
        return u'href="#index-{0}">'.format(id1)

def replaceFuc2(matchobj):
    global id2
    id2=id2+1
    return u'name="index-{0}">'.format(id2)

f=codecs.open('D:\QtTest\MDictPC\doc\Longman 5\Longman Language Activator.txt','r','utf-8')
st=f.read()
st1=re.sub(pattern2,replaceFuc2,st,0,re.MULTILINE)
st2=re.sub(pattern1,replaceFuc1,st1,0,re.MULTILINE)
st2=st2.strip(u'\ufeff');
st3=re.sub(pattern,replaceFuc,st2,0,re.MULTILINE)
f.close()
f=codecs.open('D://ProjectNote//GermaData//htmlDic1.txt','w','utf-8')
f.write(st3)
f.close()
