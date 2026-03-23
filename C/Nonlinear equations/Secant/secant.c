#include<stdio.h>
#include<math.h>

double f(double x) {
    return x*x - 3*x + 2;
}

void secant(double x0, double x1, double error) {
    double x2;
    while(fabs(x1 - x0) >= error) {
        x2 = x1 - (f(x1)*(x1 - x0))/(f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
    }
    printf("The root is: %lf", x2);
}

int main() {
    double x0 = 0, x1 = 1.5, error = 0.0001;
    secant(x0, x1, error);
    return 0;
}