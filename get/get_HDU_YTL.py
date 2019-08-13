import requests
import re
from bs4 import BeautifulSoup
def main():
	mp={}
	for user in ["cthulhu", "bearx"]:
		url = "http://acm.hdu.edu.cn/userstatus.php?user={}".format(user)
		r = requests.get(url)
		soup = BeautifulSoup(r.text, "lxml")
		res = re.findall(r"p\((\d+),",soup.body.table.contents[10].td.script.text)
		for problem_id in res:
			mp[problem_id] = True
	for i in range(1,11):
		url = "http://acm.hdu.edu.cn/search.php?field=problem&key=2019+Multi-University+Training+Contest+{}&source=1&searchmode=source".format(i)
		r = requests.get(url)
		soup = BeautifulSoup(r.text, "lxml")
		table = soup.body.contents[3].tbody.contents[3].td.table
		problems = table.find_all(attrs={'class':"TABLE_TEXT"})
		if((len(problems)+1)//4<3):
			continue
		print(url)

		contest_id = 847 + i
		contest_url = "http://acm.hdu.edu.cn/contests/contest_show.php?cid={}".format(contest_id)
		contest_login_url="http://acm.hdu.edu.cn/userloginex.php?action=login&cid={}&notice=0".format(contest_id)
		params = {"username":"team0649","userpass":"147838","login":"Sign In"}
		session = requests.session()
		post_obj = session.post(contest_login_url, params)
		r2 = session.get(contest_url)
		soup = BeautifulSoup(r2.text, "lxml")
		local_mp = []
		cnt = []
		for i in range(len(soup.table.contents)):
			if i == 0:
				continue
			cnt.append(eval(soup.table.contents[i].text.split("(")[1].split("/")[0]))
			if soup.table.contents[i].img!=None:
				#print("{}".format(i+1000))
				local_mp.append(True)
			else:
				local_mp.append(False)

		for i in range(0,(len(problems)+1)//4):
			problem_id = problems[i*4].text
			problem_AC = eval(problems[i*4+3].text.split('(')[1].split('/')[0])
			problem_AC += cnt[i]
			if (problem_id in mp.keys()) or (local_mp[i]):
				problem_solved = '-'
			else:
				problem_solved = 'W'
			print("{} {} {}".format(problem_id, problem_AC, problem_solved))
		print()
	print("EOF")
if __name__ == "__main__":
	main()
