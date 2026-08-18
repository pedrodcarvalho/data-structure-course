/*
 * Vamos complicar um pouquinho, criando outras funções de Lista Linear
 * - Inserção de um Elemento da Lista (inserir no fim da lista)
 * - Remoção de um Elemento da Lista (retirar do fim da lista)
 * - Uma função que retorna a quantidade de números ímpares da lista
 * - Uma função que receba duas listas e retorne uma terceira lista que é a
 * união dessas duas listas (Não é permitido elementos repetidos na Lista União)
 */

#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
  int info;
  struct No *prox;
} No;

// Função auxiliar: busca de elemento (retorna 1 se existe, 0 caso contrário)
int buscar_elemento(No *lista, int valor)
{
  No *atual = lista;
  while (atual != NULL) {
    if (atual->info == valor) {
      return 1;
    }
    atual = atual->prox;
  }
  return 0;
}

// 1. Inserção de um elemento no fim da lista
No *inserir_fim(No *lista, int valor)
{
  No *novo = (No *)malloc(sizeof(No));
  if (novo == NULL) {
    printf("Erro de alocação de memória!\n");
    exit(1);
  }
  novo->info = valor;
  novo->prox = NULL;

  // Se a lista estiver vazia, o novo nó se torna o primeiro
  if (lista == NULL) {
    return novo;
  }

  // Percorre até o último nó
  No *atual = lista;
  while (atual->prox != NULL) {
    atual = atual->prox;
  }

  atual->prox = novo;
  return lista;
}

// 2. Remoção de um elemento do fim da lista
No *remover_fim(No *lista)
{
  if (lista == NULL) {
    printf("Aviso: A lista já está vazia.\n");
    return NULL;
  }

  // Caso com apenas um elemento
  if (lista->prox == NULL) {
    free(lista);
    return NULL;
  }

  // Percorre até o penúltimo nó
  No *atual = lista;
  while (atual->prox->prox != NULL) {
    atual = atual->prox;
  }

  // Libera o último nó e atualiza o ponteiro do penúltimo
  free(atual->prox);
  atual->prox = NULL;

  return lista;
}

// 3. Contagem de números ímpares na lista
int contar_impares(No *lista)
{
  int cont = 0;
  No *atual = lista;
  while (atual != NULL) {
    if (atual->info % 2 != 0) {
      cont++;
    }
    atual = atual->prox;
  }
  return cont;
}

// 4. União de duas listas (sem elementos repetidos na lista resultante)
No *unir_listas(No *l1, No *l2)
{
  No *l_uniao = NULL;

  // Insere elementos de L1 (garantindo sem duplicatas internas de L1)
  No *atual = l1;
  while (atual != NULL) {
    if (!buscar_elemento(l_uniao, atual->info)) {
      l_uniao = inserir_fim(l_uniao, atual->info);
    }
    atual = atual->prox;
  }

  // Insere elementos de L2 (evitando repetições já presentes em L1 ou L2)
  atual = l2;
  while (atual != NULL) {
    if (!buscar_elemento(l_uniao, atual->info)) {
      l_uniao = inserir_fim(l_uniao, atual->info);
    }
    atual = atual->prox;
  }

  return l_uniao;
}

// Funções auxiliares para teste e gerenciamento de memória
void imprimir_lista(No *lista)
{
  if (lista == NULL) {
    printf("Lista vazia.\n");
    return;
  }
  No *atual = lista;
  while (atual != NULL) {
    printf("%d -> ", atual->info);
    atual = atual->prox;
  }
  printf("NULL\n");
}

void liberar_lista(No *lista)
{
  No *atual = lista;
  while (atual != NULL) {
    No *temp = atual->prox;
    free(atual);
    atual = temp;
  }
}

int main()
{
  No *lista1 = NULL;
  No *lista2 = NULL;

  // Teste 1: Inserção no fim
  lista1 = inserir_fim(lista1, 10);
  lista1 = inserir_fim(lista1, 15);
  lista1 = inserir_fim(lista1, 20);
  lista1 = inserir_fim(lista1, 25);

  printf("Lista 1 (após inserções no fim):\n");
  imprimir_lista(lista1);

  // Teste 2: Contagem de ímpares
  printf("Quantidade de ímpares na Lista 1: %d\n", contar_impares(lista1));

  // Teste 3: Remoção do fim
  printf("\nRemovendo elemento do fim da Lista 1...\n");
  lista1 = remover_fim(lista1); // Remove o 25
  imprimir_lista(lista1);

  // Montando a Lista 2 para teste da União
  lista2 = inserir_fim(lista2, 15); // Repetido em relação à Lista 1
  lista2 = inserir_fim(lista2, 30);
  lista2 = inserir_fim(lista2, 10); // Repetido em relação à Lista 1
  lista2 = inserir_fim(lista2, 45);

  printf("\nLista 2:\n");
  imprimir_lista(lista2);

  // Teste 4: União sem repetição
  No *lista_resultado = unir_listas(lista1, lista2);
  printf("\nLista União (Lista 1 U Lista 2, sem duplicatas):\n");
  imprimir_lista(lista_resultado);

  // Liberação de memória
  liberar_lista(lista1);
  liberar_lista(lista2);
  liberar_lista(lista_resultado);

  return 0;
}
