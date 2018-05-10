#include "cliente.h"
#include "publicaciones.h"

/** \brief Pasas una idPublicacion y devuelve el inidice del cliente
 *
 * \param arrayC Cliente* array de los clientes
 * \param limiteC int espacio del array de clientes
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \param idPublicacion int el id a encontrar cliente dueño
 * \return int el indice del cliente encontrado
 *
 */
int duenioPublicaciones(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP, int idPublicacion);
/** \brief Cuenta la cantidad de aviso del id del cliente
 *
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \param idCliente int cliente a encontrar
 * \return int devuelve la cantidad de avisos
 *
 */
int contadorDeAvisos(Publicaciones *arrayP, int limiteP, int idCliente);
/** \brief Muestra todos los clientes que tengan un aviso o mas
 *
 * \param arrayC Cliente* array de los clientes
 * \param limiteC int espacio del array de clientes
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int retorna 0 al terminar
 *
 */
int mostrarClientesConAvisos(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP);
/** \brief muestra las publicaciones activas
 *
 * \param arrayC Cliente* array de los clientes
 * \param limiteC int espacio del array de clientes
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int retorna 0 al terminar
 *
 */
int publicacionesActivas(Publicaciones *arrayP, int limiteP, Cliente *arrayC, int limiteC);
/** \brief Busca el indice del cliente enviado
 *
 * \param arrayC Cliente* array de los clientes
 * \param limiteC int espacio del array de clientes
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \param idCliente int cliente a identificar
 * \return int el indice de la array de cliente
 *
 */
int duenioPublicacionesCliente(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP, int idCliente);
/** \brief Muestra el cliente con mas avisos
 *
 * \param arrayC Cliente* array de los clientes
 * \param limiteC int espacio del array de clientes
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int retorna 0 al terminar
 *
 */
int clienteMasAvisos(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP);
/** \brief Muestra el cliente con mas avisos pausados
 *
 * \param arrayC Cliente* array de los clientes
 * \param limiteC int espacio del array de clientes
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int retorna 0 al terminar
 *
 */
int clienteMasAvisosPausados(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP);
/** \brief Muestra el cliente con mas avisos activos
 *
 * \param arrayC Cliente* array de los clientes
 * \param limiteC int espacio del array de clientes
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int retorna 0 al terminar
 *
 */
int clienteMasAvisosActivos(Cliente *arrayC, int limiteC, Publicaciones *arrayP, int limiteP);

/** \brief Pide un rubro yte dice cuantas veces fue publicado
 *
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int retorna 0 al terminar
 *
 */
int cantidadPublicacionActivasRubroIngresado(Publicaciones *arrayP, int limiteP);
/** \brief El rubro mas publicado en publicaciones activas
 *
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int retorna 0 al terminar
 *
 */
int rubroMasPublicacionesActivas(Publicaciones *arrayP, int limiteP);
/** \brief El rubro mas publicado en publicaciones pausadas
 *
 * \param arrayP Publicaciones* array de la publicacion
 * \param limiteP int espacio del array de publicacion
 * \return int retorna 0 al terminar
 *
 */
int rubroMenosPublicacionesActivas(Publicaciones *arrayP, int limiteP);
