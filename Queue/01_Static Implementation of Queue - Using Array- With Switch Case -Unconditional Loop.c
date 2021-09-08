#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define Size 7

void Enqueue(int Ele);
void Dequeue();
void Peek();
int Is_Queue_Full();
int Is_Queue_Empty();
void Display_Queue();
int Count_Element_In_Queue();
void Search_Element_In_Queue();

///declare queue
int Queue[Size]={0};
int Front=0;
int Rear=0;

int main()
{
    char ch='\0';
    int choice =0, Ele=0;

    while(1)
    {
        printf("\n===========FORK QUEUE==========");

        printf("\n Select Choice: \n\n\t01.Enqueue \n\t02.Dequeue \n\t03.Display Queue\n\t04.Search Element\n\t05.Count Element\n\t06.Peek \n\t07.Exit \n");

        printf("\n=============************================\n");

        printf("\nEnter Your Choice :");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                    printf("\nEnter Element to be Inserted in Queue =");
                    scanf("%d",&Ele);
                    Enqueue(Ele);
                    getch();
                    system("cls");
                    break;

            case 2:
                    Dequeue();
                    getch();
                    system("cls");
                    break;

            case 3:
                    Display_Queue();
                    getch();
                    system("cls");
                    break;

            case 4:
                    Search_Element_In_Queue();
                    getch();
                    system("cls");
                    break;

            case 5:
                    printf("\n No. of elements currently in Queue are=%d",Count_Element_In_Queue());
                    getch();
                    system("cls");
                    break;

            case 6 :
                    Peek();
                    getch();
                    system("cls");
                    break;

           case 7:
                    fflush(stdin);
                    printf("\nAre You Sure?? Do You Want to Exit??(Yes/NO) =");
                    ch = getchar();

                    if(ch=='Y' || ch=='y')
                    {
                        goto DWN;
                    }

                    fflush(stdin);
                    system("cls");
                    break;

           default:
                    printf("\n Invalid Input!!! Please Enter Valid choice...");
                    getch();
                    system("cls");
                    break;

        }
    }

    DWN:
        printf("\nThanks for Using Service!!! Have a Nice Day!!!");
        printf("\n Press Any Key To Exit...\n\n");
        getch();
        return 0;
}

void Enqueue(int Ele)
{
    int Ret = Is_Queue_Full();

    if(1==Ret)
    {
        printf("\nQueue is Full.. Can't Enqueue The New Element!!!!");
    }
    else
    {
        Queue[Rear]=Ele;
        Rear++;
        printf("\nThe New Element %d Inserted Successfully!!!",Ele);
    }
    return;
}

int Is_Queue_Full()
{
    int Ret =0;

    if(Rear == Size)
    {
        Ret =1;
    }
    return Ret;
}

void Dequeue()
{
    int Ret = Is_Queue_Empty();

    if(1 == Ret)
    {
        printf("\nQueue is Already Empty Cannot Dequeue Any Element!!!");
    }
    else
    {
        printf("\n Removed Element From Queue is = %d .",Queue[Front]);

        Queue[Front] =0;
        Front++;
    }
    return;
}

void Peek()
{
    int Ret=Is_Queue_Empty();

    if(1==Ret)
    {
        printf("\nQueue is Already Empty cannot find Peek Element!!!");
    }
    else
    {
        printf("\nTop Most Element in Queue is %d",Queue[Front]);
    }
    return;
}

int Is_Queue_Empty()
{
    int Ret = 0;

    if(Front == Rear)
    {
        Ret = 1;
    }
    return Ret;
}

void Display_Queue()
{
    int Ret = Is_Queue_Empty();
    int i=0;

    if(1==Ret)
    {
        printf("\nQueue is Already Empty..No Element To Display");
    }
    else
    {
        printf("\n=============************================\n");
        printf("\n Elements in Queue are = \n\n");

        for(i=Front; i<Rear; i++)
        {
            printf("\t | %d |", Queue[i]);
        }
    }
    return;
}

int Count_Element_In_Queue()
{
    return Rear-Front;
}

void Search_Element_In_Queue()
{
    int Src_Ele=0;
    int i=0;

    if(Is_Queue_Empty())
    {
        printf("\nQueue is Already Empty...No Element to Search!!!");
    }
    else
    {
        printf("\nEnter an Element to Search in Queue=>");
        scanf("%d",&Src_Ele);

        for(i=Front; i<Rear; i++)
        {
            if(Src_Ele==Queue[i])
            {
                break;
            }
        }

        if(i == Rear)
        {
            printf("\n\nGiven Element %d Not Found in Queue\n",Src_Ele);
        }
        else
        {
            printf("\n\nGiven Element %d Found at Location %d in Queue",Src_Ele,i+1);
        }
    }
     return ;
}
