#include <stdio.h>

#define LINHAS 20
#define COLUNAS 10

void inicializar_tabuleiro(char tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = '.';
        }
    }
}

void desenhar_tabuleiro(char tabuleiro[LINHAS][COLUNAS]) {
    printf("+----------+\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("|");
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("+----------+\n");
}

void posicionar_peca(char tabuleiro[LINHAS][COLUNAS], int coluna) {
    for (int i = LINHAS - 1; i > 1; i--) {
        if (tabuleiro[i][coluna] == '.' && tabuleiro[i - 1][coluna] == '.' && tabuleiro[i - 2][coluna] == '.' && tabuleiro[i - 1][coluna + 1] == '.' && tabuleiro[i][coluna + 1] == '.') {
            tabuleiro[i][coluna] = '#';
            tabuleiro[i - 1][coluna] = '#';
            tabuleiro[i - 1][coluna + 1] = '#';
            tabuleiro[i][coluna + 1] = '#';
            return;
        }
    }
}

int main() {
    char tabuleiro[LINHAS][COLUNAS];
    inicializar_tabuleiro(tabuleiro);

    int entrada;
    do {
        scanf("%d", &entrada);
        if (entrada != 0) {
            posicionar_peca(tabuleiro, entrada - 1);
        }
    } while (entrada != 0);

    desenhar_tabuleiro(tabuleiro);

    return 0;
}
