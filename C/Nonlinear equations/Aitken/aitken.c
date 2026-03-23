#include<stdio.h>
#include<math.h>

double f(double x) {
    return 1 + sin(x);
}

void aitken(double x0, double error) {
    double x1 = f(x0);
    double x2 = f(x1);
    double xe;
    while(fabs(x2 - x1) >= error) {
        xe = x0 - ((x1 - x0)*(x1 - x0))/(x2 - 2*x1 + x0);
        x0 = xe;
        x1 = f(x0);
        x2 = f(x1);
    }
    printf("The root is: %lf", xe);
}

int main() {
    double x0 = 0.5, error = 0.0001;
    aitken(x0, error);
    return 0;
}