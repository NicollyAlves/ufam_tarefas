import tkinter as tk

window = tk.Tk()
window.geometry("500x500")
canvas = tk.Canvas(window, width=500, height=500)

canvas.create_polygon([195,180,45,180,120,300],outline='black', fill='red')
canvas.create_polygon([150,300,225,180,300,300], outline='black', fill='green')
canvas.create_polygon([255,180,405,180,330,300], outline='black', fill='blue')

canvas.pack()

window.mainloop()
