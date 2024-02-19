/* Matrix Sorter by m4jbz */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* Declaration of functions. */
void printMatrix(int row, int col, int mtr[row][col]);
int* makeArray(int length, int row, int col, int matr[row][col]);
int* sortArray(int* arr, int length);
void printSortedMatrix(int* arr2, int row, int colum);

int main() {

	int matrix[3][3] = {{4, 3, 5},
											{6, 1, 2},
											{9, 8, 7}};

	int columns = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	int rows = sizeof(matrix) / sizeof(matrix[0]);
	int length = columns * rows;

	printMatrix(rows, columns, matrix);

	int* array = makeArray(length, rows, columns, matrix);
	int* sorted = sortArray(array, length);
	printSortedMatrix(sorted, rows, columns);

	return 0;
}

void printMatrix(int row, int col, int mtr[row][col]) {

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%d, ", mtr[i][j]);
		printf("\n");
	}
	printf("\n");

}

int* makeArray(int length, int row, int col, int matr[row][col]) {

	int* array = (int*) calloc(length, sizeof(int)); 

	if (array == NULL) 
	{
		fprintf(stderr, "ERROR to asign dynamic memory.\n");
		exit(EXIT_FAILURE);
	}

	int k = 0;

	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < col; j++) 
		{
			array[k] = matr[i][j];
			k++;
		}
	}

	return array;
	free(array);
}

int* sortArray(int* arr, int length) {
	
	int aux;

	for (int i = 0; i < length; i++) 
	{
		for (int j = 0; j < length-1; j++) 
		{
			if (arr[j] > arr[j+1]) 
			{
				aux = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = aux;
			}
		}
	}

	return arr;
	free(arr);
}

void printSortedMatrix(int* arr2, int row, int colum) {
	
	int l = 0;

	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < colum; j++) 
		{
			printf("%d, ", arr2[l]);
			l++;
		}
		printf("\n");
	}

}
