// Interface da BIBLIOTECA: mpuTAD

#ifndef MPU_TAD_H
#define MPU_TAD_H

#include <stdlib.h>
#include <stdio.h>


// Estrutura de dados para o MPU
typedef struct mpuTCD *mpuTAD;

mpuTAD inicializar_mpu();

void remover_mpu();

void inserir_aceleracao();

void inserir_rotacao();

double calcular_rotacao();

double calcular_aceleracao();

void inserir_sensibilidade_rotacao();

void inserir_sensibilidade_aceleracao();

#endif // MPU_TAD_H