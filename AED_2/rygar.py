from math import ceil

class Monstro:
    def __init__(self, energia, forca):
        self.energia = energia
        self.forca = forca
        self.dano_em_rygar = None

    def calcular_dano_em_rygar(self):
        turnos_para_derrotar = ceil(self.energia / 40)
        self.dano_em_rygar = (turnos_para_derrotar - 1) * self.forca

    def __lt__(self, other):
        if self.dano_em_rygar is None:
            self.calcular_dano_em_rygar()
        if other.dano_em_rygar is None:
            other.calcular_dano_em_rygar()

        if self.dano_em_rygar is None and other.dano_em_rygar is None:
            return self.energia < other.energia
        elif self.dano_em_rygar is None:
            return False
        elif other.dano_em_rygar is None:
            return True

        return self.dano_em_rygar < other.dano_em_rygar

    def __str__(self):
        return

def ordena_monstros(monstros):
    n = len(monstros)
    for i in range(n - 1):
        minimo = i
        for j in range(i + 1, n):
            if monstros[j].dano_em_rygar < monstros[minimo].dano_em_rygar:
                minimo = j
        monstros[i], monstros[minimo] = monstros[minimo], monstros[i]

def ordena_e_calcula_dano(monstros):
    for monstro in monstros:
        monstro.calcular_dano_em_rygar()
    ordena_monstros(monstros)
    return monstros

def derrota_monstros(monstros):
    cont_zero = 0
    monstros = ordena_e_calcula_dano(monstros)

    energia_rygar = 100
    derrotados = 0

    while monstros and energia_rygar > 0:
        monstro = monstros[0]
        monstro.calcular_dano_em_rygar()

        turnos_para_derrotar = ceil(monstro.energia / 40)
        
        dano_no_monstro = turnos_para_derrotar * 40
        dano_do_monstro = (turnos_para_derrotar - 1) * monstro.forca
        monstro.energia -= dano_no_monstro

        for j in range(turnos_para_derrotar - 1):
            if energia_rygar > 0:
                energia_rygar -= monstro.forca

        if energia_rygar == 0:
            cont_zero += 1
            
        if energia_rygar < 0:
            energia_rygar = 0
            break

        if (cont_zero <= 1) and (monstro.energia <= 0):
            derrotados += 1
        else:
            break

        monstros.pop(0)

    return derrotados, energia_rygar

entrada = eval(input())
monstros = [Monstro(energia, forca) for energia, forca in entrada]
resultado = derrota_monstros(monstros)

print(resultado[0], resultado[1])
