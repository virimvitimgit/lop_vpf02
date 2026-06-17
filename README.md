# lop_vpf02
Explicações do Código

## 1 - Bibliotecas e Estrutura

```
#include <stdio.h>
#include <windows.h>
#define MAX_CLIENTES 7

struct Clientes{
    char nome[50];
    int idade;
    char sexo;
};
```

As linhas que começam com um "#" representam as bibliotecas que serão utilizadas - permitem a utilização das ferramentas essenciais para a criação desse código - e as outras linhas representam a estrutura que será utilizada como base para a produção do código

## 2 - Abertura do Código e Primeiras Configurações

```
void main() {
    SetConsoleOutputCP(CP_UTF8);
    struct Clientes clientes[MAX_CLIENTES];
    FILE * arquivo = fopen("clientes.csv", "r");
    if(arquivo == NULL){
        printf("Arquivo não encontrado.\n");
        return 1;
    }
```

Aqui será introduzido o "void main", responsável por abrir o código e o "void" é para que o código não precise de um retorno para precisar se manter. Também será introduzida a estrutura com o "struct", a abertura do arquivo com "FILE", seguido pelo "*" que serve como um "ponteiro" para apontar para o arquivo e o que acontece caso o arquivo não seja encontrado com o "if".

## 3 - Leitura do Cabeçalho e Definição

```
    char linha[256];
    int tc = 0;
    if(fgets(linha, sizeof(linha), arquivo) == NULL) {
        printf("Arquivo inválido.\n");
        fclose(arquivo);
        return 1;
    }
```

Os arquivos CSV geralmente possuem uma primeira linha descritiva com os títulos das colunas (como "Nome, Idade, Sexo"). Esta etapa, utilizando a função "fgets" lê, mas não armazena as informações na estrutura de clientes, servindo exclusivamente para pular o cabeçalho e definir o tamanho da linha com "char linha".

## 4 - Leitura do Arquivo e Separação de Dados

```
    while(fgets(linha, sizeof(linha), arquivo) != NULL && tc < MAX_CLIENTES) {
        int i = 0;
        int c = 0;
        while (linha[i] != ',' && linha[i] != '\0' && c < 49) {
            clientes[tc].nome[c] = linha[i];
            i++;
            c++;
        }
        clientes[tc].nome[c] = '\0';
        if (linha[i] == ',') i++;
        char idade_str[10];
        c = 0;
        while (linha[i] != ',' && linha[i] != '\0' && c < 9) {
            idade_str[c] = linha[i];
            i++;
            c++;
        }
        idade_str[c] = '\0';
        int valor = 0, j = 0;
        while (idade_str[j] != '\0') {
            valor = (valor * 10) + (idade_str[j] - '0');
            j++;
        }
        clientes[tc].idade = valor;
        if (linha[i] == ',') i++;
        if (linha[i] != '\0' && linha[i] != '\n' && linha[i] != '\r') {
            clientes[tc].sexo = linha[i];
            tc++;
        }
    }
    fclose(arquivo);
```

Os "whiles" são utilizados com duas finalidades garantir que o código seja executado até percorrer todos os clientes e para repetir a ação de ler os caracteres e somados com o "i++" e "c++" - Salvam os caracteres e contam quais já foram lidos - são responsáveis por percorrer o arquivo e trazer suas informações para o código. Os "fgets" e "sizeof" são responsáveis por ler e selecionar - respectivamente - a linha a ser lida. Por fim, os "if (linha[i]) servem para ler se há alguma quebra na linha, sinalizado pela ',' e o "fclose" é para fechar o arquivo.

## 5 - Determinando Valores e Váriaveis

```
 int si = 0;
    int qm = 0;
    int qf = 0;
    int sim = 0;
    int sif = 0;
    printf("\n\n");
    printf("%-25s  %-5s  %-4s\n", "Nome", "Idade", "Sexo");
    printf("\n\n");
    for(int i = 0; i < tc; i++) {
        printf("%-25s  %-5d  %-4c\n", clientes[i].nome, clientes[i].idade, clientes[i].sexo);
        si += clientes[i].idade;
        if (clientes[i].sexo == 'M') {
            qm++;
            sim += clientes[i].idade;
        } else if (clientes[i].sexo == 'F') {
            qf++;
            sif += clientes[i].idade;
        }
    }
```
As variáveis "si", "qm", "qf", "sim" e "sif" representam respectivamente a 'Soma das Idades', a 'Quantidade de Homens', a 'Quantidade de Mulheres', a 'Soma das Idades dos Homens" e 'Soma das Idades das Mulheres' estão definidas com valor '0' por base e os "%-25s %-5s %-4s" servem para selecionar os valores que serão utilizados de "nome", "idade" e "sexo" e o "for" vai servir - junto coma as outras variáveis com "++" para saber quais já foram utilizados - para escrever os dados em forma de tabela.

## 6 - Cálculos Finais

```
 float media, mediam, mediaf;
    media = (float)si / tc;
    mediam = (float)sim / qm;
    mediaf = (float)sif / qf;
```

O "float" foi utilizado para definir as últimas três variáveis que suportam números com casas decimais, sendos elas a "media", "mediaf" e "mediam" que representam respectivamente as médias de idade geral, média de idade das mulheres e média de idade dos homens. As três linhas subsequentes servem para o cálculo do valor dessas variáveis considerando o cálculo da Média em Si.

## 7 - Saída do Código

```
printf("\n\n");
    printf("Total de Clientes: %d\n", tc);
    printf("Média de Idade de Ambos os Sexos: %.1f anos\n", media);
    printf("\n\n");
    printf("Quantidade de Homens (M): %d\n", qm);
    printf("Média de Idade dos Homens: %.1f anos\n", mediam);
    printf("\n\n");
    printf("Quantidade de Mulheres (F): %d\n", qf);
    printf("Média de Idade das Mulheres: %.1f anos\n", mediaf);
    getch();
}
```

As últimas linhas (com excessão do "}" que fecha o Código e o "getch();" que mantem o código aberto até ser finalizado) servem para imprimir os dados com suas informações e respectivas variáveis.
