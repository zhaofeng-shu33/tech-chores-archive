import os
import pickle
import requests
from bs4 import BeautifulSoup
headers = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36"}
headers['Cookie'] = 'douban-fav-remind=1; viewed="4126861_3697658_3360630_26773854_1086317_6719680_1597381"; gr_user_id=94e3ee5e-cbbd-4124-b3eb-d4d282a2c64b; __utma=30149280.1974588637.1601882888.1621264256.1621342143.48; _pk_id.100001.8cb4=8fbc44ee35646ea7.1609085487.44.1621343718.1621265302.; __utmv=30149280.21225; ll="108288"; bid=seooTtiWNn4; dbcl2="212256190:D/Y0W8icvQg"; push_noty_num=0; push_doumail_num=0; loc-last-index-location-id="108288"; ct=y; ck=YF2Z; ap_v=0,6.0'
user_dic = {}

def get_name_city(url):
    global user_dic
    user_id = url.split('/')[-2]
    if user_dic.get(user_id):
        return (user_dic[user_id]['name'], user_dic[user_id]['city'])
    # url = https://www.douban.com/people/82243415/
    r = requests.get(url, headers=headers)
    soup = BeautifulSoup(r.text, "lxml")
    if soup.find("div", {'class': 'user-info'}) is None:
        # wipe out
        name = 'Unknown'
        city = 'Unknown'
    else:
        result = soup.find_all("div", {'class': 'user-info'})[0]
        name = soup.find_all("h1")[0].text.strip().split('\n')[0]
        if result.find('a') is None:
            city = 'Unknown'
        else:
            city = result.find('a').text
    user_dic[user_id] = {'city': city, 'name': name}
    with open('user_dic.pickle', 'wb') as f:
        pickle.dump(user_dic, f)    
    return (name, city)

if __name__ == '__main__':
    if os.path.exists('user_dic.pickle'):
        with open('user_dic.pickle', 'rb') as f:
            user_dic = pickle.load(f)
    st = open('list.html').read()
    soup = BeautifulSoup(st, "lxml")
    for i in soup.find_all("dl"):
        url = i.find("dd").a["href"]
        # print(url)
        name, city = get_name_city(url)
        print(name, city, url)
    with open('user_dic.pickle', 'wb') as f:
        pickle.dump(user_dic, f)