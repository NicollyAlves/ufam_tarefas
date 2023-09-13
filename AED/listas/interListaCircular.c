#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int numerador;
    int denominador;
} Fracao;

typedef struct FracaoNo{
    struct FracaoNo *proximo;
    struct FracaoNo *anterior;
    Fracao *fracao;
} FracaoNo;

typedef struct{
    FracaoNo *atual;
} Conjunto;

Conjunto* criarConjunto(){
    Conjunto *conjunto = (Conjunto*)malloc(sizeof(Conjunto));
    conjunto->atual = NULL;
    return conjunto;
}

void apagarConjunto(Conjunto *A){
    FracaoNo *atual = A->atual;
    if(atual == NULL){
        free(A);
        return;
    }

    FracaoNo *prox = atual->proximo;
    while(prox != A->atual){
        free(atual->fracao);
        free(atual);
        atual = prox;
        prox = prox->proximo;
    }

    free(atual->fracao);
    free(atual);
    free(A);
}

void inserirElemento(Conjunto *A, Fracao *fracao){
    FracaoNo *novoNo = (FracaoNo*)malloc(sizeof(FracaoNo));
    novoNo->fracao = fracao;

    if(A->atual == NULL){
        novoNo->proximo = novoNo;
        novoNo->anterior = novoNo;
        A->atual = novoNo;
    } else {
        FracaoNo *prox = A->atual->proximo;
        A->atual->proximo = novoNo;
        novoNo->anterior = A->atual;
        novoNo->proximo = prox;
        prox->anterior = novoNo;
        A->atual = novoNo;
    }
}

Conjunto* Intersecao(Conjunto* A, Conjunto *B){
    Conjunto *intersecao = criarConjunto();

    if(A->atual == NULL || B->atual == NULL)
        return intersecao;

    FracaoNo *noA = A->atual->proximo;
    while(noA != A->atual){
        FracaoNo *noB = B->atual->proximo;
        int encontrou = 0;
        while(noB != B->atual){
            if (noA->fracao->numerador == noB->fracao->numerador && noA->fracao->denominador == noB->fracao->denominador){
                encontrou = 1;
                break;
            }
            noB = noB->proximo;
        }
        if(encontrou){
            Fracao *fracaoIntersecao = (Fracao*)malloc(sizeof(Fracao));
            fracaoIntersecao->numerador = noA->fracao->numerador;
            fracaoIntersecao->denominador = noA->fracao->denominador;
            inserirElemento(intersecao, fracaoIntersecao);
        }
        noA = noA->proximo;
    }

    return intersecao;
}

void imprimirConjunto(Conjunto *A){
    if (A->atual == NULL){
        printf("\n");
        return;
    }

    FracaoNo *atual = A->atual->proximo;
    do{
        printf("%d/%d ", atual->fracao->numerador, atual->fracao->denominador);
        atual = atual->proximo;
    } while (atual != A->atual);
    printf("\n");
}

int main(){
    Conjunto *A = criarConjunto();
    Conjunto *B = criarConjunto();
    Fracao *fracao;

    char linhaA[100];
    fgets(linhaA, sizeof(linhaA), stdin);

    char *tokenA = strtok(linhaA, " ");
    while (tokenA != NULL){
        if (tokenA[0] == '#'){
            break;
        }
        if (tokenA[strlen(tokenA) - 1] == '\n'){
            tokenA[strlen(tokenA) - 1] = '\0';
        }
        fracao = (Fracao*)malloc(sizeof(Fracao));
        if (sscanf(tokenA, "%d/%d", &fracao->numerador, &fracao->denominador) != 2){
            free(fracao);
            break;
        }
        inserirElemento(A, fracao);
        tokenA = strtok(NULL, " ");
    }

    char linhaB[100];
    fgets(linhaB, sizeof(linhaB), stdin);

    char *tokenB = strtok(linhaB, " ");
    while (tokenB != NULL) {
        if (tokenB[0] == '#') {
            break;
        }
        if (tokenB[strlen(tokenB) - 1] == '\n'){
            tokenB[strlen(tokenB) - 1] = '\0';
        }
        fracao = (Fracao*)malloc(sizeof(Fracao));
        if (sscanf(tokenB, "%d/%d", &fracao->numerador, &fracao->denominador) != 2) {
            free(fracao);
            break;
        }
        inserirElemento(B, fracao);
        tokenB = strtok(NULL, " ");
    }

    printf("A:   ");
    imprimirConjunto(A);

    printf("B:   ");
    imprimirConjunto(B);

    Conjunto *intersecao = Intersecao(A, B);
    printf("AeB: ");
    imprimirConjunto(intersecao);

    apagarConjunto(A);
    apagarConjunto(B);
    apagarConjunto(intersecao);

    return 0;
}
