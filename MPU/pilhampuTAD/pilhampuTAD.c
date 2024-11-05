#include <stdio.h>
#include <stdlib.h>
#include "pilhampuTAD.h"
#include "mpuTAD.h"

struct pilhaMPU {
    mpuTAD* elementos;
    int topo;
    int capacidade;
};

// Criação da pilha
pilhaMPU* criar_pilha(int capacidade) {
    pilhaMPU* pilha = (pilhaMPU*)malloc(sizeof(pilhaMPU));
    if (pilha == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a pilha\n");
        exit(EXIT_FAILURE);
    }
    pilha->elementos = (mpuTAD*)malloc(capacidade * sizeof(mpuTAD));
    if (pilha->elementos == NULL) {
        fprintf(stderr, "Erro ao alocar memória para os elementos da pilha\n");
        free(pilha);
        exit(EXIT_FAILURE);
    }
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    return pilha;
}

// Destruição da pilha
void destruir_pilha(pilhaMPU* pilha) {
    if (pilha != NULL) {
        free(pilha->elementos);
        free(pilha);
    }
}

// Verificação se a pilha está cheia
int pilha_cheia(pilhaMPU* pilha) {
    return pilha->topo == pilha->capacidade - 1;
}

// Verificação se a pilha está vazia
int pilha_vazia(pilhaMPU* pilha) {
    return pilha->topo == -1;
}

// Empilhar um MPU
int empilhar(pilhaMPU* pilha, mpuTAD mpu) {
    if (pilha_cheia(pilha)) {
        fprintf(stderr, "Pilha cheia, não é possível empilhar\n");
        return 0;
    }
    pilha->elementos[++pilha->topo] = mpu;
    return 1;
}

// Desempilhar um MPU
mpuTAD desempilhar(pilhaMPU* pilha) {
    if (pilha_vazia(pilha)) {
        fprintf(stderr, "Pilha vazia, não é possível desempilhar\n");
        return NULL;
    }
    return pilha->elementos[pilha->topo--];
}

// Obter o tamanho da pilha
int tamanho_pilha(const pilhaMPU* pilha) {
    return pilha->topo + 1;
}
