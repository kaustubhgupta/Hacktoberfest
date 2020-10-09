import json
import time
import pandas as pd
from selenium import webdriver
import datefinder
from datetime import datetime 
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
# driver is our way to access the webpages
# This code is meant to be run using the Google Chrome browser. Any other browser would require you to change the following function. 
# eg. webdriver.Firefox for the Firefox browser.
driver = webdriver.Chrome()
driver.implicitly_wait(5)
baseUrl = "https://www.youtube.com/feed/trending"
all_details = []

# This returns a list of links to all the trending videos
def getVideoURLs():
    driver.get(baseUrl)
    time.sleep(3)
    allVideoList= driver.find_elements_by_css_selector("#video-title")
    links = list(dict.fromkeys(map(lambda a: a.get_attribute("href"),allVideoList)))
    return links

# This returns the specified details about the input video
def getVideoDetails(video):
	driver.get(video)
	time.sleep(1.5)
	vname = driver.find_element_by_xpath('//*[@id="container"]/h1/yt-formatted-string').text
	vviews = driver.find_element_by_xpath('//*[@id="count"]/yt-view-count-renderer/span[1]').text.split()[0].replace(',', "")
	menu_container = driver.find_element_by_id("menu-container")
	menu = menu_container.find_element_by_id("menu")
	vlikes = menu.find_element_by_id("text").get_attribute('aria-label')
	vdislikes = menu.find_elements_by_id("text")[1].get_attribute('aria-label')
	date_string = driver.find_element_by_id("date").text
	date_list = list(datefinder.find_dates(date_string))
	if len(date_list) > 0:
		datetimeobj = date_list[0]
		vdate = datetimeobj.strftime("%d/%m/%Y")
	else:
		vdate = 'No dates found'
	ActionChains(driver).move_to_element(driver.find_element_by_id('comments')).perform()
	comm = driver.find_element_by_tag_name("h2")
	vcomments = comm.find_element_by_xpath("//*[@id='count']/yt-formatted-string").text.split()[0].replace(',', "")
	vviews = int(vviews)
	if vlikes: 
		vlikes = int(vlikes.split()[0].replace(',', ""))
	if vdislikes: 
		vdislikes = int(vdislikes.split()[0].replace(',', ""))
	details = [vname, vviews, vlikes, vdislikes, vcomments, vdate]
	return details

if __name__ == '__main__':
	videos = getVideoURLs()
	for video in videos:
		all_details.append(getVideoDetails(video))
	
	# all_details is a list of lists which contain the video details
	# Making a DataFrame to extract the data in a CSV
	df = pd.DataFrame(all_details, columns = ["Title", "Views", "Likes", "Dislikes", "Comments", "Date"])
	df.to_csv('Trending_Page_Data.csv')
