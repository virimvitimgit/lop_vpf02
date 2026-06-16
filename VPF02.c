#include <stdio.h>
#include <windows.h>
#define MAX_CLIENTES 7

struct Clientes{
    char nome[50];
    int idade;
    char sexo;
};

void main() {
    SetConsoleOutputCP(CP_UTF8);
    struct Clientes clientes[MAX_CLIENTES]; 
    FILE * arquivo = fopen("clientes.csv", "r");
    if(arquivo == NULL){
        printf("Arquivo não encontrado.\n");
        return 1;
    }
    char linha[256]; 
    int tc = 0;
    if(fgets(linha, sizeof(linha), arquivo) == NULL) {
        printf("Arquivo inválido.\n");
        fclose(arquivo);
        return 1;
    }
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
    float media, mediam, mediaf;
    media = (float)si / tc;
    mediam = (float)sim / qm;
    mediaf = (float)sif / qf;
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





// O arquivo a seguir contém dados de clientes. Você deve criar um programa em C que leia o arquivo, processe os dados e gere um relatório resumido dos clientes.
//clientes.csv
//Nome,Idade,Sexo
//João da Silva,30,M
//Maria Oliveira,25,F
//Pedro Santos,35,M
//Ana Costa,28,F
//Carlos Lima,40,M
//Maria Lima,40,F
//Irene Lima,40,F
//O programa deve ler os dados dos clientes, armazená-los em uma estrutura e exibir um relatório formatado na tela, mostrando o nome, a idade e o sexo de cada cliente, contar o total de clientes e
//calcular a média de idade dos clientes, contar quantos são do sexo 'M' e quantos são do sexo 'F', também a média de idade por sexo.