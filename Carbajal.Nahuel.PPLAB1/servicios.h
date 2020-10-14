#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED
typedef struct
{

    int id;
    char descripcion[25];
    float precio;

} eServicio;



#endif // SERVICIOS_H_INCLUDED


/** \brief muestra un servicio
 *
 * \param unServicio estructura
 *
 */

void mostrarServicio(eServicio unServicio);

/** \brief muestra la lista de servicios
 *
 * \param array puntero a array servicios
 * \param tam tamanio de array servicios
 * \return -1 si se produjo un error, 0 si esta todo ok
 */

int mostrarServicios(eServicio* array,int tam);
