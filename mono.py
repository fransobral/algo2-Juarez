def es_primo(numero:int):
    contador = 2
    divisor = False


    while divisor == False:
        if numero % contador == 0:
            divisor = True
        else:
            contador += 1

    if contador != numero:
        primo = False
    else:
        primo = True
    return primo

def mayor_dos(numero:int):
    while numero <= 2:
        print("ese num es menor a 3")
        numero = int(input("Ingrese un numero: "))
    return numero



def main():
    numero = int(input("Ingrese un numero: "))
    numero = mayor_dos(numero)
    primo = es_primo(numero)

    while primo == False:
        print("ese num no es primo")
        numero = int(input("Ingrese un numero: "))
        numero = mayor_dos(numero)
        primo = es_primo(numero)
    print("Ese num es primo.")
main()

