#include "informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


int mostrarBicicletasXcolor(eBicicleta* array, int tam,eColor* arrayC, int tamC,eTipo* arrayT,int tamT)
{
    int retorno= -1;
    int opcion;
    int flag =0;

    if(array != NULL && tam > 0 && arrayC != NULL && tamC > 0 && arrayT != NULL && tamT > 0)
    {
        system("cls");
        printf("______________________________________________________________________________________________________________________\n");
        printf("___________________________________________  LISTADO DE BICICLETAS POR COLOR  ________________________________________\n");
        printf("______________________________________________________________________________________________________________________\n\n");

        mostrarColores(arrayC,tamC);
        printf("Ingrese el id del color que desea listar: \n");
        scanf("%d",&opcion);
        while(validarIdColor(arrayC,tamC,opcion))
        {
            system("cls");
            mostrarColores(arrayC,tamC);
            printf("Reingrese el id del color por uno valido : \n");
            scanf("%d",&opcion);
        }
        system("cls");
        printf("ID                         MARCA                           TIPO                          COLOR                 RODADO           \n\n");
        for(int i=0; i<tam; i++)
        {
            if(!array[i].isEmpty && (array[i].idColor == opcion))
            {
                mostrarBicicleta(array[i],arrayC,tamC,arrayT,tamT);
                flag=1;
            }
        }
        printf("\n\n");
        if(!flag)
        {
            printf("No se ingreso ninguna bici\n");
        }
        retorno=0;
    }
    return retorno;
}


float buscarMenorRodado(eBicicleta* arrayB,int tamB)
{
    float retorno=-1;
    float menor;


    if(arrayB != NULL && tamB > 0)
    {
       for(int i=0;i<tamB;i++)
       {
        if(i==0 && !arrayB[i].isEmpty)
        {
            menor=arrayB[i].rodado;
        }
        else if(arrayB[i].rodado < menor && !arrayB[i].isEmpty)
        {
            menor=arrayB[i].rodado;
        }

       }

       retorno=menor;

    }
    return retorno;
}
int mostrarBicicletasXRodado(eBicicleta* arrayB,int tamB,float rodado,eColor* arrayC, int tamC,eTipo* arrayT,int tamT)
{
    int retorno=-1;

    if(arrayB != NULL && tamB > 0 && rodado > 0 && arrayC != NULL && tamC > 0 && arrayT != NULL && tamT > 0)
    {

        printf("______________________________________________________________________________________________________________________\n");
        printf("__________________________________________  LISTADO DE BICICLETAS POR RODADO  ________________________________________\n");
        printf("______________________________________________________________________________________________________________________\n\n");
        printf("ID                         MARCA                           TIPO                          COLOR                 RODADO           \n\n");
        for(int i=0; i<tamB; i++)
        {
            if(!arrayB[i].isEmpty && arrayB[i].rodado == rodado)
            {
                mostrarBicicleta(arrayB[i],arrayC,tamC,arrayT,tamT);
            }
        }

        printf("\n\n");
        retorno=0;
    }
    return retorno;
}
int mostrarBicicletasXUnTipo(eBicicleta* arrayB,int tamB,eColor* arrayC,int tamC,eTipo* arrayT,int tamT)
{
    int retorno= -1;
    int idTipo;
    int flag =0;
    char descripTipo[30];

    if(arrayB != NULL && tamB > 0 && arrayC != NULL && tamC > 0 && arrayT != NULL && tamT > 0)
    {
        system("cls");
        printf("______________________________________________________________________________________________________________________\n");
        printf("____________________________________________  LISTA DE BICICLETAS POR TIPO  __________________________________________\n");
        printf("______________________________________________________________________________________________________________________\n\n");
        mostrarTipos(arrayT,tamT);
        utn_getNumero(&idTipo,"Ingrese el id del tipo: \n","Error\n",1000,1003,1);

        while(validarIdTipo(arrayT,tamT,idTipo))
        {
            system("cls");
            mostrarTipos(arrayT,tamT);
            utn_getNumero(&idTipo,"Reingrese el id del tipo: \n","Error\n",1000,1003,1);
        }

        system("cls");
        cargarDescripcionTipo(arrayT,tamT,idTipo,descripTipo);
        printf("Listado de bicicletas de tipo %s\n\n",descripTipo);

        printf("ID                         MARCA                           TIPO                          COLOR                 RODADO           \n\n");
        for(int j=0; j<tamB; j++) //lista de persona
        {

            if(!arrayB[j].isEmpty && arrayB[j].idTipo == idTipo)
            {

                mostrarBicicleta(arrayB[j],arrayC,tamC,arrayT,tamT);

                flag=1;
            }
        }
        retorno=0;
    }
    if(!flag)
    {
        printf("No se ingreso ninguna bici\n");
    }

    return retorno;
}

