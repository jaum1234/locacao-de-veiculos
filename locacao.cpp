#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <cstdlib>

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

void menu_principal(Cliente clientes[], Veiculo veiculos[], int posicao_cliente, int posicao_veiculo);
//MENU DO CADASTRO DE CLIENTES

void data_hora_atual(int &dia, int &mes, int &ano) {
    time_t t = time(NULL);
    struct tm local_time = *localtime(&t);
    ano = local_time.tm_year + 1900;
    mes = local_time.tm_mon + 1;
    dia = local_time.tm_mday;
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

void listagem_clientes(Cliente clientes[], int posicao_cliente, Veiculo veiculos[], int posicao_veiculo, int tipo_ordenamento)
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
    printf("--------------------------------------------------\n");
    system("pause");

    menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);
}

int verificar_cliente_associado(char placa[], Cliente clientes[], int posicao_cliente)
{
    for (int i = 0; i < posicao_cliente; i++) {
        if (strcmp(placa, clientes[i].veiculo.placa) == 0) {
            return i;
        }
    }   
    return -1;
}

void ordenar_por_placa(Veiculo veiculos[], int posicao_veiculo) {
    for (int i = 0; i < posicao_veiculo; i++) {
        for (int j = i; j < posicao_veiculo; j++) {
            if (strcmp(veiculos[i].placa, veiculos[j].placa) == 1) {
                Veiculo temp = veiculos[i];
                veiculos[i] = veiculos[j];
                veiculos[j] = temp;
            }
        }
    }
}

void ordenar_por_modelo(Veiculo veiculos[], int tamanho_array_veiculos) {
    for (int i = 0; i < tamanho_array_veiculos; i++) {
        for (int j = i; j < tamanho_array_veiculos; j++) {
            if (strcmp(veiculos[i].modelo, veiculos[j].modelo) == 1) {
                Veiculo temp = veiculos[i];
                veiculos[i] = veiculos[j];
                veiculos[j] = temp;
            }
        }
    }
}

void listagem_veiculos(Veiculo veiculos[], Cliente clientes[], int posicao_veiculo, int posicao_cliente, int tipo_ordenamento)
{
     if (tipo_ordenamento == 1) {
        ordenar_por_placa(veiculos, posicao_veiculo);
    } else if (tipo_ordenamento == 2) {
        ordenar_por_modelo(veiculos, posicao_veiculo);
    }

    system("cls");

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
    system("pause");

    menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);
}


void listagem_locacoes(Cliente clientes[], Veiculo veiculos[], int posicao_cliente, int posicao_veiculo)
{
    system("cls");

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
    system("pause");
    system("cls");

    menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);
}

int encontrar_cpf(char cpf[], Cliente clientes[], int tamanho_array_clientes)
{
    for (int posicao = 0; posicao < tamanho_array_clientes; posicao++) {
        if (strcmp(cpf, clientes[posicao].cpf) == 0) {
            return posicao;
        }
    }
    return -1;
}

bool is_cpf_valido(char cpf[])
{
    if (strlen(cpf) != 11) {
        return false;
    }

    for (int i = 0; i < strlen(cpf); i++) {
        if (!isdigit(cpf[i])) {
            return false;
        }
    }

    return true;
}

void registrar_cpf(char cpf[], Cliente clientes[], int posicao_cliente, int posicao_veiculo, Veiculo veiculos[])
{
    while (true) {
        printf("CPF: ");
        gets(cpf);
        

        if (encontrar_cpf(cpf, clientes, posicao_cliente) >= 0) {
            printf("\nERRO NO CADASTRO. CPF JA CADASTRADO!\n");
            system("pause");
            system("cls");
            continue;
        }
        
        if (!is_cpf_valido(cpf)) {
            printf("CPF INVALIDO!\n");
            system("pause");
            system("cls");
            continue;
        }
        break;
    }
}

bool is_nome_valido(char nome[], Cliente clientes[], int posicao_cliente)
{
    if (strlen(nome) < 4 || strlen(nome) > 50) {
        return false;
    }

    return true;
}

