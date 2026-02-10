#include <stdio.h>

// O(N^2 / 2)
int selection_sort(int *a, int len) {
  for (int i = 0; i < len - 1; i++) {
    int index = i;

    for (int j = index + 1; j < len; j++) {
      if (a[j] < a[index]) {
        index = j;
      }
    }
    if (index != i) {
      int lowest = a[i];
      a[i] = a[index];
      a[index] = lowest;
    }

  }
}

int main(void) {
  int a[10] = {14,45,6,53,754,12,43,65,43,23};

  selection_sort(a,10);

  printf("Selection sorted array:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d\n",a[i]);
  }
}
