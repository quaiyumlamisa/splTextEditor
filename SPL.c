#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORDS   1000



#define NULL 0

int size=0;

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

struct Tab
{
    char name[100],address[100];
    int id;
    struct Tab *next;
};

struct Tab *first,*last;
char fileName[100] ;


void Create()
    {
        char ch[100],ch2[100];
        printf("Enter the name of the file:\n");
        scanf("%s",&ch);
/*
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

       // printf("%s",ch2);
    //fp1=fopen(ch,"w");
    fp1=fopen(ch2,"w");
    printf("%s",ch2);
*/
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
 /*
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



     fp1=fopen(ch2,"r");

*/
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

     fp1=fopen(fn,"r");
    while(!feof(fp1))
    {
    c=getc(fp1);
    printf("%c",c);
    }


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
    printf("press 1 to copy  a file and press 2 to copy line of a file\n");
    scanf("%d",&a);



    if(a==1)
        CopyFile();
    else if(a==2)
        copyLine();

    }

    void Append()
    {
    printf("\n\tEnter the file name: ");
    scanf("%s",fn);
    fp1=fopen(fn,"r");


    while(!feof(fp1))
    {
    c=getc(fp1);
    printf("%c",c);
    }
    fclose(fp1);

    char ch[100];
    printf("\n\tType the text \n");
    scanf("%s",ch);
    fp1=fopen(fn,"a");


    fprintf(fp1,"%s",ch);
    fclose(fp1);


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





void createFile()
{
    printf("Enter the name of the file:\n");
    scanf("%s",&fileName);
}


void tableInsert()
{
    int n;
    char l[10];
    printf("\n\tEnter the name : ");
    scanf("%s",l);
    n=tableSearch(l,1);

    if(n==1)
        printf("\n\tThe  exists already in the symbol table\n\tDuplicate can't be inserted");
    else
    {
        char s[10] ;
        int a ;

        printf("\n\tEnter the address: ");
        scanf("%s",&s);
        printf("\n\tEnter the id : ");
        scanf("%d",&a);
        tableWriteInFile(l,s,a) ;
    }

    printf("\n\tname inserted\n");
}

void tableDisplay()
{
    tableReadFromFile();

    int i;
    struct Tab *p;
    p=first;
    printf("\n\tName\t\tAddress\t\tId\n");
    for(i=0;i<size;i++)
    {
        printf("\t%s\t\t%s\t\t%d\n",p->name,p->address,p->id);
        p=p->next;
    }
}

void tableFullWriteInFile()
{
    int i;
    FILE *oFile ;
    oFile = fopen(fileName,"w") ;
    struct Tab *p;
    p=first;

    fprintf(oFile,".\n\tName\t\tAddress\t\tID\n");

    for(i=0;i<size;i++)
    {
        fprintf(oFile,"\t%s\t\t%s\t\t%d\n",p->name,p->address,p->id);
        p=p->next;
    }

    fclose(oFile) ;
}

void tableWriteInFile(char *l , char *s , int a)
{
    int i;
    FILE *oFile,*iFile ;
    oFile = fopen(fileName,"a") ;
    iFile = fopen(fileName,"r") ;

    char ch ;
    fscanf(iFile,"%s",&ch) ;
    if(ch!='.'){
        fprintf(oFile,".\n\tName\t\tAddress\t\tID\n");
    }

    fprintf(oFile,"\t%s\t\t%s\t\t%d\n",l,s,a);

    fclose(oFile) ;
    //fclose(iFile) ;
}

void tableReadFromFile()
{
    int i;
    FILE *iFile ;
    iFile = fopen(fileName,"r") ;

    struct Tab *p = {0};
    p=malloc(sizeof(struct Tab));

    size = 0 ;

  //p=first;
    char faltu[100] ;
    fscanf(iFile,"%s",&faltu);
    fscanf(iFile,"%s",&faltu);
    fscanf(iFile,"%s",&faltu);
    fscanf(iFile,"%s",&faltu);

    char x[10] ;
    char *x1 = (char*) malloc(10);

    int y ;
    fscanf(iFile,"%s",&x);

    for(i=0 ; i<strlen(x) ; i++){
        x1[i] = x[i] ;
    }
    x1[i] = '\0' ;

    char check[10] = "-1" ;

    for(i=0;strlen(x)>0 && strcmp(check,x1)!=0;i++)
    {
        p=malloc(sizeof(struct Tab));
        strcpy(p->name,x1);

        x1 = (char*) malloc(10);
        fscanf(iFile,"%s",&x);
        for(i=0 ; i<strlen(x) ; i++)
        {
            x1[i] = x[i] ;
        }
        x1[i] = '\0' ;
        strcpy(p->address,x1);
        for(i=0 ; i<strlen(x) ; i++)
        {
            check[i] = x[i] ;
        }
        check[i] = '\0' ;

        x1 = (char*) malloc(10);
        fscanf(iFile,"%d",&y);
        p->id = y;

        x1 = (char*) malloc(10);
        fscanf(iFile,"%s",&x);

        for(i=0 ; i<strlen(x) ; i++)
        {
            x1[i] = x[i] ;
        }
        x1[i] = '\0' ;

        p->next=NULL;
        if(size==0)
        {
            first=p;
            last=p;
        }

        else
        {
            last->next=p;
            last=p;
        }

        size++;
   }

   fclose(iFile) ;

}

int tableSearch(char lab[],int flagForModify)
{
    if(flagForModify==1){
        tableReadFromFile() ;
    }

    int i,flag=0;
    struct Tab *p;
    p=first;
    for(i=0;i<size;i++)
    {
        if(strcmp(p->name,lab)==0)
        flag=1;

        p=p->next;
    }

    return flag;
}

void tableModify()
{
    tableReadFromFile() ;
    char l[10],nl[10];
    int add,choice,i,s;
    struct Tab *p;
    p=first;
    printf("\n\tWhat do you want to modify?\n");
    printf("\n\t1.Only the name\n\t2.Only the id\n\t3.Both the name and id\n");
    printf("\tEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("\n\tEnter the old name: ");
            scanf("%s",l);
            s=tableSearch(l,-1);

            if(s==0)
                printf("\n\tname not found\n");

            else
            {
                printf("\n\tEnter the new name : ");
                scanf("%s",nl);
                for(i=0;i<size;i++)
                {
                    if(strcmp(p->name,l)==0)
                    strcpy(p->name,nl);
                    p=p->next;
                }
                printf("\n\tAfter Modification:\n");
                tableFullWriteInFile() ;
                tableDisplay();
            }
        break;
        case 2:
            printf("\n\tEnter the name where the id is to be modified : ");
            scanf("%s",l);
            s=tableSearch(l,-1);
            if(s==0)
            printf("\n\tname not found\n");
            else
            {
                printf("\n\tEnter the new id : ");
                scanf("%d",&add);

                for(i=0;i<size;i++)
                {
                    if(strcmp(p->name,l)==0)
                    p->id=add;
                    p=p->next;
                }
                printf("\n\tAfter Modification:%dW\n",first->id);
                tableFullWriteInFile() ;
                tableDisplay();
            }
        break;
        case 3:
            printf("\n\tEnter the old name: ");
            scanf("%s",l);
            s=tableSearch(l,-1);

            if(s==0)
                printf("\n\tname not found\n");

            else
            {
                printf("\n\tEnter the new name : ");
                scanf("%s",nl);
                printf("\n\tEnter the new id : ");
                scanf("%d",&add);
                for(i=0;i<size;i++)
                {
                    if(strcmp(p->name,l)==0)
                    {
                        strcpy(p->name,nl);
                        p->id=add;
                    }
                    p=p->next;
                }
            printf("\n\tAfter Modification:\n");
            tableFullWriteInFile();
            tableDisplay();
            }
        break;
    }
}

void tableDelete()
{
    tableReadFromFile() ;
    int a;
    char l[10];
    struct Tab *p,*q;
    p=first;
    printf("\n\tEnter the name to be deleted : ");
    scanf("%s",l);
    a=tableSearch(l,-1);
    if(a==0)
    printf("\n\tname not found\n");
    else
    {
        if(strcmp(first->name,l)==0)
        first=first->next;

        else if(strcmp(last->name,l)==0)
        {
            q=p->next;
            while(strcmp(q->name,l)!=0)
            {
                p=p->next;
                q=q->next;
            }

            p->next=NULL;
            last=p;
        }
    else
    {
        q=p->next;
        while(strcmp(q->name,l)!=0)
        {
            p=p->next;
            q=q->next;
        }
        p->next=q->next;
    }

        size--;
        printf("\n\tAfter Deletion:\n");
        tableFullWriteInFile() ;
        tableDisplay();
    }
}






void tableMain()
{
 int op,y;
 char la[10];
 //clrscr();
    do
    {
        printf("\n\t TABLE IMPLEMENTATION\n");
        printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.MODIFY\n\t6.END\n");
        printf("\n\tEnter your option : ");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
              tableInsert();
              break;

            case 2:
              tableDisplay();
              break;

            case 3:
              tableDelete();
              break;

            case 4:
              printf("\n\tEnter the name to be searched : ");
              scanf("%s",la);
              y=tableSearch(la,1);
              printf("\n\tSearch Result:");

              if(y==1)
                printf("\n\tThe name is present in the symbol table\n");
              else
                printf("\n\tThe name is not present in the symbol table\n");
              break;

            case 5:
              tableModify();
              break;

            case 6:
              exit(0);
        }
    }

    while(op<6);

    getch();
}


