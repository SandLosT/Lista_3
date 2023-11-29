#include <stdio.h>
#include <string.h>
#include <ctype.h>


int validadorplaca(char *numplaca) 
{
    int comprimento = strlen(numplaca);

    if ((comprimento == 8||comprimento == 7) &&
        (isalpha(numplaca[0]) && isalpha(numplaca[1]) && isalpha(numplaca[2]) &&
         (isdigit(numplaca[comprimento -1]) || isalpha(numplaca[3]) &&
          isdigit(numplaca[comprimento -1])))) {
        return 1;
    }
    return 0;
}

int validarDiaSemana(char *nomeDia) 
{
    const char *DiasSemana[] = 
    {"SEGUNDA-FEIRA",
     "TERCA-FEIRA", 
     "QUARTA-FEIRA", 
     "QUINTA-FEIRA",                 
     "SEXTA-FEIRA", 
     "SABADO", 
     "DOMINGO"};

    for (int i = 0; i < 7; i++) {
        if (strcmp(nomeDia, DiasSemana[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(void) 
{
    char placaVeiculo[10], diaSemana[20];

    scanf("%s", placaVeiculo);

    for (int i = 0; i < strlen(placaVeiculo); i++)
     {
        placaVeiculo[i] = toupper(placaVeiculo[i]);
    }

    scanf("%s", diaSemana);

    int ultimoDigitoPlaca = placaVeiculo[strlen(placaVeiculo) - 1] - '0';

    if (!validadorplaca(placaVeiculo))
     {
        printf("Placa invalida\n");
        if (!validarDiaSemana(diaSemana)) {
            printf("Dia da semana invalido\n");
        }
        return 0;
    }

    if (!validarDiaSemana(diaSemana))
     {
        printf("Dia da semana invalido\n");
        return 0;
    }

    if (strcmp(diaSemana, "SABADO") == 0 || strcmp(diaSemana, "DOMINGO") == 0) 
    {
        printf("Nao ha proibicao no fim de semana\n");
    } else {
        for (int i = 0; i < strlen(diaSemana); i++) 
        {
            diaSemana[i] = tolower(diaSemana[i]);
        }

        const char *DiasSemanaLowerCase[] = {"segunda-feira", "terca-feira", "quarta-feira", "quinta-feira",
                                              "sexta-feira"};

        for (int i = 0; i < 5; i++) 
        {
            if (strcmp(diaSemana, DiasSemanaLowerCase[i]) == 0) {
                if ((ultimoDigitoPlaca == i * 2 || ultimoDigitoPlaca == i * 2 + 1)) {
                    printf("%s nao pode circular %s\n", placaVeiculo, diaSemana);
                } else {
                    printf("%s pode circular %s\n", placaVeiculo, diaSemana);
                }
                break;
            }
        }
    }

    return 0;
}
