

typedef int ptr;

struct node
{
    char element[51];
    ptr next;
};

typedef ptr position;
typedef ptr LIST;


void cursorInitialize(struct node cursor[129],int sizeOfCursor)
{
    int i=0;
    for (i=0;i<sizeOfCursor-1;i++)
        cursor[i].next = i+1;
    cursor[sizeOfCursor-1].next = 0;
}

position cursorAlloc(struct node cursor[129])
{
    position p;
    p=cursor[0].next;
    cursor[0].next = cursor[p].next;
    cursor[p].next=0;
    return p;
}

void cursorFree(struct node cursor[129],position p)
{
    cursor[p].next = cursor[0].next;
    cursor[0].next = p;
}

position findPrevious(struct node cursor[129],LIST L,char x[51]){
    position p = L;
    while (cursor[p].next != 0 && !strEq(cursor[cursor[p].next].element,x))
        p = cursor[p].next;
    return p;
}
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

position findLast(struct node cursor[129],LIST L){
    position p = L;
    while (cursor[p].next != 0)
        p = cursor[p].next;
    return p;
}


void addItem(struct node cursor[129],LIST L,char x[51]){
    position last = findLast(cursor,L);
    position p = cursorAlloc(cursor);
    cursor[last].next = p;
    cursor[p].next = 0;
    strcopy(x,cursor[p].element);
}

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

int isEmpty(struct node cursor[129],LIST L){
   return (cursor[L].next == 0);
}
