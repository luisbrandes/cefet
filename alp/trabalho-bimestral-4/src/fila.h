/* 
 * fila.h
 * 
 * Descrição:
 * Cabeçalho da biblioteca que implementa uma fila encadeada
 * para armazenar dados de amigos e compromissos.
 */

 #ifndef FILA_H
 #define FILA_H
 
 // Definindo constantes para tamanho dos campos
 #define TAM_NOME 50
 #define TAM_COMPROMISSO 100
 #define TAM_EXTRA 50
 
 // Estrutura que representa os dados de cada amigo
 typedef struct {
     char nome[TAM_NOME];
     int idade;
     char compromisso[TAM_COMPROMISSO];
     char campoExtra1[TAM_EXTRA];
     char campoExtra2[TAM_EXTRA];
 } Amigo;
 
 // Nó da fila, contendo os dados e o ponteiro para o próximo nó
 typedef struct No {
     Amigo dado;
     struct No *proximo;
 } No;
 
 // Estrutura da fila, com ponteiros para o início (frente) e fim (traseira)
 typedef struct {
     No *frente;  
     No *fundo;   
 } Fila;
 
 /**
  * @brief Inicializa a fila, definindo ponteiros de frente e fundo como NULL.
  * @param f Ponteiro para a estrutura da fila.
  */
 void inicializarFila(Fila *f);
 
 /**
  * @brief Verifica se a fila está vazia.
  * @param f Ponteiro para a fila.
  * @return 1 se vazia, 0 caso contrário.
  */
 int filaVazia(Fila *f);
 
 /**
  * @brief Insere um novo nó ao final da fila.
  * @param f Ponteiro para a fila.
  * @param dado Estrutura do tipo Amigo com as informações a serem enfileiradas.
  */
 void enfileirar(Fila *f, Amigo dado);
 
 /**
  * @brief Remove o nó do início da fila.
  * @param f Ponteiro para a fila.
  * @param removido Ponteiro para uma variável Amigo onde será armazenado o nó removido.
  * @return 1 se a remoção foi bem-sucedida, 0 se a fila estava vazia.
  */
 int desenfileirar(Fila *f, Amigo *removido);
 
 /**
  * @brief Imprime o conteúdo de todos os nós da fila, do início ao fim.
  * @param f Ponteiro para a fila.
  */
 void imprimirFila(Fila *f);
 
 /**
  * @brief Remove todos os nós da fila (esvaziando-a).
  * @param f Ponteiro para a fila.
  */
 void esvaziarFila(Fila *f);
 
 /**
  * @brief Remove todos os nós e desaloca a memória utilizada pela fila.
  * @param f Ponteiro para a fila.
  */
 void desalocarFila(Fila *f);
 
 /**
  * @brief Lê dados de um arquivo texto (separados por vírgula) e enfileira cada linha.
  * @param f Ponteiro para a fila.
  * @param nomeArquivo Nome do arquivo texto (ex: "conteudo.txt").
  */
 void lerDeArquivo(Fila *f, const char *nomeArquivo);
 
 /**
  * @brief Salva o conteúdo da fila em um arquivo texto, cada nó em uma linha, com campos separados por vírgula.
  * @param f Ponteiro para a fila.
  * @param nomeArquivo Nome do arquivo texto (ex: "conteudo.txt").
  */
 void salvarEmArquivo(Fila *f, const char *nomeArquivo);
 
 #endif
 