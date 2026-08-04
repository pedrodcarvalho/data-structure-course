/*
 * Elabore um programa que leia os parâmetros a, b
 * e c de uma equação quadrática e determine as
 * raízes desta equação.
 */

#include <math.h>
#include <stdio.h>

int main(void)
{
  double a, b, c, delta, x1, x2;

  printf("Digite o valor de a: ");
  scanf("%lf", &a);

  printf("Digite o valor de b: ");
  scanf("%lf", &b);

  printf("Digite o valor de c: ");
  scanf("%lf", &c);

  delta = b * b - 4 * a * c;

  if (delta < 0) {
    printf("A equação não possui raízes reais.\n");
  }
  else if (delta == 0) {
    x1 = -b / (2 * a);
    printf("A equação possui uma raiz real: x = %.2f\n", x1);
  }
  else {
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
    printf("A equação possui duas raízes reais: x1 = %.2f e x2 = %.2f\n", x1,
           x2);
  }

  return 0;
}
