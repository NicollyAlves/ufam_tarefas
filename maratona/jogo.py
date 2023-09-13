def verificar_resultado_jogo(transcricao):
    # Verifica se há alguma sequência inconsistente que indica que Alice começou
    if transcricao.startswith('OO'):
        return '?'
    
    # Verifica se há alguma sequência inconsistente que indica que Bob começou
    if transcricao.startswith('XXX'):
        return '?'
    
    # Verifica se há um vencedor (Alice ou Bob)
    if 'XXX' in transcricao:
        return 'Alice'
    if 'OOO' in transcricao:
        return 'Bob'
    
    # Verifica se é um empate
    if 'X' not in transcricao or 'O' not in transcricao:
        return '*'
    
    # Caso contrário, a transcricao é inconsistente
    return '?'

# Lê a entrada
transcricao = input().strip()

# Verifica o resultado do jogo e imprime o resultado
resultado = verificar_resultado_jogo(transcricao)
print(resultado)
