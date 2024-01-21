#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void imprimirMatriz(int fil, int col, int mtr[fil][col]) {

	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d, ", mtr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

int* hacerArray(int longitud, int fil, int col, int matr[fil][col]) {

	int* arreglo = (int*) calloc(longitud, sizeof(int)); 

    if (arreglo == NULL) {
			fprintf(stderr, "Error al asignar memoria dinámica\n");
			exit(EXIT_FAILURE);
    }
	int k = 0;

	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			arreglo[k] = matr[i][j];
			k++;
		}
	}

	return arreglo;
}

int* ordenarArray(int* arr, int length) {
	
	int aux;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length-1; j++) {
			if (arr[j] > arr[j+1]) {
				aux = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = aux;
			}
		}
	}

	return arr;
}

void imprimirOrdenado(int* arr2, int fila, int colum, int lg) {
	
	int l = 0;

	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < colum; j++) {
			printf("%d, ", arr2[l]);
			l++;
		}
		printf("\n");
	}

}

int main() {

	int matriz[3][4] = {{4, 3, 5, 7},
											{6, 1, 2, 0},
											{9, 8, 11, 10}};

	int columnas = sizeof(matriz[0]) / sizeof(matriz[0][0]);
	int filas = sizeof(matriz) / sizeof(matriz[0]);
	int longitud = columnas * filas;

	imprimirMatriz(filas, columnas, matriz);

	int* array = hacerArray(longitud, filas, columnas, matriz);
	int* ordenado = ordenarArray(array, longitud);
	imprimirOrdenado(ordenado, filas, columnas, longitud);
	free(array);

	return 0;
}
