#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n)
{
    int minIndex;
    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main()
{
    int arr[6] = {5, 3, 6, 9, 0, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, size);
    for (auto num : arr)
    {
        cout << num << endl;
    }
}