def solucionarRompecabezas(N):
    var_A = 1
    var_B = 1
    var_C = 1
    var_D = 1

    for i in range(1, N + 1):
        resultado = 3 * var_D + 1 * var_C + 4 * var_B + 1 * var_A
        var_A = var_B
        var_B = var_C
        var_C = var_D
        var_D = resultado

    return var_D % 10000000000  # últimos 10 dígitos de var_D


print(solucionarRompecabezas(10))
print(solucionarRompecabezas(100))
print(solucionarRompecabezas(2023 ** 100))  # 2023 elevado a la 100
