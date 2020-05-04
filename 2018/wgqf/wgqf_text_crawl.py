#!/usr/bin/python3
# author: zhaofeng-shu33
# created: 2018/6/14
# description: crawling wgqf text from mp.weixin.qq.com
from bs4 import BeautifulSoup
import MySQLdb
import re
import requests
import pdb
if __name__ == '__main__':
    db = MySQLdb.connect(host ="localhost",user="root", db="wgqf", passwd="xxx", charset="utf8")
    cursor = db.cursor()
    cursor.execute('select wgqf_id, wgqf_text_url, wgqf_text from info')
    for item in cursor.fetchall():
        wgqf_id = item[0]
        wgqf_text_url = item[1]
        if not(item[2] == None):
            continue
        print('get text for id = %d'%wgqf_id)
        r = requests.get(wgqf_text_url) 
        wgqf_text = None
        if(r.status_code == 200):
            soup_r = BeautifulSoup(r.text,'lxml')
            try:
                wgqf_text = soup_r.find('div',class_ = 'rich_media_content').text.replace('\xa0','')
            except Exception as e:
                print('%d ignored...'%wgqf_id)
                continue
        else:
            pdb.set_trace()
        sql_statement = 'update info set wgqf_text = "{0}" where wgqf_id = {1}'.format(wgqf_text.replace('"','\\"'), wgqf_id)
        try:
            cursor.execute(sql_statement)
        except Exception as e:
            print(e)
            continue
        db.commit()
