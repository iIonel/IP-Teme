#include <iostream>
#include <stdio.h>
void Reverse()
{
    FILE *fptr = fopen("program1.txt", "a+");
    FILE *fptr2 = fopen("program1.txt", "a+");
    char ch, fname[30], newch[500];
    int i=0, j, k=0;
    fprintf(fptr2,"\n");
    fprintf(fptr2, "ordinea normala: \n");
    ch = getc(fptr);
    while(ch != EOF)
    {
        k++;
        fprintf(fptr2,"%c", ch);
        newch[i] = ch;
        i++;
        ch = getc(fptr);
    }
    fprintf(fptr2, "\nordinea inversata: ");
    for(j=k-1; j>=0; j--)
       fprintf(fptr2, "%c", newch[j]);
    fclose(fptr);
    fclose(fptr2);
}

int main()
{
    Reverse();
}
