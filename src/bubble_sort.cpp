#include <cstdio>

int array[5] = {82, 61, 5, 30, 74};
int count = 5;

int move_count = 0;

void swap(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
    move_count++;
}

void bubble_sort(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i; j--) {
            if (arr[j-1] > arr[j]) {
                swap(&arr[j-1], &arr[j]);
            }
        }
    }
}

void print_array(int n, int arr[]);

int main()
{
    printf("%16s ", "before sort:");
    print_array(count, array);

    bubble_sort(count, array);

    printf("%16s ", "after sort:");
    print_array(count, array);
    printf("-> total %d moves.\n", move_count);
}

void print_array(int n, int arr[]) {
    for (int i = 0; i < n; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}
