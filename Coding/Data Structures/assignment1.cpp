#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// Implement a program that reads input from a file, sorts each array in the file using
// three different algorithms (Selection, Shell, and Merge Sort), and calculates the
// number of moves and comparisons performed by each algorithm.

using namespace std;

template <class T>
void linearinsertionSort(T data[], int n) {
    cout<<"insertion with linear search\n";
    int shifts = 0; // Counter for shifts
    int comparisons = 0; // Counter for comparisons

    for (int i = 1, j; i < n; i++) {
        comparisons++;
        T tmp = data[i]; // Store current element
        // Shift larger elements to the right
        for (j = i; j > 0 && tmp < data[j - 1]; j--) {
            data[j] = data[j - 1];
            shifts++; // Increment shift counter
            comparisons++; // Increment comparison counter
        }
        // Put the current element in its right place
        data[j] = tmp;
        //shifts++;

    }

    cout << "Total shifts: " << shifts <<endl;
    cout << "Total comparisons: " << comparisons <<endl;
}
template <class M>
void BinarySearchInsertionSort(M data[], int n) {
    cout << "Insertion with binary search (unsorted array)\n";
    int shifts = 0; // Counter for shifts
    int comparisons = 0; // Counter for comparisons

    for (int i = 1; i < n; i++) {
        M tmp = data[i]; // Store current element

        // Perform binary search to find the correct position
        int left = 0;
        int right = i - 1;
        int insertionIndex = i; // Default insertion index is the current position

        while (left <= right) {
            int mid = left + (right - left) / 2;
            comparisons++;

            if (data[mid] < tmp) {
                left = mid + 1;
            } else {
                insertionIndex = mid; // Update insertion index
                right = mid - 1;
            }
        }

        // Shift elements to the right
        for (int j = i - 1; j >= insertionIndex; j--) {
            data[j + 1] = data[j];
            shifts++;
        }

        // Put the current element in its right place
        data[insertionIndex] = tmp;
        shifts++;
    }

    cout << "Total shifts: " << shifts << endl;
    cout << "Total comparisons: " << comparisons << endl;
}


template <class T>
void selectionSort(T data[], int n)
{

    cout << "Selection Sort" << endl;
    int shifts = 0;      // Counter for shifts
    int comparisons = 0; // Counter for comparisons

    for (int i = 0, j, least; i < n - 1; i++)
    {

        for (j = i + 1, least = i; j < n; j++)
        {
            comparisons++;

            if (data[j] < data[least])
                least = j;
        }

        swap(data[least], data[i]);
        shifts += 3;
    }
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total shifts: " << shifts << endl;
}

template <class T>
void shellsort(T a[], int n)
{
    cout << "Shell Sort" << endl;
    int comparisons = 0;
    int moves = 0;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; ++i)
        {

            T tmp = a[i];
            moves++;
            comparisons++;
            int j = i;
            for (; j >= gap && tmp <= a[j - gap]; j -= gap)
            {
                comparisons++; // Increment comparison counter inside the loop

                a[j] = a[j - gap];
                moves++; // Increment move counter inside the loop
            }

            a[j] = tmp;
            moves++;
        }
    }
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total moves: " << moves << endl;
}

void merge(int arr[], int left, int middle, int right, int &comparisons, int &moves)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
        moves++;
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[middle + 1 + j];
        moves++;
    }

    // Merge the temporary arrays back into arr[left..right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {

        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
            moves++;
        }
        else
        {
            arr[k++] = R[j++];
            moves++;
        }
        comparisons++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k++] = L[i++];
        moves++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k++] = R[j++];
        moves++;
    }
}

void mergeSort(int arr[], int left, int right, int &comparisons, int &moves)
{
    if (left < right)
    {
        // Same as (left + right) / 2, but avoids overflow for large left and right
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle, comparisons, moves);
        mergeSort(arr, middle + 1, right, comparisons, moves);

        // Merge the sorted halves
        merge(arr, left, middle, right, comparisons, moves);
    }
}

// Print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    int size;

    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int arr[size];
    int originalArr[size];

    cout << "Enter the elements of your array: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        originalArr[i] = arr[i]; // Store the original array
    }

    linearinsertionSort(arr, size);

    cout << "Sorted array with linear insertion sort: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Reset the array to its original state
    for (int i = 0; i < size; i++) {
        arr[i] = originalArr[i];
    }

    BinarySearchInsertionSort(arr, size);

    cout << "Sorted array with binary search insertion sort: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << endl << "_________________________Task 2____________________" << endl << endl;

    ifstream inputFile("arrays.txt");

    string line;
    while (getline(inputFile, line))
    {
        istringstream lines(line);
        int num, size, comp = 0, moves = 0;
        bool flag = false;
        vector<int> vec;
        while (lines >> num)
        {
            if (flag == false)
            {
                size = num;
                flag = true;
                continue;
            }
            vec.push_back(num);
        }

        int array0[size];
        int array1[size];
        int array2[size];

        copy(vec.begin(), vec.end(), array0);
        copy(vec.begin(), vec.end(), array1);
        copy(vec.begin(), vec.end(), array2);

        cout << "Original array: ";
        printArray(array0, size);

        selectionSort(array0, size);
        cout << "Sorted array: ";
        printArray(array0, size);

        shellsort(array1, size);
        cout << "Sorted array: ";
        printArray(array1, size);

        mergeSort(array2, 0, size - 1, comp, moves);

        cout << "Merge Sort " << endl;
        cout << "Total comparisons: " << comp << endl;
        cout << "Total moves: " << moves << endl;
        cout << "Sorted array: ";
        printArray(array2, size);
        cout << endl;
    }

    inputFile.close();
    return 0;
}