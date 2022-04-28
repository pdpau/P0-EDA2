#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "utils.h"
#include "exercise3_p0.h"

/*----------------------------- Functions Exercise 3 -------------------------*/

/**
* Ex. 3.1
*
* Initializes the values of a given matrix with random integers.
*
* @param matrix The matrix to be initialized with random integers between MIN_RAND_EX3 and MAX_RAND_EX3.
*
*/

//Para inicializar los valores de la matriz con nº aleatorios, recorremos las filas y las columnas de la matriz
//Para recorrerlas usamos dos bucles, uno que se repite tantas veces como filas hay y dentro de este otro que se repite tantas veces como columnas hay
//De esta manera, vamos asignando valores aleatorios con get_random para cada elemento de la matriz

void init_matrix_values(Matrix matrix) {
// Implement this function, get_random(min, max) viene ya dada, los valores MIN_RAND_EX3 y MAX ya están definidos

    for (int i=0; i<matrix.num_rows; i++){
        for (int j=0; j<matrix.num_cols; j++){
            matrix.values[i][j]=get_random(MIN_RAND_EX3, MAX_RAND_EX3);
        }
    }
}

/**
* Ex. 3.2.1
*
* Returns the scalar product of an integer and a matrix.
*
* @param scalar Number to multiply.
* @param matrix A matrix initialized.
* @return A matrix obtained by the scalar product of the number and the matrix.
*
*/

//Para hacer el producto escalar creamos una nueva matriz con el new_matrix
//Esta matriz tendrá el mismo nº de filas y de columnas que la matriz que queremos multiplicar por un escalar
//Con dos bucles recorremos las filas y las columnas de la matriz y a cada elemento de la nueva matriz de alignamos el elemento de la matriz original por el escalar dado
//Retornamos la matriz resultante, pues, de multiplicar todos los elementos de la matriz por un escalar

Matrix scalar_prod(int scalar, Matrix matrix_a) {
    Matrix matrix_result  = new_matrix(matrix_a.num_rows, matrix_a.num_cols);

    for (int i=0; i<matrix_a.num_rows; i++){
        for (int j=0; j<matrix_a.num_cols; j++){
            matrix_result.values[i][j]=scalar*matrix_a.values[i][j];
        }
    }
    return matrix_result;
}

/**
* Ex. 3.2.2
*
* Returns sum of two matrices.
*
* @param matrix_a Matrix of shape R x C
* @param matrix_b Matrix of shape R x C
* @return A matrix of shape R x C obtained by the sum of the two matrices or a matrix with values=NULL if they are of incompatible shapes.
*
*/

//Creamos una nueva matriz con new_matrix con el mismo nº de filas y de columnas que A (porque si se puede hacer A+B el nº de filas y columnas de A y B es el mismo y si no da igual el valor que tenga porque los elementos se instaurarán como NULL)
//Comprobamos si el nº de filas y columnas de A y B son el mismo. Si no lo son, imprimimos ERROR e instauramos los valores de la matriz como NULL
//Si son iguales, recorremos las filas y las columnas de la nueva matriz, instaurando los elementos de cada posición como la suma de las mismas posiciones de A y B
//Retornamos la matriz resultante

Matrix matrix_sum(Matrix matrix_a, Matrix matrix_b) {
    Matrix matrix_result = new_matrix(matrix_a.num_rows, matrix_a.num_cols);

    if (matrix_a.num_rows!=matrix_b.num_rows || matrix_a.num_cols!=matrix_b.num_cols){
        printf("ERROR\n");
        matrix_result.values = NULL;

    } else {
        for (int i=0; i<matrix_result.num_rows; i++){
            for (int j=0; j<matrix_result.num_cols; j++){
                matrix_result.values[i][j]=matrix_a.values[i][j]+matrix_b.values[i][j];
            }
        }
    }
    return matrix_result;
}

/**
* Ex. 3.2.3
*
* Returns product of two matrices.
*
* @param matrix_a Matrix of shape Ra x Ca
* @param matrix_b Matrix of shape Rb x Cb
* @return A matrix of shape Ra x Cb obtained by the product of the two matrices or a matrix with values=NULL if they are of incompatible shapes.
*
*/

//Creamos una nueva matriz con new_matrix con el mismo nº de filas que A y de columnas que B (porque si se puede hacer A·B la matriz resultante es de ese tamaño y si no da igual el valor que tenga porque los elementos se instaurarán como NULL)
//Comprobamos lo necesario para poder multiplicar 2 matrices, que el nº de columnas de A sea igual al nº de filas de B
//Si no son iguales, imprimos error e instauramos los elementos de la matriz resultante como NULL
//Si lo son, se puede hacer el producto de las 2 matrices, por lo que usamos 3 bucles para llevar a cabo las operaciones según la fórmula del producto de 2 matrices
//Retornamos la matriz resultante

