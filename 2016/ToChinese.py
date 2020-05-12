#coding=utf-8
import re
import toUnicode
file_name=raw_input(u"请输入要转码的tex文件名: ".encode('gbk'))
try:
        f=open(file_name,'r')
except IOError,reason:
        print reason
else:
        st=f.read()
        f.close()
        st=re.sub('\\\\begin\{document\}','\\\\begin{document}\n\\\\begin{CJK}{GBK}{song}',st,1)
        st=re.sub('\\\\usepackage\{amsmath\}','\\\\usepackage{amsmath}\n\\\\usepackage{CJK}',st,1)
        st=re.sub('\\\\end\{document\}','\\\\end{CJK}\n\\\\end{document}',st,1)
        a=re.findall('U\{(\w*)\}',st)
        b=[]
        for item in a:
        	b.append(toUnicode.toUnicode(item))
        st=st.decode('ISO-8859-2')
        for item in b:
                st=re.sub('\\\\U\{\w*\}',item,st,1)
        st=st.encode('gbk')
        file_name=file_name.replace('.tex','_new.tex')
        f=open(file_name,'w')
        f.write(st)
        f.close()
        

