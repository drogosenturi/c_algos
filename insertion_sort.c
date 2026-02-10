#include <stdio.h>

void insertion_sort(int *a, int len) {
  for (int i = 1; i < len; i++) {
    int temp = a[i];
    int position = i - 1;

    while (position >= 0) {
      if (temp < a[position]) {
        a[position + 1] = a[position];
        position -= 1;
      } else {
        break; // otherwise it will keep going down
      }
    }
    a[position + 1] = temp;
  }

}

int main(void) {
  int a[10] = {123,128,261,1,65,381,3,64,50,21};

  insertion_sort(a, 10);

  printf("sorted array:\n");

  for (int i = 0; i < 10; i++){
    printf("%d\n",a[i]);
  }

}
