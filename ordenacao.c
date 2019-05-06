#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void bolha(int n, int*v){
	int i,j;
	for(i=n-1;i>= 1; i--){
		for(j=0;j<i;j++){
			if(v[j]>v[j+1]){
				int temp = v[j];
				v[j]= v[j+1];
				v[j+1] = temp;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	
	int i v[8] = []; 
	
	
	return 0;
}
