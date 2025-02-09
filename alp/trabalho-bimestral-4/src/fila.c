/*
 * fila.c
 *
 * Descrição:
 * Implementação das funções de uma fila encadeada para armazenar dados de amigos e compromissos.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "fila.h"
 
 // Inicializa a fila, definindo ponteiros de frente e fundo como NULL
 void inicializarFila(Fila *f) {
     f->frente = NULL;
     f->fundo = NULL;
 }
 
 // Verifica se a fila está vazia
 int filaVazia(Fila *f) {
     return (f->frente == NULL);
 }
 
 // Enfileira (insere no fundo da fila)
 void enfileirar(Fila *f, Amigo dado) {
     // Aloca memória para um novo nó
     No *novo = (No *) malloc(sizeof(No));
     if (novo == NULL) {
         printf("Erro de alocacao de memoria.\n");
         return;
     }
     
     // Atribui os dados ao novo nó
     novo->dado = dado;
     novo->proximo = NULL;
     
     // Se a fila estiver vazia, frente e fundo apontam para o novo nó
     if (filaVazia(f)) {
         f->frente = novo;
         f->fundo = novo;
     } else {
         // Caso contrário, insere após o fundo e atualiza o fundo
         f->fundo->proximo = novo;
         f->fundo = novo;
     }
 }
 
 // Desenfileira (remove do início da fila)
 int desenfileirar(Fila *f, Amigo *removido) {
     if (filaVazia(f)) {
         return 0; // Falha, fila vazia
     }
     
     No *aux = f->frente;           // Nó a ser removido
     *removido = aux->dado;         // Copia os dados do nó removido
     f->frente = aux->proximo;      // Avança o ponteiro frente
     
     // Se a fila ficou vazia, fundo também deve ser NULL
     if (f->frente == NULL) {
         f->fundo = NULL;
     }
     
     free(aux); // Libera a memória do nó removido
     return 1;  // Remoção bem-sucedida
 }
 
 // Imprime os dados de todos os nós da fila
 void imprimirFila(Fila *f) {
     if (filaVazia(f)) {
         printf("\nA fila esta vazia!\n");
         return;
     }
     
     printf("\n== Conteudo da Fila ==\n");
     No *aux = f->frente;
     int pos = 1;
     while (aux != NULL) {
         printf("No %d:\n", pos);
         printf("  Nome: %s\n", aux->dado.nome);
         printf("  Idade: %d\n", aux->dado.idade);
         printf("  Compromisso: %s\n", aux->dado.compromisso);
         printf("  Campo Extra 1: %s\n", aux->dado.campoExtra1);
         printf("  Campo Extra 2: %s\n", aux->dado.campoExtra2);
         printf("-------------------------\n");
         
         aux = aux->proximo;
         pos++;
     }
 }
 
 // Esvazia completamente a fila, removendo todos os nós
 void esvaziarFila(Fila *f) {
     Amigo aux;
     while (!filaVazia(f)) {
         desenfileirar(f, &aux);
     }
 }
 
 // Desaloca completamente a fila
 void desalocarFila(Fila *f) {
     esvaziarFila(f);
     // Após esvaziar, o frente e fundo devem ser NULL
     f->frente = NULL;
     f->fundo = NULL;
 }
 
 // Lê dados de um arquivo texto (campos separados por vírgula) e enfileira cada linha
 void lerDeArquivo(Fila *f, const char *nomeArquivo) {
     FILE *fp = fopen(nomeArquivo, "r");
     if (fp == NULL) {
         printf("Nao foi possivel abrir o arquivo %s para leitura.\n", nomeArquivo);
         return;
     }
     
     char linha[256];
     
     while (fgets(linha, sizeof(linha), fp) != NULL) {
         // Remove quebra de linha (\n) se existir
         linha[strcspn(linha, "\n")] = '\0';
         
         // Quebrando a linha em tokens separados por vírgula
         // Esperamos: nome, idade, compromisso, extra1, extra2
         Amigo temp;
         char *token;
         
         token = strtok(linha, ",");
         if (token == NULL) continue;
         strncpy(temp.nome, token, TAM_NOME);
         temp.nome[TAM_NOME - 1] = '\0'; // Garantir fim de string
         
         token = strtok(NULL, ",");
         if (token == NULL) continue;
         temp.idade = atoi(token);
         
         token = strtok(NULL, ",");
         if (token == NULL) continue;
         strncpy(temp.compromisso, token, TAM_COMPROMISSO);
         temp.compromisso[TAM_COMPROMISSO - 1] = '\0';
         
         // Campo extra 1
         token = strtok(NULL, ",");
         if (token == NULL) continue;
         strncpy(temp.campoExtra1, token, TAM_EXTRA);
         temp.campoExtra1[TAM_EXTRA - 1] = '\0';
         
         // Campo extra 2
         token = strtok(NULL, ",");
         if (token == NULL) continue;
         strncpy(temp.campoExtra2, token, TAM_EXTRA);
         temp.campoExtra2[TAM_EXTRA - 1] = '\0';
         
         // Insere na fila
         enfileirar(f, temp);
     }
     
     fclose(fp);
 }
 
 // Salva o conteúdo da fila em um arquivo texto (separando os campos com vírgula)
 void salvarEmArquivo(Fila *f, const char *nomeArquivo) {
     FILE *fp = fopen(nomeArquivo, "w");
     if (fp == NULL) {
         printf("Nao foi possivel abrir o arquivo %s para escrita.\n", nomeArquivo);
         return;
     }
     
     No *aux = f->frente;
     while (aux != NULL) {
         fprintf(fp, "%s,%d,%s,%s,%s\n",
                 aux->dado.nome,
                 aux->dado.idade,
                 aux->dado.compromisso,
                 aux->dado.campoExtra1,
                 aux->dado.campoExtra2);
         
         aux = aux->proximo;
     }
     
     fclose(fp);
 }
 