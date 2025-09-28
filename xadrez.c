#include <stdio.h>

/*
 * Desafio de Xadrez - MateCheck | Nível Novato
 * Objetivo: demonstrar movimentação com estruturas de repetição
 * Direções válidas: "Cima", "Baixo", "Esquerda", "Direita"
 *
 * Requisitos atendidos:
 * - Entrada via constantes (sem leitura externa)
 * - Uso de for, while e do-while
 * - Saída clara com a direção de cada movimento
 * - Comentários explicando cada parte
 */

/* ===================== Entrada de Dados (constantes) ===================== */
const int PASSOS_BISPO  = 5;  /* diagonal superior direita = Cima + Direita */
const int PASSOS_TORRE  = 5;  /* Direita */
const int PASSOS_RAINHA = 8;  /* Esquerda */

/* ===================== Utilidades de saída (nomenclatura exigida) ===================== */
static inline void cima(void)     { printf("Cima\n"); }
static inline void baixo(void)    { printf("Baixo\n"); }
static inline void esquerda(void) { printf("Esquerda\n"); }
static inline void direita(void)  { printf("Direita\n"); }

/* ===================== Movimentações (Nível Novato) ===================== */

/* Bispo: 5 casas na diagonal superior direita
 * Estratégia: cada “passo diagonal” é impresso como duas direções básicas:
 * Cima e depois Direita. Estrutura: do-while (para variar os loops). */
void mover_bispo_diag_sup_dir(int passos) {
    printf("== Bispo: %d casa(s) na diagonal superior direita ==\n", passos);
    if (passos <= 0) {
        printf("(Sem movimento solicitado)\n\n");
        return;
    }

    int i = 0;
    do {
        cima();      /* componente vertical da diagonal */
        direita();   /* componente horizontal da diagonal */
        i++;
    } while (i < passos);

    printf("-- Fim do movimento do Bispo --\n\n");
}

/* Torre: 5 casas para a direita
 * Estrutura: for (clássico para contagem) */
void mover_torre_direita(int passos) {
    printf("== Torre: %d casa(s) para a direita ==\n", passos);
    for (int i = 0; i < passos; i++) {
        direita();
    }
    printf("-- Fim do movimento da Torre --\n\n");
}

/* Rainha: 8 casas para a esquerda
 * Estrutura: while (decrementando restante) */
void mover_rainha_esquerda(int passos) {
    printf("== Rainha: %d casa(s) para a esquerda ==\n", passos);
    int restante = passos;
    while (restante > 0) {
        esquerda();
        restante--;
    }
    printf("-- Fim do movimento da Rainha --\n\n");
}

/* ===================== Função principal ===================== */
int main(void) {
    /* Cabeçalho informativo */
    printf("=====================================\n");
    printf("  MateCheck | Desafio de Xadrez (C)\n");
    printf("  Nível: Novato - Loops + Funções\n");
    printf("=====================================\n\n");

    /* Execução das movimentações solicitadas */
    mover_bispo_diag_sup_dir(PASSOS_BISPO);   /* do-while + combinação (Cima, Direita) */
    mover_torre_direita(PASSOS_TORRE);        /* for */
    mover_rainha_esquerda(PASSOS_RAINHA);     /* while */

    /* Resumo para validação rápida */
    printf("Resumo:\n");
    printf("- Bispo: diagonal sup. direita = %d passo(s) [Cima, Direita]\n", PASSOS_BISPO);
    printf("- Torre: direita = %d passo(s)\n", PASSOS_TORRE);
    printf("- Rainha: esquerda = %d passo(s)\n", PASSOS_RAINHA);

    return 0;
}
