#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
}S_Empleado;

S_Empleado* Empleado_new();
S_Empleado* Empleado_newParametros(int id, char* nombre, int horasTrabajadas);
void Empleado_delete(S_Empleado* this);

int Empleado_setId(S_Empleado* this,int id);
int Empleado_getId(S_Empleado* this,int* id);

int Empleado_setNombre(S_Empleado* this,char* nombre);
int Empleado_getNombre(S_Empleado* this,char* nombre);

int Empleado_setHorasTrabajadas(S_Empleado* this,int horasTrabajadas);
int Empleado_getHorasTrabajadas(S_Empleado* this,int* horasTrabajadas);

int em_trabajaMasDe120Horas(void* item);
#endif // EMPLEADO_H_INCLUDED
