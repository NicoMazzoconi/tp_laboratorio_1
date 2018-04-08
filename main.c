#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int primerNumero=0;
    int segundoNumero=0;
    int respuesta;
    int resultado;
    float resultadoDivi;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%d)\n", primerNumero);
        printf("2- Ingresar 2do operando (B=%d)\n", segundoNumero);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el primer numero\n");
                scanf("%d", &primerNumero);
                fflush(stdin);
            break;
            case 2:
                printf("Ingrese el segundo numero\n");
                scanf("%d", &segundoNumero);
                fflush(stdin);
            break;
            case 3:
                respuesta = suma(primerNumero, segundoNumero, &resultado);
                if(respuesta == -1)
                {
                    printf("Error de OverFlow\n");
                }
                else
                {
                    printf("La suma es %d\n", resultado);
                }
            break;
            case 4:
                respuesta = resta(primerNumero, segundoNumero, &resultado);
                if(respuesta == -1)
                {
                    printf("Error de OverFlow\n");
                }
                else
                {
                    printf("La resta es %d\n", resultado);
                }
            break;
            case 5:
                respuesta = dividir(primerNumero, segundoNumero, &resultadoDivi);
                if(respuesta == -2)
                {
                    printf("No se puede dividir por cero(0)\n");
                }
                else
                {
                    if(respuesta == -1)
                    {
                        printf("Error de OverFlow\n");
                    }
                    else
                    {
                        printf("La divicion es %.2f\n", resultadoDivi);
                    }
                }
            break;
            case 6:
                respuesta = multiplicacion(primerNumero, segundoNumero, &resultado);
                if(respuesta == -1)
                {
                    printf("Error de OverFlow\n");
                }
                else
                {
                    printf("La multiplicacion es %d\n", resultado);
                }
            break;
            case 7:
                respuesta = factorial(primerNumero, &resultado);
                if(respuesta == -2)
                {
                    printf("No se puede calcular el factorial de un numero menor a 1 \n");
                }
                else
                {
                    if(respuesta == -1)
                    {
                        printf("Error de OverFlow \n");
                    }
                    else
                    {
                        printf("El factorial es %d\n", resultado);
                    }
                }
            break;
            case 8:
                respuesta = suma(primerNumero, segundoNumero, &resultado);
                if(respuesta == -1)
                {
                    printf("Error de OverFlow\n");
                }
                else
                {
                    printf("La suma es %d\n", resultado);
                }
                respuesta = resta(primerNumero, segundoNumero, &resultado);
                if(respuesta == -1)
                {
                    printf("Error de OverFlow\n");
                }
                else
                {
                    printf("La resta es %d\n", resultado);
                }
                respuesta = dividir(primerNumero, segundoNumero, &resultadoDivi);
                if(respuesta == -2)
                {
                    printf("No se puede dividir por cero(0)\n");
                }
                else
                {
                    if(respuesta == -1)
                    {
                        printf("Error de OverFlow\n");
                    }
                    else
                    {
                        printf("La divicion es %.2f\n", resultadoDivi);
                    }
                }
                respuesta = multiplicacion(primerNumero, segundoNumero, &resultado);
                if(respuesta == -1)
                {
                    printf("Error de OverFlow\n");
                }
                else
                {
                    printf("La multiplicacion es %d\n", resultado);
                }
                respuesta = factorial(primerNumero, &resultado);
                if(respuesta == -2)
                {
                    printf("No se puede calcular el factorial de un numero menor a 1 \n");
                }
                else
                {
                    if(respuesta == -1)
                    {
                        printf("Error de OverFlow \n");
                    }
                    else
                    {
                        printf("El factorial es %d\n", resultado);
                    }
                }
            break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}
