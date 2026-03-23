#include<stdio.h>
#include<math.h>

double f(double x) {
    return x*x*x - x*x + 2;
}

void bisection(double a, double b, double error) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid input! f(a) and f(b) must have opposite signs.");
        return;
    }

    double c = a;
    while ((b-a) >= error) {
        c = (a+b)/2;
        if (f(c) == 0.0) {
            break;
        }
        else if (f(c)*f(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }
    printf("The root is: %lf", c);
}

int main() {
    double a = -200, b = 300, error = 0.0001;
    bisection(a, b, error);
    return 0;
}