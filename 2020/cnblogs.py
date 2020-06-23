from bs4 import BeautifulSoup

f = open('/home/zhaofeng/Downloads/CNBlogs_BlogBackup_131_201810_202006.xml')
st = f.read()
soup = BeautifulSoup(st, 'html.parser')
Ls = soup.find_all('item')
for i in Ls:
    title = i.title.text
    time_list = i.guid.text.split('/')
    time_str = time_list[-4] + '/' + time_list[-3] + '/' + time_list[-2]
    content = i.description.text
    whole = '# ' + title + '\n' + time_str + '\n\n' + content
    file_name = title.replace(' ', '_') + '.md'
    file_folder = time_list[-4]
    with open(file_folder + '/' + file_name, 'w') as f:
        f.write(whole)
