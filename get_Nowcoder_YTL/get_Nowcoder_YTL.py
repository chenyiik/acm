import time
import os
import json
import requests
def main():
	for contest_id in range(881,891):
		hyper="https://ac.nowcoder.com/acm/contest/{}#question".format(contest_id)
		url="https://ac.nowcoder.com/acm/contest/problem-list?token=&id={}".format(contest_id)
		r=requests.get(url)
		text=json.loads(r.text)
		if text["code"]!=0:
			break
		print(hyper)
		for problem in text["data"]["data"]:
			print("{} {}".format(problem["index"],problem["acceptedCount"]))
		print("")
	print("EOF")
if __name__=='__main__':
	main()
