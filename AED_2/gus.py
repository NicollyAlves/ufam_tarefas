indice_mudanca = 0

def mudaOrdem(lista):
    global indice_mudanca
    n = len(lista)
    
    if indice_mudanca < n:
        primeiro_elemento = lista[indice_mudanca]
        for j in range(indice_mudanca, 0, -1):
            lista[j] = lista[j - 1]
        lista[0] = primeiro_elemento
        indice_mudanca += 1

        for k in range(n):
            print(lista[k])
    else:
        indice_mudanca = 0
    
    return lista

def somaDistancia(casas):
    distancias = []
    for i in range(len(casas)):
        k = 1
        while(k < len(casas)):
            distancias.append(abs(casas[i] - casas[k]))
            print(casas[i], casas[k])
            k += 1
        mudaOrdem(casas)
    return distancias
	
casas = input().strip("[]")
valores = casas.split(",")
numeros = [int(valor) for valor in valores]

somaFinal = somaDistancia(numeros)

print(somaFinal)

print(mudaOrdem(numeros))