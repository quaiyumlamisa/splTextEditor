
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS   1000

void clrscr(void)
{
	system("clear");
}

    int i,j,ch;
    char fn[20],e,c,chr;
    FILE *fp1,*fp2,*fp;


void Create()
    {
        char ch[100];
        printf("Enter the name of the file:\n");
        scanf("%s",&ch);


    fp1=fopen(ch,"w");
    printf("\n\tEnter the text and press '*' to save\n\n\t");

    c=getchar();
    while(1)
    {
    c=getchar();


    if(c == '*')
    {

    fclose(fp1);
    break;
    }
    fputc(c,fp1);
    }
   }

     void Display()
    {
    printf("\n\tEnter the file name: ");
    scanf("%s",fn);
    fp1=fopen(fn,"r");
    if(fp1==NULL)
    {
    printf("\n\tFile not found!");
    goto end1;
    }
    while(!feof(fp1))
    {
    c=getc(fp1);
    printf("%c",c);
    }
    end1:
    fclose(fp1);
    printf("\n\n\tPress any key to continue\n");
    getch();
    }


int main(void)
 {

         Create();


         Display();


    return 0;
 }

