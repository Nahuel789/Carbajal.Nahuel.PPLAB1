#include "fecha.h"

#ifndef DATASTORE_H_INCLUDED
#define DATASTORE_H_INCLUDED

char nombres[10][20]=
{"Juan",
"Astor",
"Rogelio",
"Analia",
"Mario",
"Facundo",
"Beatriz",
"Florencia",
"Tomas",
"Gustavo"};

char nombresMascotas[10][20]={ "Michi", "Firulais", "Dobby", "Bobby", "Chatran", "Pucky", "Michifus",
"Bolt", "Dexter", "Ayudante de santa"};

char sexos[10]={'m','m','m','f','m','m','f','f','m','m'};
int ides[10]={1,2,3,4,5,6,7,8,9,10};
int legajos[10]={20000,20001,20002,20003,20004,20005,20006,20007,20008,20009};

float alturas[10]={1.78,1.68,1.59,1.99,1.65,1.49,1.55,1.75,1.69,1.70};

int dias[10]={4,5,6,20,18,10,29,31,15,11};

int meses[10]={12,5,8,11,1,5,6,7,10,2};

int anios[10]={2000,1998,1999,1995,1994,1994,2001,2002,2004,1993};

int edades[10]={20,21,22,30,24,25,30,19,18,22};

float peso[10]={70,68,59,99,86,78,65,65,77,78};


eFecha fechas[10]={
{11,11,2000},
{21,3,1998},
{21,1,2000},
{16,9,2002},
{21,3,2001},
{15,2,1995},
{21,12,1994},
{4,9,1999},
{21,3,2000}};


int idDeportes[10]={1005,1001,1000,1001,1003,1004,1005,1004,1001,1002};
int idTipos[10]={1000,1001,1002,1003,1003,1002,1002,1002,1001,1003};
int idColores[10]={5000,5001,5001,5003,5004,5004,5003,5004,5001,5000};
int idColoresDos[10]={10000,10001,10003,10005,10004,10006,10009,10010,10009,10001};
int idauto[10]={1,2,3,4,5,6,7,8,9,10};
char marcas[10][20]={"Ducati","Kawasaki","Honda","BMW","Zanella","Harley Davidson","KTM","Motomel","Susuki","Ferrari"};
char marcasBicis[10][20]={"Specialized","Trek","Merida","Scott","Giant","Cube","Lapierre","Orbea","Orbea","Orbea"};
float rodados[10]={20,27.5,26,29,29,26,27.5,20,20,20};
int idDuenios[10]={1,2,3,4,5,6,4,5,6,10};
int cilindradas[10]={125,500,750,600,125,500,600,750,600,50};
int lleno[10]={0,0,0,0,0,0,0,0,0,0};

#endif // DATASTORE_H_INCLUDED
