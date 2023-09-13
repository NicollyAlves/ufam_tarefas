import turtle as t

t.shape("turtle")

def triang_equilatero():
    t.speed(2)
    t.pu()
    t.goto(-90,-10)
    t.pd()

    t.fillcolor('purple')

    t.begin_fill()

    t.forward(200)
    t.left(120)
    t.forward(200)
    t.left(120)
    t.forward(200)

    t.end_fill()

triang_equilatero()
t.mainloop()