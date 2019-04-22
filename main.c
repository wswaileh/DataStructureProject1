// Project#1 Version #3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myString.h"
#include "addItemToArray.h"
#include "readFromFile.h"
#include "writeDataToFile.h"
#include "deleteItem.h"
#include "radixSort.h"

void showMenu();

int main()
{

    //the main array we will deal with
    char strings[100][51];
    //to show the user the choices
    showMenu();
    //choice is where user's choice is saved , maxStringLength is the length of the longest string , array length is how many names added
    int choice,maxStringLength=0,arrayLength=0;
    scanf("%d",&choice);

    while (choice != 11)
    {
        switch(choice)
        {
        case 1:
            readFromFileMenu(strings,&maxStringLength,&arrayLength);
            break;
        case 2:
            addItemToArrayMenu(strings,&maxStringLength,&arrayLength);
            break;
        case 3:
            deleteItemMenu(strings,&arrayLength);
            break;
        case 4:
            radixSort(strings,&arrayLength,&maxStringLength);
            printf("Names Sorted Successfully!\n");
            break;
        case 5:
            writeDataToFileMenu(strings,&arrayLength,&maxStringLength);
            break;
        case 6:
            printArray(strings,&arrayLength,&maxStringLength);
            break;
        case 7:
            system("cls");
            break;
        case 8:
            EmptyArray(strings,&arrayLength,&maxStringLength);
            break;
        case 9:
            searchForNameMenu(strings,&arrayLength);
            break;
        case 10:
            printNamesStartWithCharacterMenu(strings,&arrayLength);
            break;
        }
        radixSort(strings,&arrayLength,&maxStringLength);
        showMenu();
        scanf("%d",&choice);
    }
    printf("GoodBye :)\n");
    return 0;
}


void showMenu()
{
    printf(" _______________________________________________________\n");
    printf("| Enter The Number Of Operation You Want To Do Please : |\n");
    printf("|     1.Read Data From File.                            |\n");
    printf("|     2.Add New Item.                                   |\n");
    printf("|     3.Delete Item.                                    |\n");
    printf("|     4.Radix Sort.                                     |\n");
    printf("|     5.Write Data To File.                             |\n");
    printf("|     6.Write Data To Screen.                           |\n");
    printf("|     7.Clear Console.                                  |\n");
    printf("|     8.Clear Previous Data.                            |\n");
    printf("|     9.Search For A Name.                              |\n");
    printf("|    10.Print All Names That Start With A Character.    |\n");
    printf("|    11.Exit                                            |\n");
    printf("|_______________________________________________________|\n");
    printf("# Of Operation : ");

}

void EmptyArray(char strings[100][51],int *arrayLength,int *maxStringLength)
{
    *arrayLength = 0;
    *maxStringLength = 0;
    printf("Items Deleted Successfully!\n");
}

void searchForNameMenu(char strings[100][51],int *arrayLength)
{
    char name[51];
    if (*arrayLength <0)
        printf("List Is Empty!\n");
    else
    {
        printf("Enter The Name You Want To Find Please :\n");
        getchar();
        gets(name);
        int i,flag=0; //flag = 0 means name not found;
        for (i=0; i<*arrayLength; i++)
            if (strEq(name,strings[i]))  //if found flag = 1;
            {
                flag=1;
                break;
            }
        if (flag)
            printf("Name \"%s\" Found Successfully! And It's Index Is : %d\n",name,i);
        else
            printf("Name \"%s\" Was Not Found!\n",name);
    }
}

void printNamesStartWithCharacterMenu(char strings[100][51],int *arrayLength)
{
    if (*arrayLength <0)
        printf("List Is Empty!\n");
    else
    {
        char c;
        int i=0,flag=0,isCharacterPrinted=0; //flag = 0 means that no names found start with the letter the user had chosen
        printf("Enter The Character You Want To Print The Names Starting With Please :\n");
        getchar();
        scanf("%c",&c);
        while (i<*arrayLength)
            if (toUpperCase(c) == toUpperCase(strings[i++][0]))
            {
                if (!isCharacterPrinted) // to print the character before the names if names starting with it were found
                {
                    printf("   ********%c*********\n",toUpperCase(c));
                    isCharacterPrinted = 1;
                }
                printf("      ");
                puts(strings[i-1]);
                flag = 1; //to make sure that names starting with the letter the user entered were in the list
            }
        if (flag == 0) //notify the user if no names starting with the letter the he/she entered were in the list
            printf("No Names Starting With \"%c\" Letter Found!\n",toUpperCase(c));
    }

}
