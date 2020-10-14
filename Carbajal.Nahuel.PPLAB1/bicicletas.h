#include "tipos.h"
#include "colores.h"

#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED



typedef struct{

int id;
char marca[20];
int idTipo;
int idColor;
float rodado;
int isEmpty;

}eBicicleta;






#endif // MASCOTAS_H_INCLUDED


/** \brief indica con el isempty en 1 que el array de bicicletas esta vacio
 *
 * \param array de bicicleta
 * \param tam tamanio de bicicleta
 * \return return 0 si esta todo ok, o -1 si fallo al inicializar
 *
 */
int inicializarBicicletas(eBicicleta* array,int tam);

/** \brief busca espacio libre dentro del array de bicicleta
 *
 * \param array de estructura bicicleta
 * \param tam tamanio de array bicicleta
 * \return -1 si no hay libre, o el primer indice libre
 *
 */
int buscarLibre(eBicicleta* array,int tam);


/** \brief Hace un alta de bicicleta
 *
 * \param  array de estructura bicicleta
 * \param tamT tamanio de estructura bicicleta
 * \param legax legajo de bicicleta
 * \param arrayTi array de estructuras tipos
 * \param tamTi tamanio de estructura tipos
 * \param arrayC array de estructura colores
 * \param tamC tamanio de estructura colores
 * \return 0 si esta todo ok, -1 si se produjo un error
 *
 */

int altaBicicleta(eBicicleta* array, int tamB, int legajx,eTipo* arrayT,int tamT,eColor* arrayC,int tamC);

/** \brief Muestra una bicicleta
 *
 * \param unaBicicleta una estruct bicicleta
 * \param array de Color
 * \param tamC tamanio de array color
 * \param array de Tipos
 * \param tamT tamanio de array Tipos
 *
 */
void mostrarBicicleta(eBicicleta unaBicicleta,eColor* arrayC,int tamC,eTipo* arrayT,int tamT);
/** \brief muestra el listado de bicicletas
 *
 * \param arrayB puntero de array bicicletas
 * \param tam tamanio de array bicicletas
 * \param arrayC puntero a array de colores
 * \param tamC tamanio de array color
 * \param arrayT puntero a array de Tipos
 * \param tamT tamanio de array Tipos
 * \return 0 si esta todo ok, -1 si se produjo un error
 *
 */

int mostrarBicicletas(eBicicleta* arrayB,int tam,eColor* arrayC,int tamC,eTipo* arrayT,int tamT);


/** \brief produce una baja logica en el array de estructuras bicicleta
 *
 * \param arrayB puntero de array bicicletas
 * \param tam tamanio de array bicicletas
 * \param arrayC puntero a array de colores
 * \param tamC tamanio de array color
 * \param arrayT puntero a array de Tipos
 * \param tamT tamanio de array Tipos
 *
 * \return 0 si esta todo ok, -1 si se produjo un error
 *
 */

int bajaBicicleta(eBicicleta* arrayB, int tamB,eColor* arrayC,int tamC,eTipo* arrayT,int tamT);

/** \brief Carga la descripcion del tipo utilizando el id
 *
 * \param puntero a array de estructura tipo
 * \param tam tamanio de array tipo
 * \param idTipo id a cargar
 * \param descripcionTipo puntero a donde va a ser guardada la descripcion
 * \return 0 si esta todo ok,-1 si se produjo un error
 *
 */
int cargarDescripcionTipo(eTipo* array,int tam,int idTipo,char* descripcionTipo);

/** \brief Carga la descripcion del Color utilizando el id
 *
 * \param puntero a array de estructura Color
 * \param tam tamanio de array Color
 * \param idColor id a cargar
 * \param descripcionColor puntero a donde va a ser guardada la descripcion
 * \return 0 si esta todo ok,-1 si se produjo un error
 *
 */
int cargarDescripcionColor(eColor* array,int tam,int idColor,char* descripcionColor);


/** \brief Ordena el array de bicicletas por tipo y rodado
 *
 * \param puntero a array de estructura bicicleta
 * \param tam tamanio de array bicicleta
 * \param arrayT puntero de array de tipos
 * \param tam tamanio de array tipos
 * \return 0 si esta todo ok,-1 si se produjo un error
 *
 */
int ordenarBicicletasPorTipoyRodado(eBicicleta* array,int tam,eTipo* arrayT,int tamT);

/** \brief busca una bicicleta por su id
 *
 * \param array puntero a array de bicicletas
 * \param tam tamanio de array bicicletas
 * \param legajo id buscado
 * \return -1 si se produjo el error, o el indice buscado
 *
 */

int buscarBicicletas(eBicicleta* array,int tam,int legajo);


/** \brief Hace una modificacion de una bicicleta
 *
 * \param arrayB array de estructura bicicleta
 * \param tamB tamanio de estructura bicicleta
 * \param arrayT array de estructuras tipo
 * \param tamT tamanio de estructura tipo
 * \param arrayC array de estructura colores
 * \param tamC tamanio de estructura colores
 * \return 0 si esta todo ok, -1 si se produjo un error
 *
 */

int modificarBicicletas(eBicicleta* arrayB, int tamB,eTipo* arrayT,int tamT,eColor* arrayC,int tamC);


/** \brief harcodea bicicletas
 *
 * \param array puntero a array bicicleta
 * \param tam tamanio array bicicleta
 * \param cant cantidad que quiere ser harcodeada
 * \return 0 todo ok, -1 si se produjo un error
 *
 */


int harcodearBicicletas(eBicicleta* array,int tam,int cant);


