#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	struct No* prox;
	void* item;
	unsigned char tipo;
} No;

typedef struct {
	No* prim;
} Lista;

typedef struct {
	int numerador, denominador;
} Fracao;

typedef struct {
	float x, y;
} Ponto;

// Retorna uma lista
Lista* criarLista();
// Insere no inicio da lista
void inserir(Lista* l, void* item, unsigned char tipo);
// Remove o primeiro elemento da lista
void remover(Lista* l);
// Apaga uma lista encadeada
void apagarLista(Lista* l);
// Retorna o endereço do primeiro elemento da lista
void* getInicio(Lista* l);
// Retorna o tipo do primeiro elemento da lista
unsigned char getTipoInicio(Lista* l);

// Faz a leitura de uma fracao
void lerFracao(Fracao* f);
// Imprime uma fracao
void imprimirFracao(Fracao* f);
// Cria uma instancia de uma fracao
void* criarInstanciaFracao(Fracao* f);
// Faz a leitura de um ponto
void lerPonto(Ponto* p);
// Imprime um ponto
void imprimirPonto(Ponto* p);
// Cria uma instancia de um ponto
void* criarInstanciaPonto(Ponto* p);

Lista* criarLista() {
	Lista* l = (Lista*)malloc(sizeof(Lista));
	l->prim = NULL;
	return l;
}

void inserir(Lista* l, void* item, unsigned char tipo) {
	No* novoNo = (No*)malloc(sizeof(No));
	novoNo->prox = l->prim;
	novoNo->item = item;
	novoNo->tipo = tipo;
	l->prim = novoNo;
}

void remover(Lista* l) {
	if (l->prim == NULL) {
		return;
	}

	No* noRemovido = l->prim;
	l->prim = noRemovido->prox;

	free(noRemovido);
}

void apagarLista(Lista* l) {
	while (l->prim != NULL) {
		remover(l);
	}

	free(l);
}

void* getInicio(Lista* l) {
	if (l->prim != NULL) {
		return l->prim->item;
	}

	return NULL;
}

unsigned char getTipoInicio(Lista* l) {
	if (l->prim != NULL) {
		return l->prim->tipo;
	}

	return 0;
}

void lerFracao(Fracao* f) {
	scanf("%d %d", &f->numerador, &f->denominador);
}

void imprimirFracao(Fracao* f) {
	printf("%d/%d\n", f->numerador, f->denominador);
}

void* criarInstanciaFracao(Fracao* f) {
	Fracao* novaFracao = (Fracao*)malloc(sizeof(Fracao));
	novaFracao->numerador = f->numerador;
	novaFracao->denominador = f->denominador;

	return novaFracao;
}

void lerPonto(Ponto* p) {
	scanf("(%f, %f)", &p->x, &p->y);
}

void imprimirPonto(Ponto* p) {
	printf("(%0.2f, %0.2f)\n", p->x, p->y);
}

void* criarInstanciaPonto(Ponto* p) {
	Ponto* novoPonto = (Ponto*)malloc(sizeof(Ponto));
	novoPonto->x = p->x;
	novoPonto->y = p->y;

	return novoPonto;
}

int main() {
	Lista* lista = criarLista();
	int opcao;
	unsigned char tipo;

	do {
		scanf("%d", &opcao);

		switch (opcao) {
			case 0:
				apagarLista(lista);
				return 0;
			case 1: {
				Fracao* f = (Fracao*)malloc(sizeof(Fracao));
				lerFracao(f);
				tipo = 1;
				void* instancia = criarInstanciaFracao(f);
				inserir(lista, instancia, tipo);
				break;
			}
			case 2: {
				Ponto* p = (Ponto*)malloc(sizeof(Ponto));
				lerPonto(p);
				tipo = 2;
				void* instancia = criarInstanciaPonto(p);
				inserir(lista, instancia, tipo);
				break;
			}
			case 3: {
				if (getTipoInicio(lista) == 1) {
					Fracao* f = (Fracao*)getInicio(lista);
					imprimirFracao(f);
				} else if (getTipoInicio(lista) == 2) {
					Ponto* p = (Ponto*)getInicio(lista);
					imprimirPonto(p);
				}
				break;
			}
			case 4:
				remover(lista);
				break;
			default:
				break;
		}
	} while (opcao != 0);

	return 0;
}
