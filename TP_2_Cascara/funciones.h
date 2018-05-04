#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int isEmpty;
    char dni[9];
    int idEPersona;
    int grafico;

}EPersona;

/** \brief Muestra un grafico de edades
 *
 * \param lista el array se pasa como parametro.
 * \param int sizeArray  tamaño de la array
 * \return void
 *
 */
void graficoEdades(EPersona *lista, int QTY);

/** \brief Inicializa la variable estado
 *
 * \param lista el array se pasa como parametro.
 * \param int sizeArray  tamaño de la array
 * \return int
 *
 */
int personaInit(EPersona lista[], int sizeArray);

/** \brief Obtiene el primer indice libre del array.
 *
 * \param lista el array se pasa como parametro.
 * \param int sizeArray  tamaño de la array
 * \return int
 *
 */
int obtenerEspacioLibre(EPersona lista[], int sizeArray);

/** \brief Obtiene el indice que coincide con el id pasado por parametro.
 *
 * @param EPersona lista el array se pasa como parametro.
 * @param int id el id a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro id
 */
int buscarPorID(EPersona lista[], int id, int sizeArray);

/** \brief Da de alta una persona
 *
 * \param EPersona lista[] el array se pasa como parametro.
 * \param int sizeArray  tamaño de la array
 * \return int
 *
 */
int personaAlta(EPersona lista[], int sizeArray);

/** \brief Da de baja un persona
 *
 * \param EPersona lista[] el array se pasa como parametro.
 * \param int sizeArray tamaño de la array
 * \param int id id de la persona a dar de baja
 * \return int
 *
 */
int personaBaja(EPersona lista[], int sizeArray, int id);

/** \brief Muestra todos las personas de alta
 *
 * \param lista[] EPersona
 * \param sizeArray int
 * \return int
 *
 */
int mostrarPersonas(EPersona lista[], int sizeArray);

/** \brief Ordena las personas por nombre
 *
 * \param EPersona lista[] el array se pasa como parametro.
 * \param int sizeArray tamaño de la array
 * \param int orden Indica el orden con 1 / 0
 * \return int
 *
 */
int ordenarPorNombre(EPersona lista[], int sizeArray, int orden);

#endif // FUNCIONES_H_INCLUDED
