#ifndef EXERCISES_P0_EXERCISE2_P0_H
#define EXERCISES_P0_EXERCISE2_P0_H

#define ERROR_FILE -1

#define MAX_LENGTH_FILEPATH_EX2 30
#define MAX_NUM_LINES_EX2 10
#define MAX_STRING_LENGTH_EX2 10
#define FILEPATH_EX2 "../resources/strings.txt"

// Functions Exercise 2

void exercise_2();
int read_lines_file(char* file_path, char** lines, int max_line_length);
int string_length(char* str);
bool is_reverse(char* string1, char* string2);
int count_substring(char* string1, char* string2);
char* concat_strings(char* string1, char* string2);
void concat_strings_mod(char* string1, char* string2);

#endif //EXERCISES_P0_EXERCISE2_P0_H
