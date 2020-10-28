from googletrans import Translator

translator = Translator()

trans = translator.translate("kaise ho")

print(trans.text)

import pyttsx3

engine = pyttsx3.init()
engine.say(trans.text)
engine.runAndWait()

import tkinter as tk
root = tk.Tk()
root.geometry("400x400")
root.title("Translator")
en = tk.StringVar()
l = tk.Label(root,text= "Enter Text: ").grid(row=0,column=0)

e = tk.Entry(root,textvariable = en).grid(row=0,column=1,ipady=20,ipadx=150)

tb = tk.Button(root,text= 'Translate', fg = "green", bg = "black").grid(row=1,column=0,padx = 10, pady = 10)

sb = tk.Button(root,text= "Speak").grid(row=1,column=1,padx = 10, pady = 10)

T = tk.Text(root,height=30, width = 30)
T.grid(row =2, column = 0, padx=10,pady=10)
root.mainloop()