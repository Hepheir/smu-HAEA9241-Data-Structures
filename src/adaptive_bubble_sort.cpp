#include <cstdio>

#define ARRAY_SIZE 5

int array[ARRAY_SIZE] = {1, 2, 3, 5, 4};
int count = ARRAY_SIZE;

void print_array(int n, int arr[])
{
    for (int i = 0; i < n; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}

void swap(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

void adaptive_bubble_sort(int n, int arr[])
{
    int i;
    int swapped;

    do {
        swapped = 0;
        for (i = 1; i < n; i++) {
            if (arr[i-1] > arr[i]) {
                swap(&arr[i-1], &arr[i]);
                swapped = 1;
            }
        }
        print_array(n, arr);
    } while (swapped == 1);
}

int main()
{
    adaptive_bubble_sort(count, array);
}
