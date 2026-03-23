#include<stdio.h>
#include<math.h>

double f(double x) {
    return x*x*x - x*x + 2;
}

void regula_falsi(double a, double b, double error) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid input! f(a) and f(b) must have opposite signs.");
        return;
    }

    double c = a;
    while (fabs(b-a) >= error) {
        c = (a*f(b) - b*f(a))/(f(b) - f(a));
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
    double a = -1.5, b = 0, error = 0.0001;
    regula_falsi(a, b, error);
    return 0;
}