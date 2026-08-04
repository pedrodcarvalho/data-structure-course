/*
 * Faça um programa que leia um número inteiro positivo
 * de três dígitos (de 100 a 999). Gere outro número
 * formado pelos dígitos invertidos do número lido.
 * Exemplo:
 * Número lido: 123
 * Número gerado: 321
 */

#include <stdio.h>

int main(void)
{
  int numero, invertido;

  printf("Digite um número inteiro positivo de três dígitos (100 a 999): ");
  scanf("%d", &numero);

  if (numero < 100 || numero > 999) {
    printf("Número inválido! Por favor, digite um número entre 100 e 999.\n");
    return 1;
  }

  invertido = (numero % 10) * 100 + ((numero / 10) % 10) * 10 + (numero / 100);

  printf("Número lido: %d\n", numero);
  printf("Número gerado: %d\n", invertido);

  return 0;
}
