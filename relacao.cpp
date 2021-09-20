#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct Veiculo {
    char placa[8] = "ABC1234";
    bool em_locacao = false;
};

struct Cliente {
    Veiculo veiculo;
};

int main()
{
    int idade;

    Veiculo veiculo;
    Cliente cliente;
    printf("Deseja sair? Digite 0\n");

    gets(veiculo.placa);


    if (strcmp(veiculo.placa, "\0")) {
        printf("Nao tem nada aqui\n\n");
    }

    Veiculo veiculo2;

    cliente.veiculo = veiculo;
    cliente.veiculo.em_locacao = true;

    cliente.veiculo = veiculo2;

    printf("%d\n", cliente.veiculo.em_locacao);
    printf("%d", veiculo.em_locacao);
}