#include <stdio.h>

/* Direções exigidas */
static inline void cima(void)     { printf("Cima\n"); }
static inline void baixo(void)    { printf("Baixo\n"); }
static inline void esquerda(void) { printf("Esquerda\n"); }
static inline void direita(void)  { printf("Direita\n"); }

/* -----------------------------------------------------------
 * NÍVEL AVENTUREIRO — Cavalo: movimento em L usando LOOPS ANINHADOS
 * Alvo: “para BAIXO e para a ESQUERDA”.
 * ----------------------------------------------------------- */

/* Variante 1: 2 para BAIXO, depois 1 para ESQUERDA
 * Estruturas: for (externo) + while (interno)  => loops aninhados obrigatórios. */
void cavalo_L_baixo_baixo_esquerda(void) {
    printf("== Cavalo (L): 2x Baixo, 1x Esquerda ==\n");

    int segmentos[2] = {2, 1}; /* quantidade de passos por segmento do L */
    for (int seg = 0; seg < 2; seg++) {           /* for externo */
        int passos = segmentos[seg];
        while (passos-- > 0) {                    /* while interno */
            if (seg == 0) baixo(); else esquerda();
        }
    }
    printf("-- Fim do L (Baixo,Baixo,Esquerda) --\n\n");
}

/* Variante 2: 2 para ESQUERDA, depois 1 para BAIXO
 * Estruturas: for (externo) + do-while (interno)  => outra dupla de loops aninhados. */
void cavalo_L_esquerda_esquerda_baixo(void) {
    printf("== Cavalo (L): 2x Esquerda, 1x Baixo ==\n");

    for (int seg = 0; seg < 2; seg++) {           /* for externo */
        int alvo = (seg == 0) ? 2 : 1;            /* 2 passos no 1º seg, 1 passo no 2º */
        int c = 0;
        do {                                      /* do-while interno */
            if (seg == 0) esquerda(); else baixo();
            c++;
        } while (c < alvo);
    }
    printf("-- Fim do L (Esquerda,Esquerda,Baixo) --\n\n");
}

/* Exemplo de uso isolado: */
int main(void) {
    cavalo_L_baixo_baixo_esquerda();
    cavalo_L_esquerda_esquerda_baixo();
    return 0;
}
