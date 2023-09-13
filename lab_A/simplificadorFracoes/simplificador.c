#include <stdio.h>

typedef struct fracao {
    int num;
    int den;
} Fracao;

void simplifica_fracao(Fracao fracao) {
    if (fracao.num == 0) {
        fracao.num = 0;
        fracao.den = 1;
    } else if (fracao.num == fracao.den) {
        int mdc = fracao.num;
        fracao.num /= mdc;
        fracao.den /= mdc;
    }
    
    if (fracao.num < fracao.den) {
        int mdc = 0;
        int maior = fracao.num;
        
        for (int i = maior; i > 1; i--) {
            if (fracao.num % i == 0 && fracao.den % i == 0) {
                mdc = i;
                while (fracao.num >= mdc && fracao.den >= mdc) {
                    fracao.num /= mdc;
                    fracao.den /= mdc;
                }
            }
        }
    }
    
    if (fracao.num > fracao.den) {
        int mdc = 0;
        
        for (int i = 2; i <= fracao.den; i++) {
            if (fracao.num % i == 0 && fracao.den % i == 0) {
                mdc = i;
                while (fracao.num >= mdc && fracao.den >= mdc) {
                    fracao.num /= mdc;
                    fracao.den /= mdc;
                }
            }
        }
    }
    
    printf("%d/%d\n", fracao.num, fracao.den);
}

int main(void) {
    int num, den;
    Fracao fracao;

    while (scanf("%d %d", &num, &den) == 2) {
        if (num == 0 && den == 0) {
            break;
        }
        fracao.num = num;
        fracao.den = den;
        simplifica_fracao(fracao);
    }
}