int mostrarBicicletasXTipos(eBicicleta* arrayB,int tamB,eColor* arrayC,int tamC,eTipo* arrayT,int tamT)
{
    int retorno=-1;
    char descripTipo[25];
    if(arrayB != NULL && tamB > 0 && arrayC != NULL && tamC > 0 && arrayT != NULL && tamT > 0)
    {
        system("cls");
        printf("______________________________________________________________________________________________________________________\n");
        printf("_______________________________________  LISTADO DE BICICLETAS POR TIPOS  ____________________________________________\n");
        printf("______________________________________________________________________________________________________________________\n\n");
        printf("ID                         MARCA                           TIPO                          COLOR                 RODADO           \n\n");
        for(int i=0; i<tamT; i++)
        {
            cargarDescripcionTipo(arrayT,tamT,arrayT[i].id,descripTipo);
            printf("Listado de bicicletas por tipo %s\n\n",descripTipo);
            for(int j =0; j<tamB; j++)
            {
                if(!arrayB[j].isEmpty && arrayT[i].id == arrayB[j].idTipo)
                {
                    printf("______________________________________________________________________________________________________________________\n");
                    mostrarBicicleta(arrayB[j],arrayC,tamC,arrayT,tamT);
                    printf("______________________________________________________________________________________________________________________\n");
                }
            }

            printf("\n");
        }

        retorno=0;
    }
    return retorno;
}
int mostrarCantidadPorColorYTipo(eBicicleta* arrayB,int tamB,eColor* arrayC,int tamC,eTipo* arrayT,int tamT)
{
    int retorno=-1;
    int opcionColor;
    int opcionTipo;
    int counter=0;
    char descripColor[25];
    char descripTipo[25];

    if(arrayB != NULL && tamB > 0 && arrayC != NULL && tamC > 0 && arrayT != NULL && tamT > 0)
    {

        system("cls");
        printf("______________________________________________________________________________________________________________________\n");
        printf("______________________________________________  CONTADOR POR COLOR Y TIPO  ___________________________________________\n");
        printf("______________________________________________________________________________________________________________________\n\n");


        mostrarColores(arrayC,tamC);
        printf("Ingrese el id del color que desea listar: \n");
        scanf("%d",&opcionColor);
        while(validarIdColor(arrayC,tamC,opcionColor))
        {
            system("cls");
            mostrarColores(arrayC,tamC);
            printf("Reingrese el id del color por uno valido : \n");
            scanf("%d",&opcionColor);
        }

        cargarDescripcionColor(arrayC,tamC,opcionColor,descripColor);

        system("cls");
        mostrarTipos(arrayT,tamT);
        utn_getNumero(&opcionTipo,"Ingrese el id del tipo: \n","Error\n",1000,1003,1);

        while(validarIdTipo(arrayT,tamT,opcionTipo))
        {
            system("cls");
            mostrarTipos(arrayT,tamT);
            utn_getNumero(&opcionTipo,"Reingrese el id del tipo: \n","Error\n",1000,1003,1);
        }

        cargarDescripcionTipo(arrayT,tamT,opcionTipo,descripTipo);

        for(int i=0; i<tamB; i++)
        {

            if(!arrayB[i].isEmpty && (arrayB[i].idTipo == opcionTipo)&& (arrayB[i].idColor == opcionColor))
            {

                counter++;


            }

        }

        system("cls");
        printf("hay %d bicicletas de color %s y de tipo %s \n",counter,descripColor,descripTipo);



        retorno=0;
    }

    return retorno;
}



