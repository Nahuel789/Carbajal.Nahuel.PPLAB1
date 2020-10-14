#include <stdio.h>
#include <ctype.h>
#include "menu.h"
#include "utn.h"


int menu()
{
    char opcion;

    printf("......................................................................................................................\n");
    printf(".......................................            MENU-DE-OPCIONES             ......................................\n");
    printf("......................................................................................................................\n\n");
    printf("A) Alta Bicicleta\nB) Modificar Bicicleta\nC) Baja Bicicleta\nD) Listar Bicicletas\nE) Listar Tipos\nF) Listar colores\nG) Listar Servicios\nH) Alta trabajo\nI) Listar Trabajos\nJ)SALIR\n\nIngrese la opcion que desee: \n");
    fflush(stdin);
    scanf("%c",&opcion);
    opcion=tolower(opcion);

    return opcion;

}

int menuModificacion()
{
    int opcion;
    printf("......................................................................................................................\n");
    printf("......................................              MENU DE MODIFICACION         .....................................\n");
    printf("......................................................................................................................\n\n");
    printf("1)Tipo\n");
    printf("2)Rodado\n\n");
    utn_getNumero(&opcion,"Ingrese la opcion que desea: \n","Error.Opcion Incorrecta\n",1,2,3);


    return opcion;

}
