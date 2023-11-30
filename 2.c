#include <math.h>
#include <stdio.h>

double calcularMontanteAoFimDoMes(int numeroMes, double contribuicaoMensal, double taxaJuros) 
{
    return contribuicaoMensal * (1 + taxaJuros) * ( ( (pow(1 + taxaJuros, numeroMes) - 1) / taxaJuros) );
}

int main(void) 
{
    int quantidadeMeses;
    double contribuicaoMensal, juros;

    scanf("%d", &quantidadeMeses);

    scanf("%lf", &contribuicaoMensal);

    scanf("%lf", &juros);

    for (int i = 1; i <= quantidadeMeses; i++) {
        double montante = calcularMontanteAoFimDoMes(i, contribuicaoMensal, juros);
        printf("Montante ao fim do mes %d: R$ %.2f\n", i, montante);
    }

    return 0;
}
