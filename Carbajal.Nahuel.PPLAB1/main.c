#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "bicicletas.h"
#include "menu.h"
#include "trabajos.h"
#include "informes.h"

#define TAM_B 10
#define TAM_T 4
#define TAM_C 5
#define TAM_S 4
#define TAM_TR 6

int main()
{
    char seguir = 's';
    char continuar = 's';
    int idBici=6; //porque harcodee 5 bicis
    int idTrab=3005; //harcodee 5 trabajos q inician en 3000
    int flagAltaBicicleta=1; // EL FLAG TIENE QUE INICIALIZARSE EN 0 PERO LO PONGO EN 1 PARA QUE NO INTERFIERA CON EL HARCODEO
    int flagAltaTrabajo=1; //EL FLAG TIENE QUE INICIALIZARSE EN 0 PERO LO PONGO EN 1 PARA QUE NO INTERFIERA CON EL HARCODEO
    char rta;
    char rtaI;
    float menor;
    eBicicleta listaB[TAM_B];

    if(!inicializarBicicletas(listaB,TAM_B))
    {
        printf("Inicializacion exitosa");


    eTipo listaT[TAM_T]= {{1000,"Rutera"},{1001,"Carrera"},{1002,"Mountain"},{1003,"BMX"}};
    eColor listaC[TAM_C]= {{5000,"Gris"},{5001,"Negro"},{5002,"Blanco"},{5003,"Azul"},{5004,"Rojo"}};
    eServicio listaS[TAM_S]= {{20000,"Limpieza",250},{20001,"Parche",300},{20002,"Centrado",400},{20003,"Cadena",350}};


    harcodearBicicletas(listaB,TAM_B,5);


    eTrabajo listaTr[TAM_TR]={{3000,1,20000,0,{11,11,2020}},{3001,1,20003,0,{21,3,2020}},{3002,2,20001,0,{21,1,2020}},{3003,3,20002,0,{16,9,2020}},{3004,4,20001,0,{21,3,2020}},{0,0,0,1,{0,0,0}}};

    //inicializarTrabajos(listaTr,TAM_TR);

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
             if(flagAltaBicicleta)
            {
            system("cls");
            ordenarBicicletasPorTipoyRodado(listaB,TAM_B,listaT,TAM_T);
            mostrarBicicletas(listaB,TAM_B,listaC,TAM_C,listaT,TAM_T);
            system("pause");
            }

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
        case'j'://MENU DE INFORMES
            system("cls");
            if(flagAltaBicicleta && flagAltaTrabajo)
            {

            do
            {
                 switch(menuInformes())
            {
          case 1:// LISTADO DE BICICLETAS POR COLOR
            system("cls");
            mostrarBicicletasXcolor(listaB,TAM_B,listaC,TAM_C,listaT,TAM_T);
            system("pause");
            break;
          case 2:  // LISTADO DE BICICLETAS POR UN TIPO
            system("cls");
            mostrarBicicletasXUnTipo(listaB,TAM_B,listaC,TAM_C,listaT,TAM_T);
            system("pause");
            break;
          case 3: //LISTADO DE BICIS POR MENOR RODADO
            system("cls");
            menor=buscarMenorRodado(listaB,TAM_B);
            if(menor != -1)
            {
                mostrarBicicletasXRodado(listaB,TAM_B,menor,listaC,TAM_C,listaT,TAM_T);
            }
            else
            {
                printf("Error al buscar el menor rodado\n");
            }
            system("pause");
            break;
          case 4://LISTADO DE BICIS POR TIPOS
            system("cls");
            mostrarBicicletasXTipos(listaB,TAM_B,listaC,TAM_C,listaT,TAM_T);
            system("pause");
            break;
          case 5://CANTIDAD POR COLOR Y TIPO
            system("cls");
            mostrarCantidadPorColorYTipo(listaB,TAM_B,listaC,TAM_C,listaT,TAM_T);
            system("pause");
            break;
          case 6://COLORES MAS ELEGIDOS
            system("cls");
            mostrarColoresMasElegidos(listaB,TAM_B,listaC,TAM_C);
            system("pause");
            break;
          case 7://MUESTRA LOS TRABAJOS HECHOS POR BICICLETA
            system("cls");
            mostrarTrabajosXBicicletas(listaTr,TAM_TR,listaB,TAM_B,listaS,TAM_S,listaC,TAM_C,listaT,TAM_T);
            system("pause");
            break;
          case 8:
            system("cls"); // MUESTRA IMPORTE TOTAL POR TRABAJOS DE BICICLETA
            mostrarImporteXBicicletas(listaTr,TAM_TR,listaB,TAM_B,listaS,TAM_S,listaC,TAM_C,listaT,TAM_T);
            system("pause");
            break;
          case 9: // PIDE SERVICIO Y MUESTRA LAS BICICLETAS DE ESE SERVICIO
            system("cls");
            mostrarBicicletaXServicio(listaTr,TAM_TR,listaB,TAM_B,listaS,TAM_S,listaC,TAM_C,listaT,TAM_T);
            system("pause");
            break;
          case 10: //MUESTRA SERVICIOS HECHOS EN FECHA DETERMINADA
            system("cls");
            mostrarServiciosXFecha(listaTr,TAM_TR,listaB,TAM_B,listaS,TAM_S,listaC,TAM_C,listaT,TAM_T);
            system("pause");
            break;
          case 11: //SALIDA DE INFORMES
               if(!utn_getCaracter(&rtaI,"Confirma salida del menu de informes ? (s/n) \n","Error.Solo s o n : \n",'n','s',2))
            {
                if(rtaI== 's')
                {
                    continuar='n';
                }
            }

            break;
             }

            }while(continuar=='s');

            }

            break;

        case 'k':// SALIDA
            system("cls");
            if(!utn_getCaracter(&rta,"Confirma salida del menu principal ? (s/n) \n","Error.Solo s o n : \n",'n','s',2))
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

    }else
    {
     printf("Hubo un error al inicializar\n");
     system("pause");
    }


  return 0;
}



