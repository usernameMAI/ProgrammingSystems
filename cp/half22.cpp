/*  ZDV   */
#include "mlisp.h"
double root/*2*/ (double a, double b);
	 double half__interval/*14*/ (double a, double b
	 , double fa, double fb);
	 double __ZDV__try/*26*/ (double neg__point, double pos__point);
	 bool close__enough_Q/*40*/ (double x, double y);
	 double average/*42*/ (double x, double y);
	 extern double tolerance/*45*/;
	extern double total__iterations/*46*/;
	double f/*47*/ (double z);
	 //________________ 
double root/*2*/ (double a, double b){
 double temp/*3*/(0.);
	temp = half__interval(a, b, f(a), f(b));
	 display("Total number of iteranions=");
	 display(total__iterations);
	 newline();
	 display("[");
	 display(a);
	 display(" , ");
	 display(b);
	 display("]");
	 return
 temp;
	 }
double half__interval/*14*/ (double a, double b
	 , double fa, double fb){
 double root/*15*/(0.);
	total__iterations = 0.;
	 root = (!(((0. <= fa) || (fb <= 0.))) 
	? __ZDV__try(a, b) 
	 :!(((fa <= 0.) || (0. <= fb))) 
	? __ZDV__try(b, a) 
	 :(b + 1.));
	 newline();
	 return
 root;
	 }
double __ZDV__try/*26*/ (double neg__point, double pos__point){
 double midpoint/*27*/(0.);
	double test__value/*28*/(0.);
	midpoint = average(neg__point, pos__point);
	 return
 (close__enough_Q(neg__point, pos__point) 
	? midpoint 
	 :(test__value = f(midpoint),
	 display("+"),
	 total__iterations = (total__iterations + 1.),
	 (!((test__value <= 0.)) 
	? __ZDV__try(neg__point, midpoint) 
	 :!((0. <= test__value)) 
	? __ZDV__try(midpoint, pos__point) 
	 :midpoint)));
	 }
bool close__enough_Q/*40*/ (double x, double y){
 return !((tolerance <= abs((x - y))));
	 }
double average/*42*/ (double x, double y){
 return
 ((x + y) * (1. / ( 2.0e+0)));
	 }
double tolerance/*45*/ = 0.001;
	double total__iterations/*46*/ = 0.;
	double f/*47*/ (double z){
 return
 (((0.1 * expt(z, 2.)) - (z * log(z))) + 19.85);
	 }
int main(){
 display("Variant 208-n07\n");
	 display(root(19.97, 21.));
	 newline();
	 display("(c) Dmitriy Zubko 2022\n");
	 std::cin.get();
	 return 0;
	 }
 
