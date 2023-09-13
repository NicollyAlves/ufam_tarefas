import turtle as t

n = int(input("Digite quantos retângulos você deseja: "))

t.pu()
t.goto(-150,-250)
t.pensize(3)
t.pd()

t.fillcolor(.8,.6,.90)

t.shape("turtle")

for i in range(n):
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

    t.right(90)

t.mainloop()