/* 
 * Author: Marco Aurelio Juárez Baltazar
*/

#include <stdio.h>
#include <stdlib.h>

// declaration of functions
void printMatrix(int row, int col, int mtr[row][col]);
int* makeArray(int length, int row, int col, int matr[row][col]);
int* sortArray(int* arr, int length);
void printSortedMatrix(int* arr, int row, int colum);

int main()
{
	// this is the matrix that will be sorted
	int matrix[3][4] = {{4, 3, 5, 10},
											{6, 1, 2, 12},
											{9, 8, 7, 11}};

	int columns = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	int rows = sizeof(matrix) / sizeof(matrix[0]);
	int length = columns * rows;

	printMatrix(rows, columns, matrix);

	int* array = makeArray(length, rows, columns, matrix);
	int* sorted = sortArray(array, length);
	printSortedMatrix(sorted, rows, columns);

	return 0;
}

void printMatrix(int row, int col, int mtr[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%d, ", mtr[i][j]);
		printf("\n");
	}
	printf("\n");

}

int* makeArray(int length, int row, int col, int matr[row][col])
{
	int* array = calloc(length, sizeof(int)); 

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

int* sortArray(int* arr, int length)
{
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

void printSortedMatrix(int* arr, int row, int colum)
{
	int k = 0;

	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < colum; j++) 
		{
			printf("%d, ", arr[k]);
			k++;
		}
		printf("\n");
	}

	free(arr);
}
