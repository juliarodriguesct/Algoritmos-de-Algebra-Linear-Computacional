#include <stdio.h>

int main (void) {
    int N, M, i, j;

    printf("Informe a dimensao do vetor e da matriz: ");
    scanf("%d %d", &N, &M);

    int matriz[N][M], vetor[N], vet_final[M];

    for (i=0;i<M;i++) {
        vet_final[i]=0;
    }

    printf("Informe os valores do vetor:\n");
    for (i=0;i<N;i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Informe os valores da matriz:\n");
    for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            vet_final[i]+=matriz[i][j]*vetor[j];
        }
    }

    /*for (i=0;i<N;i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }*/

    printf("Vetor final:\n");
    for (i=0;i<M;i++) {
        printf("%d ", vet_final[i]);
    }

    return 0;
}
