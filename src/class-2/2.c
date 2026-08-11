/*
 * Implemente um programa que determine se um inteiro e positivo dado pelo
 * usuário, é primo
 */

#include <stdio.h>

int main()
{
  int num, i, isPrime = 1;

  printf("Digite um numero inteiro positivo: ");
  scanf("%d", &num);

  if (num <= 1) {
    isPrime = 0;
  }
  else {
    for (i = 2; i <= num / 2; i++) {
      if (num % i == 0) {
        isPrime = 0;
        break;
      }
    }
  }

  if (isPrime) {
    printf("%d é um número primo.\n", num);
  }
  else {
    printf("%d não é um número primo.\n", num);
  }

  return 0;
}
