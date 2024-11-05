#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpuTAD.h"

struct mpuTCD {
    double aceleracaoX;
    double aceleracaoY;
    double aceleracaoZ;
    double rotacaoX;
    double rotacaoY;
    double rotacaoZ;
    int sensibilidadeAceleracao;
    int sensibilidadeRotacao;
};

mpuTAD inicializar_mpu() {
    mpuTAD mpu = malloc(sizeof(struct mpuTCD));
    if (mpu == NULL) {
        fprintf(stderr, "Erro ao alocar memória para MPU\n");
        exit(EXIT_FAILURE);
    }
    mpu->aceleracaoX = 0.0;
    mpu->aceleracaoY = 0.0;
    mpu->aceleracaoZ = 0.0;
    mpu->rotacaoX = 0.0;
    mpu->rotacaoY = 0.0;
    mpu->rotacaoZ = 0.0;
    return mpu;
}

void remover_mpu(mpuTAD *mpu) {
    if (mpu == NULL) {
        return;
    }
    free(mpu);
    mpu = NULL;
}

void inserir_rotacao(mpuTAD mpu, double rotacaoX, double rotacaoY, double rotacaoZ) {
    if (mpu == NULL) {
        fprintf(stderr, "MPU não inicializado\n");
        return;
    }
    mpu->rotacaoX = rotacaoX;
    mpu->rotacaoY = rotacaoY;
    mpu->rotacaoZ = rotacaoZ;
}

void inserir_aceleracao(mpuTAD mpu, double aceleracaoX, double aceleracaoY, double aceleracaoZ) {
    if (mpu == NULL) {
        fprintf(stderr, "MPU não inicializado\n");
        return;
    }
    mpu->aceleracaoX = aceleracaoX;
    mpu->aceleracaoY = aceleracaoY;
    mpu->aceleracaoZ = aceleracaoZ;
}

double calcular_rotacao(const mpuTAD mpu) {
    if (mpu == NULL) {
        fprintf(stderr, "MPU não inicializado\n");
        return -1.0;
    }

    double fator_escala;
    switch (mpu->sensibilidadeRotacao) {
        case 250:
            fator_escala = 131.0;
            break;
        case 500:
            fator_escala = 65.5;
            break;
        case 1000:
            fator_escala = 32.8;
            break;
        case 2000:
            fator_escala = 16.4;
            break;
        default:
            fprintf(stderr, "Sensibilidade de rotação inválida\n");
            return -1.0;
    }

    double rotacaoX = mpu->rotacaoX / fator_escala;
    double rotacaoY = mpu->rotacaoY / fator_escala;
    double rotacaoZ = mpu->rotacaoZ / fator_escala;

    return sqrt(rotacaoX * rotacaoX + rotacaoY * rotacaoY + rotacaoZ * rotacaoZ);
}

double calcular_aceleracao(const mpuTAD mpu) {
    if (mpu == NULL) {
        fprintf(stderr, "MPU não inicializado\n");
        return -1.0;
    }

    double fator_escala;
    switch (mpu->sensibilidadeAceleracao) {
        case 2:
            fator_escala = 16384.0;
            break;
        case 4:
            fator_escala = 8192.0;
            break;
        case 8:
            fator_escala = 4096.0;
            break;
        case 16:
            fator_escala = 2048.0;
            break;
        
        default:
            fprintf(stderr, "Sensibilidade de aceleração inválida\n");
            return -1.0;
    }

    double aceleracaoX = mpu->aceleracaoX / fator_escala;
    double aceleracaoY = mpu->aceleracaoY / fator_escala;
    double aceleracaoZ = mpu->aceleracaoZ / fator_escala;

    return sqrt(aceleracaoX * aceleracaoX + aceleracaoY * aceleracaoY + aceleracaoZ * aceleracaoZ);
}

void inserir_sensibilidade_rotacao(mpuTAD mpu, int sensibilidade) {
    if (mpu == NULL) {
        fprintf(stderr, "MPU não inicializado\n");
        return;
    }
    if (sensibilidade != 250 && sensibilidade != 500 && sensibilidade != 1000 && sensibilidade != 2000) {
        fprintf(stderr, "Sensibilidade de rotação inválida\n");
        return;
    }
    mpu->sensibilidadeRotacao = sensibilidade;
}

void inserir_sensibilidade_aceleracao(mpuTAD mpu, int sensibilidade) {
    if (mpu == NULL) {
        fprintf(stderr, "MPU não inicializado\n");
        return;
    }
    if (sensibilidade != 2 && sensibilidade != 4 && sensibilidade != 8 && sensibilidade != 16) {
        fprintf(stderr, "Sensibilidade de aceleração inválida\n");
        return;
    }
    mpu->sensibilidadeAceleracao = sensibilidade;
}