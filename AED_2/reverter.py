N = int(input())

lista = [0] * N
revertida = [0] * N

for i in range(N):
	n = eval(input())
	lista[i] = n
	
k = 0
for j in range(N - 1, -1, -1):
	revertida[k] = lista[j]
	k += 1

print(revertida)