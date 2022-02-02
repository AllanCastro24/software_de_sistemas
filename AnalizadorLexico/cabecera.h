typedef enum{
    PalRes,
    ID,
    NUM,
    SIM,
    OPAR,
    OPCOMP,
    OPASIGN,
    OPLOG,
    ESPECIAL,
    CAD,
    ERROR
}TipoToken;

typedef enum{
    INT,
    STRING,
    CHAR,
    FLOAT,
    OTRO
}TipoDato;

typedef struct{
    TipoToken tipoToken;
    char lexema[100];
    TipoDato tipoDato;
}Token;

//Estructura del nodo
typedef struct nodo
{
    Token tok;
    struct nodo *siguiente;
    struct nodo *anterior;
} NODO;

NODO *CrearNodo(Token tok);
int InsertarInicio(NODO **cabeza, Token tok);
int InsertarFinal(NODO **cabeza,Token tok);
void ImprimirLista(NODO *cabeza);
