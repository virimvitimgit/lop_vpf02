# lop_vpf02
Explicações do Código

## 1 - Bibliotecas e Estrutura

<br />
<div align="left">
    <img src="Bibliotecas.PNG" alt="Bibliotecas" width="50">
  </a>

As linhas que começam com um "#" representam as bibliotecas que serão utilizadas - permitem a utilização das ferramentas essenciais para a criação desse código - e as outras linhas representam a estrutura que será utilizada como base para a produção do código

## 2 - Abertura do Código e Primeiras Configurações

<br />
<div align="left">
   
  </a>

Aqui será introduzido o "void main", responsável por abrir o código e o "void" é para que o código não precise de um retorno para precisar se manter. Também será introduzida a estrutura com o "struct", a abertura do arquivo com "FILE" e o que acontece caso o arquivo não seja encontrado com o "if".

## 3 - Leitura do Cabeçalho e Definição

<br />
<div align="left">
   
  </a>
  
Os arquivos CSV geralmente possuem uma primeira linha descritiva com os títulos das colunas (como "Nome, Idade, Sexo"). Esta etapa, utilizando a função fgets lê, mas não armazena as informações na estrutura de clientes, servindo exclusivamente para pular o cabeçalho e definir o tamanho da linha com "char linha".

## 4 - Leitura do Arquivo e Separação de Dados

<br />
<div align="left">
   
  </a>

Os "whiles" são utilizados com duas finalidades garantir que o código seja executado até percorrer todos os clientes e para repetir a ação de ler os caracteres e somados com o "i++" e "c++" - Salvam os caracteres e contam quais já foram lidos - são responsáveis por percorrer o arquivo e trazer suas informações para o código. Os "fgets" e "sizeof" são responsáveis por selecionar a linha a ser lida. Por fim, os "if (linha[i]) servem para ler se há alguma quebra na linha, sinalizado pela ',' e o "fclose" é para fechar o arquivo.

## 5 - Determinando Valores e Váriaveis

<br />
<div align="left">
   
  </a>

As váriaveis "si", "qm", "qf", "sim" e "sif" representam respectivamente a 'Soma das Idades', a 'Quantidade de Homens', a 'Quantidade de Mulheres', a 'Soma das Idades dos Homens" e 'Soma das Idades das Mulheres' estão definidas com valor '0' por base e os "%-25s %-5s %-4s" servem para selecionar os valores que serão utilizados de "nome", "idade" e "sexo" e o "for" vai servir para - junto coma as outras variáveis com "++" - determinar o valor das variáveis.

## 6 - 
