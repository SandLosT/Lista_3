#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para validar a placa do veículo
int validarPlaca(char *numeroPlaca) 
{
    int comprimento = strlen(numeroPlaca);

    if ((comprimento == 8 || comprimento == 7) &&
        (isalpha(numeroPlaca[0]) && isalpha(numeroPlaca[1]) && isalpha(numeroPlaca[2]) &&
         (isdigit(numeroPlaca[comprimento - 1]) || isalpha(numeroPlaca[3]) &&
          isdigit(numeroPlaca[comprimento - 1])))) {
        return 1;
    }
    return 0;
}

// Função para validar o dia da semana
int validarDiaSemana(char *nomeDia) 
{
    const char *diasSemana[] = 
    {"SEGUNDA-FEIRA",
     "TERCA-FEIRA", 
     "QUARTA-FEIRA", 
     "QUINTA-FEIRA",                 
     "SEXTA-FEIRA", 
     "SABADO", 
     "DOMINGO"};

    for (int i = 0; i < 7; i++) {
        if (strcmp(nomeDia, diasSemana[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Função principal
int main(void) 
{
    char numeroPlacaVeiculo[10], diaSemana[20];

    scanf("%s", numeroPlacaVeiculo);

    for (int i = 0; i < strlen(numeroPlacaVeiculo); i++) {
        numeroPlacaVeiculo[i] = toupper(numeroPlacaVeiculo[i]);
    }

    scanf("%s", diaSemana);

    int ultimoDigitoPlaca = numeroPlacaVeiculo[strlen(numeroPlacaVeiculo) - 1] - '0';

    if (!validarPlaca(numeroPlacaVeiculo)) {
        printf("Placa invalida\n");
        if (!validarDiaSemana(diaSemana)) {
            printf("Dia da semana invalido\n");
        }
        return 0;
    }

    if (!validarDiaSemana(diaSemana)) {
        printf("Dia da semana invalido\n");
        return 0;
    }

    if (strcmp(diaSemana, "SABADO") == 0 || strcmp(diaSemana, "DOMINGO") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } else {
        for (int i = 0; i < strlen(diaSemana); i++) {
            diaSemana[i] = tolower(diaSemana[i]);
        }

        const char *diasSemanaLowerCase[] = {"segunda-feira", "terca-feira", "quarta-feira", "quinta-feira",
                                              "sexta-feira"};

        for (int i = 0; i < 5; i++) {
            if (strcmp(diaSemana, diasSemanaLowerCase[i]) == 0) {
                if ((ultimoDigitoPlaca == i * 2 || ultimoDigitoPlaca == i * 2 + 1)) {
                    printf("%s nao pode circular %s\n", numeroPlacaVeiculo, diaSemana);
                } else {
                    printf("%s pode circular %s\n", numeroPlacaVeiculo, diaSemana);
                }
                break;
            }
        }
    }

    return 0;
}
