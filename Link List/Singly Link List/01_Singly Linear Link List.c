#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
};

int main()
{
    struct Node *Head=NULL;

    Delete_First(&Head);

    getch();

    Insert_First(&Head,11);
    Insert_First(&Head,12);
    Insert_First(&Head,13);
    Insert_First(&Head,14);
    Insert_First(&Head,15);
    Insert_First(&Head,16);
    Insert_First(&Head,17);
    Insert_First(&Head,18);

    Display_LL(Head);
    getch();

    Delete_First(&Head);
    Delete_First(&Head);

    Insert_First(&Head,19);

    Display_LL(Head);

    getch();

    Delete_Last(&Head);
    Delete_Last(&Head);

    getch();

    Insert_First(&Head,50);
    Insert_First(&Head,60);
    Insert_First(&Head,70);

    Display_LL(Head);

    getch();

    Delete_Last(&Head);
    Delete_Last(&Head);

    Display_LL(Head);

    getch();
    return 0;
}

void Insert_First(struct Node **First, int Ele)
{
    struct Node *NewN = NULL;

    NewN = (struct Node*) malloc (sizeof(struct Node));

    if(NULL == NewN)
    {
        printf("\n\n Node Creation Denied...Some Memory Level Issue...");
        return;
    }

    NewN->Data=Ele;
    NewN->Next=NULL;

    if(*First == NULL)
    {
        *First=NewN;
    }
    else
    {
        NewN->Next=*First;
        *First=NewN;
    }

    return ;
}

void Display_LL(struct Node* First)
{
    if(NULL == First)
    {
        printf("\nLink List Already Empty,No Element to Display...");
    }
    else
    {
        printf("\n\nElements in Link List are=>");

        while(First != NULL)
        {
            printf("| %d | -> ",First->Data);
            First = First->Next;
        }
        printf(" NULL");
    }

    return ;
}

void Delete_First(struct Node **First)
{
    struct Node *Temp = *First;

    if(NULL == *First)
    {
        printf("\nLink List is  Already Empty,No Element To Delete\n");
        return ;
    }

    if(NULL == Temp->Next)
    {
        *First = NULL;
    }
    else
    {
        *First = Temp->Next;
    }

    printf("\n\nRemoved Element From Link List = %d",Temp->Data);
    free(Temp);
    return ;
}
void Insert_Last(struct Node **First, int Ele)
{
    struct Node *NewN = NULL;

   NewN = (struct Node*) malloc (sizeof(struct Node));

    if(NULL == NewN)
    {
        printf("\nMemory Not Allocated,Some Memory Level Issue...\n");
        return ;
    }

    NewN->Data = Ele;
    NewN->Next = NULL;

    if(NewN->Next == NULL)
    {
        *First = NewN;
    }
    else
    {
        struct Node *Temp = *First;

        while(Temp->Next != NULL)
        {
            Temp=Temp->Next;
        }
        Temp->Next = NewN;
    }
    return ;
}

void Delete_Last(struct Node **First)
{
    struct Node *Temp = *First;

    if(*First == NULL)
    {
        printf("\n\nGiven Link List Empty Node is not Available to Delete");
        return 0;
    }
    if(Temp->Next == NULL)
    {
        *First = NULL;
    }
    else
    {
        while((Temp->Next)->Next != NULL )
        {
            Temp = Temp->Next;
        }
        printf("\n\nWe Remove the Element %d",(Temp->Next)->Data);

        free(Temp->Next);
        Temp->Next = NULL;
    }

    return ;
}

