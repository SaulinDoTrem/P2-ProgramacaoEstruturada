// Projeto para P2 De Programação Estrutura
//  Feito por Saulo Klein e Thaís Munier

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Struct para armazenar os dados de cada vendedor
struct Venda
{
  char codigoVendedor[20];
  char nomeVendedor[50];
  double valorVenda;
  int mes;
  int ano;
};

// Função para criar o arquivo de dados
void criarArquivo()
{
  FILE *fp;
  fp = fopen("vendas.dat", "w");
  if (fp == NULL)
  {
    printf("Erro ao criar o arquivo de dados.\n");
  }
  else
  {
    printf("Arquivo de dados criado com sucesso.\n");
  }
  fclose(fp);
}

// Função para ler os dados da struct do usuário
struct Venda recebeRegistro()
{
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

// Função para incluir um registro no arquivo
void incluirRegistro()
{
  FILE *fp;
  fp = fopen("vendas.dat", "ab");
  if (fp == NULL)
  {
    printf("Erro ao abrir o arquivo de dados.\n");
  }
  else
  {
    struct Venda registro = recebeRegistro();
    // Verifica se já existe um registro com o mesmo código de vendedor
    int found = 0;
    struct Venda r;
    fseek(fp, 0, SEEK_SET);
    while (fread(&r, sizeof(struct Venda), 1, fp))
    {
      if (strcmp(r.codigoVendedor, registro.codigoVendedor) == 0)
      {
        found = 1;
        break;
      }
    }
    if (found)
    {
      printf("Já existe um vendedor com este código.\n");
    }
    else
    {
      // Verifica onde o novo registro deve ser inserido
      fseek(fp, 0, SEEK_END);
      long pos = ftell(fp);
      fseek(fp, 0, SEEK_SET);
      while (fread(&r, sizeof(struct Venda), 1, fp))
      {
        if (strcmp(r.codigoVendedor, registro.codigoVendedor) > 0 ||
            (strcmp(r.codigoVendedor, registro.codigoVendedor) == 0 && r.ano > registro.ano) ||
            (strcmp(r.codigoVendedor, registro.codigoVendedor) == 0 && r.ano == registro.ano && r.mes > registro.mes))
        {
          pos = ftell(fp) - sizeof(struct Venda);
          break;
        }
      }
      // Insere o novo registro na posição encontrada
      fseek(fp, pos, SEEK_SET);
      fwrite(&registro, sizeof(struct Venda), 1, fp);
      printf("Registro incluido com sucesso.\n");
    }
  }
  fclose(fp);
}

void excluirVendedor()
{
}

void alterarValorVenda()
{
}

void consultarMaiorVenda()
{
}

void consultarMaiorVendaMesAno()
{
}

void somatorioVendasMesAno()
{
}

void somatorioVendasAno()
{
  // Abre o arquivo em modo de leitura binária
  FILE *fp;
  fp = fopen("vendas.dat", "rb");
  if (fp == NULL)
  {
    printf("Erro ao abrir o arquivo de dados.\n");
    return;
  }
  else
  {
    double total = 0;
    int ano = 0;

    // Recebe o ano desejado para a consulta
    printf("Digite o ano que deseja realizar o somatorio: ");
    scanf("%d", &ano);
    
    struct Venda registro;
    while (fread(&registro, sizeof(struct Venda), 1, fp))
    {
      if (registro.ano == ano)
      {
        total += registro.valorVenda;
      }
    }
    printf("\nSomatorio das vendas do ano %d: %.2lf\n", ano, total);
  }
  fclose(fp);
}

void imprimirRegistros()
{
  // Abre o arquivo em modo de leitura binária
  FILE *fp;
  fp = fopen("vendas.dat", "rb");
  if (fp == NULL)
  {
    printf("Erro ao abrir o arquivo de dados.\n");
  }
  else
  {
    struct Venda registro;
    // Lê cada registro do arquivo e exibe na tela
    while (fread(&registro, sizeof(struct Venda), 1, fp))
    {
      printf("Codigo do vendedor: %s\n", registro.codigoVendedor);
      printf("Nome do vendedor: %s\n", registro.nomeVendedor);
      printf("Valor da venda: R$ %.2f\n", registro.valorVenda);
      printf("Mes/Ano: %d/%d\n", registro.mes, registro.ano);
      printf("\n");
    }
  }
  fclose(fp);
}

void excluirArquivo()
{
  // Remove o arquivo
  if (remove("vendas.dat") == 0)
  {
    printf("Arquivo excluido com sucesso.\n");
  }
  else
  {
    printf("Erro ao excluir o arquivo.\n");
  }
}

int main()
{
  int opcao;

  while (1)
  {

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
    switch (opcao)
    {
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
