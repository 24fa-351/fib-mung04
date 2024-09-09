#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fib_iterative(int n) {
   int i;
   int next;
   int num1 = 0;
   int num2 = 1;
   if (n <= 1) {
      return 0;
   }
   for (i = 2; i < n; i++) {
      next = num1 + num2;
      num1 = num2;
      num2 = next;
   }
   return num2;
}

int fib_recursive(int n) {
   if (n == 0 || n == 1) {
      return n;
   }
   return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main(int argc, char* argv[]) {
	FILE* fptr;

   fptr = fopen(argv[3], "r");

   if (fptr == NULL) {
      printf("File not opened.");
      exit(0);
   }
   else {
      int file_num;
      fscanf(fptr, "%d", &file_num);

      int nth = file_num + atoi(argv[1]);

      if (strcmp(argv[2], "-i")) {
         printf("%d", fib_iterative(nth));
      }
      else if (strcmp(argv[2], "-r")) {
         printf("%d", fib_recursive(nth - 1));
      }
      else {
         printf("Invalid argument.");
      }
   }

	return 0;
}

