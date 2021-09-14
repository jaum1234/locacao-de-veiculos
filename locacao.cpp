#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

struct Cliente {
    char cpf[12];
    char nome[50];
    //pelo menos 4 caracteres
};

struct Veiculo {
    char placa[7];
    //XXX9999
    //nao podem existir dois veículos com a mesma placa

    char tipo[1];
    //C para carro, M para moto

    char modelo[30];
    //pelo menos 4 caracteres

    int ano_fabricacao;
    //>= 2000 e <= ano atual

    float valor_alocacao;
    //> 0

    int quilometragem;
    //>= 0
};

void data_hora_atual(int &dia, int &mes, int &ano, int &hora, int &min, int &seg) {
    time_t t = time(NULL);
    struct tm local_time = *localtime(&t);
    ano = local_time.tm_year + 1900;
    mes = local_time.tm_mon + 1;
    dia = local_time.tm_mday;
    hora = local_time.tm_hour;
    min = local_time.tm_min;
    seg = local_time.tm_sec;
}

void listagem_clientes(Cliente clientes[], int posicao_clientes_cadastrados)
{
    system("cls");

    printf("\n--------------------------------------------------\n");
    printf("CPF\t\t\tNome");
    printf("\n--------------------------------------------------\n");

    for (int i = 0; i < posicao_clientes_cadastrados; i ++) {
        printf("%-11s\t\t%s\n", clientes[i].cpf, clientes[i].nome);
        printf("\t\t\tPlaca: %s\n", "XXX-9999");
        printf("\t\t\tTipo: %c\n", 'c');
        printf("\t\t\tModelo: %s\n", "");
        printf("\t\t\tData da locacao: %02d/%02d/%02d\n", 1, 1, 1);
    }
    printf("--------------------------------------------------");
}

void listagem_veiculos()
{
    printf("\n------------------------------------------------------------------------------\n");
    printf("%s\t\t%s\t%s\t\t\t\t%s\t%s\t%s", "Placa", "T", "Modelo", "Ano", "Km", "Valor");
    printf("\n------------------------------------------------------------------------------\n");

    printf("%s\t%c\t%-30s\t%04d\t%06d\t%04.2f", "XXX-9999", 'C', "modelo", 999999, 999999, 9999.99);

    printf("\n\t\t\tCPF: %s\n", "99999999999");
    printf("\t\t\tNome: %s\n", "Joao vitor de Soouza Coura");
    printf("\t\t\tData da locacao: %02d/%02d/%02d\n", 99, 99, 9999);

        printf("%s\t%c\t%-30s\t%04d\t%06d\t%04.2f", "XXX-9999", 'M', "modelo", 999999, 999999, 9999.99);


    printf("\n--------------------------------------------------\n");
}

void listagem_locacoes()
{

    printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
    printf("CPF\t\tNome\t\t\t\t\t\t\tPlaca\t\tModelo\t\t\t\tData");
    printf("\n---------------------------------------------------------------------------------------------------------------------------------\n"); 

    printf("%-11s\t%-50s\t%-7s\t%-30s\t%02d/%02d/%02d", "99999999999", "Joao vitor de Souza Coura", "xxx-9999", "ford", 1,2,3);

    printf("\n--------------------------------------------------\n");

}

void verificar_registro(char cpf[], Cliente clientes_cadastrados[])
{
    for (int i = 0; i < 2; i++) {
        if (cpf == clientes_cadastrados[i].cpf) {
            printf("CPF ja cadastrado");
            break;
        }
    }
}

void registrar_cpf(char cpf[], Cliente clientes_cadastrados[])
{
    while (true) {
        printf("CPF: ");
        gets(cpf);

        verificar_registro(cpf, clientes_cadastrados);

        if (strlen(cpf) == 11) {
            break;
        }

        printf("CPF INVALIDO!\n");
        system("pause");
        system("cls");
    }
}

void registrar_nome(char nome[], Cliente clientes_cadastrados[])
{
    while (true) {
        printf("Nome: ");
        gets(nome);

        if (strlen(nome) <= 50) {
            strupr(nome);
            break;
        }

        printf("NOME INVALIDO!\n");
        system("pause");
        system("cls");
    }
}

void cadastro_cliente(Cliente clientes[], int &posicao_clientes_cadastrados)
{
    system("cls");

    registrar_cpf(clientes[posicao_clientes_cadastrados].cpf);

    registrar_nome(clientes.nome);

    printf("\nCliente cadastrado com sucesso!\n");

    system("pause");

    clientes_cadastrados[posicao_clientes_cadastrados] = cliente;
    posicao_clientes_cadastrados++;
}


int main()
{
    int dia, mes, ano, hora, min, seg;
    int posicao = 0;

    Cliente clientes[50];

    data_hora_atual(dia, mes, ano, hora, min, seg);

  
    cadastro_cliente(clientes, posicao);
    cadastro_cliente(clientes, posicao);


    listagem_clientes(clientes, posicao);
    //listagem_veiculos();
    //listagem_locacoes();


    

}