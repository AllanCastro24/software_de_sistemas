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
            case 1:/* Espera un: "Mostrar" */
                if (strcmp(cabeza->tok.lexema, "MOSTRAR") == 0){
                    SintaxisLeer(cabeza->siguiente, 2);
                }
                else{
                    printf("No lo encontro");
                }
                break;
            case 2:/* Espera un: "(" */
                if (strcmp(cabeza->tok.lexema, "(") == 0){
                    printf("Correcto 2");
                    SintaxisLeer(cabeza->siguiente, 3);
                    }
                else{
                    printf("No lo encontro");
                }
                break;
        }
    }
}

void SintaxisMientras(NODO *cabeza, int paso){
    if(cabeza != NULL) {
        switch(paso) {
          case 1:/*si*/
            if( strcmp(cabeza->tok.lexema, "Mientras") == 0 )
              SintaxisMientras(cabeza->siguiente, 2);
            break;
          case 2:/* ( -> Parentesis Abierto*/
            if( strcmp(cabeza->tok.lexema,"(") == 0 )
              SintaxisMientras(cabeza->siguiente, 3);
            else
              printf("Se esperaba apertura de paréntesis despues de Mientras");
            break;
          case 3:/* ) -> Parentesis Cerrado*/
            if( strcmp(cabeza->tok.lexema,")" ) == 0)
              SintaxisMientras(cabeza->siguiente, 4);
            else
              SintaxisMientras(cabeza->siguiente, paso);
            break;
          case 4:
            if(strcmp(cabeza->tok.lexema, "{") == 0)
              SintaxisMientras(cabeza->siguiente,5);
            else
              printf("Se esperaba llave de apertura después de ) en sentencia Mientras\n");
            break;
          case 5:
            if(strcmp(cabeza->tok.lexema, "Romper") == 0)
              SintaxisMientras(cabeza->siguiente, 6);
            else
            //Intrucciones del boque true
              SintaxisMientras(cabeza->siguiente, paso);
            break;
          case 6:/*sino*/
            if(strcmp(cabeza->tok.lexema, "}") == 0)
              printf("Sintaxis de Mientras correcta\n");
            else
              printf("Se esperaba cierre de llave en Mientras\n");
            break;
          default:
            SintaxisMientras(cabeza->siguiente, paso);
            break;
        }
    SintaxisMientras(cabeza->siguiente, 1);
    }
}

void SintaxisPara(NODO *cabeza, int paso){
    if(cabeza != NULL) {
        switch(paso) {
          case 1:/*para*/
            if( strcmp(cabeza->tok.lexema, "Para") == 0 )
              SintaxisPara(cabeza->siguiente, 2);
            break;
          case 2:/* ( -> Parentesis Abierto*/
            if( strcmp(cabeza->tok.lexema,"(") == 0 )
              SintaxisPara(cabeza->siguiente, 3);
            else
              printf("Se esperaba apertura de paréntesis despues de Para \n");
            break;
          case 3:/* ) -> Parentesis Cerrado*/
            if( strcmp(cabeza->tok.lexema,")" ) == 0)
              SintaxisPara(cabeza->siguiente, 4);
            else
              SintaxisPara(cabeza->siguiente, paso);
            break;
          case 4:
            if(strcmp(cabeza->tok.lexema, "{") == 0)
              SintaxisPara(cabeza->siguiente,5);
            else
              printf("Se esperaba llave de apertura después de ) en sentencia Para \n");
            break;
          case 5:
            if(strcmp(cabeza->tok.lexema, "Romper") == 0)
              SintaxisPara(cabeza->siguiente, 6);
            else
            //Intrucciones del boque true
              SintaxisPara(cabeza->siguiente, paso);
            break;
          case 6:/*sino*/
            if(strcmp(cabeza->tok.lexema, "}") == 0)
              printf("Sintaxis de Para correcta \n");
            else
              printf("Se esperaba cierre de llave en Para\n");
            break;
          default:
            SintaxisPara(cabeza->siguiente, paso);
            break;
        }
    SintaxisPara(cabeza->siguiente, 1);
    }
}

