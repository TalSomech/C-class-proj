#include "myMath.h"
#include <stdio.h>
#define exp 2.71828182846


double Power(double x , int y) 
{
int i;
double base=1;
int it=y>0?y:y*(-1);
for(i=0;i<it;i++)
{
if(y>0){
base=base*x;
}
else{
base=base/x;
}
}
return base;
}


double Exponent(int x) 
{
double pE=Power(exp,x);
 return pE;
}
