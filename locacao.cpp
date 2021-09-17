#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

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

    int ano_locacao;
    int mes_locacao;
    int dia_locacao;

    bool em_locacao = false;
};

struct Cliente {
    char cpf[12];
    char nome[50];
    //pelo menos 4 caracteres
    bool em_locacao = false;

    Veiculo veiculo;
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

void ordenar_por_cpf(Cliente clientes[], int posicao_cliente) {
    for (int i = 0; i < posicao_cliente; i++) {
        for (int j = i; j < posicao_cliente; j++) {
            if (strcmp(clientes[i].cpf, clientes[j].cpf) == 1) {
                Cliente temp = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = temp;
            }
        }
    }
}

void ordenar_por_nome(Cliente clientes[], int posicao_cliente)
{
    for (int i = 0; i < posicao_cliente; i++) {
        for (int j = i; j < posicao_cliente; j++) {
            if (strcmp(clientes[i].nome, clientes[j].nome) == 1) {
                Cliente temp = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = temp;
            }
        }
    }
}

void listagem_clientes(Cliente clientes[], int posicao_cliente, int tipo_ordenamento)
{
    if (tipo_ordenamento == 1) {
        ordenar_por_cpf(clientes, posicao_cliente);
    } else if (tipo_ordenamento == 2) {
        ordenar_por_nome(clientes, posicao_cliente);
    }

    system("cls");

    printf("\n--------------------------------------------------\n");
    printf("CPF\t\t\tNome");
    printf("\n--------------------------------------------------\n");

    for (int i = 0; i < posicao_cliente; i ++) {
        printf("%-11s\t\t%s\n", clientes[i].cpf, clientes[i].nome);
        if (clientes[i].em_locacao) {
            printf("\t\t\tPlaca: %s\n", clientes[i].veiculo.placa);
            printf("\t\t\tTipo: %c\n", clientes[i].veiculo.tipo);
            printf("\t\t\tModelo: %s\n", clientes[i].veiculo.modelo);
            printf("\t\t\tData da locacao: %02d/%02d/%02d\n", 
                clientes[i].veiculo.dia_locacao, 
                clientes[i].veiculo.mes_locacao, 
                clientes[i].veiculo.ano_locacao
                );
        }
    }
    printf("--------------------------------------------------");
}

int verificar_cliente_associado(char placa[], Cliente clientes[], int posicao_cliente)
{
    for (int i = 0; i < posicao_cliente; i++) {
        if (strcmp(placa, clientes[i].veiculo.placa) == 0) {
            return i;
        }
    }
}

void listagem_veiculos(Veiculo veiculos[], Cliente clientes[], int posicao_veiculo, int posicao_cliente)
{
    printf("\n------------------------------------------------------------------------------\n");
    printf("Placa\t\t" "T\t" "Modelo\t\t\t\t" "Ano\t" "Km\t" "Valor");
    printf("\n------------------------------------------------------------------------------\n");

    for (int i = 0; i < posicao_veiculo; i++) {

        printf("%s\t\t%c\t%-30s\t\%04d\t%06d\t%04.2f\n", 
            veiculos[i].placa, 
            veiculos[i].tipo, 
            veiculos[i].modelo, 
            veiculos[i].ano_fabricacao, 
            veiculos[i].quilometragem, 
            veiculos[i].valor_alocacao
            );

        if (veiculos[i].em_locacao) {
            int posicao_encontrado_cliente = verificar_cliente_associado(veiculos[i].placa, clientes, posicao_cliente);

            printf("\t\t\tCPF: %s\n", clientes[posicao_encontrado_cliente].cpf);
            printf("\t\t\tNome: %s\n", clientes[posicao_encontrado_cliente].nome);
            printf("\t\t\tData da locacao: %02d/%02d/%02d\n", 
                clientes[posicao_encontrado_cliente].veiculo.dia_locacao, 
                clientes[posicao_encontrado_cliente].veiculo.mes_locacao, 
                clientes[posicao_encontrado_cliente].veiculo.ano_locacao
                );
        }
    }

    printf("------------------------------------------------------------------------------\n");
}

void ordenar_por_placa(Cliente clientes[], int posicao_cliente) {
    for (int i = 0; i < posicao_cliente; i++) {
        for (int j = i; j < posicao_cliente; j++) {
            if (strcmp(clientes[i].veiculo.placa, clientes[j].veiculo.placa) == 1) {
                Cliente temp = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = temp;
            }
        }
    }
}

void ordenar_por_modelo(Cliente clientes[], int posicao_cliente) {
    for (int i = 0; i < posicao_cliente; i++) {
        for (int j = i; j < posicao_cliente; j++) {
            if (strcmp(clientes[i].veiculo.modelo, clientes[j].veiculo.modelo) == 1) {
                Cliente temp = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = temp;
            }
        }
    }
}

void listagem_locacoes(Cliente clientes[], int posicao_cliente, int tipo_ordenamento)
{
    if (tipo_ordenamento == 1) {
        ordenar_por_placa(clientes, posicao_cliente);
    } else if (tipo_ordenamento == 2) {
        ordenar_por_modelo(clientes, posicao_cliente);
    }

    printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
    printf("CPF\t\tNome\t\t\t\t\t\t\tPlaca\t\tModelo\t\t\t\tData");
    printf("\n---------------------------------------------------------------------------------------------------------------------------------\n"); 

    for (int i = 0; i < posicao_cliente; i++) {
        if (clientes[i].em_locacao) {
            printf("%-11s\t%-50s\t%-7s\t\t%-30s\t%02d/%02d/%02d\n", 
                clientes[i].cpf, 
                clientes[i].nome, 
                clientes[i].veiculo.placa, 
                clientes[i].veiculo.modelo, 
                clientes[i].veiculo.dia_locacao,
                clientes[i].veiculo.mes_locacao,
                clientes[i].veiculo.ano_locacao
                );
        }
    }

    printf("--------------------------------------------------\n");

}

int is_cpf_cadastrado(char cpf[], Cliente clientes[], int posicao_cliente)
{
    for (int i = 0; i < posicao_cliente; i++) {
        if (strcmp(cpf, clientes[i].cpf) == 0) {
            return i;
        }
    }
    return -1;
}

void registrar_cpf(char cpf[], Cliente clientes[], int posicao_cliente)
{
    while (true) {
        printf("CPF: ");
        gets(cpf);

        if (is_cpf_cadastrado(cpf, clientes, posicao_cliente) >= 0) {
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

int is_placa_cadastrada(char placa[], Veiculo veiculos[], int posicao)
{
    for (int i = 0; i < posicao; i++) {
        if (strcmp(placa, veiculos[i].placa) == 0) {
            return i;
        }
    }
    return -1;
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
        

        if (is_placa_cadastrada(placa, veiculos, posicao_veiculo) >= 0) {
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
        printf("QUILOMETRAGEM INVALIDA!\n");
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


void realizar_locacao(
    Cliente clientes[], 
    Veiculo veiculos[], 
    int posicao_cliente, 
    int posicao_veiculo, 
    int dia, 
    int mes, 
    int ano
    ) {

    int posicao_encontrado_cliente, posicao_encontrado_veiculo;

    system("cls");

    while (true) {
        char cpf[12];
        printf("CPF: ");
        gets(cpf);

        posicao_encontrado_cliente = is_cpf_cadastrado(cpf, clientes, posicao_cliente);
        if (posicao_encontrado_cliente < 0) {
            printf("ERRO NA LOCACAO. CLIENTE NAO CADASTRADO!\n");
            system("pause");
            system("cls");   
            continue;  
        } 

        if (clientes[posicao_encontrado_cliente].em_locacao) {
            printf("ERRO NA LOCACAO. CLIENTE JA TEM LOCACAO!\n\n");
            printf("Dados da locacao:\n");
            printf("Placa: %s\nModelo: %s\nData de locacao: %02d/%02d/%04d\n\n",
                clientes[posicao_encontrado_cliente].veiculo.placa,
                clientes[posicao_encontrado_cliente].veiculo.modelo,
                clientes[posicao_encontrado_cliente].veiculo.dia_locacao,
                clientes[posicao_encontrado_cliente].veiculo.mes_locacao,
                clientes[posicao_encontrado_cliente].veiculo.ano_locacao
            );
            system("pause");
            system("cls");
            continue;
        }

        break;

    }

    while (true) {
        char placa[8];
        printf("Placa: ");
        gets(placa);

        strupr(placa);

        posicao_encontrado_veiculo = is_placa_cadastrada(placa, veiculos, posicao_veiculo);
        if (posicao_encontrado_veiculo < 0) {
            printf("ERRO NA LOCACAO. VEICULO NAO ENCONTRADO!\n");
            system("pause");
            system("cls");
            continue;
        }

        if (veiculos[posicao_encontrado_veiculo].em_locacao) {
            int posicao_cliente_associado = verificar_cliente_associado(
                veiculos[posicao_encontrado_veiculo].placa, 
                clientes, 
                posicao_cliente
                );

            printf("\nERRO NA LOCACAO. VEICULO JA LOCACAO!\n\n");
            printf("Dados da locacao:\n");
            printf("CPF: %s\nNome: %s\nData da locacao: %02d/%02d/%04d\n\n",
                clientes[posicao_cliente_associado].cpf,
                clientes[posicao_cliente_associado].nome,
                clientes[posicao_cliente_associado].veiculo.dia_locacao,
                clientes[posicao_cliente_associado].veiculo.mes_locacao,
                clientes[posicao_cliente_associado].veiculo.ano_locacao
            );
            system("pause");
            system("cls");
            continue;
        }

       break;
    }

    veiculos[posicao_encontrado_veiculo].em_locacao = true;

    clientes[posicao_encontrado_cliente].veiculo = veiculos[posicao_encontrado_veiculo];
    clientes[posicao_encontrado_cliente].veiculo.dia_locacao = dia;
    clientes[posicao_encontrado_cliente].veiculo.mes_locacao = mes;
    clientes[posicao_encontrado_cliente].veiculo.ano_locacao = ano;
    clientes[posicao_encontrado_cliente].em_locacao = true;

    printf("\nLocacao concedida!\n\n");
    printf("Nome: %s\nModelo: %s\nTipo: %c\nQuilometragem atual: %d\nData da Locacao: %02d/%02d/%04d\n\n",
        clientes[posicao_encontrado_cliente].nome,
        clientes[posicao_encontrado_cliente].veiculo.modelo,
        clientes[posicao_encontrado_cliente].veiculo.tipo,
        clientes[posicao_encontrado_cliente].veiculo.quilometragem,
        dia, mes, ano
    );

    system("pause");
    
}

int main()
{
    int dia, mes, ano, hora, min, seg;
    int posicao_cliente = 0, posicao_veiculo = 0;

    Cliente clientes[50];
    Veiculo veiculos[50];

    data_hora_atual(dia, mes, ano, hora, min, seg);
    //menu_principal();
    //return 0;


  
    cadastrar_cliente(clientes, posicao_cliente);
    cadastrar_cliente(clientes, posicao_cliente);
    cadastrar_cliente(clientes, posicao_cliente);
    cadastrar_veiculo(veiculos, posicao_veiculo);
    cadastrar_veiculo(veiculos, posicao_veiculo);
    cadastrar_veiculo(veiculos, posicao_veiculo);

    realizar_locacao(clientes, veiculos, posicao_cliente, posicao_veiculo, dia, mes, ano);
    realizar_locacao(clientes, veiculos, posicao_cliente, posicao_veiculo, dia, mes, ano);
    realizar_locacao(clientes, veiculos, posicao_cliente, posicao_veiculo, dia, mes, ano);

    //listagem_clientes(clientes, posicao_cliente, 2);
    //listagem_veiculos(veiculos, clientes, posicao_veiculo, posicao_cliente);
    listagem_locacoes(clientes, posicao_cliente, 2);
    
}