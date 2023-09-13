import turtle as t

t.speed(0)

def stacksquares(x,y,s,n):
    if n==0:
        return
    
    t.up()


    if n >0:
        t.goto(x-s/2,y-s/2)
    print(x, y)
    t.down()
    t.seth(0)
    t.begin_fill()
    for _ in range(4):
        t.forward(s)
        t.left(90)
    t.end_fill()

    if n > 1:
        stacksquares(x-s/2,y-s/2,s/2,n-1)
        stacksquares(x-s/2,y+s/2,s/2,n-1)
        stacksquares(x+s/2,y-s/2,s/2,n-1)
        #stacksquares(x+s/2,y+s/2,s/2,n-1)
    else:
        stacksquares(x-s/2,y-s/2,s/2,n-1)
        stacksquares(x+s/2,y+s/2,s/2,n-1)
        stacksquares(x-s/2,y+s/2,s/2,n-1)
        stacksquares(x+s/2,y-s/2,s/2,n-1)

t.up()
t.goto(-100, -100)
t.begin_fill()
t.fillcolor('black')
for i in range(4):
    t.forward(200)
    t.left(90)
t.end_fill()
t.fillcolor('white')
stacksquares(0,0,100,3)

t.mainloop()