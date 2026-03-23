import math

def f(x):
    return x*x - 3*x + 2

def secant(x0, x1, error):
    while abs(x1 - x0) >= error:
        x2 = x1 - (f(x1)*(x1 - x0))/(f(x1) - f(x0))
        x0 = x1
        x1 = x2
    print("The root is: ",x2)

x0 = 0
x1 = 1.5
error = 0.0001
secant(x0, x1, error)