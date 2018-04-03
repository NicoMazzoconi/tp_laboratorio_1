#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAXINT 32767
#define MININT -32768

/**
*\brief Recibe primerNumero y segundoNumero, y los suma
*\param La suma de los dos numeros
*\return -1 error OverFlow, 0 el resultado
*
*/
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

/**
*\brief Recibe primerNumero y segundoNumero, y los resta
*\param La resta de los dos numeros
*\return -1 error OverFlow, 0 el resultado
*
*/
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

/**
*\brief Recibe primerNumero y segundoNumero, y los divide
*\param La divicion de los dos numeros
*\return -2 si el dividendo es 0, -1 error OverFlow, 0 el resultado
*
*/
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

/**
*\brief Recibe primerNumero y segundoNumero, y los multiplica
*\param La multiplicacion de los dos numeros
*\return -1 error OverFlow, 0 el resultado
*
*/
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

/**
*\brief Recibe primerNumero y lo factoriza
*\param La factorizacion del numero
*\return -2 error de numero no valido(si es menor a 1), -1 error OverFlow, 0 el resultado
*
*/
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

