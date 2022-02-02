#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "cabecera.h"
/**
struct node *sentencia_lee(struct node *route, int state) {
    if (state == 'INICIO') {
        if (route->info.tokenType == 'LEE') {
            sentencia_lee(route->right, 'L_PARENTESIS');
        } else {
            return route;
        }
    } else if (state == 'L_PARENTESIS') {
        if (route->info.tokenType == state) {
            sentencia_lee(route->right, 'ID');
        } else {
            // error de parentesis izquierdo
            return route;
        }
    } else if (state == 'ID') {
        if (route->info.tokenType == state) {
            sentencia_lee(route->right, 'R_PARENTESIS');
        } else {
            // error de identificador
            return route;
        }
    } else if (state == 'R_PARENTESIS') {
        if (route->info.tokenType == state) {
            sentencia_lee(route->right, 'SEMICOLON');
        } else {
            // error de parentesis derecho
            return route;
        }
    } else if (state == 'SEMICOLON') {
        if (route->info.tokenType == state) {
            return route->right;
        } else {
            // error de semicolon
            return route;
        }
    }
}
**/
/**
struct node *sentencia(struct node *route) {
    if (route->info.tokenType == 'LEE') {
        return sentencia_lee(route, 'INICIO');
    } else if (route->info.tokenType == 'IMPRIMIR') {
        return sentencia_imprimir(route, 'INICIO');
    } else if () {
        // las demás sentencias
    } else {
        return route->right;
    }
}

struct node *checar_sintaxis(struct node *route) {
    if (route != NULL) {
        checar_sintaxis(sentencia(route));
    }
}
**/