Matrix matrix_prod(Matrix matrix_a, Matrix matrix_b) {
    Matrix matrix_result = new_matrix(matrix_a.num_rows, matrix_b.num_cols);

    if (matrix_a.num_cols!=matrix_b.num_rows){
        printf("ERROR\n");
        matrix_result.values = NULL;
    } else {
        for (int i=0; i<matrix_result.num_rows; i++){
            for (int j=0; j<matrix_result.num_cols; j++){
                int suma=0;
                for (int k=0; k<matrix_a.num_cols; k++){  //cols A = filas B
                    suma+=matrix_a.values[i][k]*matrix_b.values[k][j];
                }
                matrix_result.values[i][j]=suma;
            }
        }
    }
    return matrix_result;
}

/**
*
* Allocates dynamic memory for a given matrix, which should be released when no longer used.
*
* @param num_rows Number of rows.
* @param num_cols Number of columns.
* @return A matrix of num_rows x num_cols.
*
*/

//Creamos una estructura del tipo Matrix y le asignamos a sus filas y columnas las dadas por los parámetros
//Creamos espacio en la memoria dinámica para los valores de la matriz, creando primero las filas
//Después, con un bucle, creamos el espacio necesario para los columnas de cada fila
//Retornamos la matriz resultante, cuyos elementos aún no se han determinado

Matrix new_matrix(int num_rows, int num_cols) {
    Matrix matrix;
    matrix.num_rows= num_rows;
    matrix.num_cols = num_cols;

    matrix.values = (int **)malloc (num_rows*sizeof(int *));

    for (int i=0; i<matrix.num_rows; i++){
        matrix.values[i] = (int *) malloc (matrix.num_cols*sizeof(int));
    }
    return matrix;
}

/**
*
* Prints a matrix.
*
* @param matrix Matrix to print.
*
*/

//Recorremos las filas y las columnas de la matriz imprimiendo sus elementos
//Cada vez que se termina de recorrer una fila, se imprime un espacio para que los sigueintes elementos se impriman en otra línea

void print_matrix(Matrix matrix) {
    for (int i=0; i<matrix.num_rows; i++){
        for (int j=0; j<matrix.num_cols; j++){
            printf("%d ", matrix.values[i][j]);
        }
        printf("\n");
    }
}

/**
*
* Frees the memory used by a matrix.
* 1. Recorrer las filas liberando el espacio de cada columna
* 2. Liberar el espacio de las filas
*
* @param matrix Matrix to free.
*
*/
void free_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.num_rows; i++) {
        free(matrix.values[i]);
    }
    free(matrix.values);
}

/*-------------------------------- Execise 3 ----------------------------*/

void exercise_3() {

    printf("\n--- Exercise 3 ---\n");

    int rows_a = read_number("\n>> Enter the number of rows of matrix A (between %d and %d): ", MIN_ROWS_EX3, MAX_ROWS_EX3);
    int cols_a = read_number(">> Enter the number of columns of matrix A (between %d and %d): ", MIN_COLS_EX3, MAX_COLS_EX3);
    int rows_b = read_number(">> Enter the number of rows of matrix B (between %d and %d): ", MIN_ROWS_EX3, MAX_ROWS_EX3);
    int cols_b = read_number(">> Enter the number of columns of matrix B (between %d and %d): ", MIN_COLS_EX3, MAX_COLS_EX3);

    Matrix matrix_a = new_matrix(rows_a, cols_a);
    Matrix matrix_b = new_matrix(rows_b, cols_b);
    init_matrix_values(matrix_a);
    init_matrix_values(matrix_b);

    printf("Matrix A (%d x %d):\n", matrix_a.num_rows, matrix_a.num_cols);
    print_matrix(matrix_a);
    printf("\n");
    printf("Matrix B (%d x %d):\n", matrix_b.num_rows, matrix_b.num_cols);
    print_matrix(matrix_b);
    printf("\n");

    int scalar = read_number(">> Enter an integer between %d and %d: ", MIN_NUMBER_EX3, MAX_NUMBER_EX3);
    Matrix matrix_scalar_a = scalar_prod(scalar, matrix_a);
    printf("%d.A is:\n", scalar);
    print_matrix(matrix_scalar_a);
    printf("\n");

    Matrix matrix_aplusb = matrix_sum(matrix_a, matrix_b);
    if (matrix_aplusb.values == NULL) {
        printf("It is not possible to sum a matrix of shape %dx%d with a matrix of shape %dx%d\n", matrix_a.num_rows, matrix_a.num_cols, matrix_b.num_rows, matrix_b.num_cols);
    } else {
        printf("Matrix A+B (%d x %d):\n", matrix_aplusb.num_rows, matrix_aplusb.num_cols);
        print_matrix(matrix_aplusb);
        printf("\n");
    }

    Matrix matrix_axb = matrix_prod(matrix_a, matrix_b);
    if (matrix_axb.values == NULL) {
        printf("It is not possible to multiple a matrix of shape %dx%d with a matrix of shape %dx%d\n", matrix_a.num_rows, matrix_a.num_cols, matrix_b.num_rows, matrix_b.num_cols);
    } else {
        printf("Matrix A.B (%d x %d):\n", matrix_a.num_rows, matrix_b.num_cols);
        print_matrix(matrix_axb);
    }

    free_matrix(matrix_a);
    free_matrix(matrix_b);
    free_matrix(matrix_scalar_a);
    free_matrix(matrix_aplusb);
    free_matrix(matrix_axb);

}
