#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define Size 7

void Push(int Ele);
void Pop();
int Is_Stack_Empty();
int Is_Stack_Full();
void Display_Stack();
int Count_Element_In_Stack();
void Search_Element_In_Stack();

int Stack[Size] = {0};
int Top = 0;

int main()
{
    printf("\n=========****** STACK ******============\n");

    Pop();

    Push(30);
    Push(31);
    Push(32);
    Push(33);
    Push(34);

    Pop();

    getch();
    system("cls");

    Display_Stack();

    printf("\n Number of Element Currently in Stack are = %d",Count_Element_In_Stack());

    system("cls");
    getch();

    Pop();

    Push(35);
    Push(36);
    Push(37);
    Push(38);

    Display_Stack();

    Search_Element_In_Stack();

    Pop();

    Push(40);

    Display_Stack();

    getch();

    printf("\n Number of Element Currently in Stack are = %d",Count_Element_In_Stack());

    Search_Element_In_Stack();

    getch();
    return;
}

void Push(int Ele)
{
    int Ret = Is_Stack_Full();

    if(1 == Ret)
    {
        printf("\n\nStack is Already Full Cannot Push new Element!!!");
    }
    else
    {
        Stack[Top] = Ele;
        Top++;

        printf("\n\n element %d Inserted in Stack Successfully!!!",Ele);
    }
}

int Is_Stack_Full()
{
    int Ret = 0;

    if(Top == Size)
    {
        Ret = 1;
    }
    return Ret;
}

int Is_Stack_Empty()
{
    int Ret = 0;

    if(Top == 0)
    {
        Ret = 1;
    }
    return Ret;
}

 void Pop()
 {
     int Ret = Is_Stack_Empty();

     if(1== Ret)
     {
         printf("\n\n Stack is Already Empty Cannot Pop any Element!!!");
     }
     else
     {
        Top--;
        printf("\n\n Removed Element From Stack is = %d.", Stack[Top]);
     }
 }

 void Display_Stack()
 {
     int Ret = Is_Stack_Empty();

     if(1 == Ret)
     {
         printf("\n Stack is Already Empty, No Element To Display!!!");
     }
     else
     {
        printf("\n Elements in Stack Are => \n");

        int i =0;

        for(i = Top-1 ; i>= 0; i--)
        {
            printf("\n\t\t | %d |", Stack[i]);
        }
     }
 }
 int Count_Element_In_Stack()
 {
     return Top;
 }

void Search_Element_In_Stack()
{
    int Src_Ele = 0,i=0;

    if(Is_Stack_Empty())
    {
        printf("\n Stack is Already Empty Cannot Pop any Element!!!");
    }
    else
    {
        printf("\n\nEnter a Element for Searching :");
        scanf("%d",&Src_Ele);

        for(i=0; i<Top ; i++)
        {
            if(Src_Ele == Stack[i])
            {
                break;
            }
        }

        if(i == Top)
        {
            printf("\n\nGiven Element %d Not Found in Stack",Src_Ele);
        }
        else
        {
            printf("\n\nGiven Element %d Found at Location %d in Stack",Src_Ele,i+1);
        }
    }
    return ;
}
