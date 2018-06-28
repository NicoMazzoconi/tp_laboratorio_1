#ifndef GGT_H_INCLUDED
#define GGT_H_INCLUDED
typedef struct
{
    int id;
    char nombre[26];
    char apellido[26];
    int edad;
}Ggt;

Ggt* ggt_new();
void ggt_delete();

int ggt_setId(Ggt* this,int id);
int ggt_getId(Ggt* this,int* id);

int ggt_setNombre(Ggt* this,char* nombre);
int ggt_getNombre(Ggt* this,char* nombre);

int ggt_setApellido(Ggt* this,char* apellido);
int ggt_getApellido(Ggt* this,char* apellido);

int ggt_setEdad(Ggt* this,int edad);
int ggt_getEdad(Ggt* this,int* edad);

#endif // GGT_H_INCLUDED
