#include <stdio.h>

int trilegal(int v[], int tam){
    if(tam == 1){
        return 1;
    }

    if(tam % 3 != 0){
        return 0;
    }


    if(tam % 6 == 0 && tam % 9 != 0){
        return 0;
    }

    int grupoTam = tam / 3;

    int s1 = 0;
    int s2 = 0;

    for(int i = 0; i < grupoTam; i++){
        s1 += v[i];
        s2 += v[i + grupoTam];
    }

    int s3 = 0;

    for (int i = 2 * grupoTam; i < tam; i++){
        s3 += v[i];
    }
    printf("  %d %d %d %d  ", grupoTam, s1, s2, s3);

    if(s1 + s2 == s3){
        int s1Trilegal = trilegal(v, grupoTam);
        int s2Trilegal = trilegal(v + grupoTam, grupoTam);
        int s3Trilegal = trilegal(v + 2 * grupoTam, grupoTam);

        return s1Trilegal && s2Trilegal && s3Trilegal;
    } else {
        return 0;
    }
}

int main(void){
    int N;
    while (1) {
        scanf("%d", &N);
        if (N == 0){
            break;
        }

        int v[N];
        for (int i = 0; i < N; i++){
            scanf("%d", &v[i]);
        }

        int res = trilegal(v, N);
        if(res){
            printf("trilegal\n");
        } else {
            printf("normal\n");
        }
    }

    return 0;
}
