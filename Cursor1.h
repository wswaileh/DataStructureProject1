#ifndef CURSOR1_H_INCLUDED
#define CURSOR1_H_INCLUDED
typedef int ptr;

struct node
{
    char element[51];
    ptr next;
};

typedef ptr position;
typedef ptr LIST;

void cursorInitialize(struct node [129],int );
position cursorAlloc(struct node [129]);
void cursorFree(struct node [129],position );
position findPrevious(struct node [129],LIST ,char [51]);
int deleteItem(struct node [129],LIST ,char [51]);
position findLast(struct node [129],LIST );
void addItem(struct node [129],LIST ,char [51]);
void printList(struct node [129],LIST );
int isEmpty(struct node [129],LIST );

#endif // CURSOR1_H_INCLUDED
