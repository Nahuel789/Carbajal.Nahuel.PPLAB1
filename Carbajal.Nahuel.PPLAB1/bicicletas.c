#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "bicicletas.h"
#include "menu.h"
#include "tipos.h"
#include "datastore.h"




int buscarLibre(eBicicleta* array,int tam)
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


int altaBicicleta(eBicicleta* array, int tamB, int legajx,eTipo* arrayT,int tamT,eColor* arrayC,int tamC)
{

    int retorno=1;
    eBicicleta nuevaBicicleta;
    int indice;
    int auxInt;
    float auxFloat;
    char auxMarca[20];

    if(array !=NULL && arrayT != NULL && arrayC != NULL && tamB > 0 && legajx > 0 && tamT > 0 && tamC > 0)
    {
        indice= buscarLibre(array,tamB);

        if(indice == -1)
        {

            printf("......................................................................................................................\n");
            printf("................................................SISTEMA COMPLETO......................................................\n");
            printf("......................................................................................................................\n");
            system("pause");
        }
        else
        {
            nuevaBicicleta.id=legajx;
            nuevaBicicleta.isEmpty=0;

            if(!utn_getCadena(auxMarca,sizeof(auxMarca),2,"Ingrese la marca de la bicicleta : \n","Error.Reingrese\n"))
            {
                strncpy(nuevaBicicleta.marca,auxMarca,sizeof(nuevaBicicleta.marca));

                system("cls");

                mostrarTipos(arrayT,tamT);
                printf("Ingrese el id del tipo: \n");
                scanf("%d", &auxInt);
                while(validarIdTipo(arrayT,tamT,auxInt))
                {
                    system("cls");
                    mostrarTipos(arrayT,tamT);
                    printf("Error.Reingrese el id del tipo: \n");
                    scanf("%d",&auxInt);

                }

                nuevaBicicleta.idTipo=auxInt;

                system("cls");

                mostrarColores(arrayC,tamC);
                printf("Ingrese el id del color: \n");
                scanf("%d", &auxInt);
                while(validarIdColor(arrayC,tamC,auxInt))
                {
                    system("cls");
                    mostrarColores(arrayC,tamC);
                    printf("Error.Reingrese el id del color: \n");
                    scanf("%d",&auxInt);

                }

                nuevaBicicleta.idColor=auxInt;


                system("cls");

                printf("Ingrese el rodado de la bicicleta(20/26/27.5/29): \n");
                scanf("%f",&auxFloat);
                while(validarRodado(auxFloat))
                {
                    printf("Error.Reingrese el rodado de la bici(20/26/27.5/29): \n");
                    scanf("%f",&auxFloat);

                }
                nuevaBicicleta.rodado=auxFloat;
                array[indice]=nuevaBicicleta;
                retorno=0;

            }





        }



    }

    return retorno;

}




void mostrarBicicleta(eBicicleta unaBicicleta,eColor* arrayC,int tamC,eTipo* arrayT,int tamT)
{
    char descripColor[20];
    char descripTipo[20];


    cargarDescripcionColor(arrayC,tamC,unaBicicleta.idColor,descripColor);
    cargarDescripcionTipo(arrayT,tamT,unaBicicleta.idTipo,descripTipo);

    printf("%2d    %15s        %15s         %15s                        %.2f\n", unaBicicleta.id, unaBicicleta.marca,descripTipo,descripColor,unaBicicleta.rodado);

}



int mostrarBicicletas(eBicicleta* arrayB,int tam,eColor* arrayC,int tamC,eTipo* arrayT,int tamT)
{
    int retorno=-1;
    int flag=0;

    if(arrayB != NULL && tam > 0 && arrayC != NULL && tamC > 0 && arrayT != NULL && tamT > 0 )
    {
        printf(".....................................................................................................................\n");
        printf(".............................................      LISTA DE BICICLETAS      .........................................\n");
        printf(".....................................................................................................................\n");
        printf("ID                 MARCA                  TIPO                    COLOR                        RODADO            \n");

        for(int i=0; i<tam; i++)
        {

            if(!arrayB[i].isEmpty)
            {
                mostrarBicicleta(arrayB[i],arrayC,tamC,arrayT,tamT);

                retorno=0;
                flag=1;

            }




        }

        printf("\n\n");

        if(!flag)
        {
            printf("No se ingreso ninguna bici\n");
        }



    }


    return retorno;

}

int cargarDescripcionTipo(eTipo* array,int tam,int idTipo,char* descripcionTipo)
{
    int retorno=1;


    if(array != NULL && tam >0 && idTipo > 0 && descripcionTipo != NULL)
    {


        for(int i=0; i<tam; i++)
        {

            if(array[i].id ==idTipo)
            {

                strcpy(descripcionTipo,array[i].descripcion);
                retorno =0;
                break;

            }



        }


    }





    return retorno;
}


int cargarDescripcionColor(eColor* array,int tam,int idColor,char* descripcionColor)
{
    int retorno=1;


    if(array != NULL && tam >0 && idColor > 0 && descripcionColor != NULL)
    {


        for(int i=0; i<tam; i++)
        {

            if(array[i].id ==idColor)
            {

                strcpy(descripcionColor,array[i].nombreColor);
                retorno =0;
                break;

            }



        }


    }





    return retorno;
}


