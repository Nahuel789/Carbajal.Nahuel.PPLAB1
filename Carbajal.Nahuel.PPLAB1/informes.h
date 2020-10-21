#include "bicicletas.h"
#include "colores.h"
#include "tipos.h"
#include "trabajos.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED



/** \brief Muestra las bicicletas de un color determinado
 *
 * \param array puntero de array de bicicletas
 * \param tam tamanio de array de bicicletas
 * \param arrayC puntero de array de colores
 * \param tamC tamanio de array de colores
 * \param arrayT puntero de array Tipos
 * \param tamT tamanio de array Tipos
 * \return -1 si se produjo un error, 0 si esta todo ok
 *
 */

int mostrarBicicletasXcolor(eBicicleta* array, int tam,eColor* arrayC, int tamC,eTipo* arrayT,int tamT);

/** \brief Busca el menor rodado del array Bicicletas
 *
 * \param arrayB puntero a array Bicicletas
 * \param tamB tamanio de array Bicicletas
 * \return -1 si se produjo un error, o el indice
 *
 */

float buscarMenorRodado(eBicicleta* arrayB,int tamB);

/** \brief Muestra bicicletas por rodado
 *
 * \param arrayB puntero a array Bicicletas
 * \param tamB tamanio de array Bicicletas
 * \param rodado de la bicicleta
 * \param arrayC puntero de array de colores
 * \param tamC tamanio de array de colores
 * \param arrayT puntero de array Tipos
 * \param tamT tamanio de array Tipos
 * \return -1 si se produjo un error, 0 si esta todo ok
 *
 */
int mostrarBicicletasXRodado(eBicicleta* arrayB,int tamB,float rodado,eColor* arrayC, int tamC,eTipo* arrayT,int tamT);
/** \brief Muestra las bicicletas por un tipo seleccionado
 *
 * \param arrayB puntero a array Bicicletas
 * \param tamB tamanio de array Bicicletas
 * \param arrayC puntero de array de colores
 * \param tamC tamanio de array de colores
 * \param arrayT puntero de array Tipos
 * \param tamT tamanio de array Tipos
 * \return -1 si se produjo un error, 0 si esta todo ok
 *
 */
int mostrarBicicletasXUnTipo(eBicicleta* arrayB,int tamB,eColor* arrayC,int tamC,eTipo* arrayT,int tamT);
/** \brief Muestra bicicletas por todos los tipos
 *
 * \param arrayB puntero a array Bicicletas
 * \param tamB tamanio de array Bicicletas
 * \param arrayC puntero de array de colores
 * \param tamC tamanio de array de colores
 * \param arrayT puntero de array Tipos
 * \param tamT tamanio de array Tipos
 * \return -1 si se produjo un error, 0 si esta todo ok
 *
 */

int mostrarBicicletasXTipos(eBicicleta* arrayB,int tamB,eColor* arrayC,int tamC,eTipo* arrayT,int tamT);
/** \brief Muestra las bicicicletas por tipo y color seleccionado
 *
 * \param arrayB puntero a array Bicicletas
 * \param tamB tamanio de array Bicicletas
 * \param arrayC puntero de array de colores
 * \param tamC tamanio de array de colores
 * \param arrayT puntero de array Tipos
 * \param tamT tamanio de array Tipos
 * \return -1 si se produjo un error, 0 si esta todo ok
 *
 */
int mostrarCantidadPorColorYTipo(eBicicleta* arrayB,int tamB,eColor* arrayC,int tamC,eTipo* arrayT,int tamT);
/** \brief Muestra las bicicletas por color seleccionado
 *
 * \param arrayB puntero a array Bicicletas
 * \param tamB tamanio de array Bicicletas
 * \param arrayC puntero de array de colores
 * \param tamC tamanio de array de colores
 * \return -1 si se produjo un error, 0 si esta todo ok
 *
 */
int mostrarColoresMasElegidos(eBicicleta* arrayB,int tamB,eColor* arrayC,int tamC);
/** \brief Muestra los trabajos hechos en una bicicleta
 *
 * \param arrayT puntero a array Trabajos
 * \param tamT tamanio de array Trabajos
 * \param arrayB puntero a array Bicicletas
 * \param tamB tamanio de array Bicicletas
 * \param arrayS puntero a array Servicios
 * \param tamS tamanio de array Servicios
 * \param arrayC puntero de array de colores
 * \param tamC tamanio de array de colores
 * \param arrayTi puntero de array Tipos
 * \param tamTi tamanio de array Tipos
 * \return -1 si se produjo un error, 0 si esta todo ok
 *
 */
int mostrarTrabajosXBicicletas(eTrabajo* arrayT,int tamT,eBicicleta* arrayB,int tamB,eServicio* arrayS,int tamS,eColor* arrayC,int tamC,eTipo* arrayTi,int tamTi);
/** \brief Muestra Importes de los trabajos hechos en la bicicleta
 *
* \param arrayT puntero a array Trabajos
 * \param tamT tamanio de array Trabajos
 * \param arrayB puntero a array Bicicletas
 * \param tamB tamanio de array Bicicletas
 * \param arrayS puntero a array Servicios
 * \param tamS tamanio de array Servicios
 * \param arrayC puntero de array de colores
 * \param tamC tamanio de array de colores
 * \param arrayTi puntero de array Tipos
 * \param tamTi tamanio de array Tipos
 * \return -1 si se produjo un error, 0 si esta todo ok
 *
 *
 */

int mostrarImporteXBicicletas(eTrabajo* arrayT,int tamT,eBicicleta* arrayB,int tamB,eServicio* arrayS,int tamS,eColor* arrayC,int tamC,eTipo* arrayTi,int tamTi);

/** \brief Muestra Bicicletas por un servicio seleccionado
 *
* \param arrayT puntero a array Trabajos
 * \param tamT tamanio de array Trabajos
 * \param arrayB puntero a array Bicicletas
 * \param tamB tamanio de array Bicicletas
 * \param arrayS puntero a array Servicios
 * \param tamS tamanio de array Servicios
 * \param arrayC puntero de array de colores
 * \param tamC tamanio de array de colores
 * \param arrayTi puntero de array Tipos
 * \param tamTi tamanio de array Tipos
 * \return -1 si se produjo un error, 0 si esta todo ok
 *
 *
 */
int mostrarBicicletaXServicio(eTrabajo* arrayT,int tamT,eBicicleta* arrayB,int tamB,eServicio* arrayS,int tamS,eColor* arrayC,int tamC,eTipo* arrayTi,int tamTi);

/** \brief Muestra Servicios por una fecha seleccionada
 *
* \param arrayT puntero a array Trabajos
 * \param tamT tamanio de array Trabajos
 * \param arrayB puntero a array Bicicletas
 * \param tamB tamanio de array Bicicletas
 * \param arrayS puntero a array Servicios
 * \param tamS tamanio de array Servicios
 * \param arrayC puntero de array de colores
 * \param tamC tamanio de array de colores
 * \param arrayTi puntero de array Tipos
 * \param tamTi tamanio de array Tipos
 * \return -1 si se produjo un error, 0 si esta todo ok
 *
 *
 */
int mostrarServiciosXFecha(eTrabajo* arrayT,int tamT,eBicicleta* arrayB,int tamB,eServicio* arrayS,int tamS,eColor* arrayC,int tamC,eTipo* arrayTi,int tamTi);
