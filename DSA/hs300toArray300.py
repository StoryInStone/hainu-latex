# -*- coding:utf-8 -*-  
import sys
reload(sys)
sys.setdefaultencoding("utf-8")

import tushare as ts
import csv

csvfile_hs300 = file('hs300.csv', 'rb')
reader = csv.reader(csvfile_hs300)

data = ''
for line in reader:
	data += line[1]+','


txt_hs300_code = open('hs300_code.txt', 'w')
txt_hs300_code.write(data)
txt_hs300_code.close( )

csvfile_hs300.close() 