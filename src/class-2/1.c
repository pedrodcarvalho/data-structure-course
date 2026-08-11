/*
 * Escreva um programa que calcule e imprima o valor de S
 * S = 1/3 + 2/5 + 3/7 + ... + 20/41
 */

#include <stdio.h>

int main(void)
{
  int i;
  double s = 0.0;

  for (i = 1; i <= 20; i++) {
    s += (double)i / (2 * i + 1);
  }

  printf("Valor de S: %.2f\n", s);

  return 0;
}
