#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILA 5  // año
#define COLUM 12 // mes

void promedio(int matriz[FILA][COLUM]);
int mayor(int matriz[FILA][COLUM], int *year, int *mes);
int menor(int matriz[FILA][COLUM], int *year, int *mes);

int main()
{

    int matriz[FILA][COLUM];

    int mayorValor, yearMaximo, mesMaximo;
    int menorValor, yearMinimo, mesMinimo;

    srand(time(NULL));

    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUM; j++)
        {
            matriz[i][j] = rand() % 40001 + 10000;
            printf("%d \t", matriz[i][j]);
        }
        printf("\n");
    }

    promedio(matriz);

    mayorValor = mayor(matriz, &yearMaximo, &mesMaximo);
    printf("\nEl mayor valor fue:%d en Mes:%d - Annio:%d", mayorValor, mesMaximo, yearMaximo);

    menorValor = menor(matriz, &yearMinimo, &mesMinimo);
    printf("\nEl menor valor fue:%d en Mes:%d - Annio:%d", menorValor, mesMinimo, yearMinimo);

    return 0;
}

void promedio(int matriz[FILA][COLUM])
{

    int suma = 0;
    float promedio;

    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUM; j++)
        {
            suma = suma + matriz[i][j];
        }

        promedio = (suma / 12);
        printf("\nEl promedio de ganancia por anio:%.2f", promedio);
    }
}

int mayor(int matriz[FILA][COLUM], int *year, int *mes)
{

    int maximo = 0;

    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUM; j++)
        {
            if (matriz[i][j] > maximo)
            {
                maximo = matriz[i][j];
                // matriz 5(años) x 12 (meses)
                *year = i+1;
                *mes = j+1;
            }
        }
    }
    return (maximo);
}

int menor(int matriz[FILA][COLUM], int *year, int *mes)
{

    int minimo;

    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COLUM; j++)
        {
            if (i == 0)
            {
                minimo = matriz[i][j];
                // matriz 5(años) x 12 (meses)
                *year = i+1;
                *mes = j+1;
            }
            else
            {
                if (matriz[i][j] < minimo)
                {
                    minimo = matriz[i][j];
                    // matriz 5(años) x 12 (meses)
                    *year = i;
                    *mes = j;
                }
            }
        }
    }
    return (minimo);
}
