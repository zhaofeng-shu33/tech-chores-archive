# http://reserves.lib.tsinghua.edu.cn/book3//00001068/00001068005/HTML5/l/5.jpg
import requests
import shutil
cookies_str = open('cookie.txt').read().lstrip('Cookie: ').rstrip('\n')
headers = {'Cookie': cookies_str}
save_dir = 'D2/U6/'
root_url = 'http://reserves.lib.tsinghua.edu.cn/book3/'
book_id = '00001068'
start_index = '0000106800'
unit = 6
page_num = 26
new_url = root_url + book_id + '/' + start_index + str(unit) + '/' + 'HTML5' + '/' + 'l' + '/'
for i in range(1, page_num + 1):
    total_url = new_url + str(i) + '.jpg'
    r = requests.get(total_url, stream=True, headers=headers)
    path = save_dir + str(i) + '.jpg'
    if r.status_code == 200:
        with open(path, 'wb') as f:
            r.raw.decode_content = True
            shutil.copyfileobj(r.raw, f)
    else:
        import pdb
        pdb.set_trace()