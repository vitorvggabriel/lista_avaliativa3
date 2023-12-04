#include <stdio.h>
#include <string.h>
#include <ctype.h>

// validar o formato da placa
int validarFormatoPlaca(char *placa) {
    int formatoMercosul = (strlen(placa) == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) && isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]));
    int formatoAntigo = (strlen(placa) == 8 && placa[3] == '-' && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) && isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7]));
    return formatoAntigo || formatoMercosul;
    
}

// validar o dia da semana
int validarDiaSemana(char *dias) {
    char *semana[] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
    for (int i = 0; i < 7; i++) {
        if (strcmp(dias, semana[i]) == 0) {
            return i + 1;
        }
    }
    return 0;
}

// mudar o nome do dia da semana para minúsculas
void converterMinusculasSemana(char *str) {
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

int main() {
    
    char placa[10], dias[15];
    scanf("%s", placa);
    scanf("%s", dias);

    // verifica se o dia e a placa são válidos
    
    int diaValido = validarDiaSemana(dias);
    int placaValida = validarFormatoPlaca(placa);

    if (!diaValido && !placaValida) {
        
        printf("Placa invalida\n");
        
        printf("Dia da semana invalido\n");
        
        return 0;
    } else if (!diaValido) {
        
        printf("Dia da semana invalido\n");
        return 0;
    } else if (!placaValida) {
        
        printf("Placa invalida\n");
        return 0;
    }

    int ultimoDigito = placa[strlen(placa) - 1] - '0';
    int restricao = ((ultimoDigito % 10) / 2) + 1;

    converterMinusculasSemana(dias); 

    if (diaValido == 6 || diaValido == 7) {
        printf("Nao ha proibicao no fim de semana\n");
    } else if (diaValido == restricao) {
        printf("%s nao pode circular %s\n", placa, dias);
    } else {
        printf("%s pode circular %s\n", placa, dias);
    }

    return 0;
}
