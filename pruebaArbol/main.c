#include <stdio.h>
#include <stdlib.h>

/**typedef struct Exp {
  enum { integer_exp, string_exp, variable_exp,
         binary_exp, unary_exp, call_exp,
         projection_exp, record_exp } tag;
  union { int                                      integerExp;
          string                                   stringExp;
          string                                   variableExp;
          struct { string           operator;
                   struct Exp*      left;
                   struct Exp*      right; }       binaryExp;
          struct { string           operator;
                   struct Exp*      operand; }     unaryExp;
          struct { string           name;
                   struct Exp_list* arguments; }   callExp;
          struct { struct Exp*  record;
                   string       attribute; }       projectionExp;
          struct rec { string       attribute;
                       struct Exp*  value;
                       struct rec*  next; }        recordExp;
      } op;
} ast;**/


int main()
{
    FILE * arch = fopen("hola.txt", "rt"); //Abrimos documento de texto
    char car = ' ';

    if (arch == NULL){ //Validación, si el archivo de código no existe entonces no iniciar programa
        printf("\nError de apertura del archivo. \n\n");
    }else{

    }
    return 0;
}

/**void Gettoken(NODO *cabeza)
{
    NODO *nAux = cabeza;

    while(nAux != NULL)
    {

        printf("\nLexema = %s\nTipoToken = %i\nTipoDato = %i\n",
               nAux->tok.lexema, nAux->tok.tipoToken, nAux->tok.tipoDato);
        printf("\n---------------------------\n");
        nAux = nAux->siguiente;
    }
}**/
