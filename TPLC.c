#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

float depositoIngresado(float depo1, float totalDepo);
float extraccionIngresada(float extraccion, float totalDepo);
float consultaSaldo(float totalDepo);
float resumenTotal(float resumen, float totalDepo);


int main (){

    int contraseniaIngresada, validacionContrasenia = 1, contadorContrasenia = 0, eleccionMenu, contadorFinal = 0, i, ingresar = 0, botonSalir = 0;
    float deposito, extraccionScan, valorCuenta, acumulacionTotal, contadorOperaciones = 0;
    char cuentaEnUso, usuarioIngresado[10];
    

    int arrayNumeroCuenta [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};    


    int arrayContrasenia[10] = {123, 321, 456, 654, 789, 987, 333, 113, 112, 114};
    

    char arrayNombre[10][10] = {"Juan", "Jorge", "Andrea", "Pablo", "Jazmin", "Tamara", "Ignacio", "Ursula", "Laura", "Agustin"};
    

    int arraySaldo[10] = {5000, 300, 10000, 40000, 250, 3, 51, 2020, 3000000, 150};
    

    char arrayEstado[10][1] = {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'};     

    do{ 
    botonSalir = 0;
    printf("Ingrese el usuario  y la contrase%ca de su cuenta: \n", 164);

    do{
    scanf("%s", &usuarioIngresado);
    scanf("%i", &contraseniaIngresada);

    for (i = 0; i <= 9; i++){       
        
        if ((strcmp(usuarioIngresado, arrayNombre[i]) == 0) && (arrayContrasenia[i] == contraseniaIngresada)) {
            valorCuenta = arraySaldo[i];
            ingresar = 1;                                
                    
        }
    }    

    if(ingresar == 0){
        printf("Contrase%ca incorrecta\n", 164);
        contadorContrasenia++;
    }

    if(contadorContrasenia == 3){
        printf("Su usuario ha sido bloqueado\n");

        /* for(i = 0; i <= 9; i++){            
           if(strcmp(usuarioIngresado, arrayNombre[i]) == 0){
               printf("%s\n", arrayEstado[i]);
               arrayEstado[i][1] = 'B';
               printf("%s\n", arrayEstado[i]);
           }
        } */
        system("pause");
        return 0;
    }
    }while(contadorContrasenia < 3 && ingresar == 0);

    do{
    do{
    printf("%cQue acci%cn desea realizar?\n", 168, 162);
    printf("1-Dep%csito\n", 162);
    printf("2-Extacci%cn\n", 162);
    printf("3-Consultar saldo\n");
    printf("4-Mostrar la cantidad de operaciones realizadas y saldo actual\n");
    printf("5-Salir del menu\n");
    scanf("%i", &eleccionMenu);
    if (eleccionMenu <1 || eleccionMenu > 5) {
        printf ("Opci%cn invalida, ingrese un numero del 1 al 5\n", 162);
    } else {
        contadorFinal++;
    }
    } while (eleccionMenu < 1 || eleccionMenu > 5);

    switch (eleccionMenu)
    {
    case 1: 
        do {
        printf("Ingrese la cantidad a depositar: \n");
        scanf("%f", &deposito);
        if (deposito <= 0) {
            printf("Valor err%cneo, intente nuevamente\n", 162);
        }
        } while (deposito <= 0);
        valorCuenta = depositoIngresado(deposito, valorCuenta);
        contadorOperaciones ++;
        break;
    case 2:
        do {
        printf("Ingrese la cantidad a extraer: \n");
        scanf("%f", &extraccionScan);
        if(extraccionScan > valorCuenta) {
            printf("No tiene suficiente saldo para realizar la extracci%cn, intente nuevamente\n", 162);
        }
        } while (extraccionScan > valorCuenta);
        valorCuenta = extraccionIngresada(extraccionScan, valorCuenta);
        contadorOperaciones ++;
        break;
    case 3:
        consultaSaldo(valorCuenta);
        contadorOperaciones ++;
        break;
    case 4:
        resumenTotal(contadorOperaciones, valorCuenta);
        break;
    case 5:
        botonSalir = 1;
    }
    } while((botonSalir == 0) && (contadorOperaciones < 10));
    
    if(contadorOperaciones >= 10){

      printf("Lleg%c al l%cmite de operaciones. Fin. Gracias!\n", 162, 161);

    }
    
    }while((botonSalir == 1) || (contadorOperaciones >= 10));                
    

    system("pause");
    return 0;

}   
    


    



     
    
float depositoIngresado(float depo1, float totalDepo) {
    printf("Usted ingres%c: $%.1f\n", 162, depo1);
    totalDepo += depo1;
    return totalDepo;
}

float extraccionIngresada(float extraccion, float totalDepo) {
    printf("Usted extrajo: $%.1f\n", extraccion);
        printf("No tiene saldo suficiente para realizar esa operaci%cn\n", 162);
    totalDepo -= extraccion;
    return totalDepo;
}

float consultaSaldo(float totalDepo) {
    printf("Su saldo actual es: $%.1f\n", totalDepo);
}

float resumenTotal(float resumen, float totalDepo) {
    printf("Usted realiz%c %.1f operaciones\n", 162, resumen);
    printf("Su saldo actual es: $%.1f\n", totalDepo);
}

