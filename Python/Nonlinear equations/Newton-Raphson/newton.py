import math

def f(x):
    return x*x*x - x*x + 2

def fprime(x):
    return 3*x*x - 2*x

def newton(x0, error):
    while True:
        x1 = x0 - f(x0)/fprime(x0)
        if abs(x1 - x0) < error:
            break
        x0 = x1
    print("The root is: ",x1)

x0 = -1.5
error = 0.0001
newton(x0, error)