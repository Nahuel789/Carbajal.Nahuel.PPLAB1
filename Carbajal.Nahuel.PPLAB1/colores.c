#include <stdio.h>
#include "colores.h"

void mostrarColor(eColor unColor)
{



    printf("                   %2d                                                      %15s                            \n",unColor.id,unColor.nombreColor);

}



int mostrarColores(eColor array[],int tam)
{
    int retorno=-1;

    if(array != NULL && tam > 0)
    {
        printf("......................................................................................................................\n");
        printf(".................................................   LISTA DE COLORES  .................................................n");
        printf("......................................................................................................................\n");
        printf("                     ID                                                            NOMBRE-DEL-COLOR                 \n\n");

        for(int i=0; i<tam; i++)
        {


            mostrarColor(array[i]);
            retorno=0;


        }

        printf("\n\n");




    }


    return retorno ;

}
