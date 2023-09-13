#include <stdio.h>

void preencherMatrizRecursiva(int matriz[][19], int N, int nivel, int valor, int i, int j) {
    if (nivel >= (N + 1) / 2) {
        return;
    }

    matriz[N/2][N/2] = 1;

    if (i < N - nivel - 1) {
        matriz[i][nivel] = valor; 
        matriz[i][N - nivel - 1] = valor;
        matriz[N - nivel - 1][i] = valor;
        matriz[N - nivel - 1][N - nivel - 1] = valor;

        preencherMatrizRecursiva(matriz, N, nivel, valor, i + 1, j);
    } else if (j < N - nivel - 1) {
        matriz[nivel][j] = valor;
        matriz[N - nivel - 1][j] = valor;

        preencherMatrizRecursiva(matriz, N, nivel, valor, i, j + 1);
    } else {
        preencherMatrizRecursiva(matriz, N, nivel + 1, valor - 1, nivel + 1, nivel + 1);
    }
}

void preencherMatriz(int matriz[][19], int N) {
    preencherMatrizRecursiva(matriz, N, 0, (N + 1) / 2, 0, 0);
}

void imprimirMatriz(int matriz[][19], int N) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    printf("Digite o valor de N: ");
    scanf("%d", &N);

    int matriz[19][19] = {0};

    preencherMatriz(matriz, N);

    imprimirMatriz(matriz, N);

    return 0;
}