void CreateTable()
{
 createFile() ;
 tableMain() ;

}

void CountLines(FILE  *fptr,char *fname)
{



    int count = 0;

    char c,c1;

    if (fptr == NULL)
    {
        printf("Could not open file %s", fname);
        return 0;
    }


    for (c = getc(fptr); c != EOF; c = getc(fptr))
        if (c == '\n')
            count = count + 1;


    fclose(fptr);
    printf("The file %s has %d lines\n ", fname, count);
}

void CountWord(FILE  *fptr,char *fname)
   {

    char ch;
    int w=0;

 if(fptr==NULL)
     {
         printf("file not found");
      }
    else
      {
          ch=fgetc(fptr);
          while(ch!=EOF)
                 {
                        printf("%c",ch);
                        if(ch==' '||ch=='\n')
                          {
                               w++;
                          }
                               ch=fgetc(fptr);
                 }
                               printf("\nWords in a file are=%d\n",w);
     }
                              fclose(fptr);
        }

void CountChar( FILE  *fptr,char *fname)
{


    char ch;
    int wrd=1,charctr=1;





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

        printf(" The number of characters in the  file %s are : %d\n\n",fname,charctr-1);
        }
    fclose(fptr);

}


void CountThings()
{
     FILE *fptr;
     char fname[20];

     printf(" Input the filename to be opened : ");
	 scanf("%s",fname);
	 fptr=fopen(fname,"r");


  printf("What do you want to count?\n1.Lines\n2.Words\n3.Characters\n") ;
  int a;
  scanf("%d",&a);

  if(a==1)
    CountLines(fptr,fname);

  else if(a==2)
    CountWord(fptr,fname);

  else if(a==3)
    CountChar(fptr,fname);
}




     char* replace_char(char* str, char find, char replace)
{
    char *current_pos=strchr(str,find);
    while(current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos, find);
    }
    return str;
}




