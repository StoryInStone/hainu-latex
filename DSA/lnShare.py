# -*- coding:utf-8 -*-  
import sys
reload(sys)
sys.setdefaultencoding("utf-8")

import tushare as ts
import csv
from math import log, e


f = open("hs300_code.txt")
line = f.readline()
array = line.split(',')

for code in array:
	try:
		csvfile_share = file('./'+code+'.csv', 'rb')
		reader = csv.reader(csvfile_share)
		data = ''
		for line in reader:
			data += line[1] + ','
		data_array = data.split(',')
		ln = ''
		for i in range(1,15):
			ln += str(log(float(data_array[i]), e) - log(float(data_array[i+1]), e)) + ','
		txt_data = open('./lnShare/'+code+'.txt', 'w')
		txt_data.write(ln)
		txt_data.close()
		csvfile_share.close()
		print '成功'+code
	except:
		print '失败'+code

f.close()
