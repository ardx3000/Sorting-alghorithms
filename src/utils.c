#include "utils.h"

void generateRandomNumbers(FILE *file, int maxCount)
{
    int count = 0;

    while (count < maxCount)
    {
        int randomNumber = rand() % 10000;
        if(count < maxCount - 1) 
        {
            fprintf(file, "%d, ", randomNumber);  
        }
        else 
        {
            fprintf(file, "%d", randomNumber);
        }
        count++;
    }
}

//Create a file to store the numbers
void createTextFile(const char *filename)
{

    //Open the file for writing (creates or overwrites a file)
    FILE *file = fopen(filename, "w");
    

    //Check if the file was open
    if (file == NULL)
    {
        perror("Error creating the file!");
        return;
    }

    //Seed for the random number generator.
    srand(time(NULL));
    
    //How many numbers are added in the text file.
    int maxCount = 100000;

    //Call the function that will add the numbers
    generateRandomNumbers(file, maxCount);

    //Close the file

    fclose(file);

    printf("File '%s' has been successfully create!\n,", filename);

}