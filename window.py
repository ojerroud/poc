# -*- coding: utf-8 -*-
 
from tkinter import * 

fenetre = Tk()
value = StringVar() 
bouton1 = Radiobutton(fenetre, text="Scrap", variable=value, value=1).pack()
bouton2 = Radiobutton(fenetre, text="Parse", variable=value, value=2).pack()
bouton3 = Radiobutton(fenetre, text="Analyse", variable=value, value=3).pack()
bouton4 = Radiobutton(fenetre, text="Tout", variable=value, value=4).pack()


label = Label(fenetre, text="Veuillez coller l'adresse du profil facebook :").pack()

value = StringVar() 
value.set("https://www.facebook.com/")
entree = Entry(fenetre, textvariable=value, width=30, bg="ivory").pack()

validate=Button(fenetre, text ='Valider', bg="ivory").pack()
var = "test"

Frame1 = Frame(fenetre, borderwidth=2, relief=GROOVE).pack(padx=30, pady=30)
canvas = Canvas(Frame1, width=fenetre.winfo_reqwidth(), height=fenetre.winfo_reqheight(), background='#CCCCCC')
txt = canvas.create_text(75, 60, text=var)
canvas.pack()

fenetre.mainloop()