#include <stdio.h>
#include <stdlib.h>

int matriz(int m, int n){
    int u, v;
    int** mat = malloc(m * sizeof(int*));

    for(int i = 0; i < m; i++){
        mat[i] = malloc(n * sizeof(int));
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = j + 1;
        }
    }

    for(int i = 1; i < m; i++){
        int inicio, fim;
        scanf("%d %d", &inicio, &fim);

        for(int j = 0; j < n; j++){
            mat[i][j] = mat[i - 1][j];
        }

        int dif = abs(inicio - fim);
        if(fim < inicio){
            for(u = fim - 1, v = inicio - 1; u < v; u++, v--){
                int temp = mat[i][u];
                mat[i][u] = mat[i][v];
                mat[i][v] = temp;
            }
        } else {
            for(u = inicio - 1, v = fim - 1; u < v; u++, v--){
                int temp = mat[i][u];
                mat[i][u] = mat[i][v];
                mat[i][v] = temp;
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    int* somaCol = malloc(n * sizeof(int));
    for(int j = 0; j < n; j++){
        somaCol[j] = 0;
        for(int i = 0; i < m; i++){
            somaCol[j] += mat[i][j];
        }
    }

    int menorSoma = somaCol[0];
    int maiorSoma = somaCol[0];
    for(int i = 1; i < n; i++){
        if(menorSoma < somaCol[i]){
            menorSoma = somaCol[i];
        }
        if(maiorSoma > somaCol[i]){
            maiorSoma = somaCol[i];
        }
    }

    printf("%d %d", maiorSoma, menorSoma);
}

int main(void){
    int m, n;

    scanf("%d %d", &m, &n);

    matriz(m, n);
}

/* 
1 2 3 4 5 6
1 4 3 2 5 6
1 2 3 4 5 6
1 2 6 5 4 3 
*/