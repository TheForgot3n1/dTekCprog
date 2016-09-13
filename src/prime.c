/*
 prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/


#include <stdio.h>

int is_prime(int n){
    int num = n-1;
    printf("%d\n", n);
    while(num > 1)
    {
        //printf("This be n : %d\n", n);
        if (n % num  == 0) {
            //printf("a = %d , n = %d", num,n);
            return 0;
        }
        else {
            num = num-1;
        }
        //printf("This be the if statement : %d\n", (n % (a-1) ));
    }
    return 1;
}

int main(void){
  printf("%d\n", is_prime(11));  // 11 is a prime.      Should print 1.
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
}
