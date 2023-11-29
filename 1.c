#include <stdio.h>
#include <string.h>


int RomanopDecimal(char A) 
{
    switch (A) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}


int transfRomanopDecimal(char *romano) 
{
    int resultado = 0;
    for (int i = 0; romano[i]; i++) {
        if (RomanopDecimal(romano[i]) < RomanopDecimal(romano[i + 1])) {
            resultado -= RomanopDecimal(romano[i]);
        } else {
            resultado += RomanopDecimal(romano[i]);
        }
    }
    return resultado;
}

void transfDecimalParaBinario(int decimal, char binario[]) 
{
    binario[0] = '\0';
    while (decimal > 0) {
        char digito[2];
        sprintf(digito, "%d", decimal % 2);
        strcat(binario, digito);
        decimal /= 2;
    }
    int T = strlen(binario);
    for (int i = 0; i < T / 2; i++) {
        char temp = binario[i];
        binario[i] = binario[T - 1 - i];
        binario[T - 1 - i] = temp;
    }
}

void transfDecimalParaHexadecimal(int decimal, char hexadecimal[]) 
{
    int i = 0, resto;
    hexadecimal[0] = '\0';
    while (decimal > 0) {
        resto = decimal % 16;
        char digito[2];
        if (resto < 10) {
            sprintf(digito, "%d", resto);
        } else {
            sprintf(digito, "%c", resto - 10 + 'a');
        }
        strcat(hexadecimal, digito);
        decimal /= 16;
        i++;
    }
    int comp = strlen(hexadecimal);
    for (int i = 0; i < comp / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[comp - 1 - i];
        hexadecimal[comp - 1 - i] = temp;
    }
}

int main() 
{
    char numeralRomano[15], binario[32], hexadecimal[100];
    int decimal;
    
    scanf("%s", numeralRomano);
    
    decimal = transfRomanopDecimal(numeralRomano);
    
    transfDecimalParaBinario(decimal, binario);
    transfDecimalParaHexadecimal(decimal, hexadecimal);
    
    printf("%s na base 2: %s\n", numeralRomano, binario);
    printf("%s na base 10: %d\n", numeralRomano, decimal);
    printf("%s na base 16: %s\n", numeralRomano, hexadecimal);
    
    return 0;
}