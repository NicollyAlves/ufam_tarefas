import turtle as t

t.pu()
t.goto(-150,-50)
t.pensize(3)
t.pd()

t.pensize(3)

t.fillcolor(.4,.9,.40)

t.begin_fill()
t.forward(300)
t.left(90)
t.forward(30)
t.left(90)
t.forward(300)
t.left(90)
t.forward(30)
t.right(180)
t.forward(30)

t.end_fill()

t.pu()

t.forward(20)

t.pd()

t.fillcolor(.4,.7,.9)

t.begin_fill()

t.right(90)
t.forward(300)
t.left(90)
t.forward(30)
t.left(90)
t.forward(300)
t.left(90)
t.forward(30)

t.end_fill()

t.mainloop()