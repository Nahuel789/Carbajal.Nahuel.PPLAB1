#include <stdio.h>
#include "servicios.h"

// SERVICIOS


void mostrarServicio(eServicio unServicio)
{
    printf("            %2d                                  %15s                                        %.2f\n",unServicio.id,unServicio.descripcion,unServicio.precio);

}

int mostrarServicios(eServicio* array,int tam)
{
    int retorno=-1;

    if(array != NULL && tam > 0)
    {
        printf("......................................................................................................................\n");
        printf("..................................................... LISTA DE SERVICIOS   ...........................................\n");
        printf("......................................................................................................................\n");
        printf("             ID                                        DESCRIPCION                                       PRECIO       \n");

        for(int i=0; i<tam; i++)
        {


            mostrarServicio(array[i]);
            retorno=0;


        }



    }


    return retorno ;

}

