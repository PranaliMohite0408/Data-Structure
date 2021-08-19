#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define Size 7

void Push(int Ele);
void Pop();
int Is_Stack_Empty();
int Is_Stack_Full();
void Display_Stack();

int Stack[Size] = {0};
int Top = 0;

int main()
{
    printf("\n=====**** STACK ****========\n");

    Pop();

    Push(22);
    Push(23);
    Push(24);
    Push(25);
    Push(26);

    Pop();

    getch();
    system("cls");

    Display_Stack();

    system("cls");
    getch();

    Pop();

    Push(27);
    Push(28);
    Push(29);
    Push(30);

    Display_Stack();

    getch();
    return;
}

void Push(int Ele)
{
    int Ret = Is_Stack_Full();

    if(1 == Ret)
    {
        printf("\n Stack is Already Full Cannot Push new Element!!!");
    }
    else
    {
        Stack[Top] = Ele;
        Top++;

        printf("\nelement %d Inserted in Stack Successfully!!!",Ele);
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
         printf("\n Stack is Already Empty Cannot Pop any Element!!!");
     }
     else
     {
        Top--;
        printf("\n Removed Element From Stack is = %d.", Stack[Top]);
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
