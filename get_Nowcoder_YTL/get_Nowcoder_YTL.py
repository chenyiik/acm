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
		for contest_id in range(881,891):
			url="https://ac.nowcoder.com/acm/contest/{}#question".format(contest_id)
			driver.get(url)
			if driver.current_url!=url:
				break
			wait = WebDriverWait(driver, 10)
			table = wait.until(EC.presence_of_element_located((By.CLASS_NAME, 'table-hover')))
			table_rows = table.find_elements_by_tag_name("tr")
			print(url)
			for i in range(1,len(table_rows)):
				table_columns = table_rows[i].find_elements_by_tag_name("td")
				str=table_columns[0].text+" "+table_columns[4].text.split('/')[0]
				print(str)
			print("")
	except:
		pass
	finally:
		driver.close()
	print("EOF")
if __name__=='__main__':
	main()
