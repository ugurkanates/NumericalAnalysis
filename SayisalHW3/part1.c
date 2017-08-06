#include <stdio.h>
#include <stdlib.h>
#define SIZE 2
void fonksiyon();

int main(){

	fonksiyon();

	return 0;
}

void fonksiyon(){
	int i,j;
	int k,l;
	double x[SIZE][SIZE]={{1,2},{3,4}};
	double y[SIZE*2][SIZE*2];
	int a=0;
	int b=0;
	int btemp=0;
	int atemp=0;

   for(i=0;i<SIZE;i++){
        atemp=a;
        for(j=0;j<SIZE;j++){
            btemp=b;

            for(a=atemp,k=0;k<SIZE;a++,k++){
                for(b=btemp,l=0;l<SIZE;b++,l++){
                    y[a][b]=x[i][j];
                }

            }
            btemp++;

        }
        atemp++;

    }
	for(i=0;i<SIZE*2;i++){	
		for(j=0;j<SIZE*2;j++){
			printf("%.2f ",y[i][j]);
		}
	
	printf("\n");
	}
}