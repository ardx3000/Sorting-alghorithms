#include "sortFile.h"


void sortFile(const char *filename, int sortType)
{
    // Open the file for reading 
    FILE *file = fopen(filename, "r");
    
    clock_t start;
    clock_t end;
    double time_taken;

    // Check if the file was open
    if (file == NULL)
    {
        perror("Error opening the file!");
        return;
    }

    // Read the numbers from the file
    int *arr = NULL;
    int count = 0, capacity = 100;
    arr = malloc(capacity * sizeof(int));

    while(fscanf(file, "%d, ", &arr[count]) == 1)
    {
        count++;
        // Resize the array in case
        if(count >= capacity)
        {
            capacity *= 2;
            arr = realloc(arr, capacity * sizeof(int));
        }
    }
    // Add a timere here after reading

    // Close the file after reading
    fclose(file);
    switch(sortType)
    {
        case 1:
            start = clock();
            bubbleSort(arr, count);
            end = clock();
            time_taken = (double)(end - start) / CLOCKS_PER_SEC;
            printf("BubbleSort of 100000 took: %.6f seconds\n", time_taken);
            break;
            case 2:
                start = clock();
                selectionSort(arr, count);
                end = clock();
                time_taken = (double)(end - start) / CLOCKS_PER_SEC;
                printf("SelectionSort of 100000 took: %.6f seconds\n", time_taken);
                break;
            case 3:
                start = clock();
                insertionSort(arr, count);
                end = clock();
                time_taken = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Insertion sort of 100000 took: %.6f seconds\n", time_taken);
                break;
            case 4:
                start = clock();
                mergeSort(arr, 0, count - 1);
                end = clock();
                time_taken = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Merge sort of 100000 took: %.6f seconds\n", time_taken);
                break;
            case 5:
                start = clock();
                quickSort(arr, 0, count -1);
                end = clock();
                time_taken = (double)(end - start) / CLOCKS_PER_SEC;
                printf("QuickSort of %d elements took: %.6f seconds\n", count, time_taken);
                break;
            default:
                printf("Invalid sort type!\n");
                free(arr);
                return;
    }

    // Open the file for writing (overwrite the file)
    file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening the file !");
        exit(EXIT_FAILURE);
    }

    // Write sorted numbers back to the file
    for (int i = 0; i < count; i++)
    {
        if(i < count - 1) 
        {
            fprintf(file, "%d, ", arr[i]);  
        }
        else 
        {
            fprintf(file, "%d", arr[i]);
        }
    }
    // Add a timer for writing.

    // Close the file. 
    fclose(file);
    //Free the array memory
    free(arr);
    
    printf("File '%s' is sorted !\n", filename);

}