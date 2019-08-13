import requests
from bs4 import BeautifulSoup
def main():
	for i in range(1,11):
		url = "http://acm.hdu.edu.cn/search.php?field=problem&key=2019+Multi-University+Training+Contest+{}&source=1&searchmode=source".format(i)
		r = requests.get(url)
		soup = BeautifulSoup(r.text,"lxml")
		table = soup.body.contents[3].tbody.contents[3].td.table
		problems = table.find_all(attrs={'class':"TABLE_TEXT"})
		if((len(problems)+1)//4<3):
			break
		print(url)
		for i in range(0,(len(problems)+1)//4):
			problem_id=problems[i*4].text
			problem_AC=problems[i*4+3].text.split('(')[1].split('/')[0]
			print("{} {}".format(problem_id,problem_AC))
		print()
	print("EOF")
if __name__ == "__main__":
	main()
