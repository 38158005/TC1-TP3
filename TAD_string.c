#include "TAD_string.h"
#include <stdlib.h>
#include <stdio.h>

str createStr() {
	return NULL;
}

str creaNodoStr(char c) {
	str nuevo;
	nuevo = (str)malloc(sizeof(NodoStr));
	if (nuevo == NULL) {
		printf("Error de memoria\n");
		return NULL;
	}
	nuevo->character = c;
	nuevo->sig = NULL;
	return nuevo;
}

void agregarCaracter(str *cadena, char c) {
	str nuevo, aux;
	nuevo = creaNodoStr(c);
	
	if (*cadena == NULL) {
		*cadena = nuevo;
	} else {
		aux = *cadena;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

str load2(const char *input) {
	str nuevaCadena;
	int i;
	
	nuevaCadena = createStr();
	i = 0;
	while (input[i] != '\0') {
		agregarCaracter(&nuevaCadena, input[i]);
		i++;
	}
	return nuevaCadena;
}

void mostrarStr(str s) {
	str aux;
	aux = s;
	
	if (aux == NULL) {
		printf("[Vacio]");
		return;
	}
	
	while (aux != NULL) {
		printf("%c", aux->character);
		aux = aux->sig;
	}
}

int compararStr(str s1, str s2) {
	str aux1, aux2;
	aux1 = s1;
	aux2 = s2;
	
	while (aux1 != NULL && aux2 != NULL) {
		if (aux1->character != aux2->character) return 0;
		aux1 = aux1->sig;
		aux2 = aux2->sig;
	}
	return (aux1 == NULL && aux2 == NULL);
}

void liberarStr(str s) {
	str aux;
	while (s != NULL) {
		aux = s;
		s = s->sig;
		free(aux);
	}
}
