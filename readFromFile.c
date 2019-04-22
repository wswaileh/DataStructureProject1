#include <stdio.h>
void readFromFileMenu(char strings[100][51],int *maxStringLength,int *arrayLength)
{
    int status,i=*arrayLength;
    char fileName[21],line[51];
    printf("Enter The Name Of The File You Want To Read From Followed by \".txt\": ");
    scanf("%s",fileName);
    FILE *in = fopen(fileName,"r");
    /**
     *  asked the user to enter the name if the file he wanted to read from , then trimmed '\n' from each string I read
     *  and checked the maxStringLength while reading each line , and added items to the array and increased array length
     */
    if (in)
    {
        while (fgets(line,50,in)!=NULL)
        {
            trimNewLineSymbol(line);
            if (strLen(line)>*maxStringLength)
                *maxStringLength = strLen(line);
            strcopy(line,strings[i++]);
        }
        *arrayLength = i;
        fclose(in);
        printf("File Read Success!\n");
    }

    else
        printf("File Not Found!\n");


}