void registrar_nome(char nome[], Cliente clientes[], int posicao_cliente)
{
    while (true) {
        printf("Nome: ");
        gets(nome);

        strupr(nome);
        
        if (!is_nome_valido(nome, clientes, posicao_cliente)) {
            printf("\nNOME INVALIDO!\n");
            system("pause");
            system("cls");
            continue;
        }
        break;
    }
}

void cadastrar_cliente(Cliente clientes[], Veiculo veiculos[], int posicao_cliente, int posicao_veiculo)
{
    system("cls");

    registrar_cpf(clientes[posicao_cliente].cpf, clientes, posicao_cliente, posicao_veiculo, veiculos);

    registrar_nome(clientes[posicao_cliente].nome, clientes, posicao_cliente);

    system("cls");

    printf("CPF: %s\n", clientes[posicao_cliente].cpf);
    printf("Nome: %s\n", clientes[posicao_cliente].nome);

    printf("\nCliente cadastrado com sucesso!\n");

    posicao_cliente++;
    system("pause");

    menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);

}

int encontrar_placa(char placa[], Veiculo veiculos[], int tamanho_array_veiculos)
{
    for (int posicao = 0; posicao < tamanho_array_veiculos; posicao++) {
        if (strcmp(placa, veiculos[posicao].placa) == 0) {
            return posicao;
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

void registrar_placa(char placa[], Veiculo veiculos[], int posicao_veiculo, Cliente clientes[], int posicao_cliente)
{
    while (true) {
        printf("Placa (XXX9999): ");
        gets(placa);

        strupr(placa);
        
        if (encontrar_placa(placa, veiculos, posicao_veiculo) >= 0) {
            printf("NAO PODEM EXISTIR DOIS VEICULOS COM A MESMA PLACA!\n");
            system("pause");
            system("cls");
            continue;
        }

        if (!is_placa_valida(placa)) {
            printf("\nESSE FORMATO DE PLACA NAO EH VALIDO!\n- CUIDADO COM OS ESPACOS\n");
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

void registrar_ano_fabricacao(int &ano, int ano_atual)
{
    while (true) {
        printf("Ano: ");
        scanf("%d", &ano);
        getchar();

        if (ano >= 2000 && ano <= ano_atual) {
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
        getchar();
        
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
        getchar();

        if (quilometragem >= 0) {
            break;
        }
        printf("QUILOMETRAGEM INVALIDA!\n");
        system("pause");
        system("cls");
    }
}

void cadastrar_veiculo(Cliente clientes[], Veiculo veiculos[], int posicao_cliente, int posicao_veiculo)
{
    int dia, mes, ano;
    data_hora_atual(dia, mes, ano);

    system("cls");

    registrar_placa(veiculos[posicao_veiculo].placa, veiculos, posicao_veiculo, clientes, posicao_cliente);
    registrar_tipo(veiculos[posicao_veiculo].tipo);
    registrar_modelo(veiculos[posicao_veiculo].modelo);
    registrar_ano_fabricacao(veiculos[posicao_veiculo].ano_fabricacao, ano);
    registrar_valor_alocacao(veiculos[posicao_veiculo].valor_alocacao);
    registrar_quilometragem(veiculos[posicao_veiculo].quilometragem);

    system("cls");

    printf("Placa: %s\n", veiculos[posicao_veiculo].placa);
    printf("Tipo (C-Carro ou M-Moto): %c\n", veiculos[posicao_veiculo].tipo);
    printf("Modelo: %s\n", veiculos[posicao_veiculo].modelo);
    printf("Ano: %d\n", veiculos[posicao_veiculo].ano_fabricacao);
    printf("Valor da alocacao/dia: %.2f\n", veiculos[posicao_veiculo].valor_alocacao);
    printf("Quilometragem: %d\n\n", veiculos[posicao_veiculo].quilometragem);

    printf("Veiculo cadastrado com sucesso!\n");
    posicao_veiculo++;
    system("pause");

    menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);

}


void realizar_locacao(
    Cliente clientes[], 
    Veiculo veiculos[], 
    int posicao_cliente, 
    int posicao_veiculo
    ) {

    int dia, mes, ano;
    data_hora_atual(dia, mes, ano);
    int posicao_encontrado_cliente, posicao_encontrado_veiculo;

    system("cls");

    while (true) {
        char cpf[12];
        printf("CPF: ");
        gets(cpf);

        posicao_encontrado_cliente = encontrar_cpf(cpf, clientes, posicao_cliente);
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

        posicao_encontrado_veiculo = encontrar_placa(placa, veiculos, posicao_veiculo);
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

    menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);
    
}

bool is_bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 ==0);
}

int get_qtd_dias_mes(int mes, int ano)
{
    int qtd_dias_mes = 31;

    switch (mes) {
        case 2:
            if (is_bissexto(ano)) {
                return qtd_dias_mes -= 2;
                break;
            }
            return qtd_dias_mes -= 3;
            break;
        case 4: 
        case 6: 
        case 9: 
        case 11:
            qtd_dias_mes--;
            break;
    }

    return qtd_dias_mes;
}

int get_total_dias_locacao(
    int dia_locacao,
    int mes_locacao,
    int ano_locacao,
    int dia_devolucao,
    int mes_devolucao,
    int ano_devolucao
) {

    int total_dias = 0;
    int ultimo_mes_ano = 12;

    int ano_atual = ano_locacao;
    for (int mes_atual = mes_locacao; mes_atual <= ultimo_mes_ano; mes_atual++) {
        switch (mes_atual) {
            case 2:
                if (is_bissexto(ano_atual)) {
                    total_dias += 29;
                    break;
                }
                total_dias += 28;
                break;
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                total_dias += 31;
                break;
            case 4: case 6: case 9: case 11:
                total_dias += 30;
                break;
        }


        if (mes_atual == mes_devolucao && ano_atual == ano_devolucao) {
            break;
        }

        if (mes_atual == ultimo_mes_ano) {
            ano_atual++;
            mes_atual = 0;
        }
    }

    int devolucao_qtd_dias_mes = get_qtd_dias_mes(mes_devolucao, ano_devolucao);
    
    int excesso_dias_locacao = dia_locacao;
    int excesso_dias_devolucao = devolucao_qtd_dias_mes - dia_devolucao;

    total_dias -= (excesso_dias_locacao + excesso_dias_devolucao);

    return total_dias;
}

void realizar_devolucao(Cliente clientes[], Veiculo veiculos[], int posicao_cliente, int posicao_veiculo)
{
    system("cls");

    char cpf[12];
    int dia_devolucao = 0, mes_devolucao = 0, ano_devolucao = 0;
    int quilometragem_devolucao;
    int posicao_cliente_associado;

    while (true) {
        printf("CPF: ");
        gets(cpf);

        posicao_cliente_associado = encontrar_cpf(cpf, clientes, posicao_cliente);
        if (posicao_cliente_associado < 0) {
            printf("ERRO NA DEVOLUCAO. CLIENTE NAO CADASTRADO!\n");
            system("pause");
            system("cls");
            menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);
        }

        if (!clientes[posicao_cliente_associado].em_locacao) {
            printf("ERRO NA DEVOLUCAO. CLIENTE NAO POSSUI LOCACAO!\n");
            system("pause");
            system("cls");
            continue;
        }

        break;
    }

    while(true) {
        printf("Data de devolucao (ex: 20 12 2021): ");
        scanf("%d %d %d", &dia_devolucao, &mes_devolucao, &ano_devolucao);
        getchar();

        if (mes_devolucao < 1 || mes_devolucao > 12) {
            printf("\nO MES PRECISA ESTAR NO INTERVALO ENTRE 1 E 12!\n");
            system("pause");
            system("cls");
            continue;
        }

        int devolucao_qtd_dias_mes = get_qtd_dias_mes(mes_devolucao, ano_devolucao);

        if (dia_devolucao > devolucao_qtd_dias_mes || dia_devolucao < 1) {
            printf("\nO DIA PRECISA ESTAR NO ENTERVALO ENTRE 1 E %d!\n", devolucao_qtd_dias_mes);
            system("pause");
            system("cls");
            continue;
        }

        if (ano_devolucao > clientes[posicao_cliente_associado].veiculo.ano_locacao) {
            break;
        } else if (ano_devolucao == clientes[posicao_cliente_associado].veiculo.ano_locacao) {
            if (mes_devolucao > clientes[posicao_cliente_associado].veiculo.mes_locacao) {
                break;
            } else if (mes_devolucao == clientes[posicao_cliente_associado].veiculo.mes_locacao) {
                if (dia_devolucao >= clientes[posicao_cliente_associado].veiculo.dia_locacao) {
                    break;
                }
            }
        }

        printf("ERRO DA DEVOLUCAO. DATA DE DEVOLUCAO ANTERIOR A DATA DE %02d/%02d/%04d\n",
            clientes[posicao_cliente_associado].veiculo.dia_locacao,
            clientes[posicao_cliente_associado].veiculo.mes_locacao,
            clientes[posicao_cliente_associado].veiculo.ano_locacao      
        );
        system("pause");
        system("cls");
    }

    while (true) {
        printf("Quilometragem atual: ");
        scanf("%d", &quilometragem_devolucao);
        getchar();

        if (quilometragem_devolucao < clientes[posicao_cliente_associado].veiculo.quilometragem) {
            printf("ERRO DA DEVOLUCAO. QUILOMETRAGEM MENOR QUE A QUILOMETRAGEM DA LOCACAO %d\n",
                clientes[posicao_cliente_associado].veiculo.quilometragem
            );
            system("pause");
            system("cls");
            continue;
        }
        break;
    }

    int total_dias_locacao = get_total_dias_locacao(
        clientes[posicao_cliente_associado].veiculo.dia_locacao,
        clientes[posicao_cliente_associado].veiculo.mes_locacao,
        clientes[posicao_cliente_associado].veiculo.ano_locacao,
        dia_devolucao,
        mes_devolucao,
        ano_devolucao
    );

    int difereca_quilometragem = quilometragem_devolucao - clientes[posicao_cliente_associado].veiculo.quilometragem;

    float valor_alocacao = total_dias_locacao*clientes[posicao_cliente_associado].veiculo.valor_alocacao;
    float valor_quilometragem = difereca_quilometragem*1.5;
    float pagamento_total = valor_alocacao + valor_quilometragem; 

    int posicao_veiculo_associado = encontrar_placa(
        clientes[posicao_cliente_associado].veiculo.placa, 
        veiculos,
        posicao_veiculo 
    );


    printf("\nNome: %s\nPlaca: %s\nModelo: %s\nData da locacao: %02d/%02d/%04d\nQuilometragem: %d\n\n",
        clientes[posicao_cliente_associado].nome,
        clientes[posicao_cliente_associado].veiculo.placa,
        clientes[posicao_cliente_associado].veiculo.modelo,
        clientes[posicao_cliente_associado].veiculo.dia_locacao,
        clientes[posicao_cliente_associado].veiculo.mes_locacao,
        clientes[posicao_cliente_associado].veiculo.ano_locacao,
        clientes[posicao_cliente_associado].veiculo.quilometragem
    );

    Veiculo veiculo;

    clientes[posicao_cliente_associado].em_locacao = false;
    clientes[posicao_cliente].veiculo = veiculo;

    veiculos[posicao_veiculo_associado].quilometragem = quilometragem_devolucao;
    veiculos[posicao_veiculo_associado].em_locacao = false;
    printf("DEVOLUCAO REALIZADA COM SUCESSO:\n");
    printf("No. de dia: %d\nQuilometragem rodada: %d km\nValor a pagar: %.2f + %.2f = %.2f\n\n",
        total_dias_locacao, 
        difereca_quilometragem,
        valor_alocacao,
        valor_quilometragem,
        pagamento_total
    );
    system("pause");
    system("cls");

    menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);
}

void excluir_cliente(Cliente clientes[], int &posicao_cliente, Veiculo veiculos[], int posicao_veiculo)
{
    system("cls");

    char cpf[12];
    int posicao_cliente_encontrado;

    while (true) {
        printf("CPf: ");
        gets(cpf);

        posicao_cliente_encontrado = encontrar_cpf(cpf, clientes, posicao_cliente);

        if (posicao_cliente_encontrado < 0) {
            printf("\nERRO NA EXCLUSAO. CLIENTE NAO CADASTRADO!\n");
            system("pause");
            system("cls");
            menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);
        }

        if (clientes[posicao_cliente_encontrado].em_locacao) {
            printf("\nERRO NA EXCLUSAO. CLIENTE TEM UMA LOCACAO!\n");
            system("pause");
            system("cls");
            menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);
        }
        
        break;
    }

    for (int i = posicao_cliente_encontrado; i < posicao_cliente; i++) {
        clientes[i] = clientes[i + 1];
    }

    posicao_cliente--;

    printf("\nCliente excluido com sucesso!\n");
    system("pause");
    system("cls");
    menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);
}

