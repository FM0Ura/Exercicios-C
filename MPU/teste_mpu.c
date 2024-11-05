// PARTE 2 - FALTA IMPLEMENTAR A PILHA!!!

#include <stdlib.h>
#include <stdio.h>
#include "mpuTAD.h"

int main() {
    // Inicializa o MPU
    mpuTAD mpu = inicializar_mpu();
    if (mpu == NULL) {
        printf("Erro ao inicializar o MPU.\n");
        return 1;
    }

    // Insere valores de aceleração e rotação
    inserir_aceleracao(mpu, 1.0, 2.0, 3.0);
    inserir_rotacao(mpu, 0.1, 0.2, 0.3);

    // Insere valores de sensibilidade de aceleração e rotação
    inserir_sensibilidade_aceleracao(mpu, 4);
    inserir_sensibilidade_rotacao(mpu, 500);

    // Calcula e exibe os valores de aceleração e rotação
    double aceleracao = calcular_aceleracao(mpu);
    double rotacao = calcular_rotacao(mpu);

    printf("Aceleracao: %f\n", aceleracao);
    printf("Rotacao: %f\n", rotacao);

    // Remove o MPU
    remover_mpu(mpu);

    return 0;
}