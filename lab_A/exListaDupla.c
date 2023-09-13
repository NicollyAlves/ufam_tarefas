#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* prox;
}No;

typedef struct{
    No* inicio;
    int tam;
} Lista;

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_no_inicio(Lista *lista, int valor){
    No* novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
}

void inserir_no_fim(Lista *lista, int valor){
    No *novo, *aux = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;
        novo->prox = NULL;

        if(lista->inicio == NULL){
            lista->inicio = novo;
        } else {
            aux = lista->inicio;

            while(aux->prox){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
        lista->tam++;
    }
}

void inserir_no_meio(Lista *lista, int valor, int ant){
    No *novo, *aux = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;

        if(lista->inicio == NULL){
            novo->prox = NULL;
            lista->inicio = novo;
        } else {
            aux = lista->inicio;

            while(aux->valor != ant && aux->prox){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
        lista->tam++;
    }
}

void inserir_ordenado(Lista* lista, int valor){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;

        if(lista->inicio == NULL){
            novo->prox = NULL;
            lista->inicio = novo;
        } else if(novo->valor < lista->inicio->valor){
            novo->prox = lista->inicio;
            lista->inicio = novo;
        } else {
            aux = lista->inicio;
            while(aux->prox && novo->valor > aux->prox->valor){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
        lista->tam++;
    }
}

void imprimir(Lista lista){
    No *no = lista.inicio;
    printf("Lista tamanho: %d", lista.tam); 

    while(no){
        printf("%d ", no->valor);
        no = no->prox;
    }
}

int main(void) {
    int opcao, valor, anterior;
    
    Lista lista;
    criar_lista(&lista);

    do{
        printf("0 - sair\n");
        printf("1 - inserirI\n");
        printf("2 - inserirF\n");
        printf("3 - inserirM\n");
        printf("4 - imprimir\n");

        scanf("%d", &opcao);

        switch (opcao) {
        case 0:
            break;
        case 1:
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);
            break;
        case 3:
            scanf("%d %d", &valor, &anterior);
            inserir_no_meio(&lista, valor, anterior);
            break;
        case 4:
            imprimir(lista);
        default:
            break;
        }

    }while(opcao != 0);
    return 0;
}