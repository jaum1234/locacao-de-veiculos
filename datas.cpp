#include <stdio.h>

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

int main()
{
    int dia_devolucao = 27, mes_devolucao = 2, ano_devolucao = 2024;
    int dia_locacao = 20, mes_locacao = 9, ano_locacao = 2021;
    int total_dias = 0;


    total_dias = get_total_dias_locacao(
        dia_locacao,
        mes_locacao,
        ano_locacao,
        dia_devolucao,
        mes_devolucao,
        ano_devolucao
    );

    printf("total de dias: %d", total_dias);
}