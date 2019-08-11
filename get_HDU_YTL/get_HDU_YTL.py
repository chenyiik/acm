import time
import os
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
def main():
	try:
		driver = webdriver.Safari()
	except:
		options = webdriver.ChromeOptions()
		options.add_argument("--headless")
		driver = webdriver.Chrome(options=options)
	try:
		for contest_id in range(1,11):
			url="http://acm.hdu.edu.cn/search.php?field=problem&key=2019+Multi-University+Training+Contest+{}&source=1&searchmode=source".format(contest_id)
			driver.get(url)
			wait = WebDriverWait(driver, 2)
			table = wait.until(EC.presence_of_element_located((By.TAG_NAME, 'table')))
			table = table.find_elements_by_tag_name("table")
			table = table[2].find_elements_by_tag_name("table")
			table_rows = table[1].find_elements_by_tag_name("tr")
			if(len(table_rows)==1):
				break
			print(url)
			for i in range(1,len(table_rows)):
				table_columns = table_rows[i].find_elements_by_tag_name("td")
				str=table_columns[0].text+" "+table_columns[4].text.split("/")[0][1:]
				print(str)
			print("")
	except:
		driver.close()
	else:
		driver.close()
	print("EOF")
if __name__=='__main__':
	main()
