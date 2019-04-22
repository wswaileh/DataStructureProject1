void deleteItemMenu(char strings[100][51],int *arrayLength)
{
    char item[51];
    printf("Enter The Item You Want To delete Please:\n");
    getchar();
    gets(item);

    int i,j,flag=0; //if flag == 0 , delete failed , else deleted successfully
    //to search for the item the user wants to delete
    for (i=0; i<*arrayLength; i++)
        if (strEq(item,strings[i]))
        {
            flag = 1;
            break;
        }

    if (flag == 1)
    {
        //to shift the elements after the deleted item
        for (j=i; j<*arrayLength; j++)
            strcopy(strings[j+1],strings[j]);
        //modify the array length because it deleted an item
        *arrayLength = *arrayLength -1;
        printf("%s Deleted Successfully!\n",item);
    }
    else
        printf("Item Not Found!\n");

}
