#include <stdio.h>
#include <stdlib.h>
#include <math.h>



 double int1(double x, double xi[], double yi[], int imax)
{
	double y;
	int j;
// if x is ouside the xi[] interval
if (x <= xi[0]) 
	return y = yi[0];
if (x >= xi[imax-1]) 
	return y = yi[imax-1];
// loop to find j so that x[j-1] < x < x[j]
j = 0;
while (j <= imax-1)
{
if (xi[j] >= x) 
break;
j = j + 1;
}
y = yi[j-1]+(yi[j]-yi[j-1])*(x-xi[j-1])/(xi[j]-xi[j-1]);
return y;
}

int main(){
	double x[5]={ 1,1.3,1.6,1.9,2.2 };
	double y[5]={ 0.76,0.62,0.45,0.28,0.11 };
	double z=int1(5,x,y,10);
	printf("%f",z);
	return 0;
}


