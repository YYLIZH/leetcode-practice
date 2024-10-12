#include <iostream>
#include <vector>

const int Max = 1000;

void PrintArray(std::vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void Merge(std::vector<int> &Array, int front, int mid, int end)
{
    std::vector<int> LeftSub(Array.begin() + front, Array.begin() + mid + 1);
    std::vector<int> RightSub(Array.begin() + mid + 1, Array.begin() + end + 1);

    LeftSub.insert(LeftSub.end(), Max);
    RightSub.insert(RightSub.end(), Max);

    int idxLeft = 0, idxRight = 0;

    for (int i = front; i <= end; i++)
    {
        if (LeftSub[idxLeft] <= RightSub[idxRight])
        {
            Array[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else
        {
            Array[i] = RightSub[idxRight];
            idxRight++;
        }
    }
}

void MergeSort(std::vector<int> &array, int front, int end)
{
    if (front < end)
    {
        int mid = (front + end) / 2;
        MergeSort(array, front, mid);
        MergeSort(array, mid + 1, end);
        Merge(array, front, mid, end);
    }
}

int main()
{
    int arr[] = {5, 3, 8, 6, 2, 7, 1, 4};
    std::vector<int> array(arr, arr + sizeof(arr) / sizeof(int));

    std::cout << "original:\n";
    PrintArray(array);

    MergeSort(array, 0, 7);
    std::cout << "sorted:\n";
    PrintArray(array);

    return 0;
}