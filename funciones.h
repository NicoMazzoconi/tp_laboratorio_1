#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAXINT 32767
#define MININT -32768

int suma(int primerNumero, int segundoNumero, int *resultado)
{
   int solucion;
   int respuesta;
   solucion = primerNumero + segundoNumero;

   if(solucion < MININT || solucion > MAXINT)
   {
       respuesta = -1;
   }
   else
   {
       respuesta = 0;
       *resultado = solucion;
   }
   return respuesta;
}

int resta(int primerNumero, int segundoNumero, int *resultado)
{
   int solucion;
   int respuesta;
   solucion = primerNumero - segundoNumero;

   if(solucion < MININT || solucion > MAXINT)
   {
       respuesta = -1;
   }
   else
   {
       respuesta = 0;
       *resultado = solucion;
   }
   return respuesta;
}

int dividir(int primerNumero, int segundoNumero, float *resultadoDivi)
{
   float solucion;
   int respuesta;

   if(segundoNumero == 0)
   {
       respuesta = -2;
   }
   else
   {
        solucion = (float)primerNumero / segundoNumero;
        if(solucion < MININT || solucion > MAXINT)
        {
            respuesta = -1;
        }
        else
        {
            respuesta = 0;
            *resultadoDivi = solucion;
        }
    }
   return respuesta;
}

int multiplicacion(int primerNumero, int segundoNumero, int *resultado)
{
   int solucion;
   int respuesta;
   solucion = primerNumero * segundoNumero;

   if(solucion < MININT || solucion > MAXINT)
   {
       respuesta = -1;
   }
   else
   {
       respuesta = 0;
       *resultado = solucion;
   }
   return respuesta;
}

int factorial(int primerNumero, int *resultado)
{
    int solucion = 1;
    int respuesta;
    int i;

    if(primerNumero < 1)
    {
        respuesta = -2;
    }
    else
    {
        for(i = primerNumero; i > 1; i--)
        {
            solucion = i * solucion;
            if(solucion < MININT || solucion > MAXINT)
            {
                respuesta = -1;
            }
            else
            {
                respuesta = 0;
                *resultado = solucion;
            }
        }
    }
}
#endif // FUNCIONES_H_INCLUDED

