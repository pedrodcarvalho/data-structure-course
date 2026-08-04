/*
 * Leia 3 números reais A, B e C e exiba-os em ordem
 * crescente
 */

#include <stdio.h>

int main(void)
{
  double A, B, C, temp;

  printf("Digite o valor de A: ");
  scanf("%lf", &A);

  printf("Digite o valor de B: ");
  scanf("%lf", &B);

  printf("Digite o valor de C: ");
  scanf("%lf", &C);

  // Sort using bubble sort-like comparisons
  if (A > B) {
    temp = A;
    A = B;
    B = temp;
  }
  if (A > C) {
    temp = A;
    A = C;
    C = temp;
  }
  if (B > C) {
    temp = B;
    B = C;
    C = temp;
  }

  printf("Números em ordem crescente: %.2f, %.2f, %.2f\n", A, B, C);

  return 0;
}
