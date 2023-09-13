Sequência Trilegal

Uma sequência de números inteiros é (x1,x2,x3,…,xN)
é dita ser trilegal se ela pode ser dividida em três subsequências (s1,s2,s3)

tais que:

    Todas as subsequências têm a mesma quantidade de elementos (N/3);

A concatenação das três sequências é a sequência original;
Cada subsequência é uma sequência trilegal;
A soma de cada i-ésimo elemento de s1 com o elemento correspondente em s2 é igual ao i-ésimo elemento em s3;
Se N>3, então a soma de todos os números em s1 é igual à soma dos números em s2.

Além disso, uma sequência que contém apenas um número é uma sequência trilegal trivial.

Escreva um programa que lê uma sequência de valores inteiros e decide se essa sequência é trilegal ou não.

Entrada e Saída

A entrada conterá vários casos de teste. Cada caso de teste começa com um inteiro N, tal que 0 < N ≤ 100 que indica o tamanho da sequência a ser testada. Em seguida aparecem N valores inteiros indicando a sequência a ser processada.

Como saída, imprima a palava trilegal ou normal para cada sequência lida.

A entrada termina com N=0.

Exemplos de Entrada e Saída
Entrada 	

1 42
1 -7
3 6 6 12
27 23 -4 19 1 18 19 24 14 38 10 9 19 2 17 19 12 26 38 33 5 38 3 35 38 36 40 76
0

Saída 	

trilegal
trilegal
trilegal
trilegal

Entrada 	

3 1 2 4
3 0 47 47
3 46 48 94
9 0 47 47 44 1 47 46 48 94
0

Saída 	

normal
trilegal
trilegal
normal
