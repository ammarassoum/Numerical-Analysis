import math

def f(x):
    return 1 + math.sin(x)

def aitken(x0, error):
    x1 = f(x0)
    x2 = f(x1)
    while abs(x2 - x1) >= error:
        xe = x0 - ((x1 - x0)*(x1 - x0))/(x2 - 2*x1 + x0)
        x0 = xe
        x1 = f(x0)
        x2 = f(x1)
    print("The root is: ", xe)

x0 = 0.5
error = 0.0001
aitken(x0, error)