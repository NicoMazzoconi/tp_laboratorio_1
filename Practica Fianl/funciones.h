#include "ventas.h"
#include "clientes.h"
#include "ArrayList.h"

void funciones_listarClientes(ArrayList* pArrayClientes);
int funciones_indexClienteId(ArrayList* pArrayClientes, int id);
void funciones_listarVentas(ArrayList* pArrayVentas, ArrayList* pArrayClientes, int cod);
void funciones_archivoVentas(ArrayList* pArrayVentas, ArrayList* pArrayClientes, char* path);
void funciones_clientesMontos(ArrayList* pArrayClientes, ArrayList* pArrayVentas);
