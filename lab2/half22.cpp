#include "mlisp.h"
double root(double a, double b);
double half__interval(double a, double b, double fa, double fb);
double __DVZ__try(double neg__point, double pos__point);
bool close__enough_Q(double x, double y);
double average(double x, double y);
double f(double z);
extern double tolerance;
extern double total__iterations;

double f(double z){
    return ((0.1 * expt(z, 2.) - z * log(z)) + 19.85);
}

double average(double x, double y){
    return (x + y) * (1. / 2.);
}

bool close__enough_Q(double x, double y) {
    return (abs(x - y) < tolerance);
}

double __DVZ__try(double neg__point, double pos__point) {
    double midpoint(0.);
    double test_value(0.);
    midpoint = average(neg__point, pos__point);
    return (close__enough_Q(neg__point, pos__point) ? midpoint :
    (test_value = f(midpoint), display("+"), total__iterations = total__iterations + 1., test_value > 0. ?
    __DVZ__try(neg__point, midpoint) : test_value < 0. ? __DVZ__try(midpoint, pos__point) : (midpoint)));
}

double half__interval(double a, double b, double fa, double fb) {
    double root(0.);
    total__iterations = 0.;
    root = ((fa < 0. && fb > 0.) ? __DVZ__try(a, b) :
            ((fa > 0. && fb < 0.) ? __DVZ__try(b, a) : (b + 1.)));
    newline();
    return root;
}

double root(double a, double b) {
    double temp(0.);
    temp = half__interval(a, b, f(a), f(b));
    display("Total number of iteranions=");
    display(total__iterations);
    newline();
    display("[");
    display(a);
    display(" , ") /
    display(b);
    display("]");
    return temp;
}

double tolerance = 0.001;
double total__iterations = 0.;

int main() {
    display("Variant 208-n07\n");
    display(root(19.97, 21.));
    newline();
    display("(c) Dmitriy Zubko 2022\n");
    newline();
    std::cin.get();
    return 0;
}
