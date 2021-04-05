#include <stdio.h>

/*void mostrar (int matriz[][M], int i, int j, int N, int M) {
    for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int pegar (int M) {
    return M;
}*/

int main (void) {
    int N=0, M=0, i, j, simetrica=0;

    printf("Informe a dimensao da matriz: ");
    scanf("%d %d", &N, &M);
    int matriz[N][M];
	printf("Informe os campos da matriz\n");

    for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    /*for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }*/

    for (i=0;i<N;i++) {
        for (j=0;j<M;j++) {
            if (matriz[i][j]==matriz[j][i]) {
                simetrica=1;
                continue;
            } else {
                simetrica=0;
                break;
            }
        }
    }

    if (simetrica) {
        printf("A Matriz informada e simetrica\n");
    } else {
        printf("A Matriz informada nao e simetrica\n");
    }

    return 0;
}
