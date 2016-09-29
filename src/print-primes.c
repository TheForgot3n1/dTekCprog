/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6
int columnEnd;
/*
void print_primes(int n){
    int[n-1] A;
    int current = n-1;
    int arrayCounter = 0;
    while(current > 1)
    {
        if(isPrime(current))
        {
            A[arrayCounter] = current
            arrayCounter ++
        }
        current --
    }
    return;
}*/

int is_prime(int n){
    int num = n-1;
    while(num > 1)
    {
        if (n % num  == 0) {
            return 0;
        }
        else {
            num = num-1;
        }
    }
    return 1;
}

void print_number(int n) {
    if(columnEnd == 1)
    {
        printf("%10d ", n);
        printf("\n");
        columnEnd = COLUMNS;
        return;
    }
    printf("%10d", n);
    columnEnd --;

}

void print_primes(int n) {
    columnEnd = COLUMNS;
    int current = 2;
    while(current <= n)
    {
      if(is_prime(current)) {
        print_number(current);
      }
      current ++;
    }
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2) {
    print_primes(atoi(argv[1]));
    printf("\n");
  } else
    printf("Please state an integer number.\n");
  return 0;
}
