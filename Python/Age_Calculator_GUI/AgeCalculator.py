# Author - Sandip Sadhukhan
# Date - 09-10-2020
#import datetime module
import datetime
from tkinter import *
from tkinter import messagebox
#calculations
def setFullAge(y,m,d):
    fullDay.set(str(d))
    fullMonth.set(str(m))
    fullYear.set(str(y))

def setNextBirthday(m,d):
    nextBirthdayDayVar.set(str(d))
    nextBirthdayMonthVar.set(str(m))

def setTotalValues(y,m,w,d):
    totalDaysVar.set(str(d))
    totalWeeksVar.set(str(w))
    totalMonthsVar.set(str(m))
    totalYearsVar.set(str(y))

def calculateAge():
    #get the current date
    currentdate = datetime.datetime.now()
    #take input
    birthday = inputfield.get()
    try:
        birthdayDate=datetime.datetime.strptime(birthday,'%d/%m/%Y')
    except:
        setFullAge(0,0,0)
        setNextBirthday(0,0)
        setTotalValues(0,0,0,0)
        messagebox.showerror("Error","Wrong Value of Birthday")
        return
    nextBirthday = str(birthdayDate.day)+'/'+str(birthdayDate.month)+'/'+str(currentdate.year+1)
    nextBirthdayDate=datetime.datetime.strptime(nextBirthday,'%d/%m/%Y')

    #calculate years
    years = (currentdate-birthdayDate).total_seconds()/3600/24/365.242
    yearsInt = int(years)

    #calculate months
    months = (years-yearsInt)*12
    monthsInt = int(months)

    #calculate days
    days = (months-monthsInt)*(365.242/12)
    daysInt = int(days)

    #calculate next birthday
    nextBirthdayMonth = ((nextBirthdayDate-currentdate).total_seconds())/3600/24/(365.242/12)
    nextBirthdayMonthInt = int(nextBirthdayMonth)
    nextBirthdayDays = (nextBirthdayMonth-nextBirthdayMonthInt)*(365.242/12)
    nextBirthdayDaysInt = round(nextBirthdayDays)

    #total month,weeks,days
    totalMonth = round((currentdate-birthdayDate).total_seconds()/3600/24/(365.242/12))
    totalWeeks = round((currentdate-birthdayDate).total_seconds()/3600/24/(365.242/52.149))
    totalDays = round((currentdate-birthdayDate).total_seconds()/3600/24)

    # #outputs 
    setFullAge(yearsInt,monthsInt,daysInt)
    setNextBirthday(nextBirthdayMonthInt,nextBirthdayDaysInt)
    setTotalValues(yearsInt,totalMonth,totalWeeks,totalDays)
    # print(f"You're {yearsInt} Years, {monthsInt} Months, {daysInt} Days.")
    # print(f"Next birthday is {nextBirthdayMonthInt} months and {nextBirthdayDaysInt} days left.")
    # print(f"Your total Years = {yearsInt},\nTotal Months = {totalMonth}\nTotal Weeks = {totalWeeks}\nTotal Days = {totalDays}")



#default window size
HEIGHT = 400
WIDTH = 600

#init the tkinter
root = Tk()
root.title("Age Calculator")

#init the canvas
canvas = Canvas(root,width = WIDTH, height = HEIGHT)
canvas.pack()

#setup frontend
#set frame
frame = Frame(root,bg="#30336b")
frame.place(relheight=1,relwidth=1,relx=0,rely=0)
#set heading
headingLabel = Label(frame,text="Age Calculator",bg="#ed4d4b",fg="#fff",font=55)
headingLabel.place(relheight = .08,relwidth=.23,relx=.4,rely=.02)
#set inputlabel
inputLabel = Label(frame,text="Enter Your Date Of Birth (DD/MM/YYYY) :",font=40,fg="#fff",bg="#30336b")
inputLabel.place(relheight=.05,relwidth=.55,relx=.1,rely=.13)
#set input
inputfield = StringVar()
myInput = Entry(frame,font = 50,textvariable = inputfield,bg="teal",fg="#fff")
myInput.place(relheight = .07,relwidth=.2,relx=.67,rely=.13)
#calculateAge button
calculateButton = Button(frame,text="Calculate Age",bg="#fc427b",fg="#fff",activebackground="#fd9944",command=calculateAge)
calculateButton.place(relheight=.07,relwidth=.3,relx=.36,rely=.25)
#output screen 
textAgeLabel=Label(frame,textvariable="fullAge",text="Your Age - ",bg="#30336b",fg="#fff",font=55)
textAgeLabel.place(relheight=.05,relwidth=.15,relx=.09,rely=.39)
#for years
fullYear=StringVar()
fullYearOutput = Label(frame,textvariable =fullYear,bg="#30336b",fg="white",font=60)
fullYearOutput.place(relheight=.05,relwidth=.06,relx=.24,rely=.39)
fullYearText=Label(frame,text="Years,",bg="#30336b",fg="#fff",font=55)
fullYearText.place(relheight=.05,relwidth=.1,relx=.32,rely=.39)
#for month
fullMonth=StringVar()
fullMonthOutput = Label(frame,textvariable =fullMonth,bg="#30336b",fg="white",font=60)
fullMonthOutput.place(relheight=.05,relwidth=.05,relx=.42,rely=.39)
fullMonthText=Label(frame,text="Months,",bg="#30336b",fg="#fff",font=55)
fullMonthText.place(relheight=.05,relwidth=.13,relx=.49,rely=.39)
#for days
fullDay=StringVar()
fullDayOutput = Label(frame,textvariable =fullDay,bg="#30336b",fg="white",font=60)
fullDayOutput.place(relheight=.05,relwidth=.05,relx=.62,rely=.39)
fullDayText=Label(frame,text="Days,",bg="#30336b",fg="#fff",font=55)
fullDayText.place(relheight=.05,relwidth=.1,relx=.67,rely=.39)
#set default value
setFullAge(0,0,0)

