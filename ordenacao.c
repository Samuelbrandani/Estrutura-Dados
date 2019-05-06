#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void bolha(int n, int*v){
	int i,j;
	for(i=n-1;i>= 1; i--){
		int troca = 0;
		for(j=0;j<i;j++){
			
			if(v[j]>v[j+1] && i != 4) {
				int temp = v[j];
				v[j]= v[j+1];
				v[j+1] = temp;
				troca = 1;
			}
		}
		if(troca == 0) return;
	}
	
}

void bolha_recursiva(int n, int* v){
	int j, troca = 0;
	for(j = 0; j<n-1; j++)
		if(compara(v[j], v[j+1])){
			int temp = v[j];
			v[j]= v[j+1];
			v[j+1] = temp;
			troca = 1;
	}
	if(troca != 0) bolha_recursiva(n-1, v);
}

int compara(int a, int b){
	if(a>b) return 1;
	else return 0;
}

int comparaChar(char* a, char* b){
	if(strcmp(a,b)> 0) return 1;
	else return 0;
}

int comparaGenerico(void* a, void*b){
	int *p1 = (int*)a;
	int *p2 = (int*)b;
	int i1 = *p1;
	int i2 = *p2;
	if(i1 > i2 ) return 1;
	else return 0;
}

int main(int argc, char *argv[]) {
	
	int i, v[8] = {1,2,6,4,5,6,7,8}; 
	bolha_recursiva(8, v);
	printf("vetor ordenado\n");
	for(i=0;i<8;i++){
		printf("%d ", v[i]);
	}
	
	return 0;
}