void excluir_veiculo(Cliente clientes[],  int posicao_cliente, Veiculo veiculos[], int posicao_veiculo)
{
    system("cls");
    int posicao_veiculo_encontrado;

    while (true) {
        char placa[8];

        printf("Placa: ");
        gets(placa);

        strupr(placa);

        posicao_veiculo_encontrado = encontrar_placa(placa, veiculos, posicao_veiculo);

        if (posicao_veiculo_encontrado < 0) {
            printf("\nERRO NA EXCLUSAO. VEICULO NAO CADASTRADO!\n");
            system("pause");
            system("cls");
            menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);

        }

        if (veiculos[posicao_veiculo_encontrado].em_locacao) {
            printf("\nERRO NA EXCLUSAO. VEICULO ESTA LOCADO!\n");
            system("pause");
            system("cls");
            menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);
        }

        break;
    }

    for (int i = posicao_veiculo_encontrado; i < posicao_veiculo; i++) {
        veiculos[i] = veiculos[i + 1];
    }

    posicao_veiculo--;
    
    printf("\nVeiculo excluido com sucesso!\n");
    system("pause");
    system("cls");
    menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);
}

void menu_cadastro_cliente(Cliente clientes[], Veiculo veiculos[], int posicao_cliente, int posicao_veiculo)
{

    system("cls");

    int numero_clientes = 0;
    

    puts("Menu do Cadastro de Clientes\n");

    printf("[1]-Cadastrar novo cliente\n[2]-Excluir cliente\n[3]-Listar clientes (Ordenado por CPF)\n[4]-Listar clientes (Ordenado por nome)\n[5]-Voltar\n");
    scanf("%d", &numero_clientes);
    getchar();


    while(numero_clientes != 1 && numero_clientes != 2 && numero_clientes != 3 && numero_clientes != 4 && numero_clientes != 5){
        system("cls");
        puts("Menu do Cadastro de Clientes\n");

        printf("[1]-Cadastrar novo cliente\n[2]-Excluir cliente\n[3]-Listar clientes (Ordenado por CPF)\n[4]-Listar clientes (Ordenado por nome)\n[5]-Voltar\n");
        puts("Erro. Digite um valor valido");
        scanf("%d", &numero_clientes);
        getchar();

    }

    if(numero_clientes == 1){
        cadastrar_cliente(clientes, veiculos, posicao_cliente, posicao_veiculo);
    }

    else if(numero_clientes == 2){
        excluir_cliente(clientes, posicao_cliente, veiculos, posicao_veiculo);
    }

    else if(numero_clientes == 3){
        listagem_clientes(clientes, posicao_cliente, veiculos ,posicao_veiculo, 1);
    }

    else if(numero_clientes == 4){
        listagem_clientes(clientes, posicao_cliente, veiculos , posicao_veiculo, 2);
    }
    else
        menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);
}


