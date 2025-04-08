#ifndef TAD_STRING_H
#define TAD_STRING_H

#define TMC 100 

typedef char Tcad[TMC]; 

typedef struct NodoStr {
	char character;
	struct NodoStr *sig;
} NodoStr;

typedef NodoStr *str;


str createStr();
str creaNodoStr(char );
void agregarCaracter(str *cad, char c);
str load2(const char *);
void mostrarStr(str s);
int compararStr(str s1, str s2);
void liberarStr(str s);

#endif
