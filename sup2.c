#include <stdio.h>
#include <stdlib.h>


int main()
{
    char data[5000];

    FILE * fPtr;

    fPtr = fopen("sup2.txt", "r");

    if(fPtr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter contents to store in file : \n");
    fgets(data, 5000, stdin);

    fputs("jay bhadiyadra", fPtr);

    fclose(fPtr);

    printf("File created and saved successfully. :) \n");

}