//MENU DE CADASTRO DE VEICULOS
void menu_cadastro_veiculos(Cliente clientes[], Veiculo veiculos[], int posicao_cliente, int posicao_veiculo)
{
    system("cls");

    int numero_veiculos = 0;

    puts("Menu do Cadastro de Veiculos\n");
    printf("[1]-Cadastrar novo veiculo\n[2]-Excluir veiculo\n[3]-Listar veiculo (Ordenado por por placa)\n[4]-Listar veiculos (Ordenado por modelo)\n[5]-Voltar\n");
    scanf("%d", &numero_veiculos);
    getchar();


    while(numero_veiculos != 1 && numero_veiculos != 2 && numero_veiculos != 3 && numero_veiculos != 4 && numero_veiculos != 5){
        system("cls");

        puts("Menu do Cadastro de Veiculos\n");
        printf("[1]-Cadastrar novo veiculo\n[2]-Excluir veiculo\n[3]-Listar veiculo (Ordenado por por placa)\n[4]-Listar veiculos (Ordenado por modelo)\n[5]-Voltar\n");
        puts("Erro, digite um valor valido");
        scanf("%d", &numero_veiculos);
        getchar();
    }

    if(numero_veiculos == 1){
        cadastrar_veiculo(clientes, veiculos, posicao_cliente, posicao_veiculo);
    }

    else if(numero_veiculos == 2){
        excluir_veiculo(clientes, posicao_cliente, veiculos, posicao_veiculo);
    }

    else if(numero_veiculos == 3){
        listagem_veiculos(veiculos, clientes, posicao_veiculo, posicao_cliente, 1);
    }
    else if(numero_veiculos == 4){
        listagem_veiculos(veiculos, clientes, posicao_veiculo, posicao_cliente, 2);
    }

    else
        menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);
}

