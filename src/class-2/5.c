/*
 * Fazer um programa que faz a leitura de um vetor X, com N
 * inteiros, com tamanho máximo igual a 20 e N deverá ser
 * lido. Gera um segundo vetor com os valores de vetor lido
 * em ordem inversa. Imprimir o vetor lido e vetor com a
 * ordem inversa. Construir da maneira mais eficiente possível
 * Ex:
 * Vetor lido: 12, 13, 34, -5, 65, 34, 10, 1, -48
 * Vetor invertido: -48, 1, 10, 34, 65, -5, 34, 13, 12
 */

#include <stdio.h>

int main(void)
{
  int vetor[20], vetorInvertido[20], n, i;

  printf("Digite o tamanho do vetor (max 20): ");
  scanf("%d", &n);

  if (n > 20 || n <= 0) {
    printf("Tamanho inválido. O tamanho deve ser entre 1 e 20.\n");
    return 1;
  }

  for (i = 0; i < n; i++) {
    printf("Digite o %dº número inteiro: ", i + 1);
    scanf("%d", &vetor[i]);
    vetorInvertido[n - 1 - i] = vetor[i];
  }

  printf("Vetor lido: ");
  for (i = 0; i < n; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  printf("Vetor invertido: ");
  for (i = 0; i < n; i++) {
    printf("%d ", vetorInvertido[i]);
  }
  printf("\n");

  return 0;
}
