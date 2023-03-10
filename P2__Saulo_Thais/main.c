// Projeto para P2 De Programação Estrutura
//  Feito por Saulo Klein e Thaís Munier

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_CODE_LEN 10
#define MAX_NAME_LEN 50
#define FILE_NAME "vendas.dat"

struct Venda
{
  char codigoVendedor[MAX_CODE_LEN];
  char nomeVendedor[MAX_NAME_LEN];
  double valorVenda;
  int mes;
  int ano;
};

void criarArquivo()
{
  FILE *fp;
  fp = fopen(FILE_NAME, "w");
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

void incluirRegistro()
{
  int found = 0;
  FILE *fp;
  fp = fopen(FILE_NAME, "r+b");
  if (fp == NULL)
  {
    printf("Erro ao abrir o arquivo de dados.\n");
  }
  else {
    struct Venda registro = recebeRegistro();
    struct Venda r;
    fseek(fp, 0, SEEK_SET);
    while (fread(&r, sizeof(struct Venda), 1, fp))
    {
      if (strcmp(r.codigoVendedor, registro.codigoVendedor) == 0 && strcmp(r.nomeVendedor, registro.nomeVendedor) != 0)
      {
        found = 1;
        break;
      }
    }
    if(found == 1) {
        printf("Ja existe um vendedor com este codigo.\n");
    }
    else {
      fwrite(&registro, sizeof(struct Venda), 1, fp);
      printf("Registro incluido com sucesso.\n");
    }
  }
      
  fclose(fp);
}

void excluirVendedor()
{
  FILE *fp = fopen(FILE_NAME, "r+b");

  if (fp == NULL) {
    printf("Erro ao abir o arquivo de dados.\n");
    return;
  }

  FILE *fpCopy = fopen("vendas-copy.dat", "wb");

  struct Venda registro;
  char codigo[MAX_CODE_LEN];
  int counter = 0;
  int found = 0;

  printf("Digite o codigo do vendedor que deseja excluir do arquivo\nObs: Todos os registros que possuem esse vendedor serao apagados tambem:");
  scanf("%s", codigo);

  while(fread(&registro, sizeof(struct Venda), 1, fp)) {
    if(strcmp(registro.codigoVendedor, codigo) == 0) {
      found = 1;
      counter++;
    }
    else fwrite(&registro, sizeof(struct Venda), 1, fpCopy);
  }

  if(found == 1) {
    printf("O vendedor foi excluído com sucesso, %d registros foram afetados.\n", counter);
  }

  fclose(fp);
  fclose(fpCopy);
  remove(FILE_NAME);
  rename("vendas-copy.dat", FILE_NAME);
}

void alterarValorVenda()
{
  FILE *fp = fopen(FILE_NAME, "r+b");

  if (fp == NULL) {
    printf("Erro ao abir o arquivo de dados.\n");
    return;
  }

  FILE *fpCopy = fopen("vendas-copy.dat", "wb");

  struct Venda registro;
  struct Venda newRegistro;
  double valorVenda;
  int found = 0;


  printf("A seguir digite os dados antigos da venda realizada que deseja alterar:\n");
  printf("Digite o codigo do vendedor:");
  scanf("%s", newRegistro.codigoVendedor);
  printf("Digite o nome do vendedor:");
  scanf("%s", newRegistro.nomeVendedor);
  printf("Digite o valor da venda:");
  scanf("%lf", &valorVenda);
  printf("Digite o mes:");
  scanf("%d", &newRegistro.mes);
  printf("Digite o ano:");
  scanf("%d", &newRegistro.ano);
  printf("Digite o novo valor da venda:");
  scanf("%lf", &newRegistro.valorVenda);

  while(fread(&registro, sizeof(struct Venda), 1, fp)) {
    if(strcmp(registro.codigoVendedor, newRegistro.codigoVendedor) == 0 && registro.ano == newRegistro.ano && registro.mes == newRegistro.mes && registro.valorVenda == valorVenda) {
      fwrite(&newRegistro, sizeof(struct Venda), 1, fpCopy);
      printf("Registro incluido com sucesso.\n");
      found = 1;
    }
    else {
      fwrite(&registro, sizeof(struct Venda), 1, fpCopy);
    }
  }

  if(found == 0) printf("Registro não encontrado.\n");

  fclose(fp);
  fclose(fpCopy);
  remove(FILE_NAME);
  rename("vendas-copy.dat", FILE_NAME);
}

void consultarMaiorVenda()
{
  FILE *fp;
  fp = fopen(FILE_NAME, "rb");

  if (fp == NULL){
    printf("Erro ao abir o arquivo de dados.\n");
    return;
  }

  struct Venda registro;
  double maxVenda = 0.0;
  char maxVendedor[MAX_NAME_LEN];
  int found = 0;
  
  while(fread(&registro, sizeof(struct Venda), 1, fp)){
    if(registro.valorVenda > maxVenda){
      maxVenda = registro.valorVenda;
      strcpy(maxVendedor, registro.nomeVendedor);
      found = 1;
    }
  }

  if(found) 
    printf("O maior valor de venda foi de R$%.2lf, realizado pelo vendedor %s.\n", maxVenda, maxVendedor);
  else
    printf("Não foi encontrado nenhum registro");
  
  fclose(fp);

}

void consultarMaiorVendaMesAno()
{
  FILE *fp;
  fp = fopen(FILE_NAME, "rb");
  if (fp == NULL)
  {
    printf("Erro ao abrir o arquivo de dados.\n");
  }
  else
  {
    int mes, ano;
    printf("Informe o mes: ");
    scanf("%d", &mes);
    printf("Informe o ano: ");
    scanf("%d", &ano);

    struct Venda registro;
    double maxVenda = 0.0;
    char maxVendedor[MAX_NAME_LEN];
    int found = 0;
    while (fread(&registro, sizeof(struct Venda), 1, fp))
    {
      if (registro.mes == mes && registro.ano == ano && registro.valorVenda > maxVenda)
      {
        maxVenda = registro.valorVenda;
        strcpy(maxVendedor, registro.nomeVendedor);
        found = 1;
      }
    }
    if (found)
    {
      printf("O maior valor de venda para o mes %d/%d foi de R$%.2lf, realizado pelo vendedor %s.\n", mes, ano, maxVenda, maxVendedor);
    }
    else
    {
      printf("Nao foi encontrado nenhum registro para o mes %d/%d.\n", mes, ano);
    }
  }
  fclose(fp);
}

void somatorioVendasMesAno()
{
  FILE *fp;
  fp = fopen(FILE_NAME, "rb");
  if (fp == NULL)
  {
    printf("Erro ao abrir o arquivo de dados.\n");
  }
  else
  {
    double total = 0;
    int mes, ano;
    printf("Informe o mes: ");
    scanf("%d", &mes);
    printf("Informe o ano: ");
    scanf("%d", &ano);

    struct Venda registro;
    while (fread(&registro, sizeof(struct Venda), 1, fp))
    {
      if (registro.mes == mes && registro.ano == ano)
      {
        total += registro.valorVenda;
      }
    }
    printf("Somatorio das vendas de %d/%d: %.2lf\n", mes, ano, total);
  }
  fclose(fp);
}

void somatorioVendasAno()
{
  FILE *fp;
  fp = fopen(FILE_NAME, "rb");
  if (fp == NULL)
  {
    printf("Erro ao abrir o arquivo de dados.\n");
    return;
  }
  else
  {
    double total = 0;
    int ano;
    printf("Informe o ano: ");
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
  FILE *fp;
  fp = fopen(FILE_NAME, "rb");
  if (fp == NULL)
  {
    printf("Erro ao abrir o arquivo de dados.\n");
  }
  else
  {
    struct Venda registro;
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
  if (remove(FILE_NAME) == 0)
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
