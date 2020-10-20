#!/Library/Frameworks/Python.framework/Versions/3.7/bin/python3

import tweepy
import time
import datetime
import random


def start_tweeting_fun_messages():
	time_between_messages = 20

	# create a twitter developer account, or use your account if you have one
	# follow this steps to get your keys from your developer account
	# https://www.slickremix.com/docs/how-to-get-api-keys-and-tokens-for-twitter/
	consumer_key = input("ADD_CONSUMER_KEY_HERE: ")
	consumer_secret = input("ADD_CONSUMER_SECRET_HERE: ")

	access_token = input("ADD_ACCESS_TOKEN_HERE: ")
	access_secret = input("ADD_ACCESS_SECRET_HERE: ")

	auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
	auth.set_access_token(access_token, access_secret)

	try:
		redirect_url = auth.get_authorization_url()
	except tweepy.TweepError:
		print('Error! Failed to get request token.')


	api = tweepy.API(auth)

	#friends list, you have to create some friends without the @ to tweepy don't drop your connection
	friends = ["a", "b", "fakeTwitterFriend so the api doesnt block you", "@add your friends name here", "@me", "@you"]

	# initial part of the tweet
	initTextMessages = [
		"EXAMPLE MESSAGES",
		"BOMDIAZYM Pessoa encantada do submundo",
		"FAAAAALA BONECOS E BONECAS DESSE BRASIL",
		"HEEEEEEEEEEEEEY",
		"TA NA HORA TA NA HORA",
		"PARARANPAM PARARANPAM PIRATAS DO CARIBE",
		"Hoje o dia ta tao bonito",
		"as rosas sao vermetas e viotelhas sao azuis",
		"Um dia a gente perde, outro dia ganham da gente",
		"se voce ta lendo isso desliga o telefone e sai do quarto :)",
		"nada melhor que um cu            pom"
	]

	# final part of the tweet
	endTextMessages = [
		"EXAMPLE MESSAGES",
		"QUE DEUS ELIMINE A SUA VIDA POR COMPLETO",
		"SABE POR QUE O AIRTON SENNA NAO PILOTA A NOITE?",
		"LEEEEEAVE THEM KIDS ALONE",
		"FLAMENGO NAO É TIME FLAMENGO É SELECAO PORRAAAAAAA",
		"QUETINHOOOOOO",
		"que deus lhe abençoe",
		"é isso mesmo rapaiz",
		"comam frutas e se hidratem "]

	date = datetime.datetime.now()
	# verify hour to say good morning, or good afternoon or good night
	timeHour = ["manhã, bom dia!", "tarde, boa tarde!", "noite, boa noite!"]

	if 5 < date.hour <= 12:
		timeHour = timeHour[0]
	elif 12 < date.hour <= 17:
		timeHour = timeHour[1]
	else:
		timeHour = timeHour[2]

	for friend in friends:
		# create new status concatenating your fun messages and post in your timeline
		new_status = random.choice(initTextMessages) + ' ' + friend + ' agora são: ' + str(date.hour) + " da " + timeHour +" " +random.choice(endTextMessages)
		print(new_status)
		api.update_status(new_status)

		time.sleep(time_between_messages)

if __name__ == "__main__":
	start_tweeting_fun_messages()
