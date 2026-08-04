/*
 * Leia uma velocidade em km/h (quilômetros por hora)
 * e apresente-a convertida em m/s (metros por segundo).
 * A fórmula de conversão é: M = K/3.6, sendo K a
 * velocidade em km/h e M em m/s.
 */

#include <stdio.h>

int main(void)
{
  double km_h, m_s;

  printf("Digite a velocidade em km/h: ");
  scanf("%lf", &km_h);

  m_s = km_h / 3.6;

  printf("Velocidade em m/s: %.2f\n", m_s);

  return 0;
}
