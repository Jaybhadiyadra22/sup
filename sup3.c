#include <stdio.h>
#include <stdlib.h>


void readFile(FILE * fPtr);
int main()
{
    FILE *fPtr;
    char filePath[100];

    char dataToAppend[5000];


    printf("Enter file path: ");
    scanf("%s", filePath);

    fPtr = fopen(filePath, "a");

    if (fPtr == NULL)
    {
        printf("\nUnable to open '%s' file.\n", filePath);
        printf("Please check whether file exists and you have write privilege.\n");
        exit(EXIT_FAILURE);
    }
    printf("\nEnter data to append: ");
    fflush(stdin); 
    fgets(dataToAppend, 5000, stdin);

    fputs(dataToAppend, fPtr);
    fPtr = freopen(filePath, "r", fPtr);
    printf("\nSuccessfully appended data to file. \n");
    printf("Changed file contents:\n\n");
    readFile(fPtr);
    fclose(fPtr);
 
}
void readFile(FILE * fPtr)
{
    char ch;
    do 
    {
        ch = fgetc(fPtr);
        putchar(ch);
    } while (ch != EOF);
}
