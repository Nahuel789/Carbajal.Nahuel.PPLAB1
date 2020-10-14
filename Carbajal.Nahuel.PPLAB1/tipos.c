#include <stdio.h>
#include "tipos.h"

void mostrarTipo(eTipo unTipo)
{

    printf("                  %2d                                                           %15s                       \n",unTipo.id,unTipo.descripcion);

}

int mostrarTipos(eTipo array[],int tam)
{
    int retorno=-1;

    if(array != NULL && tam > 0)
    {
        printf("......................................................................................................................\n");
        printf("................................................  LISTA DE TIPOS  ....................................................\n");
        printf("......................................................................................................................\n");
        printf("                  ID                                                                 DESCRIPCION                      \n");

        for(int i=0; i<tam; i++)
        {


            mostrarTipo(array[i]);
            retorno=0;


        }

        printf("\n\n");


    }


    return retorno ;

}
