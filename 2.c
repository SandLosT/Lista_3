#include <math.h>
#include <stdio.h>

double calculofimdomes(int mes, double contribuicao, double juros) 
{
    return contribuicao* (1 + juros)* ( ( (pow(1 + juros, mes) - 1) / juros) );
}

int main(void) 
{
    int qnt_meses;
    double contribuicao_mensal, taxa_juros;

    scanf("%d", &qnt_meses);
    scanf("%lf", &contribuicao_mensal);
    scanf("%lf", &taxa_juros);

    for (int i = 1; i <= qnt_meses; i++) {
        double montante = calculofimdomes(i, contribuicao_mensal, taxa_juros);
        printf("Montante ao fim do mes %d: R$ %.2f\n", i, montante);
    }

    return 0;
}
