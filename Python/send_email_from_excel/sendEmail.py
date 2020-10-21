import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication

class Email():
	def __init__(self, username, password, sender):
		self.username = username
		self.password = password
		self.sender = sender.lower()

	def send(self, to, subject, message, attachment=None):
		
		try:

			# configuring mime for email
			self.msg = MIMEMultipart()
			self.msg['From'] = self.username
			self.msg['To'] = to
			self.msg['Subject'] = subject

			self.msg.attach(MIMEText(message))

			if attachment:
				with open(attachment, 'rb') as f:
					self.part = MIMEApplication(f.read())

				self.part['Content-Disposition'] = 'attachment; filename="%s"' % attachment
				self.msg.attach(self.part)

			# configuring SMTP 
			if self.sender == "gmail":
				self.server = smtplib.SMTP('smtp.gmail.com', 587)
			elif self.sender == "outlook":
				self.server = smtplib.SMTP('smtp.office365.com',587)

			self.server.ehlo()
			self.server.starttls()
			self.server.login(self.username, self.password)

			self.server.send_message(self.msg)
			self.server.quit()

			return "email sent to %s" % to

		except Exception as e:

			return str(e)