#ifndef PILHAMPUTAD_H
#define PILHAMPUTAD_H

#include "mpuTAD.h"

#define MAX_SENSORES 100

// Estrutura de dados para a pilha de sensores MPU
typedef struct {
    mpuTAD sensores[MAX_SENSORES];
    int topo;
} pilhaMPU;

// Inicializa a pilha
void inicializar_pilha(pilhaMPU *p);

// Verifica se a pilha está vazia
int pilha_vazia(pilhaMPU *p);

// Verifica se a pilha está cheia
int pilha_cheia(pilhaMPU *p);

// Empilha um sensor MPU na pilha
int push(pilhaMPU *p, mpuTAD sensor);

// Desempilha um sensor MPU da pilha
mpuTAD pop(pilhaMPU *p);

#endif // PILHAMPUTAD_H