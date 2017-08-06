#include <iostream>
#include <new> 
#include <math.h>  
#include <iomanip>
#include <cmath>
#include <cstdlib>
       //RELATIVE_ERROR
	   //ABSOLUTE_ERROR
		//DISTANCE_TO_ROOT
using namespace std;

void bisection(float start_root,float end_root,float epsilon,
 string mystr);
float function(float x);

int main(int argc, char** argv) {
	
	float start_root=atoi(argv[1]);
	float end_root= atoi(argv[2]);
	string mystr =argv[3];
	float epsilon=atoi(argv[4]); 	
	
	
	bisection(start_root,end_root,epsilon,mystr);
	
	
	
	return 0;
}
 //maximum iteration size is 100 #
 
 
 void bisection(float start_root,float end_root,float epsilon,
 string mystr){
 	int count=0;
 	// c=a+b/2; loop, epsilon sentinel.
 	float p=(start_root+end_root)/2;
 	float pre; //old p to pn-1 Equations
 	float abserror;
 	float relative;
 	int i=1;
 		if(function(start_root)*function(end_root)>0){
	 		cout << "nice formatted error";
	 		exit(-1);
	 	}
 		if(i==1){
 			if(function(start_root)*function(p)<0){
 				
 				 relative=abs((start_root-p)/p);
 				 pre=p;
 				 end_root=p;
 				 i++;
 				cout << std::fixed << std::setprecision(5) << "Iteration Number: 1"<<" abs error"<<abserror
	  	<<" and the relative error is "<< relative<<endl;
			 }
 			
 			else if(function(end_root)*function(p)<0){	
 				abserror=abs (end_root-p);
 				relative=abs(p-end_root)/abs(p);
 				pre=p;
 				cout << "pre is" << abserror <<endl;
 				start_root=p;
 				i++;
 				cout << "Iteration Number: 1"<<" abs error"<<abserror
	  	<<" and the relative error is "<< relative<<endl;
			 }
 	
 	for( i=2;i<100;i++){
 		p=(start_root+end_root)/2.0;
 	
	if(abs(function(p))<epsilon && mystr=="DISTANCE_TO_ROOT"){
		cout << "DISTANCE error .here is root"<<p<<endl;
		//mystr="DISTANCE_TO_ERROR";
		count++;
		break;
	}
	else if(abs(p-pre)<epsilon && mystr=="ABSOLUTE_ERROR"){
		cout << "ABSOLUTE error .here is root"<<p<<endl;
		//mystr="ABSOLUTE_ERROR";
		count++;
		break; 
	}
	else if( abs(( p-pre)/p)<epsilon && mystr=="RELATIVE_ERROR"){
	
		cout << "RELATIVE error .here is root"<<p<<endl;
		//mystr="RELATIVE_ERROR";
		count++;
		break; //or exit 1 , or iteraasyon 101 yap,quit yap	
	}
	else if(i>1)
	 { 
	 	relative=abs(( p-pre)/p);
	 	abserror=abs(p-pre);
	  	cout << "Iteration Number:"<<i<<" abs error"<<abserror
	  	<<" and the relative error is "<< relative<<endl;
		if(function(p)<0 && function(start_root)<0)
		{
			pre=p;
			start_root=p;
			
			
		}
		else if(function(p)>0 && function(end_root)>0)
		{
			pre=p;
			end_root=p;	
		}
				
	 }
	 
	 }
	 if(count==0){
	 	cout << "we are in error , n Iterative is over 100 #" << endl;
	 }

 	
 }
}
 
 float function(float x){
 	
 	
 	return((x*x*x)+(4*x*x)-10); // Function to test please .x 
 }
