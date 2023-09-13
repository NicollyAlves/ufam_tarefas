def ordena(competidores):
	n = len(competidores)
	for i in range(n - 1):
		for j in range(0, n - i - 1):
			if competidores[j] > competidores[j + 1]:
				competidores[j], competidores[j + 1] = competidores[j + 1], competidores[j]
		
class Comp:
	posicao = 1
	
	def __init__(self, nome, n1, n2, n3):
		numeros = []
		
		numeros.append(n1)
		numeros.append(n2)
		numeros.append(n3)
		maior1 = numeros[0]
		maior2 = numeros[1]
		

		if maior2 > maior1:
			maior1, maior2 = maior2, maior1
		for i in range(2, len(numeros)):
			numero = numeros[i]
			if numero > maior1:
				maior2 = maior1
				maior1 = numero
			elif numero > maior2:
				maior2 = numero
		soma = maior1 + maior2
		self.nome = nome.replace("'", "")
		self.nota = soma
		self.posicao = Comp.posicao
		Comp.posicao += 1

	def __str__(self):
		return f"{self.nome} : {self.nota}"

	def __lt__(self, outro):
		if self.nota == outro.nota:
			return self.posicao < outro.posicao
		return self.nota > outro.nota
	

competidores = []

n = int(input())
for i in range(n):
	entrada = input().strip("()")
	partes = entrada.split(",")
	nome = partes[0].strip()
	n1 = float(partes[1])
	n2 = float(partes[2])
	n3 = float(partes[3])
	competidor = Comp(nome,n1,n2,n3)
	competidores.append(competidor)

ordena(competidores)

for comp in competidores:
	print(comp)