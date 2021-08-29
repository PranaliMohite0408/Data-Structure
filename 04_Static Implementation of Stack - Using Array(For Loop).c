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
    char ch ='\0';
    int choice=0, Ele='\0';

    for(;;)                                      ///While(1)
    {


        printf("\n=========****** STACK ******============\n");

        printf("\n Select Choice: \n\n\t01.Push \n\t02.POP \n\t03.Display Stack\n\t04.Search Element\n\t05.Count Element\n\t06.Exit \n");

        printf("\n=============*****************================\n");

        printf("\nEnter Your Choice :");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                    printf("\nEnter Element to be Inserted in Stack =");
                    scanf("%d",&Ele);
                    Push(Ele);
                    getch();

                    system("cls");
                    break;

            case 2:
                    Pop();
                    getch();

                    system("cls");
                    break;

            case 3:
                    Display_Stack();
                    getch();

                    system("cls");
                    break;

            case 4:
                    Search_Element_In_Stack();
                    getch();

                    system("cls");
                    break;

            case 5:
                    printf("\nNo of Element Currently in Stack are = %d",Count_Element_In_Stack());
                    getch();

                    system("cls");
                    break;

            case 6 :
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

        }
    }

       DWN:
           printf("\nThanks for Using Service!!! Have a Nice Day!!!");
           printf("\n#Pres Any Key To Exit...\n\n");


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

        printf("\n\nElement %d Inserted in Stack Successfully!!!",Ele);
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
