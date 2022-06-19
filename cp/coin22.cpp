/*  ZDV   */
#include "mlisp.h"
double largest/*1*/ (double coins__set);
	 double count__change/*13*/ (double amount);
	 bool Shaeffer_Q/*31*/ (double x_Q, double y_Q);
	 double cc/*36*/ (double amount, double coins__set);
	 double denomination__list/*44*/ (double coins__set);
	 extern double VARIANT/*54*/;
	extern double COINS/*55*/;
	//________________ 
double largest/*1*/ (double coins__set){
 return
 ((coins__set == 1.) 
	? 1. 
	 :(coins__set == 2.) 
	? 2. 
	 :(coins__set == 3.) 
	? 3. 
	 :(coins__set == 4.) 
	? 5. 
	 :(coins__set == 5.) 
	? 10. 
	 :(coins__set == 6.) 
	? 50. 
	 :0.);
	 }
double count__change/*13*/ (double amount){
 display("______\n amount: ");
	 display(amount);
	 newline();
	 display("COINS: ");
	 display(COINS);
	 newline();
	 return
 (((amount <= 0.) || !((!((COINS <= 1.)) || !(!((COINS == 1.))))) || (largest(COINS) == 0.)) 
	? (display("Improper parameter value!\ncount-change= "),
	 -1.) 
	 :(display("List of coin denominations: "),
	 denomination__list(COINS),
	 display("count-change= "),
	 cc(amount, COINS)));
	 }
bool Shaeffer_Q/*31*/ (double x_Q, double y_Q){
 return (!(x_Q) || !(y_Q));
	 }
double cc/*36*/ (double amount, double coins__set){
 return
 ((amount == 0.) 
	? 1. 
	 :Shaeffer_Q((1. <= amount), !((coins__set <= 0.))) 
	? 0. 
	 :(cc(amount, (coins__set - 1.)) + cc((amount - largest(coins__set)), coins__set)));
	 }
double denomination__list/*44*/ (double coins__set){
 return
 ((coins__set == 0.) 
	? (newline(),
	 0.) 
	 :(display(largest(coins__set)),
	 display(" "),
	 denomination__list((coins__set - 1.)),
	 -1.));
	 }
double VARIANT/*54*/ = 7.;
	double COINS/*55*/ = 6.;
	int main(){
 display("Variant ");
	 display(VARIANT);
	 newline();
	 display(count__change(100.));
	 newline();
	 COINS = 13.;
	 display(count__change(100.));
	 newline();
	 display("(c) Dmitriy Zubko 2022\n");
	 std::cin.get();
	 return 0;
	 }
 
