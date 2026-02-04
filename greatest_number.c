#include <stdio.h>

// O(N)
int greatest_number(int *a, int len) {
  int index = 0;
  int compare = 1;
  for (int i = 0; i < len; i++) {
    if (compare  == len - 1) {
      return a[index];
    }
    if (a[index] > a[compare]) {
      compare++;
    } else if (a[index] <= a[compare]) {
      index = compare;
      compare = index + 1;
    }
  }
  return a[index];
}

int main (void) {
  int a[10] = {40,20,54,423,420,571,1,3,6,83};
  printf("the greatest number is %d.\n", greatest_number(a,10));

}
