import pandas as pd
import sendEmail
import os


def fileNames():
	# This function will display the list of files inside the working directory
	files = os.listdir(os.getcwd())
	for k, v in enumerate(files):
		print(k, v)

	return files

def fileSelector():
	# This function will encure that the user select one of the file inside the folder
	files_ = fileNames()
	f_ = int(input("Enter the file number: "))

	if f_ in range(len(files_)):
		a = files_[f_]
	else:
		print("="*30)
		print('Please select a proper file name')
		fileSelector()

	return a


def start():
	# configuration
	U_ = input('Enter your email: ')
	P_ = input('Enter Password: ')
	SENDER_ = input('Select one (Gmail/Outlook): ').capitalize()

	# check if the user has entered all thr required information
	if U_ != "" or P_ != "" or SENDER_ != "":

		# check if the user has selected either gmail or outlook
		if SENDER_ in ['Gmail','Outlook']:

			# configure the sendEmail module
			EMAIL_ = sendEmail.Email(U_, P_, SENDER_)

			# select the excel file
			f = fileSelector()

			try:
				# read the excel file
				data = pd.read_excel(f)

				# loop over each rows in the excel file
				for k, v in data.iterrows():
					target = v['Email'] 
					subject = v['Subject']
					body = v['Body']

					# send email 
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