int mostrarColoresMasElegidos(eBicicleta* arrayB,int tamB,eColor* arrayC,int tamC)
{
    int retorno=-1;
    int contadores[tamC];
    int mayor;
    int flag=0;

    if(arrayB != NULL && tamB > 0 && arrayC != NULL && tamC > 0)
    {
        printf("______________________________________________________________________________________________________________________\n");
        printf("___________________________________________________  MAS ELEGIDOS  ___________________________________________________\n");
        printf("______________________________________________________________________________________________________________________\n\n");
         for(int i=0; i<tamC; i++)
            {
                contadores[i]=0;
            }

        for(int c=0; c<tamC; c++) //RECORRO COLORES
        {


            for(int b=0; b<tamB; b++)
            {
                if(!arrayB[b].isEmpty && arrayB[b].idColor == arrayC[c].id)
                {
                    contadores[c]++;
                }
            }
        }
        //BUSCO EL CONTADOR MAYOR
        for(int i=0; i<tamC; i++)
        {
            if(contadores[i]> mayor ||flag ==0)
            {
                mayor=contadores[i];
                flag=1;
            }
        }
        printf("El o los colores mas elegidos son : \n");
        for(int i=0; i<tamC; i++)
        {
            if(contadores[i] ==mayor)
            {
                printf("%s\n",arrayC[i].nombreColor);
            }
        }
        printf("\n\n");

        retorno=0;

    }
    return retorno;
}


int mostrarTrabajosXBicicletas(eTrabajo* arrayT,int tamT,eBicicleta* arrayB,int tamB,eServicio* arrayS,int tamS,eColor* arrayC,int tamC,eTipo* arrayTi,int tamTi)
{
   int retorno=-1;
   int opcion;

    if(arrayT !=NULL && tamT > 0 && arrayB != NULL && tamB > 0 && arrayS != NULL && tamS > 0 && arrayC != NULL && tamC > 0 && arrayTi != NULL && tamTi > 0)
    {
        system("cls");
        mostrarBicicletas(arrayB,tamB,arrayC,tamC,arrayTi,tamTi);
        utn_getNumero(&opcion,"Ingrese el id de la bicicleta que quiere listar: \n","Error.",1,10,1);
        while(validarIdBici(arrayB,tamB,opcion))
        {
        system("cls");
        mostrarBicicletas(arrayB,tamB,arrayC,tamC,arrayTi,tamTi);
        utn_getNumero(&opcion,"Reingrese el id de la bicicleta que quiere listar: \n","Error.",1,10,1);

        }

        system("cls");
        printf("______________________________________________________________________________________________________________________\n");
        printf("__________________________________________________  BICICLETAS X TRABAJO    __________________________________________\n");
        printf("______________________________________________________________________________________________________________________\n\n");
        printf("ID TRABAJOS            MARCA                             SERVICIO                               FECHA\n\n");
        for(int i=0;i<tamT;i++)
        {
            if(arrayT[i].idBicicleta == opcion && !arrayT[i].isEmpty)
            {
              mostrarTrabajo(arrayT[i],arrayB,tamB,arrayS,tamS);
            }
        }
    }
    return retorno;
}
int mostrarImporteXBicicletas(eTrabajo* arrayT,int tamT,eBicicleta* arrayB,int tamB,eServicio* arrayS,int tamS,eColor* arrayC,int tamC,eTipo* arrayTi,int tamTi)
{
   int retorno=-1;
   int opcion;
   int idServ;
   float total = 0;

    if(arrayT !=NULL && tamT > 0 && arrayB != NULL && tamB > 0 && arrayS != NULL && tamS > 0 && arrayC != NULL && tamC > 0 && arrayTi != NULL && tamTi > 0)
    {
        system("cls");
        mostrarBicicletas(arrayB,tamB,arrayC,tamC,arrayTi,tamTi);
        utn_getNumero(&opcion,"Ingrese el id de la bicicleta que desea saber el importe: \n","Error.",1,10,1);
        while(validarIdBici(arrayB,tamB,opcion))
        {
        system("cls");
        mostrarBicicletas(arrayB,tamB,arrayC,tamC,arrayTi,tamTi);
        utn_getNumero(&opcion,"Reingrese el id de la bicicleta que desea saber el importe: \n","Error.",1,10,1);

        }


            for(int i=0;i<tamT;i++)
            {
                if(arrayT[i].idBicicleta == opcion && !arrayT[i].isEmpty)
                {

                    idServ=arrayT[i].idServicio;

                    for(int j=0;j<tamS;j++)
                    {
                        if(arrayS[j].id == idServ )
                        {
                           total=total + arrayS[j].precio;

                        }
                    }

                }
            }
             printf("EL TOTAL GASTADO POR EL ID %d es %.2f\n",opcion,total);
    }

     return retorno;
}

