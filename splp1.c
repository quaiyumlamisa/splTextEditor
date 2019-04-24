#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

int i,j,ch;
char fn[20],fn1[20],e,c;
FILE *fp1,*fp2,*fp;

int linecount, wordcount, charcount;

 linecount = 0;
 wordcount = 0;
 charcount = 0;

void clrscr(void)
{
	system("clear");
}

void Create()
    {
        char ch[100];
        printf("Enter the name of the file:\n");
        scanf("%s",&ch);


    fp1=fopen(ch,"w");
    printf("\n\tEnter the text and press '*' to save\n\n\t");
    while(1)
    {
    c=getchar();
    fputc(c,fp1);
    if(c == '*')
    {
    fclose(fp1);
    break;
    }
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
    void Copy()
    {
    printf("\n\tEnter the new filename to copy:  ");
    scanf("%s",fn);
     printf("\n\tEnter the previous filename to copy:  ");
      scanf("%s",fn1);
    fp1=fopen(fn1,"r");
    fp2=fopen(fn,"w");
    while(!feof(fp1))
    {
    c=getc(fp1);

    putc(c,fp2);
    }
    fclose(fp2);
    }

    void Delete()
    {
    printf("\n\tEnter the file name: ");
    scanf("%s",fn);
    fp1=fopen(fn,"r");
    if(fp1==NULL)
    {
    printf("\n\tFile not found!");
    goto end2;
    }
    fclose(fp1);
    if(remove(fn)==0)
    {
    printf("\n\n\tFile has been deleted successfully!");
    goto end2;
    }
    else
    printf("\n\tError!\n");
    end2: printf("\n\n\tPress any key to continue\n");
    getch();
    }

    void Append()
    {
    printf("\n\tEnter the file name: ");
    scanf("%s",fn);
    fp1=fopen(fn,"r");
    if(fp1==NULL)
    {
    printf("\n\tFile not found!");
    fclose(fp1);
    goto end3;
    }
    while(!feof(fp1))
    {
    c=getc(fp1);
    printf("%c",c);
    }
    fclose(fp1);
    printf("\n\tType the text \n");
    fp1=fopen(fn,"a");
    while(1)
    {
    c=getch();
    if(c==19)
    goto end3;
    if(c==13)
    {
    c='\n';
    printf("\n\t");
    fputc(c,fp1);
    }
    else
    {
    printf("%c",c);
    fputc(c,fp1);
    }
    }
    end3: fclose(fp1);

    getch();
    }


    void Count()
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
      while ((ch=getc(fp1)) != EOF) {

		    if (ch != ' ' && ch != '\n') { ++charcount; }


		   if (ch == ' ' || ch == '\n') { ++wordcount; }


		   if (ch == '\n') { ++linecount; }



	   }

	   if (charcount > 0) {
		++linecount;
		++wordcount;
	   }
    }
     end1:
    fclose(fp1);

     printf("Lines : %d \n", linecount);
    printf("Words : %d \n", wordcount);
    printf("Characters : %d \n", charcount);


    printf("\n\n\tPress any key to continue\n");
    getch();
    }


 int main(void)
 {
  int a;
    while(1)
    {


    clrscr();
    printf("\n\t\t***** WELCOME TO THE TEXT EDITOR *****");
    printf("\n\n\tWhat do you want to do?\n\t\n");
    printf("\n\t1.CREATE\n\t2.DISPLAY\n\t3.APPEND\n\t4.COPY\n\t5.DELETE\n\t6.COUNT\n\t7.EXIT\n");
    printf("\n\tEnter your choice: ");
    scanf("%d",&a);

    if(a==1)
     {
         Create();
     }
    else if(a==2)
    {
         Display();
    }
    else if(a==3)
    {
        Append();
    }
    else if(a==4)
    {
         Copy();
    }
    else if(a==5)
    {
         Delete();
    }
    else if(a==6)
    {
         Count();
    }

    else if(a==7)
    {
          exit(0);
    }
    }
    return 0;
}
