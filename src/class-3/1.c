/*
 * Construa, em C, um programa que contenha as seguintes funções de Lista
 * Encadeada:
 * - Inserção de um Elemento da Lista (inserir no início)
 * - Remoção de um Elemento da Lista (retirar do início)
 * - Impressão da Lista
 * - Busca de um elemento na Lista, retorna 1 se ele existe e 0 caso contrário
 * - Uma função que verifica se a lista está vazia, retorna 1 se ela estiver
 * vazia e 0 caso contrário
 * - Uma função que retorne a quantidade de elementos de uma lista (a lista é
 * passada por parâmetro).
 * - Uma função que some os elementos de uma lista que é passada por parâmetro
 */

#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
  int info;
  struct No *prox;
} No;

// 1. Verifica se a lista está vazia (retorna 1 se vazia, 0 caso contrário)
int esta_vazia(No *lista) { return (lista == NULL); }

// 2. Inserção de um elemento no início da lista
No *inserir_inicio(No *lista, int valor)
{
  No *novo = (No *)malloc(sizeof(No));
  if (novo == NULL) {
    printf("Erro de alocação de memória!\n");
    exit(1);
  }
  novo->info = valor;
  novo->prox = lista;
  return novo; // O novo nó passa a ser o primeiro
}

// 3. Remoção de um elemento do início da lista
No *remover_inicio(No *lista)
{
  if (esta_vazia(lista)) {
    printf("Aviso: A lista já está vazia.\n");
    return NULL;
  }
  No *temp = lista;
  lista = lista->prox;
  free(temp); // Libera o nó removido
  return lista;
}

// 4. Impressão dos elementos da lista
void imprimir_lista(No *lista)
{
  if (esta_vazia(lista)) {
    printf("Lista vazia.\n");
    return;
  }
  No *atual = lista;
  printf("Lista: ");
  while (atual != NULL) {
    printf("%d -> ", atual->info);
    atual = atual->prox;
  }
  printf("NULL\n");
}

// 5. Busca de um elemento (retorna 1 se existe, 0 caso contrário)
int buscar_elemento(No *lista, int valor)
{
  No *atual = lista;
  while (atual != NULL) {
    if (atual->info == valor) {
      return 1; // Encontrado
    }
    atual = atual->prox;
  }
  return 0; // Não encontrado
}

// 6. Retorna a quantidade de elementos da lista
int contar_elementos(No *lista)
{
  int cont = 0;
  No *atual = lista;
  while (atual != NULL) {
    cont++;
    atual = atual->prox;
  }
  return cont;
}

// 7. Retorna a soma dos elementos da lista
int somar_elementos(No *lista)
{
  int soma = 0;
  No *atual = lista;
  while (atual != NULL) {
    soma += atual->info;
    atual = atual->prox;
  }
  return soma;
}

// Função auxiliar para liberar a lista inteira da memória ao final
void liberar_lista(No *lista)
{
  No *atual = lista;
  while (atual != NULL) {
    No *proximo = atual->prox;
    free(atual);
    atual = proximo;
  }
}

int main()
{
  No *lista = NULL;

  printf("Lista criada. Está vazia? %d (1 = Sim, 0 = Não)\n",
         esta_vazia(lista));

  // Inserção no início: 10, depois 20, depois 30
  lista = inserir_inicio(lista, 10);
  lista = inserir_inicio(lista, 20);
  lista = inserir_inicio(lista, 30);

  printf("\nApós inserções no início:\n");
  imprimir_lista(lista); // Saída esperada: 30 -> 20 -> 10 -> NULL

  // Contagem e Soma
  printf("Quantidade de nós: %d\n", contar_elementos(lista));
  printf("Soma dos elementos: %d\n", somar_elementos(lista));

  // Busca
  printf("\nBusca pelo elemento 20: %d\n", buscar_elemento(lista, 20));
  printf("Busca pelo elemento 99: %d\n", buscar_elemento(lista, 99));

  // Remoção do início
  printf("\nRemovendo o primeiro elemento...\n");
  lista = remover_inicio(lista); // Remove o 30
  imprimir_lista(lista);

  printf("Nova quantidade: %d\n", contar_elementos(lista));
  printf("Nova soma: %d\n", somar_elementos(lista));

  // Limpeza de memória
  liberar_lista(lista);
  lista = NULL;

  return 0;
}
