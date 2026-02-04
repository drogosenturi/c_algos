#include <stdio.h>

// O(N^2)
void bubble_sort(int *a, int len) {
  int sorted = 0; // false
  int last_ind = len; // mark last index of array
  while (sorted == 0) {
    sorted = 1;
    for (int i = 0; i < len; i++) {
      if (a[i] > a[i + 1]) {
        int first = a[i];
        int second = a[i + 1];
        a[i] = second;
        a[i + 1] = first;

        sorted = 0;
      }
    }

    last_ind--;
  }
}

int main(void) {
  int a[10] = {30,24,1,6,50,23,14,35,6,101};

  printf("pre-sort:\n");
  for (int i; i < 10; i++) {
    printf("%d\n", a[i]);
  }

  bubble_sort(a, 10);

  printf("post-sort:\n");
  for (int i; i < 10; i++) {
    printf("%d\n", a[i]);
  }

}
