/*
 * Receba a altura do degrau de uma escada e a altura
 * que o usuário deseja alcançar subindo a escada.
 * Calcule e mostre quantos degraus o usuário deverá
 * subir para atingir seu objetivo.
 */

#include <stdio.h>

int main(void)
{
  double altura_degrau, altura_desejada;
  int num_degraus;

  printf("Digite a altura do degrau (em metros): ");
  scanf("%lf", &altura_degrau);

  printf("Digite a altura que deseja alcançar (em metros): ");
  scanf("%lf", &altura_desejada);

  num_degraus = (int)(altura_desejada / altura_degrau);

  printf("Número de degraus a serem subidos: %d\n", num_degraus);

  return 0;
}
