#include <stdio.h>
#include <string.h>
#include <ctype.h>

int vplaca(char *placa) {
    int formatoantigo = (strlen(placa) == 8 && placa[3] == '-' && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) && isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7]));
    int formatomercosul = (strlen(placa) == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) && isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]));

    return formatoantigo || formatomercosul;
}

int vdia(char *dias) {
    char *semana[] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
    for (int i = 0; i < 7; i++) {
        if (strcmp(dias, semana[i]) == 0) {
            return i+1;
        }
    }
    return 0;
}


void semanaminuscula(char *str) {
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

int main() {
    char placa[10], dias[15];
    scanf("%s", placa);
    scanf("%s", dias);

    int dia_valido = vdia(dias);
    int placa_valida = vplaca(placa);

    if (!dia_valido && !placa_valida) {
        printf("Placa invalida\n");
        printf("Dia da semana invalido\n");
        return 0;
    } else if (!dia_valido) {
        printf("Dia da semana invalido\n");
        return 0;
    } else if (!placa_valida) {
        printf("Placa invalida\n");
        return 0;
    }

    int ultimo_digito = placa[strlen(placa) - 1] - '0';
    int restricao = ((ultimo_digito % 10) / 2) + 1;

    semanaminuscula(dias); 

    if (dia_valido == 6 || dia_valido == 7) {
        printf("Nao ha proibicao no fim de semana\n");
    } else if (dia_valido == restricao) {
        printf("%s nao pode circular %s\n", placa, dias);
    } else {
        printf("%s pode circular %s\n", placa, dias);
    }

    return 0;
}