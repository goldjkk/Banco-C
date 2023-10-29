#include <stdio.h>
#include "proj.h"

// Função para comparar duas strings
int compararStrings(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}
// Função para copiar uma string para outra
void copiarString(char destino, const charorigem) {
    int i = 0;
    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0';
}
// Função para adicionar um novo cliente
void Novo_Cliente(Cliente clientes[], int numClientes) {
    if (numClientes < 1000) {
        Cliente novoCliente;
        printf("Nome: ");
        scanf("%s", novoCliente.nome);
        printf("CPF: ");
        scanf("%s", novoCliente.cpf);
        printf("Tipo de conta (comum ou plus): ");
        scanf("%s", novoCliente.tipo_conta);
        printf("Valor inicial da conta: ");
        scanf("%f", &novoCliente.saldo);
        printf("Senha: ");
        scanf("%s", novoCliente.senha);

        clientes[numClientes] = novoCliente;
        (numClientes)++;
        printf("Cliente adicionado com sucesso.\n");
    } else {
        printf("Limite maximo de clientes atingido.\n");
    }
}