int mostrarBicicletaXServicio(eTrabajo* arrayT,int tamT,eBicicleta* arrayB,int tamB,eServicio* arrayS,int tamS,eColor* arrayC,int tamC,eTipo* arrayTi,int tamTi)
{
  int retorno= -1;
  int opcion;
  char descripServicio[25];
 if(arrayT !=NULL && tamT > 0 && arrayB != NULL && tamB > 0 && arrayS != NULL && tamS > 0 && arrayC != NULL && tamC > 0 && arrayTi != NULL && tamTi > 0)
      {

        system("cls");
        mostrarServicios(arrayS,tamS);
        utn_getNumero(&opcion,"Ingrese el id del servicio que desea: \n","Error.",20000,20003,1);
        while(validarIdServicio(arrayS,tamS,opcion))
        {
        system("cls");
        mostrarServicios(arrayS,tamS);
        utn_getNumero(&opcion,"Ingrese el id del servicio que desea: \n","Error.",20000,20003,1);

        }

        system("cls");
        printf("______________________________________________________________________________________________________________________\n");
        printf("__________________________________________________  BICICLETAS X SERVICIO    _________________________________________\n");
        printf("______________________________________________________________________________________________________________________\n\n");

        cargarDescripcionServicio(arrayS,tamS,opcion,descripServicio);
        printf("El servicio seleccionado es %s\n\n",descripServicio);
        printf("ID                     MARCA                           TIPO                          COLOR                 RODADO           \n\n");

        for(int i=0;i<tamT;i++)
        {

            if(arrayT[i].idServicio == opcion && !arrayT[i].isEmpty)
            {
            for(int j=0;j< tamB;j++)
            {

                if(arrayT[i].idBicicleta == arrayB[j].id && !arrayB[j].isEmpty)
                {
                    printf("______________________________________________________________________________________________________________________\n");
                    mostrarBicicleta(arrayB[i],arrayC,tamC,arrayTi,tamTi);

                    printf("\nLa fecha en la que se realizo el trabajo es:%d/%d/%d\n",arrayT[i].fecha.dia,arrayT[i].fecha.mes,arrayT[i].fecha.anio);
                    printf("______________________________________________________________________________________________________________________\n");

                }
            }

            }

        }

      retorno = 0;
      }


    return retorno;
}


int mostrarServiciosXFecha(eTrabajo* arrayT,int tamT,eBicicleta* arrayB,int tamB,eServicio* arrayS,int tamS,eColor* arrayC,int tamC,eTipo* arrayTi,int tamTi)
{
    int retorno=-1;
    eFecha auxFecha;
    int entero;
    char descripServicio[25];
    int flag = 1;

    if(arrayT !=NULL && tamT > 0 && arrayB != NULL && tamB > 0 && arrayS != NULL && tamS > 0 && arrayC != NULL && tamC > 0 && arrayTi != NULL && tamTi > 0)
    {

        system("cls");
        mostrarFechas(arrayT,tamT);

        if(!utn_getNumero(&entero,"Ingrese dia\n","Error\n",1,31,1))
        {
            auxFecha.dia=entero;

             if(!utn_getNumero(&entero,"Ingrese mes\n","Error\n",1,12,1))
             {
                 auxFecha.mes=entero;

                  if(!utn_getNumero(&entero,"Ingrese anio\n","Error\n",2000,2020,2))
                  {
                      auxFecha.anio=entero;
                  }
             }
        }
                        for(int i=0;i<tamT;i++)
                        {
                            if(!arrayT[i].isEmpty && (auxFecha.dia == arrayT[i].fecha.dia) &&(auxFecha.mes == arrayT[i].fecha.mes) && (auxFecha.anio == arrayT[i].fecha.anio))
                            {
                                flag=0;
                                retorno=0;
                                cargarDescripcionServicio(arrayS,tamS,arrayT[i].idServicio,descripServicio);
                                printf("Se hizo el servicio %s en la fecha %d/%d/%d\n",descripServicio,arrayT[i].fecha.dia,arrayT[i].fecha.mes,arrayT[i].fecha.anio);
                            }
                        }

                        if(flag)
                        {
                            printf("No hay servicios con esa fecha\n");
                        }
    }
    return retorno;
}
