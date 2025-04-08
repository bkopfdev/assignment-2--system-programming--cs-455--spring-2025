#include <stdio.h>

#define INPUT_ARRAY_SIZE 10

void printArray(int const *, size_t);
void bubbleSort(int[], int (*sortingMethod)(int *, int *), size_t);
int ascending(int * const a, int * const b);
int descending(int * const a, int * const b);
void swap(int * const a, int * const b);

int main() {
  int a[INPUT_ARRAY_SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
  int userRequestedMethod; // 1 indicates ascending, 2 for descending

  printf("Welcome to the Bubble Sorting program!\n");
  printf("Please input the number corresponding to your preferred sorting method:\n1) Ascending\n2) Descending\n");
  scanf("%d", &userRequestedMethod);

  if(userRequestedMethod != 1 && userRequestedMethod != 2) {
    printf("Invalid input. Please try again.\n");

    return 1;
  }

  printf("\nYou have selected %s sorting.\n", userRequestedMethod == 1 ? "ASCENDING" : "DESCENDING");

  printf("Array items in original order:\n");
  printArray(a, INPUT_ARRAY_SIZE); // print the array using the function pointer

  if(userRequestedMethod == 1) {
    bubbleSort(a, &ascending, INPUT_ARRAY_SIZE); //if 1, pass ascending function address
  } else {
    bubbleSort(a, &descending, INPUT_ARRAY_SIZE); //if 2, pass descending function address
  }

  printf("\n\nArray items in sorted order:\n");
  printArray(a, INPUT_ARRAY_SIZE); // print the array using the function pointer

  putchar('\n');

  return 0;
}

/**
 * printArray()
 * Prints the contents of an array of integers
 *
 * @array: pointer to the array of integers to be printed
 * @arraySize: size of the array to be printed
 */
void printArray(int const * array, size_t arraySize) {
  for(size_t i = 0; i < arraySize; i++) {
    printf("%d ", array[i]);
  }
  putchar('\n');
}

/**
 * ascending()
 * Compares two integers by >

 * @a: pointer to the first integer
 * @b: pointer to the second integer
 * @return: 1 if a is greater than b, 0 otherwise
 */
int ascending(int * a, int * b) {
  return *a > *b;
}

/**
 * descending()
 * Compares two integers by <
 *
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 * @return: 1 if a is less than b, 0 otherwise
 */
int descending(int * a, int * b) {
  return *a < *b;
}

/**
 * swap()
 * Swaps two integers by reference
 *
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap (int * a, int * b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/**
 * bubbleSort()
 * sorts an array of integers using the bubble sort algorithm, in the order dictated by the function pointer
 *
 * @array: pointer to the array of integers to be sorted
 * @param sortingMethodPtr: pointer to the sorting method function (ascending or descending)
 * @param arraySize: size of the array to be sorted
 */
void bubbleSort(int array[], int (*sortingMethodPtr)(int *, int *), size_t arraySize) {
  for(int pass = 0; pass < arraySize - 1; pass++) {

    for(size_t j = 0; j < arraySize - 1; j++) {

      if(sortingMethodPtr(&array[j], &array[j + 1]) > 0) {
        swap(&array[j], &array[j + 1]);
      }
    }
  }
}
