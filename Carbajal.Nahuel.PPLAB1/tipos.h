#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct{

int id;
char descripcion[20];

}eTipo;

#endif // TIPOS_H_INCLUDED



/** \brief muestra un tipo
 *
 * \param unTipo estructura
 *
 */
void mostrarTipo(eTipo unTipo);


/** \brief muestra la lista de tipo
 *
 * \param array puntero a array tipo
 * \param tam tamanio de array tipo
 * \return -1 si se produjo un error, 0 si esta todo ok
 */
int mostrarTipos(eTipo* array,int tam);
