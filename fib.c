#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long fib_iterative(int n) {
   int i;
   unsigned long next;
   unsigned long num1 = 0;
   unsigned long num2 = 1;
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

unsigned long fib_recursive(int n) {
   if (n == 0 || n == 1) {
      return 0;
   }
   return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main(int argc, char* argv[]) {
	FILE* file_ptr;

   file_ptr = fopen(argv[3], "r");

   if (file_ptr == NULL) {
      exit(0);
   }
   else {
      int file_num;
      fscanf(file_ptr, "%d", &file_num);

      int nth = file_num + atoi(argv[1]);

      if (strcmp(argv[2], "-i") || strcmp(argv[2], "i")) {
         printf("%lu", fib_iterative(nth));
      }
      else if (strcmp(argv[2], "-r") || strcmp(argv[2], "r")) {
         printf("%lu", fib_recursive(nth));
      }
      else {
         printf("Invalid argument.");
      }
   }

	return 0;
}

