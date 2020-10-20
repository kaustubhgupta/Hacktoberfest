import selenium
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options
import time
import random
from enum import Enum

class Language(Enum):
    english = 1
    portuguese = 2

class DiscordBot:

    def __init__(
            self,
            email: str,
            password: str,
            server: str,
            channel: str,
            is_not_safe_for_work: bool,
            language: Language,
            time_between_messages: int,
            messages: list
    ):
        self.email = email
        self.password = password
        self.server = server
        self.channel = channel
        self.is_not_safe_for_work = is_not_safe_for_work
        self.language = language
        self.time_between_messages = time_between_messages
        self.messages = messages
        self.options = Options()
        self.options.add_argument(f"--lang={'pt-BR' if language == Language.portuguese else 'en-US'}")
        self.options.headless = False
        self.driver = webdriver.Chrome(options=self.options)
        self.getInfos()

    def getInfos(self):
        self.login()

    def closeBrowser(self):
        self.driver.close()

    def login(self):
        driver = self.driver
        driver.get("http://discordapp.com/login")

        email = driver.find_element_by_css_selector("[type=email]")
        email.send_keys(self.email)
        password = driver.find_element_by_css_selector("[type=password]")
        password.send_keys(self.password)
        driver.find_element_by_css_selector("[type=submit]").click()
        time.sleep(10)
        try:
            verifyNewMessagesNotification = driver.find_element_by_xpath("//div[@class='bar-30k2ka unreadMentionsBar-1VrBNe mention-1f5kbO active-1SSsBb']").click()
        except selenium.common.exceptions.ElementClickInterceptedException:
            print("It seems you have new messages and the code cant find the class tag")
            print("The code should never get in this print")
        time.sleep(2)
        serverName = driver.find_element_by_xpath(f"//a[@aria-label='{self.server}']").click()
        time.sleep(2)

        channelName = driver.find_element_by_xpath(
            f"//div[@aria-label='{self.channel} {'(canal de texto)' if self.language == Language.portuguese else '(text channel)'}']"
        ).click()
        time.sleep(3)

        continueButton = (driver.find_element_by_xpath(f"//div[text()='{'Continuar' if self.language == Language.portuguese else 'Continue'}']").click()) if self.is_not_safe_for_work else 0
        time.sleep(3)
        array = self.messages
        while True:
            sendMessage = driver.find_element_by_xpath(f"//div[@aria-label='{'Conversar em ' if self.language == Language.portuguese else 'Message '}#{self.channel}']")
            sendMessage.send_keys(random.choice(array))
            time.sleep(3)
            sendMessage.send_keys(Keys.ENTER)
            time.sleep(2)



if __name__ == '__main__':
    #Get inputs from user, login, channel and server name, isNSFW, language, time between messages and messages.
    email = input("insert your email: ")
    password = input("insert your password: ")
    server = input("insert the discord server name: ")
    channel = input("insert the discord channel name: ")
    is_not_safe_for_work = bool(input("the server is not safe for work: (True) or (False) "))
    language = input("Your discord is in portuguese or english?: (portuguese) or (english) ")
    if language == "portuguese":
        language = Language.portuguese
    elif language == "english":
        language = Language.english
    else:
        exit("you should pass english or portugues to continue")
    time_between_messages = int(input("insert the time between messages: "))
    messages = []
    message = ""
    while message != "continue":
        message = input("insert the messages to be sent in random order, to continue insert continue and press enter: ")
        if message == "continue": 
            break
        messages.append(message)

    discordBot = DiscordBot(
        email=email,
        password=password,
        server=server,
        channel=channel,
        is_not_safe_for_work=is_not_safe_for_work,
        language=language,
        time_between_messages=time_between_messages,
        messages=messages
    )