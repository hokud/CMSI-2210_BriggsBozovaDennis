#include <stdio.h>

int main(void) {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
    
  printf("Your number %d in binary is ", n);

  for (int i = 31; i >= 0; i--) {
      int bit = (n >> i) & 1;   // isolate bit i
      printf("%d", bit);
  }

  printf("\n");
  return 0;
}