void CopyLineC()
{
    int numOfLineToCopy,numOfLineToPaste;
    char tempStr[100];


    numOfLineToCopy=7;
    numOfLineToPaste=5;
    char fn[20]="color.txt";



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


   // printf("temp string : %s",tempStr);

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


void AppendC(char *line)
    {
      //  printf("%s",line);

  char fname[20];


  char s[10]="</font>";
  char p[100]= "<font color=""red"">";
 // printf("%s\n",line);
  strcat(line,s);
 //  printf("%s\n",line);

   strcat(p,line);
  // printf("%s",p);



    char fn[20]="color.txt";


    fp = fopen(fn, "a");
    fprintf(fp,"%s",p);


    fclose (fp);


    }




void manipulationC()
{
int numOfLine;
char line[256];
 int i = 0;
 printf("\nEnter the file name: ");
    scanf("%s",fn);

printf("\nEnter the line to mnplt : ");
    scanf("%d",&numOfLine);

 fp1 = fopen(fn, "r");
    if(fp1==NULL)
    {
        printf("\nFile not found!");
        exit(0);
    }


    while (fgets(line, sizeof(line), fp1)) {
        i++;
        if(i == numOfLine )
        {

            replace_char(line, '\n', ' ');
             AppendC(line);
        }
    }






}

void deleteLineC()
{





        int lno, ctr = 0;
        char ch;
        FILE *fptr1, *fptr2;

        char str[MAX], temp[] = "temp.txt";

		char fname[MAX]="color.txt";
        fptr1 = fopen(fname, "r");
        if (!fptr1)
		{
                printf(" File not found or unable to open the input file!!\n");
                return 0;
        }
        fptr2 = fopen(temp, "w");
        if (!fptr2)
		{
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
                return 0;
        }

      lno=7;

        while (!feof(fptr1))
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1))
            {
                ctr++;

                if (ctr != lno)
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);
        rename(temp, fname);

   fptr1=fopen(fname,"r");
            ch=fgetc(fptr1);

        fclose(fptr1);


  }

