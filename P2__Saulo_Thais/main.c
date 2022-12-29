//Projeto para P2 De Programa��o Estrutura
// Feito por Saulo Klein e Tha�s Munier

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

// Fun��o para criar o arquivo de dados
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

// Fun��o para ler os dados da struct do usu�rio
struct Venda recebeRegistro() {
  struct Venda registro;

  printf("Digite o c�digo do vendedor: ");
  scanf("%s", registro.codigoVendedor);

  printf("Digite o nome do vendedor: ");
  scanf("%s", registro.nomeVendedor);

  printf("Digite o valor da venda: ");
  scanf("%lf", &registro.valorVenda);

  printf("Digite o m�s da venda: ");
  scanf("%d", &registro.mes);

  printf("Digite o ano da venda: ");
  scanf("%d", &registro.ano);

  return registro;
}

// Fun��o de compara��o para ordenar os registros pelo c�digo do vendedor e m�s/ano
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

// Fun��o para incluir um registro no arquivo
void incluirRegistro() {
  // Abre o arquivo em modo de leitura bin�ria
  FILE *fp;
  fp = fopen("vendas.txt", "rb");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo de dados.\n");
    return;
  }
  // L� todos os registros do arquivo e os armazena em um vetor
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
  // Abre o arquivo em modo de escrita bin�ria
  fp = fopen("vendas.txt", "wb");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo de dados.\n");
    return;
  }
  // Escreve os registros ordenados no arquivo
  for (int i = 0; i < numRegistros; i++) {
    fwrite(&registros[i], sizeof(struct Venda), 1, fp);
  }
  printf("Registro inclu�do com sucesso.\n");
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

    // Menu de op��es
    printf("\n\n--------------------------------------------------------------------------------\n\n");
    printf("Selecione uma op��o:\n",setlocale(LC_ALL,""));
    printf("1 - Criar o arquivo de dados\n");
    printf("2 - Incluir um determinado registro no arquivo\n");
    printf("3 - Excluir um determinado vendedor no arquivo\n");
    printf("4 - Alterar o valor de uma venda no arquivo\n");
    printf("5 - Consultar a maior valor de venda registrado\n");
    printf("6 - Consultar o maior valor de venda registrado para um determinado m�s/ano\n");
    printf("7 - Imprimir o somat�rio das vendas de um determinado m�s/ano\n");
    printf("8 - Imprimir o somat�rio das vendas de um determinado ano\n");
    printf("9 - Imprimir os registros na sa�da padr�o\n");
    printf("10 - Excluir o arquivo de dados\n");
    printf("11 - Finalizar o programa\n\n");
    scanf("%d", &opcao);
    printf("\n--------------------------------------------------------------------------------\n\n");

    // Executar a op��o escolhida pelo usu�rio
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
        printf("Op��o Inv�lida");
        break;
    }
  }

  return 0;
}