//MENU DE LOCAÇÃO DE VEICULOS
void locacao_devolucao(Cliente clientes[], Veiculo veiculos[], int posicao_cliente, int posicao_veiculo)
{

    system("cls");

    int numero_locacao = 0;

    puts("Menu de Locacao/Devolucao de Veiculos\n");
    printf("[1]-Locar Veiculo\n[2]-Devolver Veiculo\n[3]-Listar Locacoes\n[4]-Voltar\n");
    scanf("%d", &numero_locacao);
    getchar();

    while(numero_locacao != 1 && numero_locacao != 2 && numero_locacao != 3 && numero_locacao != 4){
    system("cls");

    puts("Menu de Locacao/Devolucao de Veiculos\n");
    printf("[1]-Locar Veiculo\n[2]-Devolver Veiculo\n[3]-Listar Locacoes\n[4]-Voltar\n");
    puts("Erro. Digite um valor valido");
    scanf("%d", &numero_locacao);
    getchar();

    }

    if(numero_locacao == 1){
        realizar_locacao(clientes, veiculos, posicao_cliente, posicao_veiculo);
    }

    else if(numero_locacao == 2){
        realizar_devolucao(clientes, veiculos, posicao_cliente, posicao_veiculo);
    }

    else if(numero_locacao == 3){
        listagem_locacoes(clientes, veiculos, posicao_cliente, posicao_veiculo);
    }

    else
        menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);
}


