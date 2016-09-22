
#include <stdio.h>
#include <stdlib.h>

char* text1 = "This is a string.";
char* text2 = "Yet another thing.";
int *list1;
int *list2;
int count;


void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

/* Takes a pointer to a char, and a pointer to a memory space allocated
  to holding a copy of the string, as well as a pointer to a count
  variable for counting the amount of characters copied. */
void copycodes(char *text, int *list, int *count) {
  while (*text != 0) {
    *list = (int)*text;
    text++;
    list++;
    *count = *count + 1;
  }
}

// Call copycodes to copy text1 to the memory space of list1,
// and text2 to list2
void work() {
  copycodes(text1, list1, &count);
  copycodes(text2, list2, &count);
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n",
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));

}

int main(void){
  count = 0;
  list1 = malloc(80);
  list2 = malloc(80);
  work();

  printf("\nlist1: ");
  printlist(list1);
  printf("\nlist2: ");
  printlist(list2);
  printf("\nCount = %d\n", count);

  endian_proof((char*) &count);
  free(list1);
  free(list2);
}
