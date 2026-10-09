#include <stdio.h>
#include <stdlib.h>
#include "unicsul.h"

int main(int argc, char *argv[])
{
    char dt_proc[30];
    char hr_proc[30];
    char prox_dt[30];

    int codigo;
    float valor;
    int metodo;

    if (argc != 4)
    {
        printf("Quantidade de argumentos invalida.\n");
        return 1;
    }

    codigo = atoi(argv[1]);
    valor = atof(argv[2]);
    metodo = atoi(argv[3]);


    get_data_hora(dt_proc, hr_proc);

    // Get next business day: YYYYMMDD
    get_prox_data(dt_proc, 1, prox_dt);


    printf("Data do proc: %s\n", dt_proc);
    printf("Hora do proc: %s\n", hr_proc);
    printf("Proxima data util: %s\n", prox_dt);

    printf("Codigo: %d\n", codigo);
    printf("Valor: %.2f\n", valor);
    printf("Metodo: %d\n", metodo);

    // Record the transaction in JSON
    grava_log(
        dt_proc,
        hr_proc,
        codigo,
        valor,
        0.0,
        valor,
        prox_dt
    );

    return 0;
}