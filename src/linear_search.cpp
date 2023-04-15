#include <iostream>

typedef int indext;
typedef int elt;

elt array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int count = 9;

indext linear_search(elt x)
{
    for (int i = 0; i < count; i++)
    {
        if (array[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    std::cout << "        array: ";
    for (int i = 0; i < count; i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "linear search: ";
    for (int i = 0; i < count; i++) {
        std::cout << linear_search(array[i]) << ' ';
    }
    std::cout << std::endl;
    return 0;
}