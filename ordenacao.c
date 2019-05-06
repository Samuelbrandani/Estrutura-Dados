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
	
	int i, v[8] = {25,48,37,12,57,86,33,92}; 
	bolha(8, v);
	printf("vetor ordenado\n");
	for(i=0;i<8;i++){
		printf("%d ", v[i]);
	}
	
	return 0;
}
