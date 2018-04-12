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
                if(getInt("Ingrese un numero entero\n", "Fuera de rango del int(-32768/32767)\n", 2, &resultado)==0)
                {
                    primerNumero = resultado;
                }
                else
                {
                    printf("Se agotaron los intentos\n");
                }
            break;
            case 2:
                if(getInt("Ingrese un numero entero\n", "Fuera de rango del int(-32768/32767)\n", 2, &resultado)==0)
                {
                    segundoNumero = resultado;
                }
                else
                {
                    printf("Se agotaron los intentos\n");
                }
            break;
            case 3:
                respuesta = suma(primerNumero, segundoNumero, &resultado);
                mostrar("La suma es:", respuesta, resultado, 0);
            break;
            case 4:
                respuesta = resta(primerNumero, segundoNumero, &resultado);
                mostrar("La resta es:", respuesta, resultado, 0);
            break;
            case 5:
                respuesta = dividir(primerNumero, segundoNumero, &resultadoDivi);
                mostrar("La divicion es:", respuesta, 0, resultadoDivi);
            break;
            case 6:
                respuesta = multiplicacion(primerNumero, segundoNumero, &resultado);
                mostrar("La multiplicacion es:", respuesta, resultado, 0);
            break;
            case 7:
                respuesta = factorial(primerNumero, &resultado);
                mostrar("La factorizacion es:", respuesta, resultado, 0);
            break;
            case 8:
                respuesta = suma(primerNumero, segundoNumero, &resultado);
                mostrar("La suma es:", respuesta, resultado, 0);
                respuesta = resta(primerNumero, segundoNumero, &resultado);
                mostrar("La resta es:", respuesta, resultado, 0);
                respuesta = dividir(primerNumero, segundoNumero, &resultadoDivi);
                mostrar("La divicion es:", respuesta, 0, resultadoDivi);
                respuesta = multiplicacion(primerNumero, segundoNumero, &resultado);
                mostrar("La multiplicacion es:", respuesta, resultado, 0);
                respuesta = factorial(primerNumero, &resultado);
                mostrar("La factorizacion es:", respuesta, resultado, 0);
            break;
            case 9:
                seguir = 'n';
            break;
            default :
                printf("Opcion no valida\n");
            break;
        }

    }
    return 0;
}
