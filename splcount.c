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
     int count_lines = 0;

 int linecount, wordcount, charcount;

 // Initialize counter variables
 linecount = 0;
 wordcount = 0;
 charcount = 0;



void Create()
    {
        char ch[100];
        printf("Enter the name of the file:\n");
        scanf("%s",&ch);


    fp1=fopen(ch,"w");
    printf("\n\tEnter the text and press '.' to save\n\n\t");
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

    printf("There are %d lines in %s  in a file\n", count_lines-1, fn);



    }


    void Array()
    {
    Count();
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
            //printf("%c",array[i][max]2);
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

int main(void)
 {

         Create();


         Display();

        Array();


    return 0;
 }
