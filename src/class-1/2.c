/*
 * - Leia a cotação do dólar
 * - Leia um valor em dólares
 * - Converta esse valor para real
 * - Mostre o resultado da conversão
 */

#include <stdio.h>

int main(void)
{
  double cotacao, valor_dolar, valor_real;

  printf("Digite a cotação do dólar: ");
  scanf("%lf", &cotacao);

  printf("Digite o valor em dólares: ");
  scanf("%lf", &valor_dolar);

  valor_real = valor_dolar * cotacao;

  printf("Valor em reais: R$ %.2f\n", valor_real);

  return 0;
}
