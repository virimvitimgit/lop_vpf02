# lop_vpf02
Explicações do Código

## 1 - Bibliotecas e Estrutura

![Imagem do Código](./Biblioteca.png).

As linhas que começam com um "#" representam as bibliotecas que serão utilizadas - permitem a utilização das ferramentas essenciais para a criação desse código - e as outras linhas representam a estrutura que será utilizada como base para a produção do código

## 2 - Abertura do Código e Primeiras Configurações

![Imagem do Código](./voidmain.png).

Aqui será introduzido o "void main", responsável por abrir o código e o "void" é para que o código não precise de um retorno para precisar se manter. Também será introduzida a estrutura com o "struct", a abertura do arquivo com "FILE", seguido pelo "*" que serve como um "ponteiro" para apontar para o arquivo e o que acontece caso o arquivo não seja encontrado com o "if".

## 3 - Leitura do Cabeçalho e Definição

![Imagem do Código](./Biblioteca.png).
  
Os arquivos CSV geralmente possuem uma primeira linha descritiva com os títulos das colunas (como "Nome, Idade, Sexo"). Esta etapa, utilizando a função "fgets" lê, mas não armazena as informações na estrutura de clientes, servindo exclusivamente para pular o cabeçalho e definir o tamanho da linha com "char linha".

## 4 - Leitura do Arquivo e Separação de Dados

![Imagem do Código](./Biblioteca.png).

Os "whiles" são utilizados com duas finalidades garantir que o código seja executado até percorrer todos os clientes e para repetir a ação de ler os caracteres e somados com o "i++" e "c++" - Salvam os caracteres e contam quais já foram lidos - são responsáveis por percorrer o arquivo e trazer suas informações para o código. Os "fgets" e "sizeof" são responsáveis por ler e selecionar - respectivamente - a linha a ser lida. Por fim, os "if (linha[i]) servem para ler se há alguma quebra na linha, sinalizado pela ',' e o "fclose" é para fechar o arquivo.

## 5 - Determinando Valores e Váriaveis

![Imagem do Código](./Biblioteca.png).

As variáveis "si", "qm", "qf", "sim" e "sif" representam respectivamente a 'Soma das Idades', a 'Quantidade de Homens', a 'Quantidade de Mulheres', a 'Soma das Idades dos Homens" e 'Soma das Idades das Mulheres' estão definidas com valor '0' por base e os "%-25s %-5s %-4s" servem para selecionar os valores que serão utilizados de "nome", "idade" e "sexo" e o "for" vai servir - junto coma as outras variáveis com "++" para saber quais já foram utilizados - para escrever os dados em forma de tabela.

## 6 - Cálculos Finais

![Imagem do Código](./Biblioteca.png).

O "float" foi utilizado para definir as últimas três variáveis que suportam números com casas decimais, sendos elas a "media", "mediaf" e "mediam" que representam respectivamente as médias de idade geral, média de idade das mulheres e média de idade dos homens. As três linhas subsequentes servem para o cálculo do valor dessas variáveis considerando o cálculo da Média em Si.

## 7 - Saída do Código

![Imagem do Código](./Biblioteca.png).

As últimas linhas (com excessão do "}" que fecha o Código e o "getch();" que mantem o código aberto até ser finalizado) servem para imprimir os dados com suas informações e respectivas variáveis.
