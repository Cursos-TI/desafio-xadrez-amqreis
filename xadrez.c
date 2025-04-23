#include <stdio.h>

// Constantes para movimentação
#define BISPO_MOV 5
#define TORRE_MOV 5
#define RAINHA_MOV 8

// Função para movimentação do Bispo
void mover_bispo() {
    printf("\nMovimentos do Bispo:\n");
    for (int i = 0; i < BISPO_MOV; i++) {
        printf("Cima\n");
        printf("Direita\n");
    }
}

// Função para movimentação da Torre
void mover_torre() {
    printf("\nMovimentos da Torre:\n");
    int i = 0;
    while (i < TORRE_MOV) {
        printf("Direita\n");
        i++;
    }
}

// Função para movimentação da Rainha
void mover_rainha() {
    printf("\nMovimentos da Rainha:\n");
    int i = 0;
    do {
        printf("Esquerda\n");
        i++;
    } while (i < RAINHA_MOV);
}

// Função para movimentação do Cavalo
void mover_cavalo() {
    printf("\nMovimentos possíveis do Cavalo (em L):\n");
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++) {
        if (dx[i] == 0 || dy[i] == 0)
            continue;  // Cavalo não se move em linha reta

        if (i == 5)
            break;  // Simula interrupção de movimentos

        printf("Movimento em L: %d horizontal e %d vertical\n", dx[i], dy[i]);
    }
}

// Função recursiva para movimentação do Bispo
void mover_bispo_recursivo(int passo) {
    if (passo == 0)
        return;

    printf("Cima\n");
    printf("Direita\n");

    mover_bispo_recursivo(passo - 1);
}

void iniciar_bispo_recursivo() {
    printf("\nMovimentos do Bispo (Recursivo):\n");
    mover_bispo_recursivo(BISPO_MOV);
}

int main() {
    int opcao;

    do {
        printf("\n=== Menu de Movimentação ===\n");
        printf("1. Mover Bispo (Loop)\n");
        printf("2. Mover Torre\n");
        printf("3. Mover Rainha\n");
        printf("4. Mover Cavalo\n");
        printf("5. Mover Bispo (Recursivo)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mover_bispo();
                break;
            case 2:
                mover_torre();
                break;
            case 3:
                mover_rainha();
                break;
            case 4:
                mover_cavalo();
                break;
            case 5:
                iniciar_bispo_recursivo();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
