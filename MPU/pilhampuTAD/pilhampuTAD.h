#ifndef PILHAMPUTAD_H
#define PILHAMPUTAD_H

#include "mpuTAD.h"

// Definição da estrutura da pilha de MPUs
typedef struct pilhaMPU pilhaMPU;

// Funções da pilha
pilhaMPU* criar_pilha(int capacidade);
void destruir_pilha(pilhaMPU* pilha);
int empilhar(pilhaMPU* pilha, mpuTAD mpu);
mpuTAD desempilhar(pilhaMPU* pilha);
int pilha_vazia(pilhaMPU* pilha);
int pilha_cheia(pilhaMPU* pilha);
int tamanho_pilha(const pilhaMPU* pilha);

#endif // PILHAMPUTAD_H
