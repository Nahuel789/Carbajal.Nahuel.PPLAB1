#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct{

int id;
char nombreColor[20];

}eColor;

#endif // COLORES_H_INCLUDED


/** \brief muestra un color
 *
 * \param unColor estructura
 *
 */
void mostrarColor(eColor unColor);


/** \brief muestra la lista de colores
 *
 * \param array puntero a array colores
 * \param tam tamanio de array colores
 * \return -1 si se produjo un error, 0 si esta todo ok
 */
int mostrarColores(eColor* array,int tam);
