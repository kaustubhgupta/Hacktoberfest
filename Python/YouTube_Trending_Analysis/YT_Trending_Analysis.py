import json
import time
import pandas as pd
from selenium import webdriver
driver = webdriver.Chrome()
driver.implicitly_wait(5)
baseUrl = "https://www.youtube.com/feed/trending"
all_details = []

def getVideoURLs():
    driver.get(baseUrl)
    time.sleep(3)
    allVideoList= driver.find_elements_by_css_selector("#video-title")
    links = list(dict.fromkeys(map(lambda a: a.get_attribute("href"),allVideoList)))
    return links

def getVideoDetails(video):
	driver.get(video)
	time.sleep(1.5)
	vname = driver.find_element_by_xpath('//*[@id="container"]/h1/yt-formatted-string').text
	vviews = driver.find_element_by_xpath('//*[@id="count"]/yt-view-count-renderer/span[1]').text.split()[0]
	menu_container = driver.find_element_by_id("menu-container")
	menu = menu_container.find_element_by_id("menu")
	vlikes = menu.find_element_by_id("text").get_attribute('aria-label')
	vdislikes = menu.find_elements_by_id("text")[1].get_attribute('aria-label')
	
	#Comments, Date of Publishing, etc. can be added similarly

	details = [vname, vviews, vlikes, vdislikes]
	return details

if __name__ == '__main__':
	videos = getVideoURLs()
	for video in videos:
		all_details.append(getVideoDetails(video))

	df = pd.DataFrame(all_details, columns = ["Title", "Views", "Likes", "Dislikes"])
	df.to_csv('Trending_Page_Data.csv')
