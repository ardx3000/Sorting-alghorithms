#include <stdio.h>
#include "utils.h"
#include "sortFile.h"

int main()
{
    int option;
    const char *filename = "numbers.txt";


    printf("Please select one of the follwoing options: \n");
    printf("1. Create a file with random numbers.\n");
    printf("2. Sort the file using bubblesort\n");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        createTextFile(filename);
        break;
    case 2:
        sortFile(filename, 1);
        break;
    }
    


   printf("Ending program");

    
    return 0;
}