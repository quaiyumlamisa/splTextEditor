#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS   1000

void clrscr(void)
{
	system("clear");
}

int i,j,ch;
char fn[20],fn1[20],e,c,chr;
FILE *fp1,*fp2,*fp;
int count_lines = 0;

int linecount, wordcount, charcount;

linecount = 0;
wordcount = 0;
charcount = 0;

int lineC=0;



void Create()
    {
        char ch[100],ch2[100];
        printf("Enter the name of the file:\n");
        scanf("%s",&ch);

        char faltu[100]="C:\\\\Users\\\\lamis\\\\.android\\\\";

        int k=0;


        for(int j=0;faltu[j]!=0;j++,k++)
        {
            ch2[k] = faltu[j];
        }

        for(int i=0;ch[i]!='\0';i++,k++)
        {
            ch2[k]=ch[i];
        }

        ch2[k]='\0';

        printf("%s",ch2);

    //fp1=fopen(ch,"w");
    fp1=fopen(ch2,"w");
    printf("%s",ch2);

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

        char ch2[100];

        char faltu[100]="C:\\Users\\lamis\\.android\\";

        int k=0;


        for(int j=0;faltu[j]!=0;j++,k++)
        {
            ch2[k] = faltu[j];
        }

        for(int i=0;fn[i]!='\0';i++,k++)
        {
            ch2[k]=fn[i];
        }



        ch2[k]='\0';


    //fp1=fopen(fn,"r");
     fp1=fopen(ch2,"r");



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


void CopyFile()
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


void copyLine()
{
    int numOfLineToCopy,numOfLineToPaste;
    char tempStr[100];

    printf("\nEnter the file name: ");
    scanf("%s",fn);

    printf("\nEnter the line to copy : ");
    scanf("%d",&numOfLineToCopy);

    printf("\nEnter the number of line paste the line : ");
    scanf("%d",&numOfLineToPaste);

    fp1=fopen(fn,"r");

    if(fp1==NULL)
    {
        printf("\nFile not found!");
        goto end1;
    }
    chr = getc(fp1);

    numOfLineToCopy--;
    int i=0;
    while(chr!=EOF)
    {

        if(numOfLineToCopy==0)
        {
            tempStr[i]=chr;
            i++;
        }

        if (chr == '\n')
        {
            numOfLineToCopy--;
        }


        chr = getc(fp1);

    }

    tempStr[i]='\0';


    printf("temp string : %s",tempStr);

    end1:
    fclose(fp1);

    numOfLineToPaste--;
    fp1=fopen(fn,"r");
    fp2=fopen("3.txt","w");

    chr = getc(fp1);

    while(chr!=EOF)
    {
        if(chr=='\n') numOfLineToPaste--;

        fputc(chr,fp2);

        if(numOfLineToPaste==0)
        {
            for(int j=0;j<i;j++)
            {
                fputc(tempStr[j],fp2);
            }
            numOfLineToPaste--;

        }

        chr = getc(fp1);
    }

    fclose(fp1);
    fclose(fp2);



    fp1=fopen(fn,"w");
    fp2=fopen("3.txt","r");

    chr = getc(fp2);

    while(chr!=EOF)
    {
        fputc(chr,fp1);

        chr = getc(fp2);
    }

    fclose(fp1);
    fclose(fp2);

}




    void Copy()
    {
        int a;
    printf("press 1 to copy  a file and press 2 to copy line of a file");
    scanf("%d",&a);

    while(a)
    {


    if(a==1)
        CopyFile();
    else if(a==2)
        copyLine();
    else
        break;
    }
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
       chr = getc(fp1);
    while(chr!=EOF)
    {
                if (chr == '\n')

        {

            count_lines = count_lines + 1;

        }


        chr = getc(fp1);

    }
    end1:
    fclose(fp1);

    printf("There are %d lines in %s  in a file\n", lineC, fn);


}


void countWord()
   {

     FILE *fptr;
    char ch;
    int wrd=1,charctr=1;
    char fname[20];

	printf(" Input the filename to be opened : ");
	scanf("%s",fname);

    fptr=fopen(fname,"r");
    if(fptr==NULL)
     {
         printf(" File does not exist or can not be opened.");
      }
    else
        {
          ch=fgetc(fptr);
          printf(" The content of the file %s are : ",fname);
          while(ch!=EOF)
            {
                printf("%c",ch);
                if(ch==' '||ch=='\n')
                    {
                        wrd++;
                    }
                    else
                    {
                        charctr++;
                    }
                ch=fgetc(fptr);
            }
        printf("\n The number of words in the  file %s are : %d\n",fname,wrd-2);
        printf(" The number of characters in the  file %s are : %d\n\n",fname,charctr-1);
        }
    fclose(fptr);
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


