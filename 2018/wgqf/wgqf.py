#!/usr/bin/python3
# author: zhaofeng-shu33
# created: 2018/6/14
# description: update values into database wgqf (微观清芬), table info
from bs4 import BeautifulSoup
import MySQLdb
import re
import datetime
import pdb
if __name__ == '__main__':
    st = open('address.html').read()
    soup = BeautifulSoup(st,'lxml')
    a = soup.find_all("div", class_ = "weui_media_box")
    db = MySQLdb.connect(host ="localhost",user="root", db="wgqf", passwd="xxx", charset="utf8")
    cursor = db.cursor()
    cursor.execute('select wgqf_publication_date from info order by wgqf_publication_date desc limit 1;')
    up_to_date_time = cursor.fetchall()[0][0]
    for item in a: 
        wgqf_title = item.find('h4').text.strip()
        wgqf_title = wgqf_title.replace('\'','\'\'')
        wgqf_description = item.find('p',class_='weui_media_desc').text.strip()
        wgqf_description = wgqf_description.replace('\'','\'\'')
        wgqf_text_url = item.attrs['hrefs']
        p_d = item.find('p',class_='weui_media_extra_info').text
        matched = re.match('([0-9]+)年([0-9]+)月([0-9]+)日',p_d)        
        python_date = datetime.date(int(matched.group(1)), int(matched.group(2)), int(matched.group(3)))
        if(python_date > up_to_date_time):
            wgqf_publication_date = matched.group(1) + '-' + matched.group(2) + '-' + matched.group(3)
            sql_statement = "insert into info (wgqf_title, wgqf_description, wgqf_text_url, wgqf_publication_date) values ('{0}','{1}','{2}','{3}')".format(wgqf_title, wgqf_description, wgqf_text_url, wgqf_publication_date)
            #sql_statement = "update info set wgqf_title = '{0}', wgqf_description = ‘{1}’, wgqf_text_url = ‘{2}’, wgqf_publication_date = '{3}'".format(wgqf_title, wgqf_description, wgqf_text_url, wgqf_publication_date)
            try:
                cursor.execute(sql_statement)
            except Exception as e:
                pdb.set_trace()
    db.commit()
