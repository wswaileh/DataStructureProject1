#include <stdio.h>


void writeDataToFileMenu(char strings[100][51],int *arrayLength,int *maxStringLength)
{
    //used the same technique in print array to screen
    if (*arrayLength == 0)
        printf("No Items Found!\n");
    else
    {
        char fileName[21];
        printf("What's The Name Of The File You Want To Save Data To ? \n");
        scanf("%s",fileName);
        FILE *out;
        out = fopen(fileName,"w");

        char currentLetter = strings[0][0];
        int i=0;
        fprintf(out,"%c:\n",toUpperCase(currentLetter));
        while (i<*arrayLength)
        {
            if (toUpperCase(currentLetter) == toUpperCase(strings[i][0]))
            {
                fputs(strings[i++],out);
                fputs("\n",out);
            }

            else
            {
                currentLetter = toUpperCase(strings[i][0]);
                fprintf(out,"%c:\n",toUpperCase(currentLetter));
            }
        }


        fclose(out);
        printf("Names Were Written To File \"%s\" Successfully!\n",fileName);
    }
}
