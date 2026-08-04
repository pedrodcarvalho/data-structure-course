/*
 * Crie um algoritmo que leia dois valores (x e y)
 * representando um intervalo. Em seguida, leia um novo
 * valor (z) e verifique se z pertence ao intervalo [x, y]
 */

#include <stdio.h>

int main(void)
{
  double x, y, z;

  printf("Digite o valor de x (início do intervalo): ");
  scanf("%lf", &x);

  printf("Digite o valor de y (fim do intervalo): ");
  scanf("%lf", &y);

  printf("Digite o valor de z: ");
  scanf("%lf", &z);

  if (z >= x && z <= y) {
    printf("O valor %.2f pertence ao intervalo [%.2f, %.2f].\n", z, x, y);
  }
  else {
    printf("O valor %.2f não pertence ao intervalo [%.2f, %.2f].\n", z, x, y);
  }

  return 0;
}
