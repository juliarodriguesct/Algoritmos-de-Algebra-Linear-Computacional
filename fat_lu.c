#include <stdio.h>
#include <math.h>


int main (void) {
    int N, i, j, k;

    printf("Informe a dimensao N: ");
    scanf("%d", &N);

    int A[N][N], B[N];
    float L[N][N], U[N][N], soma=0, X[N], Y[N];

    for (i=0;i<N;i++) {
        X[i]=0;
        Y[i]=0;
        for (j=0;j<N;j++) {
            U[i][j]=0;
            if (i==j) {
                L[i][j]=1;
            } else {
                L[i][j]=0;
            }
        }
    }
    printf("Informe a matriz A:\n");
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            scanf("%d", &A[i][j]);
        }
    }

    if (N==2) {
        U[0][0]=A[0][0];
        U[0][1]=A[0][1];
        L[1][0]=A[1][0]/U[0][0];
        U[1][1]=A[1][1]-(L[1][0]*U[0][1]);
    } else if (N>2) {
        for (i=0;i<N;i++) {
            U[0][i]=A[0][i];
        }
        for (i=1;i<N;i++) {
            L[i][0]=A[i][0]/U[0][0];
        }
        for (i=1;i<N;i++) {
            U[1][i]=A[1][i] - L[1][0]*U[0][i];
        }
        for (i=2;i<N;i++) {
            L[i][1]=(A[i][1]-L[i][0]*U[0][1])/U[1][1];
        }
        for (i=2;i<N;i++) {
            for(j=2;j<N;j++) {
                if (i<=j) {
                    for (k=0;k<=i-1;k++) {
                        soma+=L[i][k]*U[k][j];
                    }
                    U[i][j]=A[i][j]-soma;
                    soma=0;
                } else if (i>j) {
                    for (k=0;k<=j-1;k++) {
                        soma+=L[i][k]*U[k][j];
                    }
                    L[i][j]=(A[i][j]-soma)/U[j][j];
                    soma=0;
                }
            }
        }
    }

    printf("Matriz L:\n");
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            printf("%.2f ", L[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz U:\n");
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            printf("%.2f ", U[i][j]);
        }
        printf("\n");
    }

    printf("\nInforme os valores da matriz B:\n");
    for (i=0;i<N;i++) {
        scanf("%d", &B[i]);
    }

    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
                if (i==j) {
                    if (i==0 && j==0) {
                        Y[i]=B[i]/L[i][j];
                    } else {
                        for (k=0;k<j;k++) {
                            soma+=Y[k]*L[i][k];
                        }
                        Y[i]=(B[i]-soma)/L[i][j];
                        soma=0;
                    }
                }
        }
    }

    for (i=N-1;i>=0;i--) {
        for (j=N-1;j>=0;j--) {

                if (i==j) {
                    if (i==N-1 && j==N-1) {
                        X[i]=Y[i]/U[i][j];
                    } else {
                        for (k=N-1;k>j;k--) {
                            soma+=X[k]*U[i][k];
                        }
                        X[i]=(Y[i]-soma)/U[i][j];
                        soma=0;
                    }
                }
        }
    }

    printf("\nMatriz Y:\n");
    for (i=0;i<N;i++) {
        printf("%.2f\n", Y[i]);
    }
    printf("\nMatriz X:\n");
    for (i=0;i<N;i++) {
        printf("%.2f\n", X[i]);
    }


    return 0;
}
