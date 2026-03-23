import math

def g(x):
    return 1 + math.sin(x)

def fixed_point(x0, error):
    x1 = g(x0)
    while abs(x1 - x0) >= error:
        x0 = x1
        x1 = g(x0)
    print("The root is: ",x1)

x0 = 0.5
error = 0.0001
fixed_point(x0, error)