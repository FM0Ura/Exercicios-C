#include "pilhampuTAD.h"

// Inicializa a pilha
void inicializar_pilha(pilhaMPU *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int pilha_vazia(pilhaMPU *p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int pilha_cheia(pilhaMPU *p) {
    return p->topo == MAX_SENSORES - 1;
}

// Empilha um sensor MPU na pilha
int push(pilhaMPU *p, mpuTAD sensor) {
    if (pilha_cheia(p)) {
        return 0; // Pilha cheia, não é possível empilhar
    }
    p->sensores[++(p->topo)] = sensor;
    return 1; // Sucesso
}

// Desempilha um sensor MPU da pilha
mpuTAD pop(pilhaMPU *p) {
    if (pilha_vazia(p)) {
        return NULL; // Pilha vazia, não é possível desempilhar
    }
    return p->sensores[(p->topo)--];
}