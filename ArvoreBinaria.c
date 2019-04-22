#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct arv {
	char info;
	struct arv* esq;
	struct arv* dir;
} Arv;

Arv* inicializa(void){
	return NULL;
}

Arv* cria(char c, Arv* sae, Arv* sad){
	Arv* p = (Arv*)malloc(sizeof(Arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}
int vazia(Arv* a){
 	return a == NULL;
}

void imprime(Arv* a){
	if(!vazia(a)){
		printf("%c ", a->info);
		imprime(a->esq);
		imprime(a->dir);
	}
}


int main() {
	
	Arv* a1 = cria('d', inicializa(), inicializa());
	
	Arv* a2 = cria('b', inicializa(), a1);
	
	Arv* a3 = cria('e', inicializa(), inicializa());
	
	Arv* a4 = cria('f', inicializa(), inicializa());
	
	Arv* a5 = cria('c', a3, a4);
	
	Arv* a = cria('a', a2, a5);
	imprime(a);
	
	return 0;
}
