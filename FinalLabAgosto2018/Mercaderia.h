#ifndef MERCADERIA_H_INCLUDED
#define MERCADERIA_H_INCLUDED
typedef struct
{
    char producto[128];
    char direccion[128];
    char localidad[128];
    char recibe[128];
    int id;
}Mercaderia;

/** \brief Asigna memoria
 *
 * \return Mercaderia* retorna una mercaderia con memoria reservada
 *
 */
Mercaderia* Mercaderia_new();
/** \brief Carga los datos recibios a una mercaderia
 *
 * \param producto char* dato a cargar
 * \param direccion char* dato a cargar
 * \param localidad char* dato a cargar
 * \param recibe char* dato a cargar
 * \param id int dato a cargar
 * \return Mercaderia* devuelve una mercaderia con los datos cargados
 *
 */
Mercaderia* Mercaderia_newParametro(char* producto,char* direccion,char* localidad,char* recibe,int id);
/** \brief elimina la reserva de memoria
 *
 * \return void
 *
 */
void Mercaderia_delete();

/** \brief setea un producto
 *
 * \param this Mercaderia* donde guardarlo
 * \param producto char* producto a guardar
 * \return int -1 si no pudo, 0 si pudo
 *
 */
int Mercaderia_setProducto(Mercaderia* this,char* producto);
/** \brief obtiene el valor del producto
 *
 * \param this Mercaderia* de donde lee el producto
 * \param producto char* donde lo guarda
 * \return int -1 si no pudo, 0 si pudo
 *
 */
int Mercaderia_getProducto(Mercaderia* this,char* producto);

/** \brief setea la direccion
 *
 * \param this Mercaderia* donde stearlo
 * \param direccion char* lo que hay que setear
 * \return int -1 si no pudo, 0 si pudo
 *
 */
int Mercaderia_setDireccion(Mercaderia* this,char* direccion);
/** \brief obtiene el valor de direccion
 *
 * \param this Mercaderia* de donde lo lee
 * \param direccion char* donde lo guarda
 * \return int -1 si no pudo, 0 si pudo
 *
 */
int Mercaderia_getDireccion(Mercaderia* this,char* direccion);

/** \brief  Setea la localidad
 *
 * \param this Mercaderia* donde setearla
 * \param localidad char* el valor a setear
 * \return int -1 si no pudo, 0 si pudo
 *
 */
int Mercaderia_setLocalidad(Mercaderia* this,char* localidad);
/** \brief obtiene el valor de la localidad
 *
 * \param this Mercaderia* de donde leerlo
 * \param localidad char* donde guardarlo
 * \return int -1 sino pudo, 0 si pudo
 *
 */
int Mercaderia_getLocalidad(Mercaderia* this,char* localidad);

/** \brief Setea la persona que recibe
 *
 * \param this Mercaderia* donde setearla
 * \param recibe char* el valor a setear
 * \return int -1 sino pudo, 0 si pudo
 *
 */
int Mercaderia_setRecibe(Mercaderia* this,char* recibe);
/** \brief obtiene el valor de recibe
 *
 * \param this Mercaderia* de donde leerlo
 * \param recibe char* donde guardarlo
 * \return int -1 sino pudo, 0 si pudo
 *
 */
int Mercaderia_getRecibe(Mercaderia* this,char* recibe);

/** \brief setea la id
 *
 * \param this Mercaderia* donde setearlo
 * \param id int la id a setear
 * \return int -1 sino pudo, 0 si pudo
 *
 */
int Mercaderia_setId(Mercaderia* this,int id);
/** \brief obtiene la id
 *
 * \param this Mercaderia* donde leerlo
 * \param id int* donde guardarlo
 * \return int -1 sino puedo, 0 si pudo
 *
 */
int Mercaderia_getId(Mercaderia* this,int* id);

/** \brief Imprime por pantalla el producto
 *
 * \param this Mercaderia* el producto a primir
 * \return int -1 si el producto es iunvalido, 0 si pudo
 *
 */
int Mercaderia_printMercaderia(Mercaderia *this);
#endif // MERCADERIA_H_INCLUDED
