def ordena(n, k, lista):
	for i in range(k):
		menor = i
		for j in range(i + 1, n):
			if lista[j] < lista[menor]:
				menor = j
		armazena = lista[i]
		for j in range(i, menor):
			if j + 1 == menor:
				lista[i] = lista[menor]
			armazena, lista[j + 1] = lista[j + 1], armazena
		
	return lista

n = int(input())
k = int(input())
entradaLista = input()
lista = [int(valor) for valor in entradaLista.strip("[]").split(",")]

lista_ordenada = ordena(n, k, lista)

print(lista_ordenada)
