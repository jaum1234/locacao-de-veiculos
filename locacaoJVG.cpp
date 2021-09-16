#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


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
    getchar();

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

    char numero_veiculos;
    void menu_principal();

    puts("Menu do Cadastro de Veiculos\n");
    printf("[1]-Cadastrar novo veiculo\n[2]-Excluir veiculo\n[3]-Listar veiculo (Ordenado por por placa)\n[4]-Listar veiculos (Ordenado por modelo)\n[5]-Voltar\n");
    scanf("%c", &numero_veiculos);


    while(numero_veiculos != '1' && numero_veiculos != '2' && numero_veiculos != '3' && numero_veiculos != '4' && numero_veiculos != '5'){
        system("cls");

        puts("Menu do Cadastro de Veiculos\n");
        printf("[1]-Cadastrar novo veiculo\n[2]-Excluir veiculo\n[3]-Listar veiculo (Ordenado por por placa)\n[4]-Listar veiculos (Ordenado por modelo)\n[5]-Voltar\n");
        puts("Erro, digite um valor valido");
        scanf("%c", &numero_veiculos);
    }

    getchar();

    if(numero_veiculos == '1'){

    }

    else if(numero_veiculos == '2'){

    }

    else if(numero_veiculos == '3'){

    }
    else if(numero_veiculos == '4'){

    }

    else
        menu_principal();
}

//MENU DE LOCAÇÃO DE VEICULOS
void locacao_devolucao()
{

    system("cls");

    char numero_locacao;
    void menu_principal();

    puts("Menu de Locacao/Devolucao de Veiculos\n");
    printf("[1]-Locar Veiculo\n[2]-Devolver Veiculo\n[3]-Listar Locacoes\n[4]-Voltar\n");
    scanf("%c", &numero_locacao);

    while(numero_locacao != '1' && numero_locacao != '2' && numero_locacao != '3' && numero_locacao != '4'){
    system("cls");

    puts("Menu de Locacao/Devolucao de Veiculos\n");
    printf("[1]-Locar Veiculo\n[2]-Devolver Veiculo\n[3]-Listar Locacoes\n[4]-Voltar\n");
    puts("Erro. Digite um valor valido");
    scanf("%c", &numero_locacao);

    }
    getchar();

    if(numero_locacao == '1'){

    }

    else if(numero_locacao == '2'){

    }

    else if(numero_locacao == '3'){

    }

    else
        menu_principal();
}


//MENU PRINCIPAL
void menu_principal()
{

    system("cls");
    char numero_menu;


    puts("Menu Principal\n");
    printf("[1]-Cadastro de Cliente\n[2]-Cadastro de Veiculos\n[3]-Locacao/Devolucao de Veiculos\n[4]-Sair\n");
    scanf("%c", &numero_menu);

    while(numero_menu != '1' && numero_menu != '2' && numero_menu != '3' && numero_menu != '4'){
        system("cls");
        puts("Menu Principal\n");
        printf("[1]-Cadastro de Cliente\n[2]-Cadastro de Veiculos\n[3]-Locacao/Devolucao de Veiculos\n[4]-Sair\n");
        puts("Erro. Digite um valor valido");
        scanf("%c", &numero_menu);

    }
    getchar();

    if(numero_menu == '1'){
        menu_cadastro_cliente();
    }

    else if(numero_menu == '2'){
        menu_cadastro_veiculos();
    }

    else if(numero_menu == '3'){
            locacao_devolucao();

    }
    else
        return;
}


int main(void)
{
    menu_principal();
    return 0;

}
