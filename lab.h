#ifndef UNTITLED1_PROJ_H
#define UNTITLED1_PROJ_H
#ifndef PROJ_H
#define PROJ_H

typedef struct {
    char nome[50];
    char cpf[12];
    char tipo_conta[10];
    float saldo;
    char senha[20];
} Cliente;

typedef struct {
    char cpf[12];
    char tipo_operacao[20];
    float valor;
} Operacao;
int compararStrings(const char *str1, const char *str2);

#endif

#endif //UNTITLED1_PROJ_H
