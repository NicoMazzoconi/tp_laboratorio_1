#include "ArrayList.h"
#ifndef PARSE_H_INCLUDED
#define PARSE_H_INCLUDED
/** \brief Lee el archivo ingresado
 *
 * \param pList ArrayList* lista donde guarda los datos obtenidos
 * \param path char* direccion donde leer el archivo
 * \return int -1 si no puedo encontrar un archivo valido, 0 si lo logro
 *
 */
int parse_leerArchivo(ArrayList* pList, char* path);

/** \brief Escribe un archivo
 *
 * \param pList ArrayList* la lista a guardar en el archivo
 * \param path char* la direccion donde guardarla
 * \return int -1 si la lista es invalida o la direccion, 0 si pudo hacerlo
 *
 */
int parse_writeArchivo(ArrayList* pList, char* path);
#endif // PARSE_H_INCLUDED
