import tkinter as tk

window = tk.Tk()
window.geometry("700x350")
canvas = tk.Canvas(window, width='700', height='350')

circulo1 = "#0885c2"
circulo2 = "#fbb132"
circulo3 = "black"
circulo4 = "#1c8b3c"
circulo5 = "#ed334e"

traco_circunferencia = 17

canvas.create_oval(10, 20, 210, 220, outline=circulo1, width=17)

canvas.create_arc(120,120,320,320, start=0, extent=92, outline=circulo2, width=traco_circunferencia, style=tk.ARC)
canvas.create_arc(120,120,320,320, start=90, extent=287, outline=circulo2, width=traco_circunferencia, style=tk.ARC)
canvas.create_arc(10,20,210,220, start=300, extent=90, outline=circulo1, width=traco_circunferencia, style=tk.ARC)

canvas.create_arc(240, 20, 440, 220, start=544, extent=354, outline=circulo3, width=traco_circunferencia, style=tk.ARC)
canvas.create_arc(120,120,320,320, start=10, extent=78, outline=circulo2, width=traco_circunferencia, style=tk.ARC)


canvas.create_arc(350,120,550,320, start=100, extent=351, outline=circulo4, width=traco_circunferencia, style=tk.ARC)
canvas.create_arc(240, 20, 440, 220, start=324, extent=74, outline=circulo3, width=traco_circunferencia, style=tk.ARC)

canvas.create_arc(470,20,670,220, start=543, extent=354,outline=circulo5, width=traco_circunferencia,style=tk.ARC)
canvas.create_arc(350,120,550,320, start=38, extent=51, outline=circulo4, width=traco_circunferencia, style=tk.ARC)

canvas.pack()

window.mainloop()