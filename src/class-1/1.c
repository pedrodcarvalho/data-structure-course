/*
 * Uma empresa contrata um encanador a R$ 30,00 por
 * dia. Faça um programa que solicite o número de dias
 * trabalhados pelo encanador e imprima a quantia
 * líquida que deverá ser paga, sabendo-se que são
 * descontados 8% para imposto de renda.
 */

#include <stdio.h>

int main(void)
{
  int dias;
  double salario, imposto, salario_liquido;

  printf("Digite o número de dias trabalhados: ");
  scanf("%d", &dias);

  salario = dias * 30.0;
  imposto = salario * 0.08;
  salario_liquido = salario - imposto;

  printf("Salário líquido: R$ %.2f\n", salario_liquido);

  return 0;
}
