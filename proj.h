#ifndef UNTITLED1_PROJ_H
#define UNTITLED1_PROJ_H
#ifndef PROJ_H
#define PROJ_H

// Definição da estrutura Cliente
typedef struct {
    char nome[50];
    char cpf[12];
    char tipo_conta[10];
    float saldo;
    char senha[20];
} Cliente;
// Definição da estrutura Operacao
typedef struct {
    char cpf[12];
    char tipo_operacao[20];
    float valor;
} Operacao;

int compararStrings(const char *str1, const char *str2);
void copiarString(char destino, const charorigem);
void Novo_Cliente(Cliente clientes[], int *numClientes);
void Apagar_Cliente(Cliente clientes[], int *numClientes);

#endif

#endif //UNTITLED1_PROJ_H
