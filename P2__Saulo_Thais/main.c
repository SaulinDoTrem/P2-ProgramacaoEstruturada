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
  fp = fopen("vendas.dat", "w");
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

  printf("Digite o codigo do vendedor: ");
  scanf("%s", registro.codigoVendedor);

  printf("Digite o nome do vendedor: ");
  scanf("%s", registro.nomeVendedor);

  printf("Digite o valor da venda: ");
  scanf("%lf", &registro.valorVenda);

  printf("Digite o mes da venda: ");
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
  FILE *fp;
  fp = fopen("vendas.dat", "a");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo de dados.\n");
  } 
  else {
    // Procura a posição correta para inserir o novo registro
    struct Venda currRecord;
    struct Venda registro = recebeRegistro();
    int found = 0;
    while (fscanf(fp, "%s %s %lf %d %d", currRecord.codigoVendedor, currRecord.nomeVendedor, &currRecord.valorVenda, &currRecord.mes, &currRecord.ano) == 5) {
      if (strcmp(registro.codigoVendedor, currRecord.codigoVendedor) < 0 || (strcmp(registro.codigoVendedor, currRecord.codigoVendedor) == 0 && registro.ano < currRecord.ano) || (strcmp(registro.codigoVendedor, currRecord.codigoVendedor) == 0 && registro.ano == currRecord.ano && registro.mes < currRecord.mes)) {
        found = 1;
        break;
      }
    }
    if (found) {
      // Insere o novo registro na posição encontrada
      fprintf(fp, "\n%s %s %.2lf %d %d", registro.codigoVendedor, registro.nomeVendedor, registro.valorVenda, registro.mes, registro.ano);
    } else {
      // Insere o novo registro no final do arquivo
      fprintf(fp, "\n%s %s %.2lf %d %d", registro.codigoVendedor, registro.nomeVendedor, registro.valorVenda, registro.mes, registro.ano);
    }
    printf("Registro incluído com sucesso.\n");
  }
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

    // Menu de opcoes
    printf("\n\n--------------------------------------------------------------------------------\n\n");
    printf("Selecione uma opcao:\n");
    printf("1 - Criar o arquivo de dados\n");
    printf("2 - Incluir um determinado registro no arquivo\n");
    printf("3 - Excluir um determinado vendedor no arquivo\n");
    printf("4 - Alterar o valor de uma venda no arquivo\n");
    printf("5 - Consultar a maior valor de venda registrado\n");
    printf("6 - Consultar o maior valor de venda registrado para um determinado mes/ano\n");
    printf("7 - Imprimir o somatario das vendas de um determinado mes/ano\n");
    printf("8 - Imprimir o somatario das vendas de um determinado ano\n");
    printf("9 - Imprimir os registros na saida padrao\n");
    printf("10 - Excluir o arquivo de dados\n");
    printf("11 - Finalizar o programa\n\n");
    scanf("%d", &opcao);
    printf("\n--------------------------------------------------------------------------------\n\n");

    // Executar a opcao escolhida pelo usuario
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
        printf("Opcao Invalida");
        break;
    }
  }

  return 0;
}

