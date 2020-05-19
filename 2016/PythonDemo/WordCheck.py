import codecs
st=[]
for line in codecs.open('D:/PythonDemo/Translation.txt','r','utf-8'):
    st.append(line.strip('\r\n'))

# open the file of Chinese translation and save the translation to a list called st
st1=[]
for line in codecs.open('D:/PythonDemo/germanWord.txt','r','utf-8'):
    st1.append(line.strip('\r\n'))

# open the file of German words and save the words to a list called st1
length=len(st)
df=[]
for i in range(length): 
    df.append(5)

#df represents the point density at each position from 0 to len(st)
total=5*length

def distribution_function(n):
    sum=0
    if n>length:
        return 1
    for i in range(n+1): # notice that range(1)=[0]
        sum+=df[i]

    return sum*1.0/total

# the function above returns the cmf curve of the distribution.
import random
def generate_random_number():
    n=random.random()
    if(distribution_function(0)>n):
        return 0
    for i in range(length):
        if(distribution_function(i)>n and distribution_function(i-1)<=n):
            return i

# the above function returns a random number according to given cmf.
def Test():
    for i in range(5): # give the number of test
        global total
        m = generate_random_number()
        a=raw_input('please input the German word with Translation '+st[m]+': ')
        if a!=st1[m]:
            print ('wrong Input'+' the right answer is '+st1[m])
            df[m]+=20
            total+=20
        else:
            print 'right Input'
            if(df[m]>4):
                df[m]-=4
                total-=4


if 0:
    "the above function starts a small test. It randomly produces a Chinese translation prompt\
    and requires the user to input the corresponding German noun. The test time is 5 in\
    total.You can change the time to adapt your tendency. For each time of test, the \
    distribution function is changed according to whether your answer if right or wrong."











    
