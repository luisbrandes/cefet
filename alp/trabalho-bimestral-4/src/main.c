/*
 * main.cåç
 *
 * Descrição:
 * Programa principal que utiliza a biblioteca de fila (fila.h e fila.c).
 * O programa carrega dados de "conteudo.txt", disponibiliza um menu com as
 * opções de enfileirar, desenfileirar, salvar e fechar.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "fila.h"
 
 // Função auxiliar para ler string do teclado com segurança
 void lerString(char *buffer, int tamanho) {
     // Lê uma linha, remove \n se existir, e garante fim de string
     if (fgets(buffer, tamanho, stdin) != NULL) {
         // Remove eventual \n
         buffer[strcspn(buffer, "\n")] = '\0';
     }
 }
 
 int main() {
     Fila minhaFila;
     inicializarFila(&minhaFila);
     
     // Carrega os dados iniciais de "conteudo.txt"
     lerDeArquivo(&minhaFila, "conteudo.txt");
     
     int opcao;
     do {
         printf("\n========== MENU ==========\n");
         printf("1. Enfileira (inserir novo no)\n");
         printf("2. Desenfileira (remover no da frente)\n");
         printf("3. Salvar em arquivo (conteudo.txt)\n");
         printf("4. Fechar (desenfileira todos e sai)\n");
         printf("==========================\n");
         printf("Escolha uma opcao: ");
         scanf("%d", &opcao);
         getchar(); // Consumir o '\n' que fica no buffer após scanf
         
         switch (opcao) {
             case 1: {
                 // Ler do teclado os dados para um novo nó e enfileirar
                 Amigo novoAmigo;
                 
                 printf("\nDigite o nome completo: ");
                 lerString(novoAmigo.nome, TAM_NOME);
                 
                 printf("Digite a idade: ");
                 scanf("%d", &novoAmigo.idade);
                 getchar(); // Consumir o '\n'
                 
                 printf("Digite o compromisso: ");
                 lerString(novoAmigo.compromisso, TAM_COMPROMISSO);
                 
                 printf("Digite o campo extra 1: ");
                 lerString(novoAmigo.campoExtra1, TAM_EXTRA);
                 
                 printf("Digite o campo extra 2: ");
                 lerString(novoAmigo.campoExtra2, TAM_EXTRA);
                 
                 enfileirar(&minhaFila, novoAmigo);
                 printf("\n>> Amigo enfileirado com sucesso!\n");
                 break;
             }
             
             case 2: {
                 // Desenfileira o nó da frente e imprime seu conteúdo
                 Amigo removido;
                 if (desenfileirar(&minhaFila, &removido)) {
                     printf("\n>> No desenfileirado com sucesso!\n");
                     printf("Nome: %s\n", removido.nome);
                     printf("Idade: %d\n", removido.idade);
                     printf("Compromisso: %s\n", removido.compromisso);
                     printf("Campo Extra 1: %s\n", removido.campoExtra1);
                     printf("Campo Extra 2: %s\n", removido.campoExtra2);
                 } else {
                     printf("\n>> Fila vazia! Nao foi possivel desenfileirar.\n");
                 }
                 break;
             }
             
             case 3: {
                 // Salvar o conteúdo da fila no arquivo "conteudo.txt"
                 salvarEmArquivo(&minhaFila, "conteudo.txt");
                 printf("\n>> Fila salva em conteudo.txt com sucesso!\n");
                 break;
             }
             
             case 4: {
                 // Desenfileira todos os nós, desaloca a fila e encerra
                 esvaziarFila(&minhaFila);
                 desalocarFila(&minhaFila);
                 printf("\n>> Fila esvaziada e desalocada. Encerrando...\n");
                 break;
             }
             
             default:
                 printf("\nOpcao invalida! Tente novamente.\n");
         }
         
     } while (opcao != 4);
     
     return 0;
 }
 