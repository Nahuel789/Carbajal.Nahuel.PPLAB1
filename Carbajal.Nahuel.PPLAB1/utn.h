#include "bicicletas.h"
#include "trabajos.h"


#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED



/** \brief Funcion que sirve para pedir un numero entero
 *
 * \param pResultado puntero a donde va a ser guardado el entero
 * \param mensaje mensaje que vera el usuario
 * \param mensajeError mensaje que vera el usuario si es invalido
 * \param  minimo valor mas chico capaz de recibir la funcion
 * \param  maximo valor mas grande capaz de recibir la funcion
 * \param reintentos la cantidad de veces que se pide el dato al ser invalido
 * \return 0 si esta todo bien , -1 si se produjo un error
 *
 */

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

/** \brief Funcion que sirve para pedir un numero flotante
 *
 * \param pResultado puntero a donde va a ser guardado el flotante
 * \param mensaje mensaje que vera el usuario
 * \param mensajeError mensaje que vera el usuario si es invalido
 * \param  minimo valor mas chico capaz de recibir la funcion
 * \param  maximo valor mas grande capaz de recibir la funcion
 * \param reintentos la cantidad de veces que se pide el dato al ser invalido
 * \return 0 si esta todo ok , -1 si se produjo un error
 *
 */

int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

/** \brief Funcion que sirve para pedir un caracter
 *
 * \param pResultado puntero a donde va a ser guardado el entero
 * \param mensaje mensaje que vera el usuario
 * \param mensajeError mensaje que vera el usuario si es invalido
 * \param  minimo valor mas chico capaz de recibir la funcion
 * \param  maximo valor mas grande capaz de recibir la funcion
 * \param reintentos la cantidad de veces que se pide el dato al ser invalido
 * \return 0 si esta todo ok, -1 si hay un error
 *
 */

int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);





/** \brief Funcion que sirve para pedir una cadena de caracteres
 *
 * \param pAux puntero a donde va a ser guardada la cadena de caracteres
 * \param len tamaño de la cadena decaracteres
 * \param retry la cantidad de veces que se pide el dato al ser invalido
  * \param mensaje mensaje que vera el usuario
 * \param mensajeError mensaje que vera el usuario si es invalido
 * \return 0 si esta todo ok, -1 si hay un error
 *
 */

int utn_getCadena(char *pAux, int len, int retry, char* mensaje, char* mensajeError);
/** \brief Funcion que pide la cadena a validar
 *
 * \param pAux cadena de caracteres
 * \param len tamaño de la cadena decaracteres
 * \return 0 si esta todo ok, -1 si hay un error
 *
 */

int getCadena(char* pAux, int len);

/** \brief Valida que el id este en la lista
 *
 * \param array de estructuras Colores
 * \param tamC tamanio de estruc colores
 * \param idColor id ingresado
 * \return 0 si esta todo ok, -1 si se produjo un error
 *
 */


int validarIdColor(eColor* array,int tamC,int idColor);
/** \brief Valida que el id este en la lista
 *
 * \param array de estructuras tipos
 * \param tamC tamanio de estruc tipos
 * \param idTipo id ingresado
 * \return 0 si esta todo ok, -1 si se produjo un error
 *
 */
int validarIdTipo(eTipo* array,int tamT,int idTipo);

/** \brief Valida que el id este en la lista
 *
 * \param array de estructuras servicios
 * \param tamC tamanio de estruc servicios
 * \param idServicio id ingresado
 * \return 0 si esta todo ok, -1 si se produjo un error
 *
 */
int validarIdServicio(eServicio* array,int tam,int idServicio);


/** \brief Valida que el id este en la lista
 *
 * \param array de estructuras bicicleta
 * \param tamC tamanio de estruc bicicleta
 * \param idBici id ingresado
 * \return 0 si esta todo ok, -1 si se produjo un error
 *
 */

int validarIdBici(eBicicleta* array,int tam,int idBici);
/** \brief Valida que el rodado este dentro de las opciones
 *
 * \param rodado ingresado por el usuario
 * \return 0 si esta todo ok, -1 si se produjo un error
 *
 */
int validarRodado(float rodado);

