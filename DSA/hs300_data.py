# -*- coding:utf-8 -*-  

import sys
reload(sys)
sys.setdefaultencoding("utf-8")

import tushare as ts
import csv

csvfile_hs300 = file('hs300.csv', 'rb')
reader = csv.reader(csvfile_hs300)

for line in reader:
	try:
		df = ts.get_hist_data(line[1])
		df.to_csv('./'+line[1]+'.csv',columns=['close'])
		print '成功'+line[1]
	except:
		print '放弃'+line[1]

csvfile_hs300.close() 
