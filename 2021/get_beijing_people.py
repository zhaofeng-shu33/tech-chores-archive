import requests
headers = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36"}
i = 4
url = f'https://www.douban.com/group/406358/members?start={(i - 1) * 36}'
r = requests.get(url, headers=headers)
print(r.status_code)
with open(f'{i}.html', 'w') as f:
    f.write(r.text)


from bs4 import BeautifulSoup
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