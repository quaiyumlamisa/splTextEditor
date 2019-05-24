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
char fn[20],e,c,chr;
FILE *fp1,*fp2,*fp;
int count_lines = 0;

int linecount, wordcount, charcount;

linecount = 0;
wordcount = 0;
charcount = 0;

int lineC=0;

void Create()
{
    char ch[100];
    printf("Enter the name of the file:\n");
    scanf("%s",&ch);

    fp1=fopen(ch,"w");
    printf("\nEnter the text and press '*' to save\n\n");

    c=getchar();

    while(1)
    {
        c=getchar();

        if(c=='\n')lineC++;

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
    printf("\nEnter the file name: ");
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


void Array()
{
    //Count();
    int n= count_lines ;
    int** array;

	array = malloc(n * sizeof(*array));


	int count = 1;
	for(int i = 0; i < n; i++)
	{
	    array[i] = malloc(count * sizeof(**array));
	    if(!array[i])
	    {
	        for(int j = 0; j < i; j++)
	        {
	            free(array[j]);
	        }
	        free(array);


	    }
	    count++;
	}

    printf("\n\tEnter the file name: ");
    scanf("%s",fn);

	FILE* fp = fopen(fn, "r");
	if(!fp)
	{
	   for(int i = 0; i < n; i++)
	   {
	      free(array[i]);
	   }
	   free(array);


	}

	int max = 0;

	for(int i = 0; i < n; i++)
	{
        while(!feof(fp1))
        {
            c=getc(fp1);
            array[i][max]=c;
            max++;
            printf("%d\n",max);

        }

            // printf("array[%d][%d] = %ch\n", i, max, array[i][max]);
	    // fscanf(fp, "%ch", &array[i][max]);


	   /* for(count = 0; count < max; count++)
	    {
	        fscanf(fp, "%ch", &array[i][count]);
	    }
	    max++;
	    */
	}



	//max = 1;

	for(int i = 0; i < n; i++)
	{
	    for(count = 0; count < max; count++)
	    {
	        printf("array[%d][%d] = %ch\n", i, count, array[i][count]);
	    }
	   // max++;
	}


	for(int i = 0; i < n; i++)
	{
	   free(array[i]);
	}
	free(array);



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

int main(void)
 {

    //Create();

    copyLine();

    Display();
    //Count();



    return 0;
 }
