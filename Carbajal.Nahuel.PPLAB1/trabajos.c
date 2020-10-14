#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajos.h"
#include "servicios.h"
#include "utn.h"

int inicializarTrabajos(eTrabajo* array,int tam)
{
    int retorno=-1;

    if(array != NULL && tam > 0)
    {

        for(int i=0; i<tam; i++)
        {


            array[i].isEmpty=1;
            retorno=0;



        }


    }


    return retorno;
}

int buscarLibreTr(eTrabajo* array,int tam)
{
    int retorno = -1;


    for(int i=0; i<tam; i++)
    {

        if(array[i].isEmpty)
        {

            retorno = i;
            break;


        }



    }
    return retorno;
}
int altaTrabajos(eTrabajo* arrayT, int tamT, int legajx,eBicicleta* arrayB,int tamB,eColor* arrayC,int tamC,eTipo* arrayTi,int tamTi,eServicio* arrayS,int tamS)
{

    int retorno=1;
    eTrabajo nuevoTrabajo;
    int indice;
    int auxInt;

    if( arrayT != NULL && legajx > 0 && tamT > 0 && legajx > 0 && arrayB != NULL && tamB > 0 && arrayC != NULL && tamC > 0 && arrayTi != NULL && tamTi > 0 && arrayS != NULL && tamS > 0 )
    {
        indice=buscarLibreTr(arrayT,tamT);

        if(indice == -1)
        {
            printf("SISTEMA COMPLETO\n");

        }
        else
        {
            retorno=0;
            nuevoTrabajo.id=legajx;
            nuevoTrabajo.isEmpty=0;

            system("cls");

            mostrarBicicletas(arrayB,tamB,arrayC,tamC,arrayTi,tamT);
            printf("Ingrese id de la bici: \n");
            scanf("%d",&auxInt);
            while(validarIdBici(arrayB,tamB,auxInt))
            {
                system("cls");
                mostrarBicicletas(arrayB,tamB,arrayC,tamC,arrayTi,tamT);
                printf("ERROR.Reingrese, no es id valido: \n");
                scanf("%d",&auxInt);
            }

            nuevoTrabajo.idBicicleta=auxInt;


            system("cls");

            mostrarServicios(arrayS,tamS);
            printf("Ingrese el id del servicio: \n");
            scanf("%d", &auxInt);
            while(validarIdServicio(arrayS,tamS,auxInt))
            {
                system("cls");
                mostrarServicios(arrayS,tamS);
                printf("Error.Reingrese el id del tipo: \n");
                scanf("%d",&auxInt);

            }

            nuevoTrabajo.idServicio=auxInt;

            if(!utn_getNumero(&auxInt,"Ingrese dia del trabajo : \n","Error.Dato Invalido\n",1,31,2))
            {
                nuevoTrabajo.fecha.dia=auxInt;

                if(!utn_getNumero(&auxInt,"Ingrese mes del trabajo : \n","Error.Dato Invalido\n",1,12,2))
                {
                    nuevoTrabajo.fecha.mes=auxInt;

                    if(!utn_getNumero(&auxInt,"Ingrese anio del trabajo : \n","Error.Dato Invalido\n",1900,2020,2))
                    {
                        nuevoTrabajo.fecha.anio=auxInt;
                        arrayT[indice]=nuevoTrabajo;

                    }

                }


            }










        }


    }





    return retorno;


}






void mostrarTrabajo(eTrabajo unTrabajo,eBicicleta* arrayB,int tamB,eServicio* arrayS,int tamS)
{
    char nombreBici[50];
    char nombreServic[50];


    cargarDescripcionBicicleta(arrayB,tamB,unTrabajo.idBicicleta,nombreBici);
    cargarDescripcionServicio(arrayS,tamS,unTrabajo.idServicio,nombreServic);


    printf("%2d                %15s               %15s                                 %d/%d/%d    \n",unTrabajo.id,nombreBici,nombreServic,unTrabajo.fecha.dia,unTrabajo.fecha.mes,unTrabajo.fecha.anio);

}

int mostrarTrabajos(eTrabajo* arrayT,int tamTr,eBicicleta* arrayB,int tamB,eServicio* arrayS,int tamS)
{
    int retorno=-1;
    int flag=0;

    if(arrayT != NULL && tamTr > 0 && arrayB != NULL && tamB > 0 && arrayS != NULL && tamS > 0)
    {
        printf("......................................................................................................................\n");
        printf("..............................................   LISTA DE TRABAJOS   .................................................\n");
        printf("......................................................................................................................\n");
        printf("ID                   BICICLETA                              SERVICIO                                  FECHA           \n");

        for(int i=0; i<tamTr; i++)
        {

            if(!arrayT[i].isEmpty)
            {
                mostrarTrabajo(arrayT[i],arrayB,tamB,arrayS,tamS);
                flag=1;

            }


            retorno=0;


        }

        printf("\n\n");
        if(!flag)
        {
            printf("No hay ningun trabajo que listar\n");

        }



    }


    return retorno ;

}


int cargarDescripcionBicicleta(eBicicleta* array,int tam,int idBici,char* descripcionBicicleta)
{
    int retorno=1;


    if(array != NULL && tam >0 && idBici > 0 && descripcionBicicleta != NULL)
    {


        for(int i=0; i<tam; i++)
        {

            if(array[i].id ==idBici)
            {

                strcpy(descripcionBicicleta,array[i].marca);
                retorno =0;
                break;

            }



        }


    }





    return retorno;
}

int cargarDescripcionServicio(eServicio array[],int tam,int idServicio,char* descripcionServicio)
{
    int retorno=1;


    if(array != NULL && tam >0 && idServicio > 0 && descripcionServicio != NULL)
    {


        for(int i=0; i<tam; i++)
        {

            if(array[i].id ==idServicio)
            {

                strcpy(descripcionServicio,array[i].descripcion);
                retorno =0;
                break;

            }



        }


    }





    return retorno;
}




