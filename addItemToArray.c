
void addItemToArrayMenu(char strings[100][51],int *maxStringLength,int *arrayLength)
{
    char name[51];
    printf("Enter The Item You Want To Add Please :\n");
    //because the '\n' isn't read from the first gets \ scanf so getchar fetches the '\n'
    getchar();

    gets(name);
    //adds the name that the user entered to the array
    strcopy(name,strings[*arrayLength]);
    //increment the array length
    *arrayLength = *arrayLength + 1;
    //make sure that the maximum length is correct even after the item is added
    if (strLen(name) > *maxStringLength)
        *maxStringLength = strLen(name);
}
