#include <iostream>

typedef int indext;
typedef int elt;

elt array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int count = 9;

indext binary_search(indext s, indext e, elt x)
{
    if (s == e)
    {
        if (array[s] == x)
        {
            return s;
        }
        return -1;
    }
    int mid = (s + e) / 2;
    if (array[mid] == x)
    {
        return mid;
    }
    if (array[mid] > x)
    {
        return binary_search(s, mid - 1, x);
    }
    else
    {
        return binary_search(mid + 1, e, x);
    }
}

int main()
{
    std::cout << "                    array: ";
    for (int i = 0; i < count; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "(recursive) binary search: ";
    for (int i = 0; i < count; i++)
    {
        std::cout << binary_search(0, count - 1, array[i]) << ' ';
    }
    std::cout << std::endl;
    return 0;
}