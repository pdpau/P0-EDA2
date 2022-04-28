#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
#include "exercise1_p0.h"

/*----------------------------- Functions Exercise 1 -------------------------*/

/**
 * Ex. 1.1
 * Returns the binary representation of an integer.
 *
 * @param num An arbitrary integer in decimal representation.
 * @return The binary representation of the passed number.
 *
 */

int potencia(int num, int pow){
    int resultado=1;
    for (int i=1; i<=pow; i++){
        resultado=resultado*num;
    }
    return resultado;
}

//Creamos una variable x en la que se guardará el nº en binario
//Mientras en nº no sea 0, calculamos la potencia de 2 más cercana por abajo al nº y le sumamos a x 10 elevado a dicha potencia
//Después, se le resta al nº la potencia de 2 más cercana encontrada para que al continuar el bucle considere la potencia que ya se ha encontrado

int get_binary(int num){
    int x=0;
    if (num==0){
        return x;
    } else {
        for (int i=num; i>=0; i--){
            if (num>=potencia(2, i)){
                x+=potencia(10, i);
                num=num-potencia(2, i);
            }
        }
        return x;
    }
}

/**
 * Ex. 1.2.1
 * Returns the factorial of a number. (Iterative implementation).
 *
 * @param num An arbitrary natural number.
 * @return The factorial of the number, or 0 if not a natural number.
 *
 */

//Para calcular el factorial comprobamos si es un nº natural. Si no lo es, retorna 0
// Si lo es, repetimos un bucle num-1 veces para multiplicar todos los nº entre 2 y num

long long int factorial_i(int num) {
    if (num%1!=0){
        return 0;
    } else {
        long long int x=1;
        for (int i=2; i<=num; i++){
            x=x*i;
        }
        return x;
    }
}

/**
 * Ex. 1.2.2
 * Returns the factorial of a number. (Recursive implementation).
 *
 * @param num An arbitrary natural number.
 * @return The factorial of the number, or 0 if not a natural number.
 *
 */

//Para calcular el factorial comprobamos si es un nº natural. Si no lo es, retorna 0
//Después, comprobamos si el nº es 1 y si lo es retorna 1
//Si no, multiplicamos num por el factorial de num-1, que a su vez es num-1 por el factorial de num-2 y así consecutivamente
//Con esto, conseguimos multiplicar num por todos los números que hay entre num y 1, ya que factorial_r(1)=1 y factorial_r(n)=n*factorial(n-1)

long long int factorial_r(int num){
    if (num%1!=0){
        return 0;
    } else if (num==1){
        return 1;
    } else {
        return num*factorial_r(num-1);
    }
}

/**
 * Ex. 1.3.1
 * Returns the Fibonacci of a number. (Iterative implementation).
 *
 * @param num An arbitrary natural number.
 * @return The Fibonacci of the number, or -1 if not a natural number.
 *
 */

//Para calcular el factorial comprobamos si es un nº natural y positivo. Si no lo es, retorna -1
//Después, instauramos 3 variables de enteros con los valores iniciales de la serie de fibonacci (0, 1, 0+1=1)
//Con esto, entramos en un bucle que se repetirá num-2 veces en los que la 1ª variable tomará el valor de la 2ª, la 2ª el de la 3ª y la 3ª volverá a ser la 1ª más la 2ª
//De esta manera se consigue calcular el valor correspondiente de la sucesión de fibonacci con sumas iterativas
//Cuando el bucle acaba, se retorna el valor de la 3ª variable

int fibonacci_i(int num){
    if (num%1!=0 || num<0){
        return -1;
    } else {
        int a=0;
        int b=1;
        int c=a+b;
        for (int i=2; i<num; i++){
            a=b;
            b=c;
            c=a+b;
        }
        return c;
    }
}

/**
 * Ex. 1.3.2
 * Returns the Fibonacci of a number. (Recursive implementation).
 *
 * @param num An arbitrary natural number.
 * @return The Fibonacci of the number, or -1 if not a natural number.
 *
 */

//Para calcular el factorial comprobamos si es un nº natural y positivo. Si no lo es, retorna -1
//Después comprobamos si el nº es igual a 1 o 0, y si lo es returnamos 1 o 0 respectivamente
//Si no, retornamos la estructura recursiva fibonacci_r(num-1)+fibonacci_r(num-2), como lo indica la fórmula del fibonacci
//Podemos ver que esto se cumple ya que, por ejemplo, f(5)=f(4)+f(3)=f(3)+f(2)+f(2)+f(1)=f(2)+f(1)+f(1)+1=f(1)+1+1+1=1+1+1+1=4
//Comprobamos que la sucesión es 0 1 1 2 3 5, por lo que el método funciona

int fibonacci_r(int num){
    if (num%1!=0 || num<0){
        return -1;
    } else {
        if (num==1 || num==0){
            return num;
        } else {
            return fibonacci_r(num-1)+fibonacci_r(num-2);
        }
    }
}

