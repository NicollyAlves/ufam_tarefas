/* #include <stdio.h>
#include <stdlib.h>


SOMENTE 67% DE ACERTO
--------------------------------------------------------------
void histograma(int n, double *medicoes, int *hist){
	for(int i = 0; i < 10; i++){
		hist[i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		if(medicoes[i] >= 0.0 && medicoes[i] <= 1.0){
            int interv = (int)(medicoes[i] * 10);
			hist[interv]++;
		}
	}
}

int main(void){
	int n;
	double *medicoes;
	int *hist;
	
	scanf("%d", &n);
	
	medicoes = malloc(n * sizeof(double));
	hist = malloc(10 * sizeof(int));
	
	for(int i = 0; i < n; i++){
		scanf("%lf", &medicoes[i]);		
	}

	histograma(n, medicoes, hist);
	
	for(int k = 0; k < 10; k++){
		printf("%d ", hist[k]);
	}
	
	free(medicoes);
	free(hist);
} 
------------------------------------------------------------*/

/* #include <stdio.h>

void histograma(int n, double *medicoes, int *hist){
	for (int i = 0; i < n; i++){
		if (medicoes[i] >= 0.0 && medicoes[i] < 0.1){
			hist[0]++;
		} else if (medicoes[i] >= 0.1 && medicoes[i] < 0.2){
			hist[1]++;
		} else if (medicoes[i] >= 0.2 && medicoes[i] < 0.3){
			hist[2]++;
		} else if (medicoes[i] >= 0.3 && medicoes[i] < 0.4){
			hist[3]++;
		} else if (medicoes[i] >= 0.4 && medicoes[i] < 0.5){
			hist[4]++;
		} else if (medicoes[i] >= 0.5 && medicoes[i] < 0.6){
			hist[5]++;
		} else if (medicoes[i] >= 0.6 && medicoes[i] < 0.7){
			hist[6]++;
		} else if (medicoes[i] >= 0.7 && medicoes[i] < 0.8){
			hist[7]++;
		} else if (medicoes[i] >= 0.8 && medicoes[i] < 0.9){
			hist[8]++;
		} else if (medicoes[i] >= 0.9 && medicoes[i] <= 1.0){
			hist[9]++;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);

	double medicoes[n];
	for (int i = 0; i < n; i++){
		scanf("%lf", &medicoes[i]);
	}

	int hist[10] = {0};
	histograma(n, medicoes, hist);

	for (int i = 0; i < 10; i++){
		printf("%d ", hist[i]);
	}
}
 */
