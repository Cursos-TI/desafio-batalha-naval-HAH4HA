#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Água
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

// Função para verificar se o navio horizontal ou vertical cabe no tabuleiro
int podePosicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                        int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (orientacao == 'V' ? i : 0); // vertical
        int c = coluna + (orientacao == 'H' ? i : 0); // horizontal

        // Verifica se o navio sai dos limites ou se a posição está ocupada
        if (l >= TAM_TABULEIRO || c >= TAM_TABULEIRO || tabuleiro[l][c] != 0) {
            return 0; // Não cabe ou já ocupado
        }
    }
    return 1; // Pode posicionar
}

// Função para verificar se o navio na diagonal pode ser posicionado
int podePosicionarNavioDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                                 int linha, int coluna, char diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (diagonal == 'D' ? i : -i); // Diagonal principal (l=linha+i, c=coluna+i)
        int c = coluna + (diagonal == 'D' ? i : -i); // Diagonal secundária (l=linha+i, c=coluna-i)

        // Verifica se o navio sai dos limites ou se a posição está ocupada
        if (l >= TAM_TABULEIRO || c >= TAM_TABULEIRO || l < 0 || c < 0 || tabuleiro[l][c] != 0) {
            return 0; // Não cabe ou já ocupado
        }
    }
    return 1; // Pode posicionar
}

// Função para posicionar o navio horizontal ou vertical no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                     int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (orientacao == 'V' ? i : 0);
        int c = coluna + (orientacao == 'H' ? i : 0);
        tabuleiro[l][c] = 3; // Representa a parte do navio
    }
}

// Função para posicionar o navio na diagonal
void posicionarNavioDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                              int linha, int coluna, char diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (diagonal == 'D' ? i : -i); 
        int c = coluna + (diagonal == 'D' ? i : -i); 
        tabuleiro[l][c] = 3; // Representa a parte do navio
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios
    int linha1 = 2, coluna1 = 3; // Navio 1 (horizontal)
    int linha2 = 5, coluna2 = 6; // Navio 2 (vertical)
    int linha3 = 1, coluna3 = 1; // Navio 3 (diagonal principal)
    int linha4 = 7, coluna4 = 8; // Navio 4 (diagonal secundária)

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

    // Validação e posicionamento do navio diagonal (principal)
    if (podePosicionarNavioDiagonal(tabuleiro, linha3, coluna3, 'D')) {
        posicionarNavioDiagonal(tabuleiro, linha3, coluna3, 'D');
    } else {
        printf("Erro: Não foi possível posicionar o navio diagonal principal.\n");
    }

    // Validação e posicionamento do navio diagonal (secundária)
    if (podePosicionarNavioDiagonal(tabuleiro, linha4, coluna4, 'S')) {
        posicionarNavioDiagonal(tabuleiro, linha4, coluna4, 'S');
    } else {
        printf("Erro: Não foi possível posicionar o navio diagonal secundária.\n");
    }

    // Exibe o tabuleiro com os navios
    exibirTabuleiro(tabuleiro);

    return 0;
}
