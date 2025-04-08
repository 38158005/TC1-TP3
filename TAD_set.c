#include "TAD_set.h"
#include <stdlib.h>
#include <stdio.h>

set crearSetVacio() {
	return NULL;
}


void agregarElemento(set *conjunto, str elemento) {
	set actual = *conjunto;
	int existe = 0;
	
	
	while (actual != NULL && !existe) {
		if (compararStr(actual->elemento, elemento)) {
			existe = 1;
		}
		
		actual = actual->sig;
	}
	
	if (!existe) {
		NodoSet *nuevo = (NodoSet*)malloc(sizeof(NodoSet));
		nuevo->elemento = elemento;
		nuevo->sig = *conjunto; 
		*conjunto = nuevo;
	}
}

void mostrarSet(set conjunto) {
	set aux;
	aux = conjunto;
	
	printf("{ ");
	while (aux != NULL) {
		mostrarStr(aux->elemento);
		if (aux->sig != NULL) printf(", ");
		aux = aux->sig;
	}
	printf(" }\n");
}


set strToSetToken(str cadena, char token) {
	set resultado = crearSetVacio();
	str buffer = createStr();
	str *tailBuffer = &buffer;
	str actual = cadena;
	
	while (actual != NULL) {
		if (actual->character != token) {
			
			str nuevoNodo = creaNodoStr(actual->character);
			if (*tailBuffer == NULL) {
				*tailBuffer = nuevoNodo;
			} else {
				(*tailBuffer)->sig = nuevoNodo;
			}
			tailBuffer = &((*tailBuffer)->sig);
		} else {
			
			if (buffer != NULL) {
				agregarElemento(&resultado, buffer);
				buffer = createStr();
				tailBuffer = &buffer;
			}
		}
		actual = actual->sig;
	}
	
	
	if (buffer != NULL) {
		agregarElemento(&resultado, buffer);
	}
	
	return resultado;
}

set unionConjuntos(set a, set b) {
	set resultado, aux;
	
	resultado = crearSetVacio();
	
	
	aux = a;
	while (aux != NULL) {
		agregarElemento(&resultado, aux->elemento);
		aux = aux->sig;
	}
	
	
	aux = b;
	while (aux != NULL) {
		agregarElemento(&resultado, aux->elemento);
		aux = aux->sig;
	}
	
	return resultado;
}

set interseccionConjuntos(set a, set b) {
	set resultado, aux;
	
	resultado = crearSetVacio();
	aux = a;
	
	while (aux != NULL) {
		if (perteneceElemento(b, aux->elemento)) {
			agregarElemento(&resultado, aux->elemento);
		}
		aux = aux->sig;
	}
	return resultado;
}

set diferenciaConjuntos(set a, set b) {
	set resultado, aux;
	
	resultado = crearSetVacio();
	aux = a;
	
	while (aux != NULL) {
		if (!perteneceElemento(b, aux->elemento)) {
			agregarElemento(&resultado, aux->elemento);
		}
		aux = aux->sig;
	}
	return resultado;
}

int perteneceElemento(set conjunto, str elemento) {
	set aux;
	aux = conjunto;
	
	while (aux != NULL) {
		if (compararStr(aux->elemento, elemento)) return 1;
		aux = aux->sig;
	}
	return 0;
}

int estaIncluido(set subconjunto, set conjunto) {
	set aux;
	aux = subconjunto;
	
	while (aux != NULL) {
		if (!perteneceElemento(conjunto, aux->elemento)) return 0;
		aux = aux->sig;
	}
	return 1;
}

void liberarSet(set s) {
	NodoSet *aux;
	while (s != NULL) {
		aux = s;
		s = s->sig;
		liberarStr(aux->elemento);
		free(aux);
	}
}
