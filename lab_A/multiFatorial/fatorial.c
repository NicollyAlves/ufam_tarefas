#include <stdio.h>

int multiFatorial(int n, int a){
	if(n <= 0){
		return 1;
	}
	return n * multiFatorial(n - a, a);
}

int main(void){
	int n;
	int a;
	
	while(scanf("%d %d", &n, &a) != EOF){
		if(n == 0 && a == 0){
			break;
		}
		
		printf("%d", n);
		for(int i = 0; i < a; i++){printf("!");}
		
		printf(" = %d\n", multiFatorial(n, a));
	}
}