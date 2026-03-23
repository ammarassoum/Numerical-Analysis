#include<stdio.h>
#include<math.h>

double f(double x) {
    return x*x*x - x*x + 2;
}

double fprime(double x) {
    return 3*x*x - 2*x;
}

void newton(double x0, double error) {
    double x1;
    while(1) {
        x1 = x0 - f(x0)/fprime(x0);
        if(fabs(x1 - x0) < error) {
            break;
        }
        x0 = x1;
    }
    printf("The root is: %lf", x1);
}

int main() {
    double x0 = -1.5, error = 0.0001;
    newton(x0, error);
    return 0;
}