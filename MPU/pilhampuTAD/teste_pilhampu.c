#include <stdio.h>
#include "mpuTAD.h"
#include "pilhampuTAD.h"

int main() {
    // Criando uma pilha de MPUs com capacidade para 5 elementos
    pilhaMPU* pilha = criar_pilha(5);

    // Inicializando alguns MPUs
    mpuTAD mpu1 = inicializar_mpu();
    inserir_aceleracao(mpu1, 1.0, 2.0, 3.0);
    inserir_rotacao(mpu1, 10.0, 20.0, 30.0);
    inserir_sensibilidade_aceleracao(mpu1, 4);
    inserir_sensibilidade_rotacao(mpu1, 500);

    mpuTAD mpu2 = inicializar_mpu();
    inserir_aceleracao(mpu2, 4.0, 5.0, 6.0);
    inserir_rotacao(mpu2, 40.0, 50.0, 60.0);
    inserir_sensibilidade_aceleracao(mpu2, 2);
    inserir_sensibilidade_rotacao(mpu2, 1000);

    // Empilhando os MPUs
    printf("Empilhando mpu1...\n");
    empilhar(pilha, mpu1);

    printf("Empilhando mpu2...\n");
    empilhar(pilha, mpu2);

    // Verificando o tamanho da pilha
    printf("Tamanho atual da pilha: %d\n", tamanho_pilha(pilha));

    // Desempilhando um MPU e exibindo seus dados
    printf("Desempilhando um MPU...\n");
    mpuTAD mpuRemovido = desempilhar(pilha);
    if (mpuRemovido != NULL) {
        printf("Aceleração (X, Y, Z): %.2f, %.2f, %.2f\n",
               mpuRemovido->aceleracaoX,
               mpuRemovido->aceleracaoY,
               mpuRemovido->aceleracaoZ);
        printf("Rotação (X, Y, Z): %.2f, %.2f, %.2f\n",
               mpuRemovido->rotacaoX,
               mpuRemovido->rotacaoY,
               mpuRemovido->rotacaoZ);
        printf("Módulo da aceleração: %.2f\n", calcular_aceleracao(mpuRemovido));
        printf("Módulo da rotação: %.2f\n", calcular_rotacao(mpuRemovido));
        remover_mpu(&mpuRemovido);
    }

    // Verificando se a pilha está vazia
    printf("A pilha está vazia? %s\n", pilha_vazia(pilha) ? "Sim" : "Não");

    // Destruindo a pilha
    destruir_pilha(pilha);
    printf("Pilha destruída.\n");

    return 0;
}
