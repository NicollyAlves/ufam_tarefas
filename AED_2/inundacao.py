def inunda_terreno(mapa, altMaxima, i, j):
	lin = len(mapa)
	col = len(mapa[0])
	
	if i < 0 or i >= lin or j < 0 or j >= col:
		return False
	
	if mapa[i][j] > altMaxima or mapa[i][j] == -1:
		return False
	
	mapa[i][j] = -1
	
	inunda_terreno(mapa, altMaxima,  i - 1, j)
	inunda_terreno(mapa, altMaxima, i + 1, j)
	inunda_terreno(mapa, altMaxima, i, j + 1)
	inunda_terreno(mapa, altMaxima, i, j - 1)
	
	return


alturaMax = int(input())
casaY, casaX = eval(input())
mapa = eval(input())

for i in range(len(mapa)):
	for j in range(len(mapa[0])):
		if mapa[i][j] == 0:
			inunda_terreno(mapa, alturaMax, 0, 0)

if mapa[casaY][casaX] == -1:
	print("Deu ruim!")
else:
	print(":)")
	