#for nextBirthday
nextBirthdayText = Label(frame,text="Next Birthday : ",bg="#30336b",fg="white",font=40)
nextBirthdayText.place(relheigh=.05,relwidth=.21,relx=.09,rely=.48)
#for nextBirthday month
nextBirthdayMonthVar=StringVar()
nextBirthdayMonthOutput = Label(frame,textvariable =nextBirthdayMonthVar,bg="#30336b",fg="white",font=60)
nextBirthdayMonthOutput.place(relheight=.05,relwidth=.05,relx=.3,rely=.48)
nextBirthdayMonthText=Label(frame,text="Months,",bg="#30336b",fg="#fff",font=55)
nextBirthdayMonthText.place(relheight=.05,relwidth=.13,relx=.35,rely=.48)
#for nextBirthday Day
nextBirthdayDayVar=StringVar()
nextBirthdayDayOutput = Label(frame,textvariable =nextBirthdayDayVar,bg="#30336b",fg="white",font=60)
nextBirthdayDayOutput.place(relheight=.05,relwidth=.05,relx=.48,rely=.48)
nextBirthdayDayText=Label(frame,text="Days",bg="#30336b",fg="#fff",font=55)
nextBirthdayDayText.place(relheight=.05,relwidth=.09,relx=.53,rely=.48)
#left text
leftText = Label(frame,text=" Left.",bg="#30336b",fg="white",font=60)
leftText.place(relheight=.05,relwidth=.07,relx=.62,rely=.48)
#set default values
setNextBirthday(0,0)

#for total values
totalYearsText = Label(frame,text="Total Years :",bg="#30336b",fg="white",font=40)
totalYearsText.place(relheight=.05,relwidth=.178,relx=.09,rely=.57)
totalYearsVar=StringVar()
totalYearsOutput = Label(frame,textvariable =totalYearsVar,bg="#30336b",fg="white",font=60,anchor="w")
totalYearsOutput.place(relheight=.05,relwidth=.10,relx=.265,rely=.57)
#for total months
totalMonthsText = Label(frame,text="Total Months :",bg="#30336b",fg="white",font=40)
totalMonthsText.place(relheight=.05,relwidth=.2,relx=.09,rely=.66)
totalMonthsVar=StringVar()
totalMonthsOutput = Label(frame,textvariable =totalMonthsVar,bg="#30336b",fg="white",font=60,anchor="w")
totalMonthsOutput.place(relheight=.05,relwidth=.15,relx=.29,rely=.66)
#for total weeks
totalWeeksText = Label(frame,text="Total Weeks :",bg="#30336b",fg="white",font=40)
totalWeeksText.place(relheight=.05,relwidth=.2,relx=.52,rely=.57)
totalWeeksVar=StringVar()
totalWeeksOutput = Label(frame,textvariable =totalWeeksVar,bg="#30336b",fg="white",font=60,anchor="w")
totalWeeksOutput.place(relheight=.05,relwidth=.19,relx=.716,rely=.57)
#for total days
totalDaysText = Label(frame,text="Total Days :",bg="#30336b",fg="white",font=40)
totalDaysText.place(relheight=.05,relwidth=.2,relx=.52,rely=.66)
totalDaysVar=StringVar()
totalDaysOutput = Label(frame,textvariable =totalDaysVar,bg="#30336b",fg="white",font=60,anchor="w")
totalDaysOutput.place(relheight=.05,relwidth=.24,relx=.716,rely=.66)
#set default values
setTotalValues(0,0,0,0)

root.mainloop()