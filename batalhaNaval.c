#include <stdio.h>

// define o tamanho do tabuleiro 
#define LINHAS 10
#define COLUNAS 10

// função para iniciar o tabuleiro
void IniciaTabuleiro (int matriz[LINHAS][COLUNAS]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = 0; // define "0" com agua.
        }
    }
}
// função para exibir o tabuleiro
void ExibirTabuleiro (int matriz[LINHAS][COLUNAS]) {
    printf("  ");
    for (int j = 0; j < COLUNAS; j++) {
        printf(" %d ", j);
    }
    printf("\n");
    // Loop aninhado para exibir tabuleiro
    for (int i = 0; i < LINHAS; i++) {
        printf(" %d", i);
        for (int j = 0; j < COLUNAS; j++) {
            printf("%2d ", matriz[i][j]);  
        }
        printf("\n");
    }
}
// função para exibir Navio Cone
void NavioCone (int matriz[LINHAS][COLUNAS], int linha, int coluna) {
   
    for (int i = 0; i < 3; i++) {
       for (int j = -i; j <= i; j++){       // loop aninhado, cria o formato de cone
        matriz[linha + i][j + coluna] = 1;
        
    }  
  }
}
// função navio cruz
void NavioCruz(int matriz[LINHAS][COLUNAS], int linha, int coluna) {
    int cruz[3][5] = {        // matriz em formato de navio cruz
        { 0, 0, 2, 0, 0 },
        { 2, 2, 2, 2, 2 },
        { 0, 0, 2, 0, 0 }
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[linha + i][coluna + j] = cruz[i][j];
        }
    }
}
// função para exibir Navio Octaedro
void NavioOctaedro(int matriz[LINHAS][COLUNAS], int linha, int coluna) {
    int octaedro[3][3] = {       // matriz em formato de navio octaedro
        { 0, 3, 0 },
        { 3, 3, 3 },
        { 0, 3, 0 }
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[linha + i][coluna + j] = octaedro[i][j];
        }
    }
}



int main() {
    int matriz[LINHAS][COLUNAS];
     
    printf("\n\n############ BATALHA NAVAL ##########\n\n");
    IniciaTabuleiro(matriz);     // preenche tabuleiro com "0"
    NavioCone(matriz, 1, 3);     // posicionamneto dos navios   
    NavioCruz(matriz, 5, 5);
    NavioOctaedro(matriz, 7, 1);
    ExibirTabuleiro(matriz);
    
   

    return 0;
}
