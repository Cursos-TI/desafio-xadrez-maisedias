#include <stdio.h>

/*
 * Desafio de Xadrez - MateCheck | Nível Mestre
 * - Bispo: recursivo + loops aninhados por passo (Cima depois Direita)
 * - Torre: recursivo (Direita)
 * - Rainha: recursivo (Esquerda)
 * - Cavalo: 1 L para cima à direita usando laços com múltiplas variáveis/condições,
 *           com continue e break.
 * Saída: "Cima", "Baixo", "Esquerda", "Direita"
 */

/* ===================== Entrada via constantes ===================== */
static const int PASSOS_BISPO  = 5;  /* diagonal superior direita */
static const int PASSOS_TORRE  = 5;  /* direita */
static const int PASSOS_RAINHA = 8;  /* esquerda */

/* ===================== Utilidades de saída ===================== */
static inline void cima(void)     { printf("Cima\n"); }
static inline void baixo(void)    { printf("Baixo\n"); }
static inline void esquerda(void) { printf("Esquerda\n"); }
static inline void direita(void)  { printf("Direita\n"); }

/* ===================== Bispo (recursivo + loops aninhados) ===================== */
/* Cada chamada recursiva executa 1 passo diagonal como dois segmentos:
   1) Cima, 2) Direita — implementados com loops aninhados (for externo + while interno). */
void mover_bispo_diag_sup_dir_rec(int passos) {
    if (passos <= 0) return;

    /* loops aninhados para compor a diagonal usando direções básicas */
    for (int seg = 0; seg < 2; seg++) {
        int reps = 1;          /* 1 passo por segmento do “L” da diagonal */
        int k = 0;
        while (k < reps) {     /* while interno: imprime a direção do segmento */
            if (seg == 0) cima();
            else          direita();
            k++;
        }
    }

    mover_bispo_diag_sup_dir_rec(passos - 1);
}

/* ===================== Torre (recursivo) ===================== */
void mover_torre_direita_rec(int passos) {
    if (passos <= 0) return;
    direita();
    mover_torre_direita_rec(passos - 1);
}

/* ===================== Rainha (recursivo) ===================== */
void mover_rainha_esquerda_rec(int passos) {
    if (passos <= 0) return;
    esquerda();
    mover_rainha_esquerda_rec(passos - 1);
}

/* ===================== Cavalo (1 L para cima à direita) ===================== */
/* Usa laço com múltiplas variáveis e condições; aplica continue e break.
   Meta: 2 passos Cima, 1 passo Direita (ordem adaptativa). */
void mover_cavalo_1L_cima_direita(void) {
    printf("== Cavalo: 1 L para cima à direita ==\n");

    /* up conta passos “Cima”, right conta “Direita”.
       Condição do for: enquanto faltar completar (up<2 || right<1). */
    for (int up = 0, right = 0; (up < 2) || (right < 1); /* sem incremento aqui */) {

        /* Segurança: se, por algum motivo, passarmos do total esperado, encerra. */
        if (up + right >= 3) {
            break; /* break obrigatório atendido */
        }

        /* Prioriza subir até 2; usa continue para pular para a próxima iteração. */
        if (up < 2) {
            cima();
            up++;
            continue; /* continue obrigatório atendido */
        }

        /* Se já subiu 2, completa com 1 à direita. */
        if (right < 1) {
            direita();
            right++;
        }

        /* Sai quando alcançar exatamente 2+1 passos. */
        if (up == 2 && right == 1) {
            break;
        }
    }

    printf("-- Fim do movimento do Cavalo --\n\n");
}

/* ===================== main ===================== */
int main(void) {
    printf("=====================================\n");
    printf("  MateCheck | Desafio de Xadrez (C)\n");
    printf("  Nível: Mestre - Recursão + Laços Avançados\n");
    printf("=====================================\n\n");

    printf("== Bispo: %d casa(s) na diagonal superior direita [recursivo + loops aninhados] ==\n", PASSOS_BISPO);
    mover_bispo_diag_sup_dir_rec(PASSOS_BISPO);
    printf("-- Fim do movimento do Bispo --\n\n");

    printf("== Torre: %d casa(s) para a direita [recursivo] ==\n", PASSOS_TORRE);
    mover_torre_direita_rec(PASSOS_TORRE);
    printf("-- Fim do movimento da Torre --\n\n");

    printf("== Rainha: %d casa(s) para a esquerda [recursivo] ==\n", PASSOS_RAINHA);
    mover_rainha_esquerda_rec(PASSOS_RAINHA);
    printf("-- Fim do movimento da Rainha --\n\n");

    mover_cavalo_1L_cima_direita();

    /* Resumo rápido para conferência */
    printf("Resumo:\n");
    printf("- Bispo: diagonal sup. direita = %d passo(s) [cada passo = Cima + Direita]\n", PASSOS_BISPO);
    printf("- Torre: direita = %d passo(s)\n", PASSOS_TORRE);
    printf("- Rainha: esquerda = %d passo(s)\n", PASSOS_RAINHA);
    printf("- Cavalo: 1 L (Cima,Cima,Direita)\n");

    return 0;
}
