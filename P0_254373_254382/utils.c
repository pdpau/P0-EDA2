#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
* Consumes characters left in the input buffer.
*
*/
void flush_input() {
    while ((getchar()) != '\n');
}

/**
 * Asks the user to enter an integer between min and max numbers.
 * Note that in a production environment the input should be checked!!!
 *
 * @param min The minimum number accepted.
 * @param max The maximum number accepted.
 * @return The number entered by the user.
 *
 */
int read_number(char* message, int min, int max) {
    int num = 0;
    bool valid = false;

    while (!valid) {
        printf(message, min, max);
        int read = scanf("%d", &num);
        flush_input();
        if (read != 1 || num < min || num > max) {
            printf("The entered value is not valid. Please try again.\n");
        } else {
            valid = true;
        }
    }

    return num;
}

/**
 * Returns a random number in the given range.
 *
 * @param min The minimum number to return.
 * @param max The maximum number to return.
 * @return A random integer between in the range [min, max].
 *
 */
int get_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/**
 * Shows a message and waits until the user presses <ENTER> to continue the execution.
 *
 */
void press_key(char* message) {
    printf("\n%s\n", message);
    getchar();
}
