#include<stdio.h>
#include<math.h>

double g(double x) {
    return 1 + sin(x);
}

void fixed_point(double x0, double error) {
    double x1 = g(x0);
    while(fabs(x1 - x0) >= error) {
        x0 = x1;
        x1 = g(x0);
    }
    printf("The root is: %lf", x1);
}

int main() {
    double x0 = 0.5, error = 0.0001;
    fixed_point(x0, error);
    return 0;
}