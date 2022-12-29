//Projeto para P2 De Programação Estrutura
// Feito por Saulo Klein e Thaís Munier

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Struct para armazenar os dados de cada vendedor
struct Venda {
  char codigoVendedor[20];
  char nomeVendedor[50];
  float valorVenda;
  int mes;
  int ano;
};

// Função para criar o arquivo de dados
void criarArquivo() {
  FILE *fp;
  fp = fopen("vendas.txt", "wb");
  if (fp == NULL) {
    printf("Erro ao criar o arquivo de dados.\n");
  } else {
    printf("Arquivo de dados criado com sucesso.\n");
  }
  fclose(fp);
}

// Função para ler os dados da struct do usuário
struct Venda recebeRegistro() {
  struct Venda registro;

  printf("Digite o código do vendedor: ");
  scanf("%s", registro.codigoVendedor);

  printf("Digite o nome do vendedor: ");
  scanf("%s", registro.nomeVendedor);

  printf("Digite o valor da venda: ");
  scanf("%lf", &registro.valorVenda);

  printf("Digite o mês da venda: ");
  scanf("%d", &registro.mes);

  printf("Digite o ano da venda: ");
  scanf("%d", &registro.ano);

  return registro;
}

// Função de comparação para ordenar os registros pelo código do vendedor e mês/ano
int compararRegistros(const void *a, const void *b) {
  struct Venda *registroA = (struct Venda *) a;
  struct Venda *registroB = (struct Venda *) b;
  int codVendedor = strcmp(registroA->codigoVendedor, registroB->codigoVendedor);
  if (codVendedor != 0) {
    return codVendedor;
  }
  if (registroA->ano != registroB->ano) {
    return registroA->ano - registroB->ano;
  }
  return registroA->mes - registroB->mes;
}

// Função para incluir um registro no arquivo
void incluirRegistro() {
  // Abre o arquivo em modo de leitura binária
  FILE *fp;
  fp = fopen("vendas.txt", "rb");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo de dados.\n");
    return;
  }
  // Lê todos os registros do arquivo e os armazena em um vetor
  struct Venda registros[100];
  int numRegistros = 0;
  while (fread(&registros[numRegistros], sizeof(struct Venda), 1, fp)) {
    numRegistros++;
  }
  fclose(fp);
  // Adiciona o novo registro no vetor
  registros[numRegistros] = recebeRegistro();
  numRegistros++;
  // Ordena o vetor de registros
  qsort(registros, numRegistros, sizeof(struct Venda), compararRegistros);
  // Abre o arquivo em modo de escrita binária
  fp = fopen("vendas.txt", "wb");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo de dados.\n");
    return;
  }
  // Escreve os registros ordenados no arquivo
  for (int i = 0; i < numRegistros; i++) {
    fwrite(&registros[i], sizeof(struct Venda), 1, fp);
  }
  printf("Registro incluído com sucesso.\n");
  fclose(fp);
}

void excluirVendedor() {
}

void alterarValorVenda() {
}

void consultarMaiorVenda() {
}

void consultarMaiorVendaMesAno() {
}

void somatorioVendasMesAno() {
}

void somatorioVendasAno() {
}

void imprimirRegistros() {
}

void excluirArquivo() {
}

void finalizarPrograma() {
}

int main() {
  int opcao;

  while (1) {

    // Menu de opções
    printf("\n\n--------------------------------------------------------------------------------\n\n");
    printf("Selecione uma opção:\n",setlocale(LC_ALL,""));
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
    printf("11 - Finalizar o programa\n\n");
    scanf("%d", &opcao);
    printf("\n--------------------------------------------------------------------------------\n\n");

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
      case 11:
        return 0;
      default:
        printf("Opção Inválida");
        break;
    }
  }

  return 0;
}

