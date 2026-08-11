/*
 * Fazer um programa em C para ler um vetor de inteiros positivos de
 * 15 posições, no máximo. O programa deverá imprimir a média dos
 * números lidos e a porcentagem de valores existentes no vetor
 * maior que a média
 */

#include <stdio.h>

int main(void)
{
  int vetor[15], i, count = 0;
  double soma = 0.0, media, porcentagem;

  for (i = 0; i < 15; i++) {
    printf("Digite o %dº número inteiro positivo: ", i + 1);
    scanf("%d", &vetor[i]);
    soma += vetor[i];
  }

  media = soma / 15;

  for (i = 0; i < 15; i++) {
    if (vetor[i] > media) {
      count++;
    }
  }

  porcentagem = ((double)count / 15) * 100;

  printf("Média dos números lidos: %.2f\n", media);
  printf("Porcentagem de valores maiores que a média: %.2f%%\n", porcentagem);

  return 0;
}
