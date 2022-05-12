#include <stdio.h>
#include <stdlib.h>
#define MAX 500
void inicializarGrafo(int matriz[MAX][MAX], int vertices);
void inserirArcos(int matriz[MAX][MAX], int num1, int num2);
int visitado(int matriz[MAX][MAX], int vertices, int *visitado);
void buscaProfundidade(int matriz[MAX][MAX], int i, int vertices, int *visitado);

int main()
{
    int matriz[MAX][MAX], result=0;
    int vertices, arestas, num1, num2;
    scanf("%d", &vertices);
    scanf("%d", &arestas);

    inicializarGrafo(matriz, vertices);
    int visit[vertices];
    for(int j=0; j < arestas; j++){
        scanf("%d %d", &num1, &num2);
        inserirArcos(matriz, num1, num2);
    }

       result = visitado(matriz, vertices, visit);
    printf("%d\n", result);
    return 0;
}

void inicializarGrafo(int matriz[MAX][MAX], int vertices){
    int i, j;
    for(i=0; i < vertices; i++){
        for(j=0;j < vertices; j++){
            matriz[i][j] = 0;
        }
    }
}
void inserirArcos(int matriz[MAX][MAX], int num1, int num2){
    if(matriz[num1][num2] == 0){
        matriz[num1][num2] = 1;
        matriz[num2][num1] = 1;
    }

}
int visitado(int matriz[MAX][MAX], int vertices, int *visitado){
    int num_vis=0, i;
    for(i = 0; i < vertices; i++){
        visitado[i] = 0;
    }
    for(i=0; i < vertices; i++){
        if(visitado[i] == 0){
            buscaProfundidade(matriz, i,vertices, visitado);
            num_vis++;
        }
    }
    return num_vis;
}
void buscaProfundidade(int matriz[MAX][MAX], int i, int vertices,int *visitado){
    int j,result1=0;
    visitado[i] = 1;
        for(j = 0; j < vertices; j++){
            if(matriz[i][j] == 1){
                if(visitado[j] == 0){
                    buscaProfundidade(matriz, j, vertices, visitado);
                }
            }
        }
}
