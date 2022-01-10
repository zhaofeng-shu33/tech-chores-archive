from bs4 import BeautifulSoup
i = 4
with open(f'{i}.html') as f:
        st = f.read()
soup = BeautifulSoup(st, "lxml")
Ls = soup.find_all("li", {"class": 'member-item'})
for i in range(len(Ls)):
    if Ls[i].text.count('北京') == 0:
        continue
    href = Ls[i].find('a')['href']
    name = Ls[i].find('a').img['alt']
    if name.count('已注销') > 0:
        continue
    print(name, href)