void CopyFileC()
    {

      char fn[100]="color.html";
      char fn1[100]="color.txt";
    fp1=fopen(fn1,"r");
    fp2=fopen(fn,"w");
    while(!feof(fp1))
    {
    c=getc(fp1);

    putc(c,fp2);
    }
    fclose(fp2);
    }




    void CopyLineS()
{
    int numOfLineToCopy,numOfLineToPaste;
    char tempStr[100];


    numOfLineToCopy=7;
    numOfLineToPaste=5;
    char fn[20]="size.txt";



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


   // printf("temp string : %s",tempStr);

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


void AppendS(char *line)
    {
      //  printf("%s",line);

  char fname[20];


    char s[10]="</h1>";
    char p[10]="<h1>";
  // char s[10]="</font>";
  // char p[100]= "<font color=""red"">";
 // printf("%s\n",line);
  strcat(line,s);
 //  printf("%s\n",line);

   strcat(p,line);
  // printf("%s",p);



    char fn[20]="size.txt";


    fp = fopen(fn, "a");
    fprintf(fp,"%s",p);


    fclose (fp);


    }




void manipulationS()
{
int numOfLine;
char line[256];
 int i = 0;
 printf("\nEnter the file name: ");
    scanf("%s",fn);

printf("\nEnter the line to mnplt : ");
    scanf("%d",&numOfLine);

 fp1 = fopen(fn, "r");
    if(fp1==NULL)
    {
        printf("\nFile not found!");
        exit(0);
    }


    while (fgets(line, sizeof(line), fp1)) {
        i++;
        if(i == numOfLine )
        {

            replace_char(line, '\n', ' ');
             AppendS(line);
        }
    }






}

void deleteLineS()
{





        int lno, ctr = 0;
        char ch;
        FILE *fptr1, *fptr2;

        char str[MAX], temp[] = "temp.txt";

		char fname[MAX]="size.txt";
        fptr1 = fopen(fname, "r");
        if (!fptr1)
		{
                printf(" File not found or unable to open the input file!!\n");
                return 0;
        }
        fptr2 = fopen(temp, "w");
        if (!fptr2)
		{
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
                return 0;
        }

      lno=7;

        while (!feof(fptr1))
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1))
            {
                ctr++;

                if (ctr != lno)
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);
        rename(temp, fname);

   fptr1=fopen(fname,"r");
            ch=fgetc(fptr1);

        fclose(fptr1);


  }

void CopyFileS()
    {

      char fn[100]="size.html";
      char fn1[100]="size.txt";
    fp1=fopen(fn1,"r");
    fp2=fopen(fn,"w");
    while(!feof(fp1))
    {
    c=getc(fp1);

    putc(c,fp2);
    }
    fclose(fp2);
    }




void CopyLineB()
{
    int numOfLineToCopy,numOfLineToPaste;
    char tempStr[100];


    numOfLineToCopy=7;
    numOfLineToPaste=5;
    char fn[20]="bold.txt";



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


   // printf("temp string : %s",tempStr);

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


void AppendB(char *line)
    {
      //  printf("%s",line);

  char fname[20];


    char s[10]="</b>";
    char p[10]="<b>";
  // char s[10]="</font>";
  // char p[100]= "<font color=""red"">";
 // printf("%s\n",line);
  strcat(line,s);
 //  printf("%s\n",line);

   strcat(p,line);
  // printf("%s",p);



    char fn[20]="bold.txt";


    fp = fopen(fn, "a");
    fprintf(fp,"%s",p);


    fclose (fp);


    }






void manipulationB()
{
int numOfLine;
char line[256];
 int i = 0;
 printf("\nEnter the file name: ");
    scanf("%s",fn);

printf("\nEnter the line to mnplt : ");
    scanf("%d",&numOfLine);

 fp1 = fopen(fn, "r");
    if(fp1==NULL)
    {
        printf("\nFile not found!");
        exit(0);
    }


    while (fgets(line, sizeof(line), fp1)) {
        i++;
        if(i == numOfLine )
        {

            replace_char(line, '\n', ' ');
             AppendB(line);
        }
    }






}

void deleteLineB()
{





        int lno, ctr = 0;
        char ch;
        FILE *fptr1, *fptr2;

        char str[MAX], temp[] = "temp.txt";

		char fname[MAX]="bold.txt";
        fptr1 = fopen(fname, "r");
        if (!fptr1)
		{
                printf(" File not found or unable to open the input file!!\n");
                return 0;
        }
        fptr2 = fopen(temp, "w");
        if (!fptr2)
		{
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
                return 0;
        }

      lno=7;

        while (!feof(fptr1))
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1))
            {
                ctr++;

                if (ctr != lno)
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);
        rename(temp, fname);

   fptr1=fopen(fname,"r");
            ch=fgetc(fptr1);

        fclose(fptr1);


  }

