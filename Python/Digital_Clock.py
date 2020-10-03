import time
from tkinter import *
root = Tk()
root.title("Digital clock")
root.geometry("250x100+0+0")
root.resizable(0,0)
label = Label(root, font=("Arial", 30, 'bold'), bg="green", fg="powder blue", bd =30)
label.grid(row =0, column=1)
def clack():
    text_input = time.strftime("%H:%M:%S")
    label.config(text=text_input)
    label.after(200, clack)
clack()
root.mainloop()crea
