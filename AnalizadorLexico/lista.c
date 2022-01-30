#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "cabecera.h"

//Funci�n para insertar al final de la lista
int InsertarFinal(NODO **cabeza, Token tok)
{
    NODO *nuevo = NULL, *nAux = *cabeza;

    nuevo = CrearNodo(tok);
    if (nuevo != NULL)
    {
        while(nAux->siguiente != NULL){ nAux = nAux->siguiente;}
        nuevo->anterior = nAux;
        nAux->siguiente = nuevo;
        return 1;
    }
    return 0;
}

//Funci�n para imprimir la lista
void ImprimirLista(NODO *cabeza)
{
    NODO *nAux = cabeza;

    while(nAux != NULL)
    {

        printf("\nLexema = %s\nTipoToken = %i\nTipoDato = %i\n",
               nAux->tok.lexema, nAux->tok.tipoToken, nAux->tok.tipoDato);
        printf("\n---------------------------\n");
        nAux = nAux->siguiente;
    }
}

//Funci�n para insertar al inicio de la lista
int InsertarInicio(NODO **cabeza, Token tok)
{
    NODO *nuevo = NULL;

    nuevo = CrearNodo(tok);
    if (nuevo != NULL)
    {
        nuevo->siguiente = *cabeza;
        nuevo->anterior = NULL;
        if( *cabeza != NULL)
            (*cabeza)->anterior = nuevo;
        *cabeza = nuevo;
        return 1;
    }
    return 0;
}

//Funci�n para crear un nuevo nodo
NODO *CrearNodo(Token tok)
{
    NODO* nuevo = NULL;

    nuevo = (NODO*)malloc(sizeof(NODO));
    if( nuevo != NULL)
    {
        nuevo->tok = tok;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
    }
    return nuevo;
}

//Y no te doy otra nom�s porque...