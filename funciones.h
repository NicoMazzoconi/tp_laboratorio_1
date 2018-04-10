#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAXINT 32767
#define MININT -32768

/** \brief Pide un numero entero
 *
 * \param int * mensaje texto que muestra al pedir el numero
 * \param int *error error que muestra al ingresar opcion no valida
 * \param int intentos cantidad de veces que puede intentarlo
 * \param int* resultado valor ingresado valido
 * \return int -1 se acabaron los intentos, 0 todo perfecto
 *
 */
int getInt(int *mensaje, int *error, int intentos, int *resultado)
{
    int retorno;
    int aux;
    int i = 0;
    do
    {
        printf("%s", mensaje);
        scanf("%d", &aux);
        fflush(stdin);
        if(aux > (MININT - 1) && aux < (MAXINT + 1))
        {
            retorno = 0;
            *resultado = aux;
            break;
        }
        else
        {
            retorno = -1;
            printf("%s", error);
        }
        i++;
    }while(i < intentos);

    return retorno;
}
/**
*\brief Suma dos numeros enteros
*\param int primerNumero, primer numero a ser sumado
*\param int segundoNumero, segundo numero a ser sumado
*\param int *resultado, donde se guarda el valor de la suma
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
*\brief Resta dos numeros enteros
*\param int primerNumero, numero a restar
*\param int segundoNumero, cantidad a restar
*\param int *resultado, donde se guarda el valor de la resta
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
*\brief Divide dos numeros enteros
*\param int primerNumero, dividendo
*\param int segundoNumero, divisor
*\param int *resultado, donde se guarda el valor de la divicion
*\return -2 el divisor es 0, -1 error OverFlow, 0 el resultado
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
*\brief Multiplica dos numeros enteros
*\param int primerNumero, multiplicado
*\param int segundoNumero, multiplicador
*\param int *resultado, donde se guarda el valor de la multiplicacion
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
*\brief Factorea un numero entero
*\param int primerNumero, numero a ser factoreado
*\param int *resultado, donde se guarda el valor de la factorizacion
*\return -2 error el numero no puede ser menor a 1, -1 error OverFlow, 0 el resultado
*
*/
int factorial(int primerNumero, int *resultado)
{
    long solucion = 1;
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
                break;
            }
            else
            {
                respuesta = 0;
                *resultado = solucion;
            }
        }
    }

    return respuesta;
}
#endif // FUNCIONES_H_INCLUDED

