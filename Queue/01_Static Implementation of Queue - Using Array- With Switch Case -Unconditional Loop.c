#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define Size 7

void Enqueue(int Ele);
void Dequeue();
int Is_Queue_Full();
int Is_Queue_Empty();
void Display_Queue();
int Count_Element_In_Queue();
void Search_Element_Queue();
int Peek();

///declare queue

int Queue[Size] = {0};
int front=0;
int Rare=0;

int main()
{
    char ch='\0';
    int choice =0, Ele=0;

    while(1)
    {
        printf("\n===========FORK QUEUE==========");

        printf("\n Select Choice: \n\n\t01.Enqueue \n\t02.Dequeue \n\t03.Display Queue\n\t04.Search Element\n\t05.Count Element\n\t06.Peek \n\t07.Exit \n");

        printf("\n=============*****************================\n");

        printf("\nEnter Your Choice :");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                    printf("\nEnter Element to be Inserted in Queue =");
                    scanf("%d",&Ele);
                    Push(Ele);
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
                    Search_Element_Queue();
                    getch();

                    system("cls");
                    break;

            case 5:
                    printf("\nCount of Element in Queue is = %d",Count_Element_In_Queue());
                    getch();
                    system("cls");
                    break;

            case 6 :
                    printf("\nTop Most Element In Queue is = %d",Peek());
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
                    printf("\nInvalid Input!!! Please Enter Valid choice...");

                    getch();
                    system("cls");
                    break;



        getch();
        return;

}
void Enqueue(int Ele)
{
    int Ret = Is_Queue_Full();

    if(1==Ret)
    {
        printf("\nQueue is Full...We Cannot Enqueue The New Element!!!!");
    }
    else
    {
        printf("\nThe New Element %d Enqueue Successfully!!!",Ele);
        Rare++;
    }
}
 int Is_Queue_Full()
{
    int Ret =0;

    if(Rare == Size)
    {
        Ret =1;

    }
    return Ret;

}
void Dequeue()
{
    int Ret = Is_Queue_Empty();

    if(1==Ret)
    {
        printf("\nQueue is Already Empty...We Cannot Dequeue Any Element...");
    }
    else
    {
        printf("\nremoved element from Queue is = %d",Queue[front]);
    }
    return;
}

int Peek()
{
    int Ret=Is_Queue_Empty();

    if(1==Ret)
    {
        printf("\nQueue is Already Empty cannot find Peek Element!!!");
    }
    else
    {
        printf("\nTop Most Element in Queue is %d",Queue[front]);
    }
    return;
}

int Is_Queue_Empty()
{
    int Ret = 0;

    if(front==Rare)
    {
        Ret=1;
    }

    return;
}

void Display_Queue()
{
    int Ret= Is_Queue_Empty();
    int i=0;

    if(1==Ret)
    {
        printf("\nQueue is Already Empty..No Element To Display");
    }
    else
    {
        for(i=front;i<Rare;i++)
        {
            printf("\t |%d|", Queue[i]);
        }
    }

    return;
}

int Count_Element_In_Queue()
{
    return Rare - front;
}

void Search_Element_Queue()
{
    int Src_Ele=0, i=0;

    if(Is_Queue_Empty())
    {
        printf("\nQueue is Already Empty...No Element to Display");

    }
    else
    {
        printf("\nEnter an Element to Search in Queue=>");
        scanf("%d",&Src_Ele);

        for(i=front;i<Rare;i++)
        {
            if(Src_Ele==Queue[i]);
            {
                break;
            }
        }

        if(i == Rare)
        {
            printf("\n\nGiven Element %d Not Found in Queue",Src_Ele);
        }
        else
        {
            printf("\n\nGiven Element %d Found at Location %d in Queue",Src_Ele,i+1);
        }

    }

     return ;

}




