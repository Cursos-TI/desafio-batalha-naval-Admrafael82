#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            printf("Erro: Navio sobrepondo-se em (%d, %d)\n", linha, coluna + i);
            return;
        }
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            printf("Erro: Navio sobrepondo-se em (%d, %d)\n", linha + i, coluna);
            return;
        }
        tabuleiro[linha + i][coluna] = 3;
    }
}

int main() {
    // Inicializando o tabuleiro com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Definindo as coordenadas de posicionamento dos navios
    // Navio 1 (horizontal)
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 3;
    
    // Navio 2 (vertical)
    int linhaNavioVertical = 5;
    int colunaNavioVertical = 6;

    // Posicionando os navios no tabuleiro
    printf("Posicionando o navio horizontal...\n");
    posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal);

    printf("Posicionando o navio vertical...\n");
    posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical);

    // Exibindo o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
