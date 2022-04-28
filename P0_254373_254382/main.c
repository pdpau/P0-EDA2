#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"
#include "exercise1_p0.h"
#include "exercise2_p0.h"
#include "exercise3_p0.h"

int main() {

    bool end = false;
    while (!end) {
        int exercise = read_number("\n>> Enter the number of the exercise to run (1, 2, 3) or 0 to exit: ", 0, 3);
        switch (exercise) {
            case 0: // Exit;
                end = true;
                break;
            case 1: // Run exercise 1;
                exercise_1();
                break;
            case 2: // Run exercise 2;
                exercise_2();
                break;
            case 3: // Run exercise 3;
                exercise_3();
                break;
        }
    }

    return EXIT_SUCCESS;
} // main
