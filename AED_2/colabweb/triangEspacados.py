import turtle as t

n = int(input("Digite quantos triângulos deseja que apareçam na reta: "))

t.pensize(3)

w = 600

t.pu()
t.goto(-w/2, 0)
t.pd()

s = w/(n + 1)
l = 30

for j in range(n):
    if j == 0 or j == n:
        t.forward(s - (l / 2))

    if j > 0 and j <= n - 1:
        t.forward(s - l)

    t.left(60)
    t.forward(l)
    t.right(120)
    t.forward(l)
    t.left(60)

t.forward(s - (l / 2))

t.mainloop()