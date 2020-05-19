import codecs
import re
f=codecs.open("D:\\QtTest\\3DOpenGL\\WINPY.TXT",'r','utf-16')
g=codecs.open("D:\\QtTest\\3DOpenGL\\WINPYR.TXT",'w','utf-16')
for i in f:
    st=i
    st1=re.search('[a-z]+',st).group()
    st2=u''
    for i in st:
        if(i!=st1[0]):
            st2=st2+i
        else:
            break
    st2=st2+' '
    st2=st2+st1
    st2=st2+'\n'
    g.write(st2)

f.close()
g.close()
