def divisivel(n):
    passos = []

    while n >= 10:
        quociente = n // 10
        resto = n % 10
        passos.append(n)
        n = n - quociente * 3 + resto
    
    passos.append(n)

    return passos

# Entrada
n = int(input())

# Sequência de passos
sequencia = divisivel(n)

# Saída
for i in range(len(sequencia) - 1, -1, -1):
    print(sequencia[i])
