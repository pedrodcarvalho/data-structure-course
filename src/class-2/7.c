/*
 * Elabore um programa que crie uma estrutura com as seguintes
 * informações de um produto:
 * - Código do produto – inteiro de 3 dígitos
 * - Quantidade em estoque - inteiro
 * - Valor de compra - real
 * - Valor de Venda - real
 * O programa deverá ler a informação de 10 produtos e
 * determinar
 * - O código do produto com maior quantidade de estoque
 * - O quantidade de estoque do produto que proporciona o
 * maior lucro
 */

#include <stdio.h>
#define MAX_PRODUTOS 10

typedef struct {
  int codigo;
  int quantidade;
  float valor_compra;
  float valor_venda;
} Produto;

int main()
{
  Produto produtos[MAX_PRODUTOS];
  int i;
  for (i = 0; i < MAX_PRODUTOS; i++) {
    printf("Digite o código do produto %d: ", i + 1);
    scanf("%d", &produtos[i].codigo);
    printf("Digite a quantidade em estoque do produto %d: ", i + 1);
    scanf("%d", &produtos[i].quantidade);
    printf("Digite o valor de compra do produto %d: ", i + 1);
    scanf("%f", &produtos[i].valor_compra);
    printf("Digite o valor de venda do produto %d: ", i + 1);
    scanf("%f", &produtos[i].valor_venda);
  }

  int codigo_maior_estoque = produtos[0].codigo;
  int maior_estoque = produtos[0].quantidade;
  float maior_lucro = (produtos[0].valor_venda - produtos[0].valor_compra) *
                      produtos[0].quantidade;
  int codigo_maior_lucro = produtos[0].codigo;

  for (i = 1; i < MAX_PRODUTOS; i++) {
    if (produtos[i].quantidade > maior_estoque) {
      maior_estoque = produtos[i].quantidade;
      codigo_maior_estoque = produtos[i].codigo;
    }
    float lucro_atual = (produtos[i].valor_venda - produtos[i].valor_compra) *
                        produtos[i].quantidade;
    if (lucro_atual > maior_lucro) {
      maior_lucro = lucro_atual;
      codigo_maior_lucro = produtos[i].codigo;
    }
  }

  printf("Código do produto com maior quantidade em estoque: %d\n",
         codigo_maior_estoque);
  printf("Código do produto que proporciona o maior lucro: %d\n",
         codigo_maior_lucro);

  return 0;
}
