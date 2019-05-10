#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 8
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void bolha_gen(int n, void* v, int tam, int (*cmp)(void*,void*));
int compara_int(void*, void* b);
int compara_inteiro(const void*, const void*);
int (*cmp) (void*, void*);
int compara_reais(void*a, void*b);
void* acessa(void* v, int i, int tam);
void* troca(void*a, void*b, int tam);

int main(int argc, char *argv[]) {
	
	int i, v[8] = {31,212,62,34,45,16,73,8231}; 
	bolha_gen(N,v, sizeof(int), compara_int);
	printf("vetor ordenado\n");
	for(i=0;i<8;i++){
		printf("%d ", v[i]);
	}
	system("pause");
	return 0;
}

void bolha_gen(int n, void*v, int tam, int (*cmp) (void*, void*)){
	int i,j;
	for(i=n-1;i>0;i--){
		int fez_troca = 0;
		for(j=0;j<i; i++){
			void* p1 = acessa(v, j, tam);
			void* p2 = acessa(v, j+1, tam);
			if(cmp(p1,p2)){
				troca(p1,p2,tam);
				fez_troca = 1;
			}
		}
		if(fez_troca == 0) return;
	}
}

int compara_int(void* a, void* b){
	int* p1 = (int*) a;
	int* p2 = (int*) b;
	int f1 = *p1;
	int f2 = *p2;
	if(f1 > f2) return 1;
	else return 0;
}

void* acessa(void* v, int i, int tam){
	char* t = (char*) v;
	t += tam* i;
	return (void*) t;
}

void* troca(void* a, void* b, int tam){
	char* v1 = (char*)a;
	char* v2 = (char*)b;
	int i;
	for(i=0;i<tam;i++){
		char temp = v1[i];
		v1[i] = v2[i];
		v2[i] = temp;
	}
}

int compara_reais(void* a, void* b){
	float* p1 = (float*) a;
	float* p2 = (float*) b;
	float f1 = *p1;
	float f2 = *p2;
	if(f1 > f2) return 1;
	else return 0;
}
