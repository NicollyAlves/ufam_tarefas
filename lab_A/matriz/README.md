Faça uma função para preencher uma matriz de dimensões N×N

com o seguinte padrão:

4  4  4  4  4  4  4
4  3  3  3  3  3  4
4  3  2  2  2  3  4
4  3  2  1  2  3  4
4  3  2  2  2  3  4
4  3  3  3  3  3  4
4  4  4  4  4  4  4

Isto é, a matriz está organizada em "camadas", com o dígito 1 no centro e incrementando "para fora".

Seu programa deverá ler apenas o valor N

, que será um número inteiro ímpar maior que 1 e menor que 20. Em seguida, imprima a matriz.
Dicas

Monte a matriz em níveis. Cada nível é um conjunto de linhas e colunas equidistantes do centro da matriz.

Nível 0: apenas a célula central da matriz. Ou seja, as linhas e colunas que estão a "distância zero" do centro:

Nível 1: as linhas e colunas que estão "a distância 1" do centro da matriz, conforme a figura abaixo:

Nível 2: as linhas e colunas que estão "a distância 2" do centro da matriz, conforme a figura abaixo:

Uma vez que você tenha identificado as linhas e colunas de cada nível da matriz, basta percorrê-las preenchendo suas células com o valor daquele nível.

A solução deste exercício pode ser iterativa ou recursiva. A recursão é mais simples. Você pode construir a matriz de dentro para fora ou de fora para dentro. A construção de dentro para fora é mais simples porque o caso base requer apenas colocar o valor "1" no centro da matriz.
Exemplos de Entrada e Saída
Entrada 	

5

Saída 	

3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3

Entrada 	

9

Saída 	

5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5