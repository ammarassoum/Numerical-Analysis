import math

def f(x):
    return x*x*x - x*x + 2

def bisection(a, b, error):
    if f(a) * f(b) >= 0:
        print("Invalid input! f(a) and f(b) must have opposite signs.")
        return
    
    c = a
    while (b-a) >= error:
        c = (a+b)/2
        if f(c) == 0.0:
            break
        elif f(c)*f(a) < 0:
            b = c
        else:
            a = c
    
    print("The root is: ",c)

a = -200
b = 300
error = 0.0001
bisection(a, b, error)