#include <stdio.h>
#include <stdbool.h>

bool ehCelulaValida(int i, int j, int N, int M) {
    return i >= 0 && j >= 0 && i < N && j < M;
}

bool buscarSequenciaMagnifica(int matriz[100][100], int i, int j, int tamAtual, int tamAlvo, bool visitado[100][100], int N, int M) {
    if (tamAtual == tamAlvo) {
        return true;
    }

    visitado[i][j] = true;

    int direcoes[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int numDirecoes = 4;

    for (int k = 0; k < numDirecoes; k++) {
        int di = direcoes[k][0];
        int dj = direcoes[k][1];
        int ni = i + di;
        int nj = j + dj;

        if (ehCelulaValida(ni, nj, N, M) && !visitado[ni][nj] && matriz[ni][nj] == tamAtual + 1) {
            if (buscarSequenciaMagnifica(matriz, ni, nj, tamAtual + 1, tamAlvo, visitado, N, M)) {
                return true;
            }
        }
    }

    visitado[i][j] = false;
    return false;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int matriz[100][100];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    bool visitado[100][100] = {false};
    int tamMin = 2;
    int tamMax = N * M;
    int tamSeqMagnifica = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matriz[i][j] == 1) {
                if (buscarSequenciaMagnifica(matriz, i, j, 1, tamMax, visitado, N, M)) {
                    tamSeqMagnifica = tamMax;
                    break;
                }
            }
        }
    }

    printf("%d\n", tamSeqMagnifica);

    return 0;
}
