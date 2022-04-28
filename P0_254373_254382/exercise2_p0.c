#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "utils.h"
#include "exercise2_p0.h"

/*----------------------------- Functions Exercise 2 -------------------------*/

/**
 * Reads the lines of a text file into an array.
 * 1. Abrir el fichero y comprobar que se ha hecho correctamente
 * 2. Inicializar numero de lineas a 0
 * 3. Iniciar un bucle que terminará cuando termine el fichero
 * 4. Dentro del bucle, fgets para coger cada linea y guardarla en lines. Añadir +1 a numero de lineas para la siguiente iteración
 * 5. Cerrar el fichero
 *
 * @param file_path The minimum number accepted.
 * @param lines A 2-dimensional array where the contents of the file are read.
 * @param max_line_length The maximum length of the lines in the file.
 * @return The number of lines successfully read or ERROR_FILE when the file cannot be read.
 *
 */
int read_lines_file(char* file_path, char** lines, int max_line_length) {
    FILE* file;
    file = fopen(file_path, "r");

    if (file == NULL) {
        return ERROR_FILE;
    }

    int num_of_lines = 0;
    //char c;
    while(!feof(file)) {
        //c = getc(file);
        fgets(lines[num_of_lines], max_line_length, file);
        num_of_lines++;
    }
    fclose(file);
    return num_of_lines;
}

/**
 * Returns the length of a string.
 * 1. Recorrer la string caracter por caracter. Si el caracter no es una letra, corta el for
 *
 * @param str Input string.
 * @return The number of characters in the string.
 *
 */
int string_length(char* str) {
    int counter = 0;
    for (int i = 0; i < MAX_STRING_LENGTH_EX2; i++) {
        if (('a' > str[i]) || (str[i] > 'z')) {
            break;
        }
        counter++;
    }

    return counter;
}

/**
 * Ex. 2.1
 * Indicates whether the first string passed is the reverse of the second one.
 * 1. Comprobar que ambas strings tengan la misma longitud (con la funcion string_length)
 * 2. Comparar el primer caracter de string1 con el ultimo de string2
 *
 * @param string1 A string.
 * @param string2 A string.
 * @return A boolean value indicating whether the two passed strings are the reverse of each other.
 *
 */
bool is_reverse(char* string1, char* string2) {
    int l1 = string_length(string1);
    int l2 = string_length(string2);
    if (l1 != l2) {
        return false;
    }

    for (int i = 0; i < l1; i++) {
        if (string1[i] != string2[l2-i-1]) {
            return false;
        }
    }

    return true;
}

/**
* Ex. 2.2
* Counts the total number of occurrences of the second string in the first one.
* 1. Comparar la primera letra de ambas, si coinciden entonces comparar segunda y sumar 1 al contador coincidence.
* Si no coinciden, comparar segunda de string1 con primera de string2
* 2. Comprobar si el contador coincidence es tan largo como la string2, si lo es significa que string2 esta
* dentro de string1 al menos una vez. Seguir con las letras de string1.
*
* @param string1 A string.
* @param string2 A string.
* @return An integer value indicating the number of times that the second string occurs in the first one.
*
*/
int count_substring(char* string1, char* string2) {
    int l1 = string_length(string1);
    int l2 = string_length(string2);
    int counter = 0;
    int coincidence = 0;
    int j = 0;

    for (int i = 0; i < l1; i++) {
        if (string1[i] == string2[j]) {
            coincidence++;
            j++;
        }
        else {
            coincidence = 0;
            j = 0;
        }
        if (coincidence == l2) {
            counter++;
            coincidence = 0;
            j = 0;
        }
    }

    return counter;
}

