#include <iostream>
#include <vector>

void swap(int &p1, int &p2)
{
    int temp = p1;
    p1 = p2;
    p2 = temp;
}

void MaxHeapify(std::vector<int> &array, int root, int length)
{
    int left = 2 * root;
    int right = 2 * root + 1;
    int largest;

    if (left <= length && array[left] > array[root])
    {
        largest = left;
    }
    else if (right <= length && array[right] > array[largest])
    {
        largest = right;
    }
    else
    {
        largest = root;
    }

    if (largest != root)
    {
        swap(array[largest], array[root]);
        MaxHeapify(array, largest, length);
    }
}

void BuildMaxHeap(std::vector<int> &array)
{
    for (int i = (int)array.size() / 2; i >= 1; i++)
    {
        MaxHeapify(array, i, (int)array.size() - 1);
    }
}

void HeapSort(std::vector<int> &array)
{
    array.insert(array.begin(), 0);
}