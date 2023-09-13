#include <stdio.h>

int potencia(int b, int e){
	if(e == 0){
		return 1;
	} else {
		if(e % 2 != 0){
			return b * potencia(b, e - 1);
		} else if(e % 2 == 0){
		    return potencia(b * b, e / 2);
		}
	}
    return 0;
}

int main(void){
	int base, expoente;

	while (scanf("%d%d", &base, &expoente) != EOF){
		printf("%d", potencia(base, expoente));
	}
}