int inicializarBicicletas(eBicicleta* array,int tam)
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





int buscarBicicletas(eBicicleta* array,int tam,int legajo)
{
    int retorno = -1;

    for(int i=0; i<tam; i++)
    {
        if(array[i].id == legajo && !array[i].isEmpty)
        {

            retorno= i;
            break;

        }


    }



    return retorno;
}




int modificarBicicletas(eBicicleta* arrayB, int tamB,eTipo* arrayT,int tamT,eColor* arrayC,int tamC)
{
    int retorno = 1;
    int aux;
    float auxf;
    int indice;


    if(arrayB != NULL && tamB > 0 && arrayT != NULL && tamT > 0 && arrayC != NULL && tamC > 0 )
    {

        system("cls");

        mostrarBicicletas(arrayB,tamB,arrayC,tamC,arrayT,tamT);
        system("pause");

        printf("Ingrese el id que desea modificar : \n");
        scanf("%d",&aux);

        if((indice=buscarBicicletas(arrayB,tamB,aux)) != -1)
        {

            switch(menuModificacion())
            {
            case 1 :


                system("cls");
                mostrarTipos(arrayT,tamT);
                printf("Ingrese el id del tipo :\n");
                scanf("%d",&aux);
                while(validarIdTipo(arrayT,tamT,aux))
                {
                    system("cls");
                    mostrarTipos(arrayT,tamT);
                    printf("Error.Reingrese el id del tipo: \n");
                    scanf("%d",&aux);
                }

                arrayB[indice].idTipo=aux;

                break;


            case 2:



                printf("Ingrese el nuevo rodado (20/26/27.5/29) : \n");
                scanf("%f",&auxf);
                while(validarRodado(auxf))
                {
                    printf("Error.Reingrese el nuevo rodado(20/26/27.5/29) : \n");
                    scanf("%f",&auxf);

                }



                arrayB[indice].rodado=auxf;


                break;
            }



        }
        else
        {
            printf("NO HAY LEGAJO\n");
        }


    }


    return retorno;


}

int bajaBicicleta(eBicicleta* arrayB, int tamB,eColor* arrayC,int tamC,eTipo* arrayT,int tamT)
{
    int retorno = -1;
    int aux;
    int indice;
    char rta;


    if(arrayB != NULL && tamB > 0 && arrayC != NULL && tamC > 0 && arrayT != NULL && tamT > 0)
    {
        system("cls");
        printf("......................................................................................................................\n");
        printf(".....................................................      BAJA DE BICICLETAS     ....................................\n");
        printf("......................................................................................................................\n\n");

        mostrarBicicletas(arrayB,tamB,arrayC,tamC,arrayT,tamT);
        utn_getNumero(&aux,"Ingrese el id que desea borrar: \n","Error, Reingrese: \n",0,300000,2);


        if((indice=buscarBicicletas(arrayB,tamB,aux)) != -1)
        {



            utn_getCaracter(&rta,"Confirma la baja? (s/n)\n","Error s o n.Reingrese: \n,",'n','s',0);
            if(rta == 's')
            {

                arrayB[indice].isEmpty=1;
                retorno = 0;

            }
            else
            {
                retorno = 2; //si usuario cancela la baja
            }


        }
        else
        {
            printf("Legajo mal ingresado\n");
        }

    }




    return retorno;


}

int ordenarBicicletasPorTipoyRodado(eBicicleta* array,int tam,eTipo* arrayT,int tamT)
{
    int retorno=-1;
    eBicicleta auxiliarBici;

    if(array != NULL && tam > 0 && arrayT != NULL && tamT > 0)
    {

        for(int i=0; i<tam-1; i++)
        {

            for(int j=i+1; j<tam; j++ )
            {

                char tiposI[20];
                char tiposJ[20];

                cargarDescripcionTipo(arrayT,tamT,array[i].idTipo,tiposI);
                cargarDescripcionTipo(arrayT,tamT,array[j].idTipo,tiposJ);


                if(strcmp(tiposI,tiposJ) >0 )
                {
                    auxiliarBici=array[i];
                    array[i]=array[j];
                    array[j]=auxiliarBici;

                }
                else if((strcmp(tiposI,tiposJ) == 0) && (array[i].rodado > array[j].rodado))
                {

                    auxiliarBici=array[i];
                    array[i]=array[j];
                    array[j]=auxiliarBici;

                }



            }




        }





        retorno=0;



    }





    return retorno;
}




int harcodearBicicletas(eBicicleta* array,int tam,int cant)
{
    int retorno=-1;

    if(array != NULL && tam > 0 && cant <= tam)
    {
        retorno = 0 ;




        for(int i=0; i<cant; i++)
        {

            array[i].id=idauto[i];
            strncpy(array[i].marca,marcasBicis[i],sizeof(array[i].marca));
            array[i].idTipo=idTipos[i];
            array[i].idColor=idColores[i];
            array[i].rodado=rodados[i];
            array[i].isEmpty=0;

            retorno++;


        }






    }



    return retorno;
}
