/*
 * Faça um algoritmo que leia uma matriz de no máximo 4
 * linhas e 4 colunas. O programa deverá:
 * - Elaborar a matriz transposta
 * - Trocar os valores da coluna 0 com a coluna 3
 * - Determinar quantos números pares tem essa matriz
 * - A soma dos valores da diagonal principal
 * - O maior valor da diagonal secundária
 * - Determine a soma de cada linha desta matriz, coloque o
 * resultado em um vetor
 * - Determine o maior valor de cada coluna dessa matriz,
 * coloque o resultado em um vetor
 * - A cada item, a matriz resultante deverá ser impressa
 */

#include <stdio.h>

int main()
{
  int matriz[4][4], transposta[4][4], i, j, linhas, colunas;
  int soma_diagonal_principal = 0, maior_diagonal_secundaria = 0;
  int soma_linhas[4] = {0}, maior_colunas[4] = {0};
  int contador_pares = 0;

  printf("Digite o número de linhas (max 4): ");
  scanf("%d", &linhas);
  printf("Digite o número de colunas (max 4): ");
  scanf("%d", &colunas);

  // Leitura da matriz
  printf("Digite os elementos da matriz:\n");
  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  // Elaborar a matriz transposta
  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      transposta[j][i] = matriz[i][j];
    }
  }

  // Trocar os valores da coluna 0 com a coluna 3
  for (i = 0; i < linhas; i++) {
    int temp = matriz[i][0];
    matriz[i][0] = matriz[i][3];
    matriz[i][3] = temp;
  }

  // Determinar quantos números pares tem essa matriz
  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      if (matriz[i][j] % 2 == 0) {
        contador_pares++;
      }
    }
  }
  // A soma dos valores da diagonal principal
  for (i = 0; i < linhas && i < colunas; i++) {
    soma_diagonal_principal += matriz[i][i];
  }

  // O maior valor da diagonal secundária
  for (i = 0; i < linhas && i < colunas; i++) {
    if (matriz[i][colunas - 1 - i] > maior_diagonal_secundaria) {
      maior_diagonal_secundaria = matriz[i][colunas - 1 - i];
    }
  }

  // Determine a soma de cada linha desta matriz, coloque o resultado em um
  // vetor
  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      soma_linhas[i] += matriz[i][j];
    }
  }

  // Determine o maior valor de cada coluna dessa matriz, coloque o resultado em
  // um vetor
  for (j = 0; j < colunas; j++) {
    for (i = 0; i < linhas; i++) {
      if (matriz[i][j] > maior_colunas[j]) {
        maior_colunas[j] = matriz[i][j];
      }
    }
  }

  // Impressão dos resultados
  printf("\nMatriz transposta:\n");
  for (i = 0; i < colunas; i++) {
    for (j = 0; j < linhas; j++) {
      printf("%d ", transposta[i][j]);
    }
    printf("\n");
  }

  printf("\nMatriz após trocar coluna 0 com coluna 3:\n");
  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  printf("\nQuantidade de números pares na matriz: %d\n", contador_pares);
  printf("Soma dos valores da diagonal principal: %d\n",
         soma_diagonal_principal);
  printf("Maior valor da diagonal secundária: %d\n", maior_diagonal_secundaria);
  printf("Soma de cada linha: ");
  for (i = 0; i < linhas; i++) {
    printf("%d ", soma_linhas[i]);
  }
  printf("\nMaior valor de cada coluna: ");
  for (j = 0; j < colunas; j++) {
    printf("%d ", maior_colunas[j]);
  }
  printf("\n");

  return 0;
}
