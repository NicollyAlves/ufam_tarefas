def arruma(N, desejada, obtida):
    return set(desejada) == set(obtida)

N = int(input())
desejada = list(map(int, input().split()))
obtida = list(map(int, input().split()))

if arruma(N, desejada, obtida):
    print("Sim")
else:
    print("Nao")
