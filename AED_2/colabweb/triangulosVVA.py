
import turtle as t

t.speed(1)

t.pu()
t.goto(-300, 300)
t.pd()

def triang_vermelho():
    t.fillcolor("red")

    t.begin_fill()
    t.goto(-150,300)
    t.right(120)

    t.goto(-225,180)
    t.right(120)

    t.goto(-300,300)
    t.end_fill()

def triang_verde():

    t.fillcolor("green")
    t.begin_fill()

    t.pu()
    t.goto(-195,180)
    t.pd()

    t.goto(-45,180)
    t.left(120)

    t.goto(-120,300)
    t.left(120)

    t.goto(-195,180)
    t.end_fill()


def triang_azul():

    t.fillcolor("blue")

    t.begin_fill()

    t.pu()
    t.goto(-15, 180)
    t.pd()

    t.left(120)
    t.goto(-90, 300)

    t.right(120)
    t.goto(60, 300)

    t.right(120)
    t.goto(-15, 180)

    t.end_fill()

triang_vermelho()
triang_verde()
triang_azul()
t.mainloop()