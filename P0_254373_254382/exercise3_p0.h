#ifndef EXERCISES_P0_EXERCISE3_P0_H
#define EXERCISES_P0_EXERCISE3_P0_H

#define MIN_ROWS_EX3 2
#define MAX_ROWS_EX3 5
#define MIN_COLS_EX3 2
#define MAX_COLS_EX3 5
#define MIN_RAND_EX3 0
#define MAX_RAND_EX3 9
#define MIN_NUMBER_EX3 1
#define MAX_NUMBER_EX3 10

// Functions and types Exercise 3

typedef struct {
    int num_rows;
    int num_cols;
    int** values;
} Matrix;

void exercise_3();
Matrix new_matrix(int num_rows, int num_cols);
void init_matrix_values(Matrix matrix);
Matrix scalar_prod(int scalar, Matrix matrix);
Matrix matrix_sum(Matrix matrix_a, Matrix matrix_b);
Matrix matrix_prod(Matrix matrix_a, Matrix matrix_b);
void print_matrix(Matrix matrix);
void free_matrix(Matrix matrix);

#endif //EXERCISES_P0_EXERCISE3_P0_H
