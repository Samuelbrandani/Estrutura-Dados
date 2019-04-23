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


//função que busca e retorna se o valor está na arvore 
// TRABALHANDO AQUI 23/04 18:50 - UNIVAS - LAB2
int buscaValor(Arv* r, char valor){
	int retorno = 0;
	if(r->esq == NULL && r->dir == NULL){
		return retorno;
	}else{
		if(valor == r->info){
			retorno = 1;
			return retorno;
		}else if(valor < r->info){
			return busca(r->esq, valor);
		}else if(valor > r->info){
			return busca(r->dir, valor);
		}
	}

}



//função que busca e retorna o valor desejado
Arv* buscaRetorno(Arv* r, char valor){
	if(r->esq == NULL && r->dir == NULL){
		return NULL;
	}else{
		if(valor == r->info){
			return r->info;
		}else if(valor < r->info){
			return busca(r->esq, valor);
		}else if(valor > r->info){
			return busca(r->dir, valor);
		}
		
	}
}

int main() {
	
	Arv* a1 = cria('d', inicializa(), inicializa());
	
	Arv* a2 = cria('b', inicializa(), a1);
	
	Arv* a3 = cria('e', inicializa(), inicializa());
	
	Arv* a4 = cria('f', inicializa(), inicializa());
	
	Arv* a5 = cria('c', a3, a4);
	
	Arv* a = cria('a', a2, a5);
//	imprime(a);
	puts(buscaRetorno(a, 'a'));
	return 0;
}
