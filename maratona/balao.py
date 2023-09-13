def ehBalao(palavra):
    if palavra == 'balao':
        return 'Mais! Mais!'
    else:
        return 'Bu!'
    
palavra = input()

print(ehBalao(palavra))