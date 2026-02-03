// can do a binary search of an ordered array, much faster than linear search
#include <stdio.h>

int binary_search(int *array, int val, int len) {
  int lower = 0;
  int upper = len - 1;
  while (lower <= upper) {
    int midpoint = (upper + lower) / 2;
    printf("midpoint: %d\n", midpoint);

    if (val == array[midpoint]) {
      return midpoint; // index of array
    } else if (val < array[midpoint]) {
      upper = midpoint - 1;
    } else {
      lower = midpoint + 1;
    }
  }
  return 0; // no matches
}


int main(void) {
  int a[13] = {1,4,5,6,7,10,16,20,50,75,98,101,205};
  int *p; // initialize pointer
  p = a; // should point to the first value in a

  printf("result is %d\n", binary_search(a, 10, 13));


}
