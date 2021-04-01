#include <stdio.h>
#include <math.h>

int main (void) {
    int N, i, j, a=0;
    float soma=0, soma_1=0, tol, tolerancia=10;

    printf("Informe a dimensao N: ");
    scanf("%d", &N);

    printf("Informe uma tolerancia: ");
    scanf("%f", &tol);

    float A[N][N], X[N], B[N], X_k_anterior[N], copia[N], diferenca[N], maior_diferenca=0,  maior_atual=0;

    printf("Insira a Matriz A:\n");
    for (i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            scanf("%f", &A[i][j]);
        }
    }

    printf("Insira o vetor b:\n");
    for(i=0;i<N;i++) {
        scanf("%f", &B[i]);
    }

    printf("Chute um vetor resultado:\n");
    for (i=0;i<N;i++) {
        scanf("%f", &X_k_anterior[i]);
        copia[i]=X_k_anterior[i];
    }

    while(tolerancia>tol) {

        for(i=0;i<N;i++) {
            X[i]=0;
            for (j=0;j<=i-1;j++) {
                soma+=A[i][j]*X[j];
            }
            for (j=i+1;j<N;j++) {
                soma_1+=A[i][j]*X_k_anterior[j];
            }
            X[i]+=(1/A[i][i])*(B[i]-soma-soma_1);
            X_k_anterior[i]=X[i];
            soma=0;
            soma_1=0;
        }

        for (i=0;i<N;i++) {
            diferenca[i]=X[i]-copia[i];
            copia[i]=X_k_anterior[i];
        }

        for (i=0;i<N;i++) {
            if (maior_diferenca<fabs(diferenca[i])) {
                maior_diferenca=fabs(diferenca[i]);
            }
            if (maior_atual<fabs(X[i])) {
                maior_atual=fabs(X[i]);
            }
        }

        tolerancia = maior_diferenca/maior_atual;

        printf("Resultado iteracao %d\n", a+1);
        for (i=0;i<N;i++) {
            printf("X[%d] = %.6f\n",i, X[i]);
        }

        if (tolerancia<tol) {
            printf("Tolerancia atual e menor que tolerancia pretendida: %.2f<%.2f . Loop para.\n", tolerancia, tol);
        } else {
            printf("Objetivo nao atingido: %.2f>%.2f\n", tolerancia, tol);
        }
        maior_atual=0;
        maior_diferenca=0;
        system("pause");
        a++;
    }

    return 0;
}

