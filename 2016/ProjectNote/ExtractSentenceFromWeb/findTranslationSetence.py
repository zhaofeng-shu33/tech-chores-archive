f1=open('SearchWord.py','r')
exec(f1.read())
f1.close()
st=soup.find_all('div',class_='lj_item')
g=[]
t=[]
for match in st:
    g.append(match.find('p').text)
    t.append(match.find('p',class_='exp').text)
