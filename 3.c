#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N  5   // cantidad de nombres
#define TAMA 100


void listarNombres2(char **vector, int cantidad);

int main(){

    char * *vector;
    char buffer[TAMA];
    int longCadena;

    vector = (char**) malloc( N * sizeof(char*));

    for (int i = 0; i < N; i++)
    {
        printf("\nIngresar nombre:");
        gets(buffer);

        longCadena = ( strlen(buffer) + 1 );

        vector[i] = (char*) malloc (longCadena * sizeof(char));

        strcpy(vector[i],buffer);

        //printf("\nPersona %d,nombre:%s", i+1, vector[i]);

    }
    listarNombres2(vector, N);


    for (int i = 0; i < N ; i++)
    {
       free(vector[i]);
    }

    free(vector);

    listarNombres2(vector,N);

    return 0;
}

//forma 1
void listarNombres(char **vector, int cantidad){

    printf("\nLista de nombres:\n" );
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nPersona %d,nombre:%s", i+1,vector[i]);
    }
}

//forma 2
void listarNombres2(char **vector, int cantidad){

    printf("\nLista de nombres:\n" );
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nPersona %d,nombre:%s", i+1,*vector);
        vector++;
    }
}  

    


