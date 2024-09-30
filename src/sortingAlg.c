#include "sortingAlg.h"

/*Bubble sort alghorithm
    Best-case performance O(n^2) or O(n) if the list is already sorted.
    Average-case performance O(n^2)
    Worst-case performance O(n^2)
 */
void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if(arr[j] > arr[j + 1])
            {
                // It checks if the element on the right is bigger than the element on the left and if yes it swaps those.
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*Selection sort alghorithm
    Best-case performance O(n^2) or O(n) if the list is already sorted.
    Average-case performance O(n^2)
    Worst-case performance O(n^2)
 */
void selectionSort(int *arr, int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        int minIndex = i;

        // Find the minimun element in the unsorted portion of the array
        for (int j = i + 1; j < count; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j; // Update the index of the smallest element
            }
        }

        // Swap the found minimum element with the first unsorted element
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        } 
    }
}

/*Insertion sort alghorithm
    Best-case performance  O(n) if the list is already sorted.
    Average-case performance O(n^2)
    Worst-case performance O(n^2)
 */
void insertionSort(int *arr, int count) 
{
    for(int i = 1; i < count; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*Merge sort
    Best-case performance  O(n log n) if the list is already sorted.
    Average-case performance O(n log n)
    Worst-case performance O(n log n) if the array is in reverse order.
*/
void merge(int *arr, int l, int m, int r)
{
    int n1 = m - l + 1; // Size of the left sub-array.
    int n2 = r - m; // Size of the right sub-array.

    // Create temp arrays.
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    // Copy the data to the temp arrays L and R
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[m + 1 + i];
    }

    //Merge the temporary arrays back into arr[]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any remains.
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any remains.
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    //Free memeory.
    free(L);
    free(R);
}
//Merge sort function.
void mergeSort(int *arr, int l, int r)
{
    if(l < r)
    {
        int middlePoint = (l + r) / 2;

        // Recursively sort first and secound halves.
        mergeSort(arr, l, middlePoint);
        mergeSort(arr, middlePoint + 1, r);

        //Merge the sorted halves.
        merge(arr, l, middlePoint, r); 
    }
}

/*Quick sort
    Best-case performance  O(n log n) if the list is already sorted.
    Average-case performance O(n log n)
    Worst-case performance O(n^2)
*/
// Partition function for quicksort
int partition(int *arr, int low, int high)
{
    int pivot = arr[high]; // Chose pivot as the last element.
    int i = (low - 1); // Index of the smallest element.

    for (int j = low; j < high; j++)
    {
        // Case if the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot)
        {
            i++; //Increment the index of the smaller element.
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap the pivot element with the element at index (i + 1).
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // Return the partition index
    return (i + 1);
}
// Quick sort function.
void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        // Partition the array
        int part = partition(arr, low, high);

        // Recursive sort the subarrays.
        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
} 