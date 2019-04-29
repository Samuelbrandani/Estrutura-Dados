#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct arvGen {
	char info;
	struct arvGen* prim;
	struct arvGen* prox;
}ArvGen;

ArvGen* cria(char c){
	ArvGen* a = (ArvGen*)malloc(sizeof(ArvGen));
	a->info = c;
	a->prim = NULL;
	a->prox = NULL;
	return a;
}


void insere (ArvGen* a, ArvGen* sa){
 sa->prox = a->prim;
 a->prim = sa;
}


void imprime (ArvGen* a){
 	ArvGen* p;
 	printf("%c\n",a->info);
 	for (p=a->prim; p!=NULL; p=p->prox){
 		imprime(p);
 		system("pause");
 	}
 
}


int busca (ArvGen* a, char c){
 ArvGen* p;
 	if (a->info==c) return 1;
 	else {
 		for (p=a->prim; p!=NULL; p=p->prox) {
 			if (busca(p,c)) return 1;
 		}
	}
 return 0;
}


int main(int argc, char *argv[]) {
	/* cria nós como folhas */
	ArvGen* a = cria('a');
	ArvGen* b = cria('b');
	ArvGen* c = cria('c');
	ArvGen* d = cria('d');
	ArvGen* e = cria('e');
	ArvGen* f = cria('f');
	ArvGen* g = cria('g');
	ArvGen* h = cria('h');
	ArvGen* i = cria('i');
	ArvGen* j = cria('j');

/* monta a hierarquia */
	insere(c,d);
	insere(b,e);
	insere(b,c);
	insere(i,j);
	insere(g,i);
	insere(g,h);
	insere(a,g);
	insere(a,f);
	insere(a,b);
	imprime(a);
}
