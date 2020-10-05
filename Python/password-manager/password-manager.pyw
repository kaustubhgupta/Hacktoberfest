# imports
from tkinter import*  # imports tkinter module used for providiving GUI to our application
import tkinter.messagebox
import random  # imports random module used in generating random password
import pyperclip  # module used to copy and paste passwords
import csv  # module used in saving file data
root = Tk()  # instance for GUI
root.geometry("800x500")  # defines size of our instance
root.title("PASSWORD MANAGER")  # title for title bar


def view():  # function to view passwords
    top = Toplevel()  # instace of GUI
    top.title("PASSWORDS")  # title for title bar of pasword window
    file = open('passwords.csv')  # opens file
    rows = csv.reader(file)  # reads rows of CSV file
    for row in csv.reader(file):
        Label(top, text=row).pack()  # shows passwords as labels of GUI
    file.close()  # closes file


# button for passwords
Button(root, text="View all Passwords", width=18, height=3, relief="raised", bd=8, fg="BLUE",
       activebackground="blue", bg="white", command=view).grid(row=36, column=60, columnspan=3)
Label(root, text="      Enter length of Password : ",
      font=("Aerial Bold", 14)).grid(row=2, column=0)
Label(root, text="(Password must be of atleast 8 characters)",
      font=("Sans Serif", 10)).grid(row=3, column=1, columnspan=2)
# takes value from user
userInput = IntVar()
Entry(root, textvariable=userInput).grid(row=2, column=1, columnspan=4)
# function to generate password


def passwordgenerate():
    x = userInput.get()
    if x < 8:  # condition for number less than 8
        tkinter.messagebox.showinfo(
            "Alert Message", "Sorry,minimum length must be 8. Please try again.")  # message box
        button = Button(root, text="Generate", height=3, width=18, bd=8, activebackground="blue",
                        command=res, relief="raised", bg="white", fg="blue", state="enable").grid(row=30, column=60,)
    else:
        new_list = []
        # to make sure our password contains atleast one integer, one special character and one alphabet we appended one to list
        new_list.append(random.choice('0123456789'))  # one random number

        # one random special character
        new_list.append(random.choice('!@#$%^&*_'))

        new_list.append(random.choice(
            'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'))  # one random alphabet

        for i in range(3, x):
            # appends character to list randomly
            new_list.append(random.choice(
                '0123456789!@#$%^&*_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'))

        random.shuffle(new_list)  # shuffles whole list toincrease randomness
        password = ""
        password = password.join(new_list)  # converts list to a string

        def copy():  # function to copy password to clipboard
            pyperclip.copy(password)  # copies password
            Button(root, text="Copied", height=1, width=10, relief="raised", bd=8,
                   bg="white", command=copy, fg="BLUE", state="disabled").grid(row=11, column=1)

        def save():  # function to save password in new file
            Button(root, text="Save", height=1, width=10, relief="raised", bd=8,
                   command=save, bg="white", fg="BLUE", state="disabled").grid(row=11, column=2)
            Label(root, text="    Password is for platform : ",
                  font=("Slab Serif", 16)).grid(row=16, column=0)
            c = StringVar()  # take domain as input form user
            Entry(root, textvariable=c).grid(row=16, column=1)

            def confirm():
                copy()  # function calling
                password = pyperclip.paste()
                Button(root, text="Saved", height=1, relief="raised", width=11, bd=8, bg="white",
                       command=confirm, state="disabled", fg="BLUE").grid(row=16, column=2)
                data = [c.get(), password]
                file = open('passwords.csv', 'a')
                csv.writer(file).writerow(data)
                file.close()
            Button(root, text=">>", height=1, width=11, relief="raised", bg="white", bd=8,
                   activebackground="blue", command=confirm, fg="BLUE").grid(row=16, column=2)
        Label(root, text="      Your random Password is : ",
              font=("Slab Serif", 16)).grid(row=5, column=0)
        Button(root, text="Copy", relief="raised", height=1, width=10, bd=8, bg="white",
               activebackground="blue", command=copy, fg="BLUE").grid(row=11, column=1)
        Button(root, text="Save & Copy", relief="raised", height=1, width=11, bd=8,
               bg="white", activebackground="blue", command=save, fg="BLUE").grid(row=11, column=2)
        return new_list


def res():

    Label(root, text=passwordgenerate(), font=("Slab Serif", 16),).grid(
        row=5, column=1, columnspan=2, padx=20)

    Button(root, text="Generate", height=3, width=18, bd=8, activebackground="blue", command=res,
           relief="raised", bg="white", state="disabled", fg="blue").grid(row=30, column=60,)


button = Button(root, text="Generate", height=3, width=18, bd=8, activebackground="blue",
                command=res, relief="raised", bg="white", fg="blue").grid(row=30, column=60,)


root.mainloop()  # loop that allows GUI to run
