#include "ArrayList.h"
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Imprime por pantalla todas las entregas
 *
 * \param pList ArrayList* donde se encuentra la lista de las entregas
 * \return void
 *
 */
void funciones_imprimirEntregas(ArrayList* pList);

/** \brief Imprime por pantalla las localidades de las entregas
 *
 * \param pList ArrayList* donde se encuntra la lista de las entregas
 * \return void
 *
 */
void funciones_localidades(ArrayList* pList);

/** \brief Genera un archivo que contenga las localidades ingresadas
 *
 * \param pList ArrayList* donde se encuntra la lista de las entregas
 * \param localidadUno char* localidad ingresada a buscar
 * \param localidadDos char* localidad ingresada a buscar
 * \param localidadTres char* localidad ingresada a buscar
 * \return void
 *
 */
void funciones_generarArchivoDeReparto(ArrayList* pList, char* localidadUno, char* localidadDos, char* localidadTres);

#endif // FUNCIONES_H_INCLUDED
