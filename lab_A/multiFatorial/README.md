Multifatorial

Dado um número inteiro n≥0, o seu fatorial é a sequência n!=n(n−1)(n−2)...1. Por exemplo, você já sabe que 7!=5.040, pois 7!=7×6×5×4×3×2×1=5.040

O fatorial duplo é uma generalização do fatorial. Ele é definido como n!!=n×(n−2)!!. Por exemplo, 7!!=105 e 6!!=48, pois 7!!=7×5×3×1 e 6!!=6×4×2

De modo geral, o multifatorial é uma sequência de multiplicações n×(n−α)×(n−2α)×…×1. Ele pode ser descrito com a seguinte relação de recorrência:

n!α={n×(n−α)!α se n>01 c.c 

Elabore uma função recursiva para calcular um multifatorial.

Faça um programa que lê uma série de pares (n,α)
e, para cada um deles, imprime o valor do multifatorial n!α. Imprima as exclamações seguindo a formatação usada nos exemplos. A entrada garante que 0<α≤40 e que o resultado n!α

cabe em um inteiro de 32 bits com sinal.

A entrada termina quando n=0 e α=0. Nenhum valor lido será negativo.

Exemplos de Entrada e Saída

Entrada 	

0 1
5 1
7 2
6 2
0 2
0 0

Saída 	

0! = 1
5! = 120
7!! = 105
6!! = 48
0!! = 1

Entrada 	

5 1
7 2
9 3
10 4
12 5
0 0

Saída 	

5! = 120
7!! = 105
9!!! = 162
10!!!! = 120
12!!!!! = 168