/**
* Ex. 2.3.1
* Concatenates two strings and returns the result.
* 1. Crear una string dinamicamente
* 2. Copiar la primera string en la nueva
* 3. Copiar la segunda a partir del espacio siguiente al ultimo caracter de la primera
* 4. Retornar la nueva string
*
* @param string1 A string.
* @param string2 A string.
* @return A string with the concatenation of the two passed strings.
*
*/
char* concat_strings(char* string1, char* string2) {
    int l1 = string_length(string1);
    int l2 = string_length(string2);
    char* new_string = (char*) malloc((l1+l2) * sizeof(char));
    //char* new_string[l1+l2];

    // Añadir string1 a new_string
    for (int i = 0; i < l1; i++) {
        new_string[i] = string1[i];
    }
    // Añadir string2 justo despues
    for (int i = l1; i <= l1+l2; i++) {
        new_string[i] = string2[i-l1];
    }

    return new_string;
}

/**
* Ex. 2.3.2
* Concatenates two strings and returns the result in the first string.
* 1. Igual que el anterior pero modificando la tring1 a partir de su ultimo caracter
*
* @param string1 A string.
* @param string2 A string.
* @return A string with the concatenation of the two passed strings.
*
*/
void concat_strings_mod(char* string1, char* string2) {
    int l1 = string_length(string1);
    int l2 = string_length(string2);

    //string1 = (char*) realloc(string1, (l1+l2) * sizeof(char));

    // Añadir string2 justo despues
    for (int i = l1; i <= l1+l2; i++) {
        string1[i] = string2[i-l1];
    }

    //printf("%s", string1);
}

/*-------------------------------- Execise 2 ----------------------------*/

void exercise_2() {

    printf("\n--- Exercise 2 ---\n");

    char strings_file_path[MAX_LENGTH_FILEPATH_EX2];
    strcpy(strings_file_path, FILEPATH_EX2);
    char* lines[MAX_NUM_LINES_EX2];

    // Assign memory for each line;
    int max_line_length = (MAX_STRING_LENGTH_EX2 + 1)* 2 + 1;
    for (int i = 0; i < MAX_NUM_LINES_EX2; i++) {
        lines[i] = (char*)malloc(max_line_length * sizeof(char));
    }

    int number_read_lines = read_lines_file(strings_file_path, lines, max_line_length);
    if (number_read_lines != ERROR_FILE) {
        printf("Read %d lines from file: %s\n", number_read_lines, strings_file_path);
        press_key("Press <ENTER> to continue\n");

        int num_line = 0;
        // We need string1 to be big enough to contain the concatenation of both strings in exercise 2.3.2.
        char string1[2*MAX_STRING_LENGTH_EX2 + 1];
        char string2[MAX_STRING_LENGTH_EX2 + 1];
        while (num_line < number_read_lines) {
            if (sscanf(lines[num_line], "%s %s", string1, string2) == 2) {
                printf("Read strings '%s' and '%s'.\n", string1, string2);

                /* 2.1 - Are strings reversed? */
                printf("'%s' is", string1);
                if (!is_reverse(string1, string2)) {
                    printf(" not");
                }
                printf(" the reverse of '%s'\n", string2);

                /* 2.2 - Count occurrences of substring */
                int count = count_substring(string1, string2);
                if (count > 0) {
                    printf("'%s' occurs %d times in '%s'\n", string2, count, string1);
                } else {
                    printf("'%s' does not occur in '%s'\n", string2, string1);
                }

                /* 2.3.1 - Concatenate two strings and returns the result */
                char* str_concat = concat_strings(string1, string2);
                printf("The concatenation of '%s' and '%s' is '%s'\n", string1, string2, str_concat);
                free(str_concat);

                /* 2.3.1 - Concatenate two strings and return the result in the first string */
                printf("The concatenation of '%s' and '%s' is ", string1, string2);
                concat_strings_mod(string1, string2);
                printf("'%s'\n", string1);

            }
            press_key("Press <ENTER> to continue\n");
            num_line++;
        }
    } else { // read_lines_file returned ERROR_FILE.
        printf("The file %s could not be read.\n", strings_file_path);
    }
}