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



//MENU DO CADASTRO DE CLIENTES
void menu_cadastro_cliente()
{

    system("cls");

    int numero_clientes = 0;
    void menu_principal();

    puts("Menu do Cadastro de Clientes\n");

    printf("[1]-Cadastrar novo cliente\n[2]-Excluir cliente\n[3]-Listar clientes (Ordenado por CPF)\n[4]-Listar clientes (Ordenado por nome)\n[5]-Voltar\n");
    scanf("%d", &numero_clientes);


    while(numero_clientes != 1 && numero_clientes != 2 && numero_clientes != 3 && numero_clientes != 4 && numero_clientes != 5){
        system("cls");
        puts("Menu do Cadastro de Clientes\n");

        printf("[1]-Cadastrar novo cliente\n[2]-Excluir cliente\n[3]-Listar clientes (Ordenado por CPF)\n[4]-Listar clientes (Ordenado por nome)\n[5]-Voltar\n");
        puts("Erro. Digite um valor valido");
        scanf("%d", &numero_clientes);

    }

    if(numero_clientes == 1){

    }

    else if(numero_clientes == 2){

    }

    else if(numero_clientes == 3){

    }

    else if(numero_clientes == 4){

    }
    else
        menu_principal();
}


//MENU DE CADASTRO DE VEICULOS
void menu_cadastro_veiculos()
{

    system("cls");

    int numero_veiculos = 0;
    void menu_principal();

    puts("Menu do Cadastro de Veiculos\n");
    printf("[1]-Cadastrar novo veiculo\n[2]-Excluir veiculo\n[3]-Listar veiculo (Ordenado por por placa)\n[4]-Listar veiculos (Ordenado por modelo)\n[5]-Voltar\n");
    scanf("%d", &numero_veiculos);


    while(numero_veiculos != 1 && numero_veiculos != 2 && numero_veiculos != 3 && numero_veiculos != 4 && numero_veiculos != 5){
        system("cls");

        puts("Menu do Cadastro de Veiculos\n");
        printf("[1]-Cadastrar novo veiculo\n[2]-Excluir veiculo\n[3]-Listar veiculo (Ordenado por por placa)\n[4]-Listar veiculos (Ordenado por modelo)\n[5]-Voltar\n");
        puts("Erro, digite um valor valido");
        scanf("%d", &numero_veiculos);
    }

    if(numero_veiculos == 1){

    }

    else if(numero_veiculos == 2){

    }

    else if(numero_veiculos == 3){

    }
    else if(numero_veiculos == 4){

    }

    else
        menu_principal();
}

//MENU DE LOCAÇÃO DE VEICULOS
void locacao_devolucao()
{

    system("cls");

    int numero_locacao = 0;
    void menu_principal();

    puts("Menu de Locacao/Devolucao de Veiculos\n");
    printf("[1]-Locar Veiculo\n[2]-Devolver Veiculo\n[3]-Listar Locacoes\n[4]-Voltar\n");
    scanf("%d", &numero_locacao);

    while(numero_locacao != 1 && numero_locacao != 2 && numero_locacao != 3 && numero_locacao != 4){
    system("cls");

    puts("Menu de Locacao/Devolucao de Veiculos\n");
    printf("[1]-Locar Veiculo\n[2]-Devolver Veiculo\n[3]-Listar Locacoes\n[4]-Voltar\n");
    puts("Erro. Digite um valor valido");
    scanf("%d", &numero_locacao);

    }

    if(numero_locacao == 1){

    }

    else if(numero_locacao == 2){

    }

    else if(numero_locacao == 3){

    }

    else
        menu_principal();
}


//MENU PRINCIPAL
void menu_principal()
{

    system("cls");
    int numero_menu;


    puts("Menu Principal\n");
    printf("[1]-Cadastro de Cliente\n[2]-Cadastro de Veiculos\n[3]-Locacao/Devolucao de Veiculos\n[4]-Sair\n");
    scanf("%d", &numero_menu);

    while(numero_menu != 1 && numero_menu != 2 && numero_menu != 3 && numero_menu != 4){
        system("cls");
        puts("Menu Principal\n");
        printf("[1]-Cadastro de Cliente\n[2]-Cadastro de Veiculos\n[3]-Locacao/Devolucao de Veiculos\n[4]-Sair\n");
        puts("Erro. Digite um valor valido");
        scanf("%d", &numero_menu);

    }

    if(numero_menu == 1){
        menu_cadastro_cliente();
    }

    else if(numero_menu == 2){
        menu_cadastro_veiculos();
    }

    else if(numero_menu == 3){
            locacao_devolucao();

    }
    else
        return;
}

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

void cadastro_cliente(Cliente clientes_cadastrados[], int &posicao_clientes_cadastrados)
{
    Cliente cliente;
    system("cls");

    registrar_cpf(cliente.cpf, clientes_cadastrados);

    registrar_nome(cliente.nome, clientes_cadastrados);

    printf("\nCliente cadastrado com sucesso!\n");

    system("pause");

    clientes_cadastrados[posicao_clientes_cadastrados] = cliente;
    posicao_clientes_cadastrados++;
}


int main()
{
    int dia, mes, ano, hora, min, seg;
    int posicao = 0;

    Cliente clientes_cadastrados[50];

    menu_principal();
    return 0;

    //data_hora_atual(dia, mes, ano, hora, min, seg);

  
    //cadastro_cliente(clientes_cadastrados, posicao);
    //cadastro_cliente(clientes_cadastrados, posicao);


    //listagem_clientes(clientes_cadastrados, posicao);
    //listagem_veiculos();
    //listagem_locacoes();


    

}