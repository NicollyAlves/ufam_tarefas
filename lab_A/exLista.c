#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* prox;
} No;

void inserir_no_inicio(No** lista, int valor) {
    No* novo = malloc(sizeof(No));
    if(novo){
        novo->valor = valor;
        novo->prox = *lista;
        *lista = novo;
    }
}

void inserir_no_fim(No** lista, int valor) {
    No *aux, *novo = malloc(sizeof(No));

    if(novo) {
        novo->valor = valor;
        novo->prox = NULL;

        if(*lista == NULL){
            *lista = novo;
        } else {
            aux = *lista;
            while(aux->prox){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    } else {
        printf("erro\n");
    }
}

void inserir_no_meio(No** lista, int valor, int ant){
    No *novo, *aux = malloc(sizeof(No));
    if(novo){
        novo->valor = valor;

        if(*lista == NULL){
            novo->prox = NULL; 
            *lista = novo;
        } else {
            aux = *lista;

            while(aux->valor != ant && aux->prox){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    } else {
        printf("erro\n");
    }
}

void inserir_ordenado(No **lista, int valor){
    No* novo = malloc(sizeof(No));

    if(novo){
        novo->valor = valor;

        if(*lista == NULL){
            novo->prox = NULL;
            *lista = novo;
        } else if(novo->valor < (*lista)->valor){
            novo->prox = *lista;
            *lista = novo;
        } else {
            aux = *lista;
            while(aux->prox && novo->valor > aux->prox->valor){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
}

void imprimir(No* no){
    printf("Lista: ");

    while(no){
        printf("%d", no->valor);
        no = no->prox;
    }
    printf("\n");
}


int main(void) {
    int opcao, valor, anterior;
    
    No* lista = NULL;
    do{
        printf("0 - sair\n");
        printf("1 - inserirI\n");
        printf("2 - inserirF\n");
        printf("3 - inserirM\n");
        printf("4 - imprimir\n");
        printf("5 - imprimirOrdenado\n");

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
            break;
        case 5:
            inserir_ordenado(&lista, valor);
        default:
            break;
        }

    }while(opcao != 0);
    return 0;
}