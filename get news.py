import requests
import json
def speak(str):
    from win32com.client import Dispatch
    speak = Dispatch("SAPI.spVoice")
    speak.Speak(str)
url = ('http://newsapi.org/v2/top-headlines?country=in&apiKey=73ded45905534847a1e8e22f49a73d52')
response = requests.get(url)
text = response.text
pr = json.loads(text)
print(pr)
for i in range(3):
    speak("News"+str(i+1)+" News "+pr['articles'][i]['title'])
