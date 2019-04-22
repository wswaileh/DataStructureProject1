//to make it easier to deal with the cursor , I redefined int type to ptr type
typedef int ptr;
//this struct is the base of the cursor
struct node
{
    char element[51];
    ptr next;
};
//redefined ptr into position and LIST to make LIST headers clear , and to make following the code easier
typedef ptr position;
typedef ptr LIST;

//To Initiallize The Cursor (Correcting cursor[index].next = index+1 , cursor[size-1].next=0
void cursorInitialize(struct node cursor[129],int sizeOfCursor)
{
    int i=0;
    for (i=0;i<sizeOfCursor-1;i++)
        cursor[i].next = i+1;
    cursor[sizeOfCursor-1].next = 0;
}
//to return a free position in the cursor
position cursorAlloc(struct node cursor[129])
{
    position p;
    p=cursor[0].next;
    cursor[0].next = cursor[p].next;
    cursor[p].next=0;
    return p;
}
//to free the node p and be able to use it again
void cursorFree(struct node cursor[129],position p)
{
    cursor[p].next = cursor[0].next;
    cursor[0].next = p;
}
//to find the position of the node in list L before some element x
position findPrevious(struct node cursor[129],LIST L,char x[51]){
    position p = L;
    while (cursor[p].next != 0 && !strEq(cursor[cursor[p].next].element,x))
        p = cursor[p].next;
    return p;
}
//delete an item from a list
int deleteItem(struct node cursor[129],LIST L,char x[51])
{
    position p,temp;
    p = findPrevious(cursor,L,x);
    if (cursor[p].next != 0){
        temp = cursor[p].next;
        cursor[p].next = cursor[temp].next;
        cursorFree(cursor,temp);
        return 1;
    }
    return 0;
}
//find the last element in an list
position findLast(struct node cursor[129],LIST L){
    position p = L;
    while (cursor[p].next != 0)
        p = cursor[p].next;
    return p;
}

//to add an item after the last node in list L
void addItem(struct node cursor[129],LIST L,char x[51]){
    position last = findLast(cursor,L);
    position p = cursorAlloc(cursor);
    cursor[last].next = p;
    cursor[p].next = 0;
    strcopy(x,cursor[p].element);
}
//to print a list
void printList(struct node cursor[129],LIST L){
    position p=cursor[L].next;
    if (p == 0)
        printf("List Is Empty!\n");
    else
        while (p!=0){
           puts(cursor[p].element);
            p = cursor[p].next;
    }
}
//to check if a list is empty
int isEmpty(struct node cursor[129],LIST L){
   return (cursor[L].next == 0);
}

// this method is used to move position p from list 'from' and add it after the last node in list 'to'
void moveToList(struct node cursor[129],LIST from,LIST to,position p)
{
    position lastInTo = findLast(cursor,to); //to add the item after last node in destination list
    position previous = findPrevious(cursor,from,cursor[p].element); //to find the node before the node we are going to move
    cursor[previous].next = cursor[p].next;
    cursor[lastInTo].next = p;
    cursor[p].next = 0;
}

//this method is used to move every item in list 'from' and add them after final node in list 'to'
void moveAllListToList(struct node cursor[129],LIST from,LIST to)
{

    position p = cursor[from].next;

    while (p != 0)
    {
        position temp = cursor[p].next;
        moveToList(cursor,from,to,p);
        p = temp;
    }


}


