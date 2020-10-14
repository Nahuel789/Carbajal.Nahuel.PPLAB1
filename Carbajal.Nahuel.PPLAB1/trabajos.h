#include "fecha.h"
#include "bicicletas.h"
#include "servicios.h"


#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED


typedef struct
{

    int id;
    int idBicicleta;
    int idServicio;
    int isEmpty;
    eFecha fecha;


} eTrabajo;


#endif // TRABAJOS_H_INCLUDED
/** \brief indica con el isempty en 1 que los trabajos estan vacios
 *
 * \param array de trabajo
 * \param tam tamanio de trabajos
 * \return return 0 si esta todo ok, o -1 si fallo al inicializar
 *
 */

int inicializarTrabajos(eTrabajo* array,int tam);

/** \brief busca espacio libre dentro del array de trabajos
 *
 * \param array de estructura trabajo
 * \param tam tamanio de array trabajo
 * \return -1 si no hay libre, o el primer indice libre
 *
 */

int buscarLibreTr(eTrabajo* array,int tam);
/** \brief Muestra un trabajo
 *
 * \param una estructura trabajo
 * \param array de bicicletas
 * \param tamB tamanio de array bicicletas
 * \param array de Servicios
 * \param tamB tamanio de array servicios
 *
 */

void mostrarTrabajo(eTrabajo unTrabajo,eBicicleta* arrayB,int tamB,eServicio* arrayS,int tamS);

/** \brief Muestra todos los trabajos
 *
 * \param arrayT array de estructuras trabajos
 * \param tamTr tamanio de estructura trabajos
 * \param arrayT array de estructuras bicicletas
 * \param tamB tamanio de estructura bicicletas
 * \param tamB tamanio de estructura servicios
 * \param tamB tamanio de estructura servicios
 * \return 0 si esta todo bien , -1 si se produjo un error
 *
 */

int mostrarTrabajos(eTrabajo* arrayT,int tamTr,eBicicleta* arrayB,int tamB,eServicio* arrayS,int tamS);

/** \brief Carga el la marca de la bicicleta utilizando el id
 *
 * \param array de estructura bicicletas
 * \param tam tamanio de array bicicletas
 * \param idBici id a cargar
 * \param descripBicicleta puntero a donde va a ser guardada la marca
 * \return 0 si esta todo ok,-1 si se produjo un error
 *
 */

int cargarDescripcionBicicleta(eBicicleta* array,int tam,int idBici,char* descripBicicleta);

/** \brief Carga la descripcion del servicio utilizando el id
 *
 * \param array de estructura servicio
 * \param tam tamanio de array servicio
 * \param idServicio id a cargar
 * \param descripcionServicio puntero a donde va a ser guardada la descripcion
 * \return 0 si esta todo ok,-1 si se produjo un error
 *
 */
int cargarDescripcionServicio(eServicio*array,int tam,int idServicio,char* descripcionServicio);


/** \brief Hace un alta de trabajo
 *
 * \param arrayT array de estructura trabajo
 * \param tamT tamanio de estructura trabajo
 * \param legax legajo del trabajo
 * \param arrayB array de estructuras bicicleta
 * \param tamB tamanio de estructura bicicleta
 * \param arrayC array de estructura colores
 * \param tamC tamanio de estructura colores
 * \param arrayTi array de estructuras tipos
 * \param tamTi tamanio de estructura tipos
 * \param arrayS array de estructura servicios
 * \param tamS tamanio de estructura servicios

 * \return 0 si esta todo ok, -1 si se produjo un error
 *
 */

int altaTrabajos(eTrabajo* arrayT, int tamT, int legajx,eBicicleta* arrayB,int tamB,eColor* arrayC,int tamC,eTipo* arrayTi,int tamTi,eServicio* arrayS,int tamS);


