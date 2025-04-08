#ifndef TAD_SET_H
#define TAD_SET_H

#include "TAD_string.h"

typedef struct NodoSet {
	str elemento;
	struct NodoSet *sig;
} NodoSet;

typedef NodoSet *set;


set crearSetVacio();
void agregarElemento(set *conjunto, str elemento);
void mostrarSet(set conjunto);
set strToSetToken(str cadena, char token);
set unionConjuntos(set a, set b);
set interseccionConjuntos(set a, set b);
set diferenciaConjuntos(set a, set b);
int perteneceElemento(set conjunto, str elemento);
int estaIncluido(set subconjunto, set conjunto);
void liberarSet(set s);

#endif
