import math

def f(x):
    return x*x*x - x*x + 2

def regula_falsi(a, b, error):
    if f(a) * f(b) >= 0:
        print("Invalid input! f(a) and f(b) must have opposite signs.")
        return
    
    c = a
    while abs(b-a) >= error:
        c = (a*f(b) - b*f(a))/(f(b) - f(a))
        if f(c) == 0.0:
            break
        elif f(c)*f(a) < 0:
            b = c
        else:
            a = c
    
    print("The root is: ",c)

a = -1.5
b = 0
error = 0.0001
regula_falsi(a, b, error)