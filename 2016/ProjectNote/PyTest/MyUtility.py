import re
import sys
import win32com.client
#sys.path.append('G:/Python2.7/Lib/site-packages/win32com/gen_py')
global total_error
total_error=0;
def TakeWordRemoveDot(st):
    st=st.decode('utf-8')
    m=re.search(u'`4`([-A-Z\xdc]*[a-z\xdf\xe4\xf6\xfc\xb7]*)',st)
    st1=m.group()
    st1=st1.lstrip('`4`')
    word=[]
    for i in st1:
        if(i!=u'\xb7'):
            word.append(i)

    st1=''.join(word)#unicode encoded without seperate dots
    return st1

def FindNoun(st):
    st=st.decode('utf-8')
    if(st[3].islower()):
        return False;
    return True;

def FindGender(st):
    st=st.decode('utf-8')
    m=re.search(u'[a-z]{3};',st)
    if(m):
        st1=m.group()
        st1=st1.strip(';')
        if(st1==u'der' or st1==u'die' or st1==u'das'):
            return st1
    return ''

def FindPluralAndGenetiv(st,given_gender):
    global total_error;
    st=st.decode('utf-8')
    genetivform='';
    pluralform='';
    m=re.search(u'{0};[ ,;glesn()nurSP-]*(geschr|lit|pej|hum|iron|euph|hist)?;'.format(given_gender),st)
    if(m):
        st1=m.group();
        Ls=st1.split(';');
        st1=Ls[1];
        if(st1==' nur Sg' or st1==' Pl'):
            return ['',st1];

        if(len(Ls)==3):
            Ls2=st1.split(', ');
            if(len(Ls2)>=2):
                if(Ls2[0]==' nur Sg' or Ls2[0]==' Pl'):
                    return ['',Ls2[0]];
                [genetivform,pluralform]=Ls2[0:2];
            else:
                #print "error: ".format(st1);
                total_error+=1;
        if(len(Ls)==4):
            genetivform=Ls[1].lstrip(' ');
            Ls2=Ls[2].split(', ');
            pluralform=Ls2[0].lstrip(' ');
##    Ls=st.split(' ');
##    st2=Ls[0].split('4')[0]
##    st2=st2.lstrip('`1`')
##    st2=st2.strip('\r\n`')
##    if(len(Ls)<3):
##        return ['','']
##    genetivform='';
##    pluralform='';
##    if(len(Ls[2])>1 and len(Ls[2])<7):
##        if(Ls[2]=='Pl;'):
##            genetivform='Pl';
##        else:
##            if(Ls[2][0]=='-'):
##                genetivform=Ls[2].strip(',')
##                genetivform=Ls[2].strip(';')
##            if(Ls[3][-1]==';'):
##                pluralform=Ls[3].strip(';')
##            if(Ls[3]=='nur'):
##                pluralform='nur_Sg';
    return [genetivform,pluralform]

        
def ConvertToLower(st):#find the first letter of each sentence and change this word to lower form if it is not a noun
    pattern=re.compile(u'\r\n([A-Z\xdc][a-z\xdf\xe4\xf6\xfc\xb7]*) ')
    pos=0;
    while(pos<len(st)):
        m=pattern.search(st,pos)
        st1=m.group()
        st1=st1.lstrip('\r\n')
        st1=st1.strip(' ')
        #if st1 is not a noun
        st1=st1.lower()
        pos=m.end()

        