/**
 * Ex. 1.4
 * Indicates if the number passed is a prime number.
 *
 * @param num An arbitrary natural number greater than 1.
 * @return 1 if the number is prime, 0 otherwise.
 *
 */

//El método más rápido para comprobar que un nº es primo es comprobar si es divisible entre algún primo
//Esto se comprueba de los primos más pequeños a los más grandes mientras que el cociente del num entre un primo sea mayor a dicho primo
//En nuestra lista de primos ponemos el 2 y el 3, porque tenemos que considerar numeros del 1 al 15 y con el siguiente primo (5), el cociente es menor a 5
//Por lo tanto, entramos en un bucle que se repite 2 veces (por la longitud de la lista) en la que si el num y el elemento de la lista son distintos y su resto es 0 se retorna 0
//Si se ha acabado el bucle sin retornar nada, significa que el nº no es divisible entre ningún elemento de la lista, por lo que es primo y se retorna 1

bool is_prime(int num){
    int lista_primos[2] = {2,3}; //Solo va de 0 a 3 pq 15/3=5 y 5>3 pero 15/5=3 y 3<5
    for (int i=0; i<2; i++){
        if (num%lista_primos[i]==0 && num!=lista_primos[i]){
            return 0;
        }
    }
    return 1;
}

/**
 * Ex. 1.5
 * Indicates whether the number passed can be expressed as the sum of two prime numbers.
 *
 * @param num An arbitrary natural number greater than 1.
 * @param prime1 The first prime number returned such that num = prime1 + prime2
 * @param prime2 The second prime number returned such that num = prime1 + prime2
 * @return A boolean indicating whether the a pair of prime numbers exists that summed up equal to the first parameter.
 *
 */

//Creamos una lista con los nº primos hasta que el más pequeño y el más grande sumen menos de 15, por lo que nuestra lista incluye del 2 al 13
//Creamos un bucle dentro de otro bucle para comprobar si la suma de dos elementos de la lista son iguales al num
//Si encontramos dos elementos de la lista que suman num, asignamos estos valores a los parámetros prime1 y prime2 y retornamos true
//Si se acaba de ejecutar el bucle, significa que no hay ninguna suma de dos elementos de la lista que sumen num, por lo que retornamos false

bool get_sum_primes(int num, int *prime1, int *prime2) {
    int lista_primos[6] = {2,3,5,7,11,13};
    for (int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if (lista_primos[i]+lista_primos[j]==num){
                *prime1 = lista_primos[i];
                *prime2 = lista_primos[j];
                return true;
            }
        }
    }
    return false;
}

/*-------------------------------- Execise 1 ----------------------------*/

void exercise_1() {

    printf("\n--- Exercise 1 ---\n");

    // Read an integer between MIN_NUMBER_EX1 and MAX_NUMBER_EX1.
    int num = read_number("\n>> Enter a number between %d and %d: ", MIN_NUMBER_EX1, MAX_NUMBER_EX1);

    /* 1.1 - Binary representation */
    int bin = get_binary(num);
    printf("The binary representation of %d is %d\n", num, bin);

    /* 1.2 - Factorial */
    long long int fac_i = factorial_i(num);
    // We know that in this case the number will be valid, so the condition of this 'if' should always be true.
    if (fac_i > 0) {
        printf("FactI(%d) = %lli\n", num, fac_i);
    } else {
        printf("Error found when calculating the factorial of %d. Please make sure that you passed a natural number.\n",
               num);
    }
    long long int fac_r = factorial_r(num);
    if (fac_r > 0) {
        printf("FactR(%d) = %lli\n", num, fac_r);
    } else {
        printf("Error found when calculating the factorial of %d. Please make sure that you passed a natural number.\n",
               num);
    }

    /* 1.3 - Fibonacci */
    // Iterative version
    int fib_i = fibonacci_i(num);
    // We know that in this case the number will be valid, so the condition of this 'if' should always be true.
    if (fib_i >= 0) {
        printf("FibI(%d) = %d\n", num, fib_i);
    } else {
        printf("Error found when calculating the Fibonacci number of %d. Please make sure that you passed a natural number.\n",
               num);
    }
    // Recursive version
    int fib_r = fibonacci_r(num);
    if (fib_r >= 0) {
        printf("FibR(%d) = %d\n", num, fib_r);
    } else {
        printf("Error found when calculating the Fibonacci number of %d. Please make sure that you passed a natural number.\n",
               num);
    }

    /* 1.4 - Is prime? */
    printf("%d is ", num);
    if (!is_prime(num)) printf("not ");
    printf("a prime number.\n");

    /* 1.5 - Is sum of primes? */
    int prime1;
    int prime2;
    bool is_sum_primes = get_sum_primes(num, &prime1, &prime2);
    if (is_sum_primes) {
        printf("%d = %d+%d\n", num, prime1, prime2);
    } else {
        printf("%d is not the sum of two prime numbers.\n", num);
    }

}




