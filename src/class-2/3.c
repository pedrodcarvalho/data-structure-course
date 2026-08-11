/*
 * Ler um vetor de inteiros 10 posições. Escrever a seguir o valor e a
 * posição do maior e menor elementos lidos. Construa da maneira mais
 * eficiente possível
 */

#include <stdio.h>

int main(void)
{
  int vetor[10], i, maior, menor, posMaior, posMenor;

  for (i = 0; i < 10; i++) {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &vetor[i]);
  }

  maior = menor = vetor[0];
  posMaior = posMenor = 0;

  for (i = 1; i < 10; i++) {
    if (vetor[i] > maior) {
      maior = vetor[i];
      posMaior = i;
    }
    if (vetor[i] < menor) {
      menor = vetor[i];
      posMenor = i;
    }
  }

  printf("Maior elemento: %d na posição %d\n", maior, posMaior);
  printf("Menor elemento: %d na posição %d\n", menor, posMenor);

  return 0;
}
