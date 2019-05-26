#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS   1000

//For Table: From
#define NULL 0

int size=0;
void Insert();
void Display();
void Delete();
int Search(char lab[],int flagForModify);
void Modify();
//to


void clrscr(void)
{
	system("clear");
}

    int i,j,ch;
    char fn[20],e,c,chr;
    FILE *fp1,*fp2,*fp;

char fileName[100] ;

void createFile()
{
    printf("Enter the name of the file:\n");
    scanf("%s",&fileName);
}

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
    createFile() ;
    tableMain() ;
    //Create();
    //mDisplay();
    return 0;
}


//For Table

struct SymbTab
{
    char label[10],symbol[10];
    int addr;
    struct SymbTab *next;
};

struct SymbTab *first,*last;

void tableMain()
{
 int op,y;
 char la[10];
 //clrscr();
    do
    {
        printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
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
              printf("\n\tEnter the label to be searched : ");
              scanf("%s",la);
              y=tableSearch(la,1);
              printf("\n\tSearch Result:");

              if(y==1)
                printf("\n\tThe label is present in the symbol table\n");
              else
                printf("\n\tThe label is not present in the symbol table\n");
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

void tableInsert()
{
    int n;
    char l[10];
    printf("\n\tEnter the label : ");
    scanf("%s",l);
    n=tableSearch(l,1);

    if(n==1)
        printf("\n\tThe label exists already in the symbol table\n\tDuplicate can't be inserted");
    else
    {
        char s[10] ;
        int a ;

        printf("\n\tEnter the symbol : ");
        scanf("%s",&s);
        printf("\n\tEnter the address : ");
        scanf("%d",&a);
        tableWriteInFile(l,s,a) ;
    }

    printf("\n\tLabel inserted\n");
}

void tableDisplay()
{
    tableReadFromFile();

    int i;
    struct SymbTab *p;
    p=first;
    printf("\n\tLABEL\t\tSYMBOL\t\tADDRESS\n");
    for(i=0;i<size;i++)
    {
        printf("\t%s\t\t%s\t\t%d\n",p->label,p->symbol,p->addr);
        p=p->next;
    }
}

void tableFullWriteInFile()
{
    int i;
    FILE *oFile ;
    oFile = fopen(fileName,"w") ;
    struct SymbTab *p;
    p=first;

    fprintf(oFile,".\n\tLABEL\t\tSYMBOL\t\tADDRESS\n");

    for(i=0;i<size;i++)
    {
        fprintf(oFile,"\t%s\t\t%s\t\t%d\n",p->label,p->symbol,p->addr);
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
        fprintf(oFile,".\n\tLABEL\t\tSYMBOL\t\tADDRESS\n");
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

    struct SymbTab *p = {0};
    p=malloc(sizeof(struct SymbTab));

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
        p=malloc(sizeof(struct SymbTab));
        strcpy(p->label,x1);

        x1 = (char*) malloc(10);
        fscanf(iFile,"%s",&x);
        for(i=0 ; i<strlen(x) ; i++)
        {
            x1[i] = x[i] ;
        }
        x1[i] = '\0' ;
        strcpy(p->symbol,x1);
        for(i=0 ; i<strlen(x) ; i++)
        {
            check[i] = x[i] ;
        }
        check[i] = '\0' ;

        x1 = (char*) malloc(10);
        fscanf(iFile,"%d",&y);
        p->addr = y;

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
    struct SymbTab *p;
    p=first;
    for(i=0;i<size;i++)
    {
        if(strcmp(p->label,lab)==0)
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
    struct SymbTab *p;
    p=first;
    printf("\n\tWhat do you want to modify?\n");
    printf("\n\t1.Only the label\n\t2.Only the address\n\t3.Both the label and address\n");
    printf("\tEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("\n\tEnter the old label : ");
            scanf("%s",l);
            s=tableSearch(l,-1);

            if(s==0)
                printf("\n\tLabel not found\n");

            else
            {
                printf("\n\tEnter the new label : ");
                scanf("%s",nl);
                for(i=0;i<size;i++)
                {
                    if(strcmp(p->label,l)==0)
                    strcpy(p->label,nl);
                    p=p->next;
                }
                printf("\n\tAfter Modification:\n");
                tableFullWriteInFile() ;
                tableDisplay();
            }
        break;
        case 2:
            printf("\n\tEnter the label where the address is to be modified : ");
            scanf("%s",l);
            s=tableSearch(l,-1);
            if(s==0)
            printf("\n\tLabel not found\n");
            else
            {
                printf("\n\tEnter the new address : ");
                scanf("%d",&add);

                for(i=0;i<size;i++)
                {
                    if(strcmp(p->label,l)==0)
                    p->addr=add;
                    p=p->next;
                }
                printf("\n\tAfter Modification:%dW\n",first->addr);
                tableFullWriteInFile() ;
                tableDisplay();
            }
        break;
        case 3:
            printf("\n\tEnter the old label : ");
            scanf("%s",l);
            s=tableSearch(l,-1);

            if(s==0)
                printf("\n\tLabel not found\n");

            else
            {
                printf("\n\tEnter the new label : ");
                scanf("%s",nl);
                printf("\n\tEnter the new address : ");
                scanf("%d",&add);
                for(i=0;i<size;i++)
                {
                    if(strcmp(p->label,l)==0)
                    {
                        strcpy(p->label,nl);
                        p->addr=add;
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
    struct SymbTab *p,*q;
    p=first;
    printf("\n\tEnter the label to be deleted : ");
    scanf("%s",l);
    a=tableSearch(l,-1);
    if(a==0)
    printf("\n\tLabel not found\n");
    else
    {
        if(strcmp(first->label,l)==0)
        first=first->next;

        else if(strcmp(last->label,l)==0)
        {
            q=p->next;
            while(strcmp(q->label,l)!=0)
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
        while(strcmp(q->label,l)!=0)
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




