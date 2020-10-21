#include <stdio.h>
#include <ctype.h>
#include "menu.h"
#include "utn.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"
#include "utn.h"


int menu()
{
    char opcion;
        printf("______________________________________________________________________________________________________________________\n");
        printf("__________________________________________________  MENU DE OPCIONES _________________________________________________\n");
        printf("______________________________________________________________________________________________________________________\n\n");
    printf("A) Alta Bicicleta\nB) Modificar Bicicleta\nC) Baja Bicicleta\nD) Listar Bicicletas\nE) Listar Tipos\nF) Listar colores\nG) Listar Servicios\nH) Alta trabajo\nI) Listar Trabajos\nJ)Informes\nK)SALIR\n\nIngrese la opcion que desee: \n");
    fflush(stdin);
    scanf("%c",&opcion);
    opcion=tolower(opcion);
    return opcion;
    }
int menuModificacion()
{
    int opcion;
        printf("______________________________________________________________________________________________________________________\n");
        printf("________________________________________________  MENU DE MODIFICACION  ______________________________________________\n");
        printf("______________________________________________________________________________________________________________________\n\n");
    utn_getNumero(&opcion,"1)Tipo\n2)Rodado\nIngrese la opcion que desea: \n","Error.Opcion Incorrecta\n",1,2,3);
    return opcion;
}

int menuInformes()
{
  int opcion;

    system("cls");
        printf("______________________________________________________________________________________________________________________\n");
        printf("________________________________________________  MENU DE INFORMES ___________________________________________________\n");
        printf("______________________________________________________________________________________________________________________\n\n");

    utn_getNumero(&opcion,"1)Mostrar bicicletas por color seleccionado\n2)Mostrar Bicicletas por un tipo\n3)Mostrar Bicicletas por menor rodado\n4)Mostrar Bicicletas por todos los tipos\n5)Contar por tipo y color\n6)Mostrar colores mas elegidos\n7)Mostrar trabajos por bicicletas\n8)Mostrar Importes por bicicleta\n9)Mostrar Bicicletas por Servicio\n10)Mostrar Servicios por fecha\n11)Salir\nIngrese la opcion que desee : \n\n","Error.Opcion invalida",1,11,1);

    return opcion;
}
