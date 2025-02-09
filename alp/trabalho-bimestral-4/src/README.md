# Algoritmos e Lógica de Programação - Trabalho Bimestral 4

Este repositório contém um exemplo de implementação de **Fila Encadeada em C** abordando operações de enfileirar, desenfileirar, impressão, leitura e escrita de arquivos, seguindo o padrão FIFO (*First In, First Out*).

## Estrutura de Diretórios

- **fila.h**: Arquivo de cabeçalho com as definições de tipos e protótipos das funções da fila.  
- **fila.c**: Implementação das funções da fila (enfileirar, desenfileirar, testar se vazia, etc.).  
- **main.c**: Programa principal que interage com o usuário via menu e utiliza a biblioteca da fila.  
- **conteudo.txt**: Arquivo com dados iniciais para popular a fila ao iniciar o programa, sendo cada linha um registro (nó).  
- **README.md**: Este arquivo de documentação.

## Descrição da Fila Encadeada

Uma fila é uma estrutura de dados do tipo FIFO (*First In, First Out*), onde:  
- **Enfileirar** (inserir) ocorre somente no final (fundo) da fila.  
- **Desenfileirar** (remover) ocorre no início (frente) da fila.

### Operações Implementadas

1. **inicializarFila**: Configura a fila para o estado vazio.  
2. **filaVazia**: Verifica se a fila está vazia.  
3. **enfileirar**: Insere um novo nó na parte de trás (fundo) da fila.  
4. **desenfileirar**: Remove o nó da frente da fila.  
5. **imprimirFila**: Exibe todos os elementos da fila.  
6. **esvaziarFila**: Remove todos os elementos.  
7. **desalocarFila**: Libera a memória utilizada pela fila.  
8. **lerDeArquivo**: Lê registros (um por linha) de um arquivo de texto e enfileira cada um deles.  
9. **salvarEmArquivo**: Salva todos os nós da fila em um arquivo de texto (um nó por linha).

## compilar e Executar

Para compilar no terminal (ou prompt) dentro do diretório:

```bash
gcc *.c -g -Wall -o programa


