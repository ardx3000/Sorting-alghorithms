#include <stdio.h>
#include "utils.h"
#include "sortFile.h"

int main()
{
    int option;
    const char *filename = "numbers.txt";


    printf("Please select one of the follwoing options: \n");
    printf("1. Create a file with random numbers.\n");
    printf("2. Sort the file using bubble sort\n");
    printf("3. Sort the file using selection sort\n");
    printf("4. Sort the file using Insertion sort\n");
    printf("5. Sort the file using Merge sort\n");
    printf("6. Sort the file using Quick sort\n");
    scanf("%d", &option);
    switch (option)
    {
        case 1:
            createTextFile(filename);
            break;
        case 2:
            sortFile(filename, 1);
            break;
        case 3:
            sortFile(filename, 2);
            break;
        case 4: 
            sortFile(filename, 3);
            break;
        case 5:
            sortFile(filename, 4);
            break;
        case 6:
            sortFile(filename, 5);
            break;
    }
    


   printf("Ending program");

    
    return 0;
}