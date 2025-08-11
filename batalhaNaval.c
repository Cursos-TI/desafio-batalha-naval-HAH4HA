#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5

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
            if (tabuleiro[i][j] == 0) {
                printf("~ "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("N "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("X "); // Área afetada pela habilidade
            }
        }
        printf("\n");
    }
}

// Função para construir a matriz de Cone
void construirCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j <= i; j++) {
            habilidade[i][j] = 1; // A área do cone será 1
        }
    }
}

// Função para construir a matriz de Cruz
void construirCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        habilidade[meio][i] = 1; // Linha central da cruz
        habilidade[i][meio] = 1; // Coluna central da cruz
    }
}

// Função para construir a matriz de Octaedro
void construirOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i <= meio; i++) {
        for (int j = meio - i; j <= meio + i; j++) {
            habilidade[i][j] = 1; // Preencher a parte superior
            habilidade[TAM_HABILIDADE - i - 1][j] = 1; // Preencher a parte inferior
        }
    }
}

// Função para sobrepor a matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha + i - (TAM_HABILIDADE / 2);
                int coluna = origemColuna + j - (TAM_HABILIDADE / 2);
                if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                    tabuleiro[linha][coluna] = 5; // Marca a área afetada pela habilidade
                }
            }
        }
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

    // Posicionamento dos navios
    tabuleiro[linha1][coluna1] = 3;
    tabuleiro[linha2][coluna2] = 3;
    tabuleiro[linha3][coluna3] = 3;
    tabuleiro[linha4][coluna4] = 3;

    // Matrizes de habilidades
    int habilidadeCone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int habilidadeCruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};
    int habilidadeOctaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Construção das matrizes de habilidades
    construirCone(habilidadeCone);
    construirCruz(habilidadeCruz);
    construirOctaedro(habilidadeOctaedro);

    // Definindo os pontos de origem para as habilidades
    int origemConeLinha = 4, origemConeColuna = 4;
    int origemCruzLinha = 3, origemCruzColuna = 3;
    int origemOctaedroLinha = 6, origemOctaedroColuna = 6;

    // Aplicando as habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, habilidadeCruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, origemOctaedroLinha, origemOctaedroColuna);

    // Exibindo o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
