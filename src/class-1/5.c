/*
 * Faça um programa para ler as dimensões de um
 * terreno (comprimento c e largura l), bem como o preço
 * do metro de tela p. Imprima o custo para cercar este
 * mesmo terreno com tela.
 */

#include <stdio.h>

int main(void)
{
  double comprimento, largura, preco_metro, custo_total;

  printf("Digite o comprimento do terreno (em metros): ");
  scanf("%lf", &comprimento);

  printf("Digite a largura do terreno (em metros): ");
  scanf("%lf", &largura);

  printf("Digite o preço do metro de tela: ");
  scanf("%lf", &preco_metro);

  custo_total = 2 * (comprimento + largura) * preco_metro;

  printf("Custo total para cercar o terreno: R$ %.2f\n", custo_total);

  return 0;
}
