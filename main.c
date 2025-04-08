#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_set.h"
#define TMC 100 // Asegúrate de que coincida con tu .h
void menuPrincipal();
void cargarSetManual(set *conjunto);
void operarConjuntos(set A, set B);
void mostrarResultado(set resultado);
void lee_cad(Tcad cad, int tam);
void lee_cadena(Tcad cad);

int main() {
	set A, B;
	int opcion;
	
	A = crearSetVacio();
	B = crearSetVacio();
	
	do {
		menuPrincipal();
		scanf("%d", &opcion);
		fflush(stdin);
		
		switch(opcion) {
		case 1:
			cargarSetManual(&A);
			break;
		case 2:
			cargarSetManual(&B);
			break;
		case 3:
			operarConjuntos(A, B);
			break;
		case 4:
			printf("Saliendo del programa...\n");
			break;
		default:
			printf("Opción inválida!\n");
		}
	} while(opcion != 4);
	
	liberarSet(A);
	liberarSet(B);
	
	return 0;
}

void menuPrincipal() {
	printf("\n=== MENÚ PRINCIPAL ===\n");
	printf("1. Cargar Conjunto A\n");
	printf("2. Cargar Conjunto B\n");
	printf("3. Operar con Conjuntos\n");
	printf("4. Salir\n");
	printf("Seleccione opción: ");
}
void lee_cad(Tcad cad, int tam) {
	char c;
	int j = 0;
	c = getchar();
	while(c != EOF && c != '\n' && j < tam-1) {
		cad[j] = c;
		j++;
		c = getchar();
	}
	cad[j] = '\0';
	// Limpiar buffer sobrante
	while (c != EOF && c != '\n') {
		c = getchar();
	}
}

void lee_cadena(Tcad cad) {
	lee_cad(cad, TMC);
}

// Resto de funciones modificadas para usar lee_cadena
void cargarSetManual(set *conjunto) {
	Tcad input, elemento;
	str cadena;
	char token;
	int opcion, cantidad, i;
	
	printf("\n=== CARGA DE CONJUNTO ===\n");
	printf("1. Ingresar elementos individuales\n");
	printf("2. Ingresar cadena tokenizada\n");
	printf("Seleccione método: ");
	scanf("%d", &opcion);
	getchar();
	
	if(opcion == 1) {
		printf("Cantidad de elementos: ");
		scanf("%d", &cantidad);
		getchar();
		
		for(i = 0; i < cantidad; i++) {
			printf("Elemento %d: ", i+1);
			lee_cadena(elemento);
			cadena = load2(elemento);
			agregarElemento(conjunto, cadena);
		}
	} else if(opcion == 2) {
		printf("Ingrese cadena (ej: a,b,c): ");
		lee_cadena(input);
		printf("Ingrese token (ej: ,): ");
		token = getchar();
		getchar();
		cadena = load2(input);
		*conjunto = strToSetToken(cadena, token);
	} else {
		printf("Opción inválida!\n");
	}
}

// [Las funciones menuPrincipal(), operarConjuntos() y mostrarResultado() 
//  se mantienen igual que en la versión anterior]
void operarConjuntos(set A, set B) {
	Tcad elemento;
	int opcion, existe, inclusion;
	str busqueda;
	set resultado;
	
	do {
		printf("\n=== OPERACIONES CON CONJUNTOS ===\n");
		printf("1. Mostrar Conjunto A\n");
		printf("2. Mostrar Conjunto B\n");
		printf("3. Unión (A ? B)\n");
		printf("4. Intersección (A n B)\n");
		printf("5. Diferencia (A - B)\n");
		printf("6. Verificar elemento\n");
		printf("7. Verificar inclusión\n");
		printf("8. Volver\n");
		printf("Seleccione operación: ");
		scanf("%d", &opcion);
		fflush(stdin);
		
		switch(opcion) {
		case 1:
			printf("\nConjunto A: ");
			mostrarSet(A);
			break;
		case 2:
			printf("\nConjunto B: ");
			mostrarSet(B);
			break;
		case 3:
			resultado = unionConjuntos(A, B);
			printf("\nUnión A ? B: ");
			mostrarSet(resultado);
			liberarSet(resultado);
			break;
		case 4:
			resultado = interseccionConjuntos(A, B);
			printf("\nIntersección A n B: ");
			mostrarSet(resultado);
			liberarSet(resultado);
			break;
		case 5:
			resultado = diferenciaConjuntos(A, B);
			printf("\nDiferencia A - B: ");
			mostrarSet(resultado);
			liberarSet(resultado);
			break;
		case 6:
			printf("Elemento a buscar: ");
			lee_cadena(elemento);
			busqueda = load2(elemento);
			existe = perteneceElemento(A, busqueda);
			printf("El elemento '%s' %s en el conjunto A\n", 
				   elemento, existe ? "está" : "NO está");
			liberarStr(busqueda);
			break;
		case 7:
			inclusion = estaIncluido(A, B);
			printf("El conjunto A %s está incluido en B\n",
				   inclusion ? "SI" : "NO");
			break;
		case 8:
			printf("Volviendo al menú principal...\n");
			break;
		default:
			printf("Opción inválida!\n");
		}
	} while(opcion != 8);
}

void mostrarResultado(set resultado) {
	if(resultado == NULL) {
		printf("Conjunto vacío\n");
	} else {
		mostrarSet(resultado);
	}
}
