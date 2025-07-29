#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("   ");
    for (int col = 0; col < TAM_TABULEIRO; col++) {
        printf("%2d ", col);
    }
    printf("\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se o navio cabe no tabuleiro e se não há sobreposição
int podePosicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                        int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (orientacao == 'V' ? i : 0);
        int c = coluna + (orientacao == 'H' ? i : 0);

        if (l >= TAM_TABULEIRO || c >= TAM_TABULEIRO || tabuleiro[l][c] != 0) {
            return 0; // fora dos limites ou já ocupado
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                     int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (orientacao == 'V' ? i : 0);
        int c = coluna + (orientacao == 'H' ? i : 0);
        tabuleiro[l][c] = 3; // valor 3 representa parte de navio
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios
    int linha1 = 2, coluna1 = 3; // horizontal
    int linha2 = 5, coluna2 = 6; // vertical

    // Validação e posicionamento do navio horizontal
    if (podePosicionarNavio(tabuleiro, linha1, coluna1, 'H')) {
        posicionarNavio(tabuleiro, linha1, coluna1, 'H');
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
    }

    // Validação e posicionamento do navio vertical
    if (podePosicionarNavio(tabuleiro, linha2, coluna2, 'V')) {
        posicionarNavio(tabuleiro, linha2, coluna2, 'V');
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro com os navios
    exibirTabuleiro(tabuleiro);

    return 0;
}
