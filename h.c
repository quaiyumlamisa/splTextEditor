#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS   1000
#define MAX_FILE_NAME 100
void clrscr(void)
{
	system("clear");
}

int i,j,ch;
char fn[20],fn1[20],e,c,chr;
FILE *fp1,*fp2,*fp;
int count_lines = 0;


int lineC=0;


void Create()
    {
        char ch[100],ch2[100];
        printf("Enter the name of the file:\n");
        scanf("%s",&ch);
 fp1=fopen(ch,"w");
    printf("%s",ch);

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

   void Create_html()
    {


        fp1=fopen("demo.txt","w");


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



    //fp1=fopen(fn,"r");
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

    void Count()
{
    int count =0;
     char filename[MAX_FILE_NAME];
    char c;  // To store a character read from file

    // Get file name from user. The file should be
    // either in current folder or complete path should be provided
    printf("Enter file name: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;

    // Close the file
    fclose(fp);
    printf("The file %s has %d lines\n ", filename, count);

}

void CopyLine()
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



void Append(char *line)
    {
        printf("%s",line);

  char fname[20];

  char s[10]="</i>";
    char p[10]="<i>";

  printf("%s\n",line);
  strcat(line,s);
   printf("%s\n",line);

   strcat(p,line);
   printf("%s",p);




         printf("Enter file name: ");
    scanf("%s", fn);




    fp = fopen(fn, "a");
    fprintf(fp,"%s",p);


    fclose (fp);
    }



void manipulation()
{
int numOfLineToCopy;
char line[10];
 int i = 0;
 printf("\nEnter the file name: ");
    scanf("%s",fn);

printf("\nEnter the line to mnplt : ");
    scanf("%d",&numOfLineToCopy);

 fp1 = fopen(fn, "r");
    if(fp1==NULL)
    {
        printf("\nFile not found!");
        exit(0);
    }


    while (fgets(line, sizeof(line), fp1)) {
        i++;
        if(i == numOfLineToCopy )
        {
            printf("%s\n", line);
             Append(line);
        }
    }






}
int main(void)
{
       // Create();
       Create_html();
          Display();
          Display();

       // Count();
        manipulation();
         Display();
         CopyLine();
         Display();
        return 0;
}