void SintaxisIf(NODO *cabeza, int paso){
    if(cabeza != NULL) {
        switch(paso) {
          case 1:/*si*/
            if( strcmp(cabeza->tok.lexema, "Si") == 0 )
              SintaxisIf(cabeza->siguiente, 2);
            break;
          case 2:/* ( -> Parentesis Abierto*/
            if( strcmp(cabeza->tok.lexema,"(") == 0 )
              SintaxisIf(cabeza->siguiente, 3);
            else
              printf("Se esperaba apertura de paréntesis despues de Si");
            break;
          case 3:/* ) -> Parentesis Cerrado*/
            if( strcmp(cabeza->tok.lexema,")" ) == 0)
              SintaxisIf(cabeza->siguiente, 4);
            else
              SintaxisIf(cabeza->siguiente, paso);
            break;
          case 4:
            if(strcmp(cabeza->tok.lexema, "{") == 0)
              SintaxisIf(cabeza->siguiente,5);
            else
              printf("Se esperaba llave de apertura después de ) en sentencia Si\n");
            break;
          case 5:
            if(strcmp(cabeza->tok.lexema, "}") == 0)
              SintaxisIf(cabeza->siguiente, 6);
            else
            //Intrucciones del boque true
              SintaxisIf(cabeza->siguiente, paso);
            break;
          case 6:/*sino*/
            if(strcmp(cabeza->tok.lexema, "Sino") == 0)
              SintaxisIf(cabeza->siguiente,7);
            else
              printf("Sintaxis de Si correcta\n");
            break;
          case 7:/*iniciosino*/
            if(strcmp(cabeza->tok.lexema, "{") == 0)
              SintaxisIf(cabeza->siguiente,8);
            else
              printf("Se esperaba una llave de apertura para la sentencia Sino\n");
            break;
          case 8:/*finsino*/
            if(strcmp(cabeza->tok.lexema, "}") == 0)
              SintaxisIf(cabeza->siguiente, 9);
            else
            //Intrucciones del boque flase
              SintaxisIf(cabeza->siguiente, paso);
            break;
          case 9:
            if(strcmp(cabeza->tok.lexema, "Encambio") == 0)
              SintaxisIf(cabeza->siguiente, 10);
            else
              printf("Sintaxis Si-Sino correcta\n");
            break;
          case 10:/*iniciosino*/
            if(strcmp(cabeza->tok.lexema, "{") == 0)
              SintaxisIf(cabeza->siguiente,11);
            else
              printf("Se esperaba una llave de apertura para la sentencia Encambio\n");
            break;
          case 11:/*finsino*/
            if(strcmp(cabeza->tok.lexema, "}") == 0)
              printf("Sintaxis Si-Sino-Encambio correcta\n");
            else
            //Intrucciones del boque flase
              SintaxisIf(cabeza->siguiente, paso);
            break;
          default:
            SintaxisIf(cabeza->siguiente, paso);
            break;
        }
    SintaxisIf(cabeza->siguiente, 1);
    }
}

void SintaxisVariables(NODO *cabeza, int paso){
}

void identificarSintaxis(NODO *cabeza){

    if(cabeza != NULL){
        if(strcmp(cabeza->tok.lexema, "Para")){ //Para
            SintaxisPara(cabeza, 1);
            identificarSintaxis(cabeza->siguiente);
        }
        else if (strcmp(cabeza->tok.lexema, "Mientras")){
            SintaxisMientras(cabeza, 1);
            identificarSintaxis(cabeza->siguiente);
        }
        else if (strcmp(cabeza->tok.lexema, "Si")){
            SintaxisIf(cabeza, 1);
            identificarSintaxis(cabeza->siguiente);
        }
        else if (strcmp(cabeza->tok.lexema, "MOSTRAR")){
            SintaxisMostrar(cabeza, 1);
            identificarSintaxis(cabeza->siguiente);
        }
        else{
            identificarSintaxis(cabeza->siguiente);
        }
    }
}

void SintaxisAsignacion(NODO *cabeza, int paso){

}
