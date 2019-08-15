import time
import os
import json
import requests
def main():
	for contest_id in range(881,891):
		hyper="https://ac.nowcoder.com/acm/contest/{}#question".format(contest_id)
		url="https://ac.nowcoder.com/acm/contest/problem-list?token=&id={}".format(contest_id)
		if contest_id<=882:
			url2="https://ac.nowcoder.com/acm/contest/status-list?token=&id={}&pageSize=100&statusTypeFilter=5&searchUserName=bed".format(contest_id)
		else:
			url2="https://ac.nowcoder.com/acm/contest/status-list?token=&id={}&pageSize=100&statusTypeFilter=5&searchUserName=Go_go".format(contest_id)
		r=requests.get(url)
		text=json.loads(r.text)
		if text["code"]!=0:
			break
		r2=requests.get(url2)
		text2=json.loads(r2.text)
		AC=[]
		for i in range(0,len(text["data"]["data"])):
			AC.append("W")
		for submit in text2["data"]["data"]:
			AC[ord(submit["index"])-65]="-"
		print(hyper)
		i=0
		for problem in text["data"]["data"]:
			print("{} {} {}".format(problem["index"],problem["acceptedCount"],AC[i]))
			i+=1
		print("")
	print("EOF")
if __name__=='__main__':
	main()
