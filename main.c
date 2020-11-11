
#include "myMath.h"


#include <stdio.h>


int main()
{
printf("please enter a number: \n");
double num;
scanf("%lf",&num);
double f=Exponent(num);
f=add(f,Power(num,3));
f=sub(f,2);
printf("The value of f(𝑥) = 𝑒^𝑥 + 𝑥^3 − 2 at the point %lf is: %0.4lf \n",num,f);
double g;
g=mul(num,3);
double gX=mul(Power(num,2),2);
g=add(g,gX);
printf("The value of f(x)=3x+2(x^2) at the point of %lf is : %0.4lf \n",num,g);
double h=mul(Power(num,3),4);
h=div(h,5);
h=sub(h,mul(2,num));
printf("The value of f(x)=(4x^3/5)-2x at the point of %lf is : %0.4lf \n",num,h);
}
