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
    char placa[8];
    //XXX9999
    //nao podem existir dois veículos com a mesma placa

    char tipo;
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

void listagem_clientes(Cliente clientes[], int posicao_cliente)
{
    system("cls");

    printf("\n--------------------------------------------------\n");
    printf("CPF\t\t\tNome");
    printf("\n--------------------------------------------------\n");

    for (int i = 0; i < posicao_cliente; i ++) {
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

bool is_cpf_repetido(char cpf[], Cliente clientes[], int posicao_cliente)
{
    for (int i = 0; i < posicao_cliente; i++) {
        if (strcmp(cpf, clientes[i].cpf) == 0) {
            return true;
        }
    }
    return false;
}

void registrar_cpf(char cpf[], Cliente clientes[], int posicao_cliente)
{
    while (true) {
        printf("CPF: ");
        gets(cpf);

        if (is_cpf_repetido(cpf, clientes, posicao_cliente)) {
            printf("\nERRO NO CADASTRO. CPF JA CADASTRADO!\n");
            system("pause");
            system("cls");
            continue;
        }

        if (strlen(cpf) == 11) {
            break;
        }

        printf("CPF INVALIDO!\n");
        system("pause");
        system("cls");
    }
}

void registrar_nome(char nome[])
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

void cadastrar_cliente(Cliente clientes[], int &posicao_cliente)
{
    system("cls");

    registrar_cpf(clientes[posicao_cliente].cpf, clientes, posicao_cliente);

    registrar_nome(clientes[posicao_cliente].nome);

    system("cls");

    printf("CPF: %s\n", clientes[posicao_cliente].cpf);
    printf("Nome: %s\n", clientes[posicao_cliente].nome);

    printf("\nCliente cadastrado com sucesso!\n");

    system("pause");

    
    posicao_cliente++;
}

bool is_placa_repetida(char placa[], Veiculo veiculos[], int posicao)
{
    for (int i = 0; i < posicao; i++) {
        if (strcmp(placa, veiculos[i].placa) == 0) {
            return true;
        }
    }
    return false;
}

bool is_placa_valida(char placa[])
{
    bool letras_validas, numeros_validos;

        if (isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2])) {
            letras_validas = true;
        } else {
            letras_validas = false;
        }

        if (
            isdigit(placa[3]) && 
            isdigit(placa[4]) && 
            isdigit(placa[5]) &&
            isdigit(placa[6]) 
            ) {
            numeros_validos = true;
        } else {
            numeros_validos = false;
        }
        
    
    if (numeros_validos && letras_validas) {
        return true;
    }
    return false;
}

void registrar_placa(char placa[], Veiculo veiculos[], int posicao_veiculo)
{
    while (true) {
        printf("Placa (XXX9999): ");
        gets(placa);

        strupr(placa);
        

        if (is_placa_repetida(placa, veiculos, posicao_veiculo)) {
            printf("NAO PODEM EXISTIR DOIS VEICULOS COM A MESMA PLACA!\n");
            system("pause");
            system("cls");
            continue;
        }

        if (!is_placa_valida(placa)) {
            printf("\nESSE FORMATO DE PLACA NAO E VALIDO!\n- CUIDADO COM OS ESPACOS\n");
            system("pause");
            system("cls");
            continue;
        };

        if (strlen(placa) == 7) {
            break;
        }
        printf("PLACA INVALIDA! GRANDE DEMAIS.\n");
        system("pause");
        system("cls");
    }
}

void registrar_tipo(char &tipo)
{
    while (true) {
        
        printf("Tipo (C-Carro ou M-Moto): ");
        scanf("%c", &tipo);
        getchar();
        toupper(tipo);
        if (tipo == 'C' || tipo == 'M') {
            break;
        }
        printf("TIPO INVALIDO!\n");
        system("pause");
        system("cls");
        
    }
}

void registrar_modelo(char modelo[])
{
    while (true) {
        printf("modelo: ");
        gets(modelo);
        strupr(modelo);
        if (strlen(modelo) <= 30) {
            break;
        }
        printf("MODELO INVALIDO!\n");
        system("pause");
        system("cls");
    }
}

void registrar_ano_fabricacao(int &ano)
{
    while (true) {
        printf("Ano: ");
        scanf("%d", &ano);

        if (ano >= 2000 && ano <= 2021) {
            break;
        }
        printf("ANO INVALIDO!\n");
        system("pause");
        system("cls");
    }
}

void registrar_valor_alocacao(float &valor_alocacao)
{
    while (true) {
        printf("Valor da alocacao/dia: ");
        scanf("%f", &valor_alocacao);

        
        if (valor_alocacao > 0) {
            break;
        }
        printf("VALOR DE ALOCACAO INVALIDO!\n");
        system("pause");
        system("cls");
    }
}

void registrar_quilometragem(int &quilometragem)
{
    while (true) {
        printf("Quilometragem: ");
        scanf("%d", &quilometragem);

        if (quilometragem >= 0) {
            break;
        }
        printf("MODELO INVALIDO!\n");
        system("pause");
        system("cls");
    }
}

void cadastrar_veiculo(Veiculo veiculos[], int &posicao_veiculo)
{
    system("cls");

    registrar_placa(veiculos[posicao_veiculo].placa, veiculos, posicao_veiculo);
    registrar_tipo(veiculos[posicao_veiculo].tipo);
    registrar_modelo(veiculos[posicao_veiculo].modelo);
    registrar_ano_fabricacao(veiculos[posicao_veiculo].ano_fabricacao);
    registrar_valor_alocacao(veiculos[posicao_veiculo].valor_alocacao);
    registrar_quilometragem(veiculos[posicao_veiculo].quilometragem);

    system("cls");

    printf("Placa: %s\n", veiculos[posicao_veiculo].placa);
    printf("Tipo (C-Carro ou M-Moto): %c\n", veiculos[posicao_veiculo].tipo);
    printf("Modelo: %s\n", veiculos[posicao_veiculo].modelo);
    printf("Ano: %d\n", veiculos[posicao_veiculo].ano_fabricacao);
    printf("Valor da alocacao/dia: %.2f\n", veiculos[posicao_veiculo].valor_alocacao);
    printf("Quilometragem: %d\n\n", veiculos[posicao_veiculo].quilometragem);
    getchar();

    printf("Veiculo cadastrado com sucesso!\n");
    system("pause");

    posicao_veiculo++;
}

int main()
{
    int dia, mes, ano, hora, min, seg;
    int posicao_cliente = 0, posicao_veiculo = 0;

    Cliente clientes[50];
    Veiculo veiculos[50];

    //menu_principal();
    //return 0;

    //data_hora_atual(dia, mes, ano, hora, min, seg);

  
    cadastrar_cliente(clientes, posicao_cliente);
    //cadastrar_veiculo(veiculos, posicao_veiculo);
    //cadastrar_veiculo(veiculos, posicao_veiculo);
    cadastrar_cliente(clientes, posicao_cliente);


    //listagem_clientes(clientes_cadastrados, posicao_cliente);
    //listagem_veiculos();
    //listagem_locacoes();


    

}