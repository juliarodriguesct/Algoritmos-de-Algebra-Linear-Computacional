#include <stdio.h>
#include <math.h>

int main (void) {
    int N, i, j, k;

    printf("Informe a dimensao N: ");
    scanf("%d", &N);
    int vetor[N];
    float A_superior[N][N], A_inferior[N][N], soma=0, vet_final[N], X[N], matriz[N][N], mat_transp[N][N], A[N][N];

    for (i=0;i<N;i++) {
        vet_final[i]=0;
        X[i]=0;
        for(j=0;j<N;j++) {
            A[i][j]=0;
            A_superior[i][j]=0;
            A_inferior[i][j]=0;
        }
    }

    printf("Informe os valores da Matriz M:\n");
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            mat_transp[i][j]=matriz[j][i];
        }
    }

    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            printf("%.2f ", mat_transp[i][j]);
        }
        printf("\n");
    }

    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            for (k=0;k<N;k++) {
                A[i][j]+=mat_transp[i][k]*matriz[k][j];
            }
        }
    }
    printf("\n");
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }

    if (N==2) {
        A_superior[0][0]=sqrt(A[0][0]);
        A_inferior[0][0]=sqrt(A[0][0]);
        A_inferior[1][0]=A[1][0]/A_superior[0][0];
        A_superior[0][1]=A[1][0]/A_superior[0][0];
        A_superior[1][1]=sqrt(A[1][1]-A_superior[0][1]*A_superior[0][1]);
        A_inferior[1][1]=sqrt(A[1][1]-A_superior[0][1]*A_superior[0][1]);
    }

    if (N>2) {
        A_superior[0][0]=sqrt(A[0][0]);
        A_inferior[0][0]=sqrt(A[0][0]);
        for (i=1;i<N;i++) {
            A_superior[0][i]=A[0][i]/A_superior[0][0];
            A_inferior[i][0]=A[0][i]/A_superior[0][0];
        }
        A_inferior[1][1]=sqrt(A[1][1]-A_superior[0][1]*A_superior[0][1]);
        A_superior[1][1]=sqrt(A[1][1]-A_superior[0][1]*A_superior[0][1]);
        for (i=2;i<N;i++) {
            A_superior[1][i]=(A[1][i]-A_superior[0][1]*A_superior[0][i])/A_superior[1][1];
            A_inferior[i][1]=(A[1][i]-A_superior[0][1]*A_superior[0][i])/A_superior[1][1];
        }

        /*for (i=2;i<N;i++) {
            for (j=3;j<N;j++) {
                for(k=0;k<j-1;k++) {
                    soma+=A_superior[i][k]*A_superior[j][k];
                }
                A_superior[i][j]=(A[i][j]-soma)/A_superior[j][j];
                A_inferior[j][i]=(A[i][j]-soma)/A_superior[j][j];
            }
        }*/
        i=2;
        for (k=0;k<=i-1;k++) {
                soma+=A_superior[k][i]*A_superior[k][i];
            }
        A_superior[i][i]=sqrt(A[i][i]-soma);
        A_inferior[i][i]=sqrt(A[i][i]-soma);
        soma=0;
        //for (i=2;i<N;i++) {
        for (j=i+1;j<N;j++) {
            for (k=0;k<=i-1;k++) {
                soma+=A_superior[k][2]*A_superior[k][j];
            }
            A_superior[2][j]=(A[2][j]-soma)/A_superior[2][2];
            A_inferior[j][2]=(A[2][j]-soma)/A_inferior[2][2];
            soma=0;
        }
        //}
        for (i=2;i<N;i++) {
            for (k=0;k<=i-1;k++) {
                soma+=A_superior[k][i]*A_superior[k][i];
            }
            A_superior[i][i]=sqrt(A[i][i]-soma);
            A_inferior[i][i]=sqrt(A[i][i]-soma);
            soma=0;
        }
        //A_superior[N-1][N-1]=sqrt(A[N-1][N-1]-soma);
        //A_inferior[N-1][N-1]=sqrt(A[N-1][N-1]-soma);

         for (i=2;i<N;i++) {
            for (j=i+1;j<N;j++) {
                for (k=0;k<=i-1;k++) {
                    soma+=A_superior[k][i]*A_superior[k][j];
                }
                A_superior[i][j]=(A[i][j]-soma)/A_superior[i][i];
                A_inferior[j][i]=(A[i][j]-soma)/A_superior[i][i];
                soma=0;
            }
         }

    }

    printf("Matriz final Superior:\n");
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            printf("%.2f ", A_superior[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz final inferior:\n");
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            printf("%.2f ", A_inferior[i][j]);
        }
        printf("\n");
    }

    printf("Informe o valor de b:\n");
    for(i=0;i<N;i++) {
        scanf("%d", &vetor[i]);
    }

    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            if (i==j) {
                if (i==0 && j==0) {
                    vet_final[i]=vetor[i]/A_inferior[i][j];
                } else {
                    for (k=0;k<j;k++) {
                        soma+=vet_final[k]*A_inferior[i][k];
                    }
                    if (A_inferior[i][j]!=0) {
                        vet_final[i]=(vetor[i]-soma)/A_inferior[i][j];
                    } else {
                        vet_final[i]=0;
                    }
                    soma=0;
                }
            }
        }
    }

    printf("\nValor de Y:\n");
    for(i=0;i<N;i++) {
        printf("%.2f\n", vet_final[i]);
    }

    for (i=N-1;i>=0;i--) {
        for (j=N-1;j>=0;j--) {
                if (i==j) {
                    if (i==N-1 && j==N-1) {
                        X[i]=vet_final[i]/A_superior[i][j];
                    } else {
                        for (k=N-1;k>j;k--) {
                            soma+=X[k]*A_superior[i][k];
                        }
                        if (A_superior[i][j]!=0) {
                            X[i]=(vet_final[i]-soma)/A_superior[i][j];
                        } else {
                            X[i]=0;
                        }
                        soma=0;
                    }
                }
        }
    }

    printf("\nValor de X:\n");
    for(i=0;i<N;i++) {
        printf("%.2f\n", X[i]);
    }


    return 0;
}
