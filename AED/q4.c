#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char data[11];
char hora[9];
double latitude;
double longitude;
} Registro;

typedef struct No {
Registro registro;
struct No* prox;
struct No* ant;
} No;

typedef struct {
No* inicio;
No* fim;
int tamanho;
} ListaRegistros;

void inicializarLista(ListaRegistros* lista);
void inserirRegistro(ListaRegistros* lista, Registro registro);
void imprimirRegistros(ListaRegistros lista);
void imprimirKRegistros(ListaRegistros lista, int k);
void imprimirIntervaloRegistros(ListaRegistros lista, int m, int n);
void removerRegistros(ListaRegistros* lista, int k);
void imprimirRegistroK(ListaRegistros lista, int k);

void inicializarLista(ListaRegistros* lista) {
lista->inicio = NULL;
lista->fim = NULL;
lista->tamanho = 0;
}

void inserirRegistro(ListaRegistros* lista, Registro registro) {
No* novoNo = (No*)malloc(sizeof(No));
novoNo->registro = registro;
novoNo->prox = NULL;

if (lista->inicio == NULL) {
    novoNo->ant = NULL;
    lista->inicio = novoNo;
    lista->fim = novoNo;
} else {
    novoNo->ant = lista->fim;
    lista->fim->prox = novoNo;
    lista->fim = novoNo;
}

lista->tamanho++;
}

void imprimirRegistros(ListaRegistros lista) {
No* atual = lista.inicio;

while (atual != NULL) {
    printf("%s %s %.2lf %.2lf\n", atual->registro.data, atual->registro.hora, atual->registro.latitude, atual->registro.longitude);
    atual = atual->prox;
}
}

void imprimirKRegistros(ListaRegistros lista, int k) {
printf("L %d\n", k);

if (k >= 0) {
    No* atual = lista.inicio;
    int cont = 0;

    while (atual != NULL && cont < k) {
        printf("%s %s %.2lf %.2lf\n", atual->registro.data, atual->registro.hora, atual->registro.latitude, atual->registro.longitude);
        atual = atual->prox;
        cont++;
    }
} else {
    No* atual = lista.fim;
    int cont = -k;

    while (atual != NULL && cont > 0) {
        printf("%s %s %.2lf %.2lf\n", atual->registro.data, atual->registro.hora, atual->registro.latitude, atual->registro.longitude);
        atual = atual->ant;
        cont--;
    }
}
}

void imprimirIntervaloRegistros(ListaRegistros lista, int m, int n) {
printf("I %d %d\n", m, n);

if (m <= n) {
    No* atual = lista.inicio;
    int tamanho = lista.tamanho;

    for (int i = 1; i <= tamanho; i++) {
        if (i >= m && i <= n) {
            printf("%s %s %.2lf %.2lf\n", atual->registro.data, atual->registro.hora, atual->registro.latitude, atual->registro.longitude);
        }

        atual = atual->prox;
    }
} else {
    No* atual = lista.fim;
    int tamanho = lista.tamanho;

    for (int i = tamanho; i >= 1; i--) {
        if (i >= n && i <= m) {
            printf("%s %s %.2lf %.2lf\n", atual->registro.data, atual->registro.hora, atual->registro.latitude, atual->registro.longitude);
        }

        atual = atual->ant;
    }
}
}

void removerRegistros(ListaRegistros* lista, int k) {
    printf("R %d\n", k);

    if (k >= 0) {
        No* atual = lista->inicio;
        No* anterior = NULL;
        int cont = 0;

        while (atual != NULL && cont < k) {
            No* proximo = atual->prox;
            free(atual);
            atual = proximo;
            cont++;
        }

        if (atual == NULL) {
            lista->inicio = NULL;
            lista->fim = NULL;
        } else {
            lista->inicio = atual;
            atual->ant = NULL;
        }
    } else {
        No* atual = lista->fim;
        No* anterior = NULL;
        int cont = 0;

        while (atual != NULL && cont > k) {
            No* anterior = atual->ant;
            free(atual);
            atual = anterior;
            cont--;
        }

        if (atual == NULL) {
            lista->inicio = NULL;
            lista->fim = NULL;
        } else {
            lista->fim = atual;
            atual->prox = NULL;
        }
    }

    lista->tamanho -= abs(k);
    imprimirRegistros(*lista);
}


void imprimirRegistroK(ListaRegistros lista, int k) {
printf("K %d\n", k);

if (k >= 0) {
    No* atual = lista.inicio;
    int cont = 1;

    while (atual != NULL && cont < k) {
        atual = atual->prox;
        cont++;
    }

    if (atual != NULL) {
        printf("%s %s %.2lf %.2lf\n", atual->registro.data, atual->registro.hora, atual->registro.latitude, atual->registro.longitude);
    }
} else {
    No* atual = lista.fim;
    int cont = -k;

    while (atual != NULL && cont > 1) {
        atual = atual->ant;
        cont--;
    }

    if (atual != NULL) {
        printf("%s %s %.2lf %.2lf\n", atual->registro.data, atual->registro.hora, atual->registro.latitude, atual->registro.longitude);
    }
}
}

int main() {
ListaRegistros lista;
inicializarLista(&lista);

Registro registro;

while (scanf("%s %s %lf %lf", registro.data, registro.hora, &registro.latitude, &registro.longitude) == 4) {
    if (strcmp(registro.data, "00/00/0000") == 0) {
        break;
    }
    inserirRegistro(&lista, registro);
}

char comando;
int k, m, n;

while (scanf(" %c", &comando) == 1 && comando != 'F') {
    switch (comando) {
        case 'L':
            scanf("%d", &k);
            imprimirKRegistros(lista, k);
            break;
        case 'I':
            scanf("%d %d", &m, &n);
            imprimirIntervaloRegistros(lista, m, n);
            break;
        case 'R':
            scanf("%d", &k);
            removerRegistros(&lista, k);
            break;
        case 'K':
            scanf("%d", &k);
            imprimirRegistroK(lista, k);
            break;
    }
}

return 0;
}
