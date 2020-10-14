#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "utn.h"
#include "bicicletas.h"
#include "menu.h"
#include "trabajos.h"

#define TAM_B 5
#define TAM_T 4
#define TAM_C 5
#define TAM_S 4
#define TAM_TR 100











int main()
{
    char seguir = 's';
    int idBici=1;
    int idTrab=1;
    int flagAltaBicicleta=1; // EL FLAG TIENE QUE INICIALIZARSE EN 0 PERO LO PONGO EN 1 PARA QUE NO INTERFIERA CON EL HARCODEO
    int flagAltaTrabajo=0;
    char rta;

    eBicicleta listaB[TAM_B];

    /*

    if(!inicializarBicicletas(listaB,TAM_B))
    {
        printf("Inicializacion exitosa");


    */


    eTipo listaT[TAM_T]= {{1000,"Rutera"},{1001,"Carrera"},{1002,"Mountain"},{1003,"BMX"}};
    eColor listaC[TAM_C]= {{5000,"Gris"},{5001,"Negro"},{5002,"Blanco"},{5003,"Azul"},{5004,"Rojo"}};
    eServicio listaS[TAM_S]= {{20000,"Limpieza",250},{20001,"Parche",300},{20002,"Centrado",400},{20003,"Cadena",350}};

    harcodearBicicletas(listaB,TAM_B,5);


    eTrabajo listaTr[TAM_TR];
    inicializarTrabajos(listaTr,TAM_TR);


    do
    {
        system("cls");


        switch(menu())
        {
        case 'a':

            if(!altaBicicleta(listaB,TAM_B,idBici,listaT,TAM_T,listaC,TAM_C))  //ALTA DE BICICLETAS
            {
                idBici++;
                flagAltaBicicleta=1;
            }


            break;

        case 'b': // MODIFICACION DE BICICLETAS

            if(flagAltaBicicleta)
            {
                system("cls");
                modificarBicicletas(listaB,TAM_B,listaT,TAM_T,listaC,TAM_C);
                system("pause");
            }
            else
            {
                printf("Primero haga un alta de bicicleta\n");
                system("pause");
            }





            break;

        case 'c':// BAJA LOGICA DE BICICLETA

            if(flagAltaBicicleta)
            {
                system("cls");
                bajaBicicleta(listaB,TAM_B,listaC,TAM_C,listaT,TAM_T);
                system("pause");

            }

            else
            {
                printf("Primero haga un alta de bicicleta\n");
                system("pause");
            }

            break;


        case 'd'://SE MUESTRA BICICLETA HABIENDO ORDENADO POR TIPO Y RODADO


            system("cls");
            ordenarBicicletasPorTipoyRodado(listaB,TAM_B,listaT,TAM_T);
            mostrarBicicletas(listaB,TAM_B,listaC,TAM_C,listaT,TAM_T);
            system("pause");

            break;

        case 'e':// MUESTRA LOS TIPOS
            system("cls");
            mostrarTipos(listaT,TAM_T);
            system("pause");


            break;

        case 'f': // MUESTRA LOS COLORES
            system("cls");
            mostrarColores(listaC,TAM_C);
            system("pause");

            break;

        case 'g': // MUESTRA LOS SERVICIOS

            system("cls");
            mostrarServicios(listaS,TAM_S);
            system("pause");

            break;

        case 'h': //ALTA DE TRABAJOS
            system("cls");

            if(flagAltaBicicleta)
            {

                if(!altaTrabajos(listaTr,TAM_TR,idTrab,listaB,TAM_B,listaC,TAM_C,listaT,TAM_T,listaS,TAM_S))
                {
                    idTrab++;
                    flagAltaTrabajo=1;

                }

            }
            else
            {
                printf("Primero hacer un alta de bicicleta\n");
            }


            system("pause");


            break;

        case 'i': // MUESTRA LOS TRABAJOS ACTIVOS
            system("cls");

            if(flagAltaTrabajo)
            {
                mostrarTrabajos(listaTr,TAM_TR,listaB,TAM_B,listaS,TAM_S);

            }
            else
            {
                printf("Para listar tienen que haber trabajos en el sistema\n");


            }


            system("pause");

            break;



        case'j': // SALIDA

            system("cls");


            if(!utn_getCaracter(&rta,"Confirma baja ? (s/n) \n","Error.Solo s o n : \n",'n','s',2))
            {
                if(rta== 's')
                {
                    seguir='n';
                }

            }




            break;



        }





    }
    while(seguir=='s');

/*
 }else
 {
     printf("Hubo un error al inicializar\n"); //COMENTADO POR EL HARCODEO DE BICICLETAS
     system("pause");
 }

*/



    return 0;
}

