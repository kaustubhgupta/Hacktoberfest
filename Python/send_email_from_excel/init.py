import pandas as pd
import sendEmail
import os

def fileNames():
	#select file : excel
	files = os.listdir(os.getcwd())
	for k, v in enumerate(files):
		print(k, v)

	return files

def fileSelector():
	files_ = fileNames()
	f_ = int(input("Enter the file number: "))

	if f_ in range(len(files_)):
		return files_[f_]
	else:
		print("="*30)
		print('Please select a proper file name')
		fileSelector()



def start():
	# configuration
	USER_ = input('Enter your email: ')
	PASS_ = input('Enter Password: ')
	SENDER_ = input('Select one (Gmail/Outlook): ').capitalize()

	if USER_ != "" or PASS_ != "" or SENDER_ != "":

		if SENDER_ in ['Gmail','Outlook']:

			EMAIL_ = sendEmail.Email(USER_, PASS_, SENDER_)

			f = fileSelector()

			try:
				data = pd.read_excel(f)

				for k, v in data.iterrows():
					target = v['Email'] 
					subject = v['Subject']
					body = v['Body']

					e = EMAIL_.send(target, subject, body)

					print(e)
					
			except Exception as e:
				print(str(e))
				
		else:
			print("="*30)
			print('Please select Gmail/Outlook')
			start()
	else:
		print("="*30)
		print('Pleas enter all values')
		start()


if __name__ == "__main__":
	start()



		



