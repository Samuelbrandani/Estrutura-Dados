#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct arv {
	char info;
	struct arv* esq;
	struct arv* dir;
} Arv;

//inicializa uma arvore
Arv* inicializa(void){
	return NULL;
}

//função que cria uma arvore colocando os seus filhos
Arv* cria(char c, Arv* sae, Arv* sad){
	Arv* p = (Arv*)malloc(sizeof(Arv));
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

//função que verifica se a arvore está vazia
int vazia(Arv* a){
 	return a == NULL;
}

//função para imprimir a arvore
void imprime(Arv* a){
	if(!vazia(a)){
		printf("%c ", a->info);
		imprime(a->esq);
		imprime(a->dir);
	}
}

//função que busca e retorna se o valor está na arvore
int busca(Arv *p, char x) {
 if (p==NULL)
	return 0;
 else if (x==p->info)
	return 1;
 else if (x<p->info)
	return (busca(p->esq,x));
 else 
	return (busca(p->dir,x));
} 


//função que busca e retorna o valor desejado
Arv* valorBusca(Arv* r, char k){
    if (r == NULL || r->info == k)
       return r->info;
    if (r->info > k)
       return busca(r->esq, k);
    else
       return busca(r->dir, k);
}

int main() {
	
	Arv* a1 = cria('d', inicializa(), inicializa());
	Arv* a2 = cria('b', inicializa(), a1);
	Arv* a3 = cria('e', inicializa(), inicializa());
	Arv* a4 = cria('f', inicializa(), inicializa());
	Arv* a5 = cria('c', a3, a4);
	Arv* a = cria('a', a2, a5);
//	imprime(a);
	puts("Digite o valor para buscar");
	printf("the returns of the function 'valorBusca' is:  %c\n",valorBusca(a, 'a'));
	printf("the returns of the function 'busca' is:  %d\n", busca(a, 'v'));
	return 0;
}
