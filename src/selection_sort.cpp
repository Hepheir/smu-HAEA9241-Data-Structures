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

int select_min(int s, int e, int arr[]) {
    int min_idx = s;
    for (int i = s; i <= e; i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

void selection_sort(int n, int arr[]) {
    int min_idx;
    for (int i = 0; i < n-1; i++) {
        min_idx = select_min(i, n-1, arr);
        swap(&arr[i], &arr[min_idx]);
    }
}

void print_array(int n, int arr[]);

int main()
{
    printf("%16s ", "before sort:");
    print_array(count, array);

    selection_sort(count, array);

    printf("%16s ", "after sort:");
    print_array(count, array);
    printf("-> total %d moves.\n", move_count);
}

void print_array(int n, int arr[]) {
    for (int i = 0; i < n; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}
