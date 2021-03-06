/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define COLUMNS 6
int columnEnd;

void print_number(int n) {
    if(columnEnd == 1)
    {
        printf("%10d ", n);
        printf("\n");
        columnEnd = COLUMNS;
        return;
    } else {
        printf("%10d ", n);
        columnEnd --;
    }
}

/* Print all prime numbers less than or equal to n using the Sieve of
  Eratosthenes algorithm. */
void print_sieves(int n, int *primes) {
  columnEnd = COLUMNS;
  memset(primes, 0, n*sizeof(int));
  for (int i = 2; i <= sqrt(n); i++) {
    if (!primes[i-1]) {
      for (int j = i*i; j <= n; j += i) {
        primes[j-1] = 1;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    if (!primes[i-1]) {
      print_number(i);
    }
  }
  printf("\n");
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){

  if(argc == 2) {
    int *numbers = malloc(atoi(argv[1])*sizeof(int));
    print_sieves(atoi(argv[1]), numbers);
    free(numbers);
  }
  else
    printf("Please state an integer number.\n");
  return 0;

}
