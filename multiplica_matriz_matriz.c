#include <stdio.h>

int main (void) {
    int N, M, P, i, j, k;

    printf("Informe a dimensao das matrizes N M P: ");
    scanf("%d %d %d", &N, &M, &P);

    float A_matriz[N][M], X_matriz[M][P], R_matriz[N][P];

    for (i=0;i<N;i++) {
        for (j=0;j<P;j++) {
            R_matriz[i][j]=0;
        }
    }

    printf("Informe os valores da matriz A:\n");
    for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            scanf("%f", &A_matriz[i][j]);
        }
    }
    printf("Informe os valores da matriz X:\n");
    for (i=0;i<M;i++) {
        for (j=0;j<P;j++) {
            scanf("%f", &X_matriz[i][j]);
        }
    }

    for (i=0;i<N;i++) {
        for (j=0;j<P;j++) {
            for (k=0;k<M;k++) {
                R_matriz[i][j]+=A_matriz[i][k]*X_matriz[k][j];
            }
        }
    }
    printf("Matriz resultado:\n");
    for (i=0;i<N;i++) {
        for (j=0;j<P;j++) {
            printf("%.2f ", R_matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
