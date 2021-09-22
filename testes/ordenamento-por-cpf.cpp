#include <stdio.h>
#include <string.h>

struct Cliente {
    char cpf[12];
};

int main()
{
    Cliente cliente[3];

    strcpy(cliente[0].cpf, "12345678901");
    strcpy(cliente[1].cpf, "09876543212");
    strcpy(cliente[2].cpf, "21345678901");

    for(int i = 0; i < 3; i++) {
        printf("%s\n", cliente[i].cpf);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            if (strcmp(cliente[i].cpf, cliente[j].cpf) == 1) {
                char temp[12];
                strcpy(temp, cliente[i].cpf);
                strcpy(cliente[i].cpf, cliente[j].cpf);
                strcpy(cliente[j].cpf, temp);
            }
        }
    }

    printf("\n");

    for(int i = 0; i < 3; i++) {
        printf("%s\n", cliente[i].cpf);
    }

    
}