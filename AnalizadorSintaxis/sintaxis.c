#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "cabecera.h"

void SintaxisLeer(NODO *cabeza, int paso){

}

void SintaxisMostrar(NODO *cabeza, int paso){
    if(cabeza != NULL){
        switch(paso){
            case 'MOSTRAR':/* Espera un: "Leer" */
                if (strcmp(cabeza->tok.lexema, "MOSTRAR") == 0){
                    printf("Correcto 1");
                    SintaxisLeer(cabeza->siguiente, 'PARENTUNO');
                }
                else{
                    printf("No lo encontro");
                }
                break;
            case 'PARENTUNO':/* Espera un: "(" */
                if (strcmp(cabeza->tok.lexema, "(") == 0){
                    printf("Correcto 2");
                    SintaxisLeer(cabeza->siguiente, 2);
                    }
                else{
                    printf("No lo encontro");
                }
                break;
        }
    }
}

void SintaxisMientras(NODO *cabeza, int paso){
}

void SintaxisPara(NODO *cabeza, int paso){
}

void SintaxisSi(NODO *cabeza, int paso){
}

void SintaxisVariables(NODO *cabeza, int paso){
}
