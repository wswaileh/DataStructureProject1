/**
 *     My String Functions Header File
 *     Author : Waleed Swaileh
 */



#include <stdio.h>
#include <stdlib.h>
//copy a string from 'from' to 'to'
void strcopy(char from[51],char to[51])
{
    int i=0;
    while (from[i++] != '\0')
        to[i-1]=from[i-1];
    to[i-1]='\0';
}
//to return the length of a string
int strLen(char string[51])
{
    int length = 0;
    while (string [length++]!='\0');
    return length-1;
}
//when reading from file ,'\n' is included in the string that was read,so this method removes it
void trimNewLineSymbol(char string[51])
{
    if (string[strLen(string)-1]=='\n')
        string[strLen(string)-1]='\0';
}
//compares if 2 strings are the same
int strEq(char s1[51],char s2[51])
{
    int i;
    if (strLen(s1)!=strLen(s2))
        return 0;
    for ( i=0; i<strLen(s1); i++)
        if (s1[i]!=s2[i])
            return 0;
    return 1;
}
//return the character in upper case *Useful when printing*
char toUpperCase(char x){
    if (x >= 'a' && x<='z')
        return x-32;
    return x;
}
