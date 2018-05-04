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

int graficoEdades(EPersona *lista, int QTY);
/** \brief Inicializa la variable estado
 *
 * \param lista el array se pasa como parametro.
 * \param int sizeArray  tamaño de la array
 * \return int
 *
 */
int personaInit(EPersona lista[], int sizeArray);

/**
 * Obtiene el primer indice libre del array.
 *
 * \param lista el array se pasa como parametro.
 * \param int sizeArray  tamaño de la array
 * \return int
 *
 */
int obtenerEspacioLibre(EPersona lista[], int sizeArray);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni, int sizeArray);

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
 * \param int dni DNI de la persona a dar de baja
 * \return int
 *
 */
int personaBaja(EPersona lista[], int sizeArray, int dni);

/** \brief
 *
 * \param lista[] EPersona
 * \param sizeArray int
 * \return int
 *
 */
int mostrarPersonas(EPersona lista[], int sizeArray);

int ordenarPorNombre(EPersona lista[], int sizeArray, int orden);

#endif // FUNCIONES_H_INCLUDED
