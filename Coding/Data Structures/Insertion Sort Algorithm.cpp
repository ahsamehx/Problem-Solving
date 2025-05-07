#include<iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i <n; i++)
    {
        key = arr[i];
        j = i -1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){

    int array[6] = {5, 2 , 9 , 8, 7, 7};
    int size = sizeof(array)/sizeof(array[0]);
    InsertionSort(array,size);
    for(auto n: array)
    {
        cout << n << endl;
    }
}