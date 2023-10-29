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
// Função para apagar um cliente pelo CPF
void Apagar_Cliente(Cliente clientes[], int numClientes) {
    char cpf[12];
    printf("Digite o CPF do cliente a ser apagado: ");
    scanf("%s", cpf);

    int i;
    for (i = 0; i <numClientes; i++) {
        if (compararStrings(clientes[i].cpf, cpf)) {
            // Move todos os clientes após o cliente apagado uma posição para frente
            for (int j = i; j < numClientes - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            (numClientes)--;
            printf("Cliente apagado com sucesso.\n");
            return;
        }
    }

    printf("Cliente nao encontrado.\n");
}
// Função para listar todos os clientes
void Listar_clientes(Cliente clientes[], int numClientes) {
    printf("Lista de Clientes:\n");
    for (int i = 0; i < numClientes; i++) {
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Tipo de conta: %s\n", clientes[i].tipo_conta);
        printf("Saldo: %.2f\n", clientes[i].saldo);
        printf("\n");
    }
}
// Função para realizar um débito na conta de um cliente
void Debito(Cliente clientes[], int numClientes, Operacao operacoes[], int *numOperacoes) {
    char cpf[12];
    char senha[20];
    float valor;
    printf("CPF: ");
    scanf("%s", cpf);
    printf("Senha: ");
    scanf("%s", senha);
    printf("Valor: ");
    scanf("%f", &valor);

    int clienteEncontrado = 0;

    for (int i = 0; i < numClientes; i++) {
        if (compararStrings(clientes[i].cpf, cpf) && compararStrings(clientes[i].senha, senha)) {
            clienteEncontrado = 1;
            if (compararStrings(clientes[i].tipo_conta, "comum")) {
                if (clientes[i].saldo - valor >= -1000) {
                    clientes[i].saldo -= valor;
                    printf("Debito realizado com sucesso.\n");
                    copiarString(operacoes[*numOperacoes].cpf, cpf);
                    copiarString(operacoes[*numOperacoes].tipo_operacao, "Debito");
                    operacoes[*numOperacoes].valor = valor;
                    (*numOperacoes)++;
                } else {
                    printf("Saldo insuficiente para realizar o débito.\n");
                }
            } else if (compararStrings(clientes[i].tipo_conta, "plus")) {
                if (clientes[i].saldo - valor >= -5000) {
                    clientes[i].saldo -= valor;
                    printf("Debito realizado com sucesso.\n");
                    copiarString(operacoes[*numOperacoes].cpf, cpf);
                    copiarString(operacoes[*numOperacoes].tipo_operacao, "Debito");
                    operacoes[*numOperacoes].valor = valor;
                    (*numOperacoes)++;
                } else {
                    printf("Saldo insuficiente para realizar o debito.\n");
                }
            } else {
                printf("Tipo de conta inválido.\n");
            }
            break;
        }
    }

    if (!clienteEncontrado) {
        printf("CPF ou senha incorretos ou cliente não encontrado.\n");
    }
}