//MENU PRINCIPAL
void menu_principal(Cliente clientes[], Veiculo veiculos[], int posicao_cliente, int posicao_veiculo)
{
    
    system("cls");
    int numero_menu;


    puts("Menu Principal\n");
    printf("[1]-Cadastro de Cliente\n[2]-Cadastro de Veiculos\n[3]-Locacao/Devolucao de Veiculos\n[4]-Sair\n");
    scanf("%d", &numero_menu);
    getchar();

    while(numero_menu != 1 && numero_menu != 2 && numero_menu != 3 && numero_menu != 4){
        system("cls");
        puts("Menu Principal\n");
        printf("[1]-Cadastro de Cliente\n[2]-Cadastro de Veiculos\n[3]-Locacao/Devolucao de Veiculos\n[4]-Sair\n");
        puts("Erro. Digite um valor valido");
        scanf("%d", &numero_menu);
        getchar();

    }

    if (numero_menu == 1){
        menu_cadastro_cliente(clientes, veiculos, posicao_cliente, posicao_veiculo);
    }

    else if (numero_menu == 2){
        menu_cadastro_veiculos(clientes, veiculos, posicao_cliente, posicao_veiculo);
    }

    else if (numero_menu == 3){
        locacao_devolucao(clientes, veiculos, posicao_cliente, posicao_veiculo);

    } else if (numero_menu == 4) {
        exit(EXIT_SUCCESS);
    }
    
}

int main()
{
    int posicao_cliente = 0, posicao_veiculo = 0;

    Cliente clientes[50];
    Veiculo veiculos[50];

    menu_principal(clientes, veiculos, posicao_cliente, posicao_veiculo);  
}