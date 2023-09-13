import tkinter as tk
import math

def desenhar_sinal_de_mais(tamanho):
    canvas.delete("all")
    
    cor_circulo = "#c8a2c8"
    cor_quadrado = "#ffb6c1"
    cor_triangulo = "#ffffe0"

    cor_borda_circulo = "purple"
    cor_borda_quadrado = "#fc0fc0"
    cor_borda_triangulo = "yellow"

    centro_x = 300
    centro_y = 300

    distancia_entre_formas_e_linhas = tamanho / 20

    canvas.create_line(centro_x - tamanho, centro_y, centro_x + tamanho, centro_y, width=2, fill="#808080")
    canvas.create_line(centro_x, centro_y - tamanho, centro_x, centro_y + tamanho, width=2, fill="#808080")

    raio_circulo = 0.45 * tamanho
    lado_quadrado = 0.9 * tamanho
    lado_triangulo = 0.9 * tamanho


    x_circulo = centro_x - tamanho + raio_circulo + distancia_entre_formas_e_linhas
    y_circulo = centro_y + raio_circulo + distancia_entre_formas_e_linhas

    x_quadrado = centro_x + (lado_quadrado / 2) + distancia_entre_formas_e_linhas
    y_quadrado = (centro_y + tamanho) - (lado_quadrado / 2) - distancia_entre_formas_e_linhas

    canvas.create_rectangle(x_quadrado - lado_quadrado / 2, y_quadrado - lado_quadrado / 2,
                            x_quadrado + lado_quadrado / 2, y_quadrado + lado_quadrado / 2, fill=cor_quadrado, outline=cor_borda_quadrado)
    
    x_triangulo = centro_x + tamanho - lado_triangulo / 2 - distancia_entre_formas_e_linhas
    y_triangulo = centro_y - (lado_triangulo / 2) - distancia_entre_formas_e_linhas

    canvas.create_oval(x_circulo - raio_circulo, y_circulo - raio_circulo, x_circulo + raio_circulo, y_circulo + raio_circulo, fill=cor_circulo, outline=cor_borda_circulo)

    altura_triangulo = (math.sqrt(3) / 2) * lado_triangulo
    ponto1_x = x_triangulo - lado_triangulo / 2
    ponto1_y = y_triangulo + altura_triangulo / 2
    ponto2_x = x_triangulo + lado_triangulo / 2
    ponto2_y = y_triangulo + altura_triangulo / 2
    ponto3_x = x_triangulo
    ponto3_y = y_triangulo - altura_triangulo / 2
    canvas.create_polygon(ponto1_x, ponto1_y, ponto2_x, ponto2_y, ponto3_x, ponto3_y, fill=cor_triangulo, outline=cor_borda_triangulo)

def atualizar_desenho(e):
    try:
        tamanho = int(entrada_tamanho.get())
        desenhar_sinal_de_mais(tamanho)
    except ValueError:
        pass

window = tk.Tk()
window.geometry("600x600")

canvas = tk.Canvas(window, width=600, height=600)
canvas.pack()

entrada_tamanho = tk.Entry(window)
entrada_tamanho.pack()
entrada_tamanho.bind("<Return>", atualizar_desenho)

window.mainloop()
