#include <iostream>

long long modulo = 10000000000LL; // Últimos 10 dígitos

long long multiplyMod(long long a, long long b) {
    return ((a % modulo) * (b % modulo)) % modulo;
}

long long powerMod(long long base, long long exponent) {
    long long result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = multiplyMod(result, base);
        }

        base = multiplyMod(base, base);
        exponent /= 2;
    }

    return result;
}

long long solucionarRompecabezas(int N) {
    long long var_A = 1;
    long long var_B = 1;
    long long var_C = 1;
    long long var_D = 1;

    for (int i = 1; i <= N; i++) {
        long long resultado = multiplyMod(3 * var_D, multiplyMod(1 * var_C, multiplyMod(4 * var_B, 1 * var_A)));
        var_A = var_B;
        var_B = var_C;
        var_C = var_D;
        var_D = resultado;
    }

    return var_D;
}

int main() {
    std::cout << solucionarRompecabezas(10) << std::endl;
    std::cout << solucionarRompecabezas(100) << std::endl;
    std::cout << powerMod(2023, 100) << std::endl; // 2023 elevado a la 100

    return 0;
}
