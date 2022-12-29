//Projeto para P2 De Programação Estrutura
// Feito por Saulo Klein e Thaís Munier

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct para armazenar os dados de cada vendedor
struct Vendedor {
  char codigo[20];
  char nome[50];
  float valorVenda;
  int mes;
  int ano;
};

// Protótipos das funções
void criarArquivo();
void incluirRegistro();
void excluirVendedor();
void alterarValorVenda();
void consultarMaiorVenda();
void consultarMaiorVendaMesAno();
void somatorioVendasMesAno();
void somatorioVendasAno();
void imprimirRegistros();
void excluirArquivo();
void finalizarPrograma();

int main() {
  int opcao;

  // Menu de opções
  printf("Escolha uma opção:\n");
  printf("1 - Criar o arquivo de dados\n");
  printf("2 - Incluir um determinado registro no arquivo\n");
  printf("3 - Excluir um determinado vendedor no arquivo\n");
  printf("4 - Alterar o valor de uma venda no arquivo\n");
  printf("5 - Consultar a maior valor de venda registrado\n");
  printf("6 - Consultar o maior valor de venda registrado para um determinado mês/ano\n");
  printf("7 - Imprimir o somatório das vendas de um determinado mês/ano\n");
  printf("8 - Imprimir o somatório das vendas de um determinado ano\n");
  printf("9 - Imprimir os registros na saída padrão\n");
  printf("10 - Excluir o arquivo de dados\n");
  printf("11 - Finalizar o programa\n");
  scanf("%d", &opcao);

  // Executar a opção escolhida pelo usuário
  switch (opcao) {
    case 1:
      criarArquivo();
      break;
    case 2:
      incluirRegistro();
      break;
    case 3:
      excluirVendedor();
      break;
    case 4:
      alterarValorVenda();
      break;
    case 5:
      consultarMaiorVenda();
      break;
    case 6:
      consultarMaiorVendaMesAno();
      break;
    case 7:
      somatorioVendasMesAno();
      break;
    case 8:
      somatorioVendasAno();
      break;
    case 9:
      imprimirRegistros();
      break;
    case 10:
      excluirArquivo();
      break;
    default:
      printf("Opção Inválida");
      break;
  }
  return 0;
}