void CopyFileB()
    {

      char fn[100]="bold.html";
      char fn1[100]="bold.txt";
    fp1=fopen(fn1,"r");
    fp2=fopen(fn,"w");
    while(!feof(fp1))
    {
    c=getc(fp1);

    putc(c,fp2);
    }
    fclose(fp2);
    }






void CopyLineI()
{
    int numOfLineToCopy,numOfLineToPaste;
    char tempStr[100];


    numOfLineToCopy=7;
    numOfLineToPaste=5;
    char fn[20]="italic.txt";



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


   // printf("temp string : %s",tempStr);

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


void AppendI(char *line)
    {
      //  printf("%s",line);

  char fname[20];


    char s[10]="</i>";
    char p[10]="<i>";
  // char s[10]="</font>";
  // char p[100]= "<font color=""red"">";
 // printf("%s\n",line);
  strcat(line,s);
 //  printf("%s\n",line);

   strcat(p,line);
  // printf("%s",p);



    char fn[20]="italic.txt";


    fp = fopen(fn, "a");
    fprintf(fp,"%s",p);


    fclose (fp);


    }




void manipulationI()
{
int numOfLine;
char line[256];
 int i = 0;
 printf("\nEnter the file name: ");
    scanf("%s",fn);

printf("\nEnter the line to mnplt : ");
    scanf("%d",&numOfLine);

 fp1 = fopen(fn, "r");
    if(fp1==NULL)
    {
        printf("\nFile not found!");
        exit(0);
    }


    while (fgets(line, sizeof(line), fp1)) {
        i++;
        if(i == numOfLine )
        {

            replace_char(line, '\n', ' ');
             AppendI(line);
        }
    }






}

void deleteLineI()
{





        int lno, ctr = 0;
        char ch;
        FILE *fptr1, *fptr2;

        char str[MAX], temp[] = "temp.txt";

		char fname[MAX]="italic.txt";
        fptr1 = fopen(fname, "r");
        if (!fptr1)
		{
                printf(" File not found or unable to open the input file!!\n");
                return 0;
        }
        fptr2 = fopen(temp, "w");
        if (!fptr2)
		{
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
                return 0;
        }

      lno=7;

        while (!feof(fptr1))
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1))
            {
                ctr++;

                if (ctr != lno)
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);
        rename(temp, fname);

   fptr1=fopen(fname,"r");
            ch=fgetc(fptr1);

        fclose(fptr1);


  }

void CopyFileI()
    {

      char fn[100]="italic.html";
      char fn1[100]="italic.txt";
    fp1=fopen(fn1,"r");
    fp2=fopen(fn,"w");
    while(!feof(fp1))
    {
    c=getc(fp1);

    putc(c,fp2);
    }
    fclose(fp2);
    }






void FontChanges()
{
     printf("What do you want to do?\n1.Change font styles\n2.Change font size\n3.Change font color\n");
    int b;
    scanf("%d\n",&b);


    if(b==1)
    {
        printf("press 1 for Italic & press 2 for Bold\n ");
        int d;
        scanf("%d",&d);
        if(d==1)
           italic();

        else if(d==2)
            bold();
    }

    else if(b==2)
    {
        fontSize();
    }

    else if(b==3)
    {
        fontColor();
    }
}





int main(void)
 {
  int a;
    while(1)
    {


    clrscr();
    printf("\n\t\t***** WELCOME TO THE TEXT EDITOR *****");
    printf("\n\n\tWhat do you want to do?\n\t\n");
    printf("\n\t1.CREATE\n\t2.DISPLAY\n\t3.APPEND\n\t4.COPY\n\t5.DELETE\n\t6.COUNT\n\t7.Create Table\n\t8.Font Changes\n\t9.EXIT\n");
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
         CountThings();
    }

     else if(a==7)
    {
         CreateTable();
    }

     else if(a==8)
    {
         FontChanges();
    }

     if(a==9)
    {
          exit(0);
    }

    }
    return 0;
}




