#include "cursor.h"

void radixSort(char strings[100][51],int *arrayLength,int *maxStringLength)
{
    if (*arrayLength == 0)
        printf("Sort Failed! No Items Found!\n");
    else
    {
        int i,j,k;

        struct node cursor[129];
        //To Initiallize The Cursor (Correcting cursor[index].next = index+1, cursor[size-1].next=0
        cursorInitialize(cursor,129);
        //defined a list to add array items to it
        LIST l = cursorAlloc(cursor);
        //adding content of the array to the list I just created
        for (i=0; i<*arrayLength; i++)
            addItem(cursor,l,strings[i]);
        //created 27 bucket (26 letter buckets and null bucket
        position buckets[27];
        //intiallizing the buckets where buckets[0] is null bucket , buckets[1] is A bucket ,..., buckets[26] is Z bucket
        for (i=0; i<27; i++)
            buckets[i] = cursorAlloc(cursor);
        // to walk through the all the letters
        for (k=*maxStringLength-1; k>=0; k--)
        {
            // position p walks through every world in the list l
            position p = cursor[l].next;
            while (p != 0)
            {
                // if the word is shorter than the counter 'k' or the character equals \0 or space it will move it to null bucket
                if ( cursor[p].element[k]<'A' || strLen(cursor[p].element) < k )
                    moveToList(cursor,l,buckets[0],p);

                //if the character is a capital letter it will move it to its bucket
                else if (cursor[p].element[k] >= 'A' && cursor[p].element[k]<= 'Z')
                {

                    int bucketNum = cursor[p].element[k] - 'A' +1;
                    moveToList(cursor,l,buckets[bucketNum],p);
                }

                //if the character is a small letter it will move it to its bucket

                else
                {
                    int bucketNum = cursor[p].element[k] - 'a'+1;
                    moveToList(cursor,l,buckets[bucketNum],p);
                }



                p = cursor[l].next;
            }


            // return items from buckets to list l
            for (j=0; j<27; j++)
                if (!isEmpty(cursor,buckets[j]))
                    moveAllListToList(cursor,buckets[j],l);


        }

        //to return sorted names from list to the array
        i=0;
        position p = cursor[l].next;
        while (p != 0)
        {
            strcopy(cursor[p].element,strings[i++]);
            p = cursor[p].next;
        }
    }
}

