void printArray(char strings[100][51],int *arrayLength,int *maxStringLength)
{
    if (*arrayLength == 0)
        printf("No Items To Print!\n");
    else
    {
         /*
        *   defined currentLetter so it contains the first letter of the list and print it, then while currentLetter is the first
        *   letter of the next words print them , when the current letter doesn't match the first character of the following word
        *   it prints the new character and makes it the current letter and keeps printing names starting with the new character
        *   until it has changed again
        */
       char currentLetter = strings[0][0];
       int i=0;
       printf("   ********%c*********\n",toUpperCase(currentLetter));
       while (i<*arrayLength){
        if (toUpperCase(currentLetter) == toUpperCase(strings[i][0])){
            printf("      ");
            puts(strings[i++]);
        }



        else{
            currentLetter = toUpperCase(strings[i][0]);
            printf("   ********%c*********\n",toUpperCase(currentLetter));
        }
       }
    }
}
