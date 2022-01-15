#include<iostream> //for cin and cout
#include<iomanip>  //for setw setfil setprecision
#include<cstdlib> //for rand and srand  and to change color of ouput
#include<conio.h> //to make the program pause when the setup only runs
#include<ctime>   // to use time with srand like unsigned seed=time();   srand(seed);
#include <windows.h>
#include <stdio.h>

/**#include "Dataman.h"
#include "DataMan.cpp"*/
using namespace std;

void SetColor(int ForgC);
void transfer();
void withdraw();
void checkBalance();
void fastCash();
void changePin();
void exit();
void intro();
void ExitOrContinue();

int main()
{
system("color 5E");
SetColor(15);
 cout <<"\t\t\t__      __   ___  | |   ___    ___    _ __ ___     ___  "<<endl;
 cout <<"\t\t\t\\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ "<<endl;
 cout <<"\t\t\t \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ "<<endl;
 cout <<"\t\t\t  \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| "<<endl;


SetColor(3);


    cout<<setw(120)<<setfill('*')<<"*"<<endl<<endl;
    cout<<"COMMERCIAL BANK OF ETHIOPIA "<<setw(80)<<setfill(' ')<<"YOUR SATISIFICATION IS OUR PROFIT"<<endl<<endl;
    cout<<setw(120)<<setfill('*')<<"*"<<endl<<endl;
    system("pause");
    system("cls");
    int password;
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPLEASE ENTER YOUR PASSWORD  : "  ;
    cin>>password;
    system("cls");
    intro();
    return 0;
}

void intro()
{
SetColor(3);
    cout<<setw(90)<<setfill('*')<<"*"<<endl<<endl;
    cout<<"\t\t\tWELLCOME TO COMMERCIAL BANK OF ETHIOPIA"<<endl<<endl;
    cout<<setw(90)<<setfill('*')<<"*"<<endl<<endl;
    cout<<"1 WITHDRAW\t\t\t\t\t\t\t4 CHECK YOUR BALANCE\n\n\n\n\n"<<endl;
    cout<<"2 TRANSFER\t\t\t\t\t\t\t5 CHANGE PIN NUMBER\n\n\n\n\n"<<endl;
    cout<<"3 FAST CAHS 100\t\t\t\t\t\t\t6 EXIT\n\n\n\n\n"<<endl;
    int choice;
    cout<<"\t\t\tPLEASE ENTER YOUR CHOICE :";
    cin>>choice;
    system("cls");
    switch(choice)
    {
    case 1:
         withdraw();
        break;
    case 2:
         transfer();
         break;

    case 3:
        fastCash();
        break;
    case 4:
        checkBalance();
        break;
    case 5:
        changePin();

        break;
    case 6:
        exit();
        break;

    }

}


void withdraw()
{

float amount;
char choice;
       cout <<"\n\n\n";
       cout << "\t\t\tA.100\t\t\t\t\t\t\tC.200\n\n\n\n\n"<<endl;
       cout << "\t\t\tB.500\t\t\t\t\t\t\tD.1000\n\n\n\n\n"<<endl;
       cout << "\t\t\tE.OTHER OPTION\n\n\n\n\n"<<endl;
       cout <<"\t\t\t\tENTER YOUR CHOICE  : ";
       cin  >> choice;

    system("cls");
    switch (choice)
      {
        case 'a':
        case 'A':
            amount = 100;
             break;

        case 'c':
        case 'C':
            amount = 200;
             break;

        case 'b':
        case 'B':
            amount =500;
             break;

        case 'd':
        case 'D':
             amount =1000;
             break;
        case 'e':
        case 'E':
        cout<<"PLEASE ENTER THE AMMOUNT"<<endl;
        cin>>amount;
           while (amount<50||amount>5000)
           {
            system("cls");

               cout<<"PLEASE ENTER BETWEEN 50 AND 5000 BIRR"<<endl;
               cout<<"PLEASE ENTER THE AMMOUNT"<<endl;
           cin>>amount;
           }
           break;


      }
       cout<<"\n\n\t\tYOU HAVE WITHDRAWN : "<<amount<<" BIRR"<<endl;
       system("pause");
       system("cls");
    ExitOrContinue();


	cout<<endl<<endl;


	}


void ExitOrContinue()
{
       int decide;
       cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t1.CONTINUE\n\n\n\n\n\n\t\t\t\t\t2.EXIT\n\n\n\n\n\n"<<endl;
       cout<<"ENTER YOUR CHOICE : ";
       cin>>decide;
       system("cls");
       switch(decide)
       {
       case 1:
           intro();
           system("cls");
           break;
       case 2:
        cout<<"THANKS FOR USING OUR SERVICE"<<endl;
        break;
       }
}
void transfer()
 {
    int amount,accNo;
    cout<<"ENTER THE ACCOUNT NUMBER YOU WANT THE MONEY TO BE TRANSFERED"<<endl;
    cin>>accNo;
    cout<<"ENTER THE AMOUNT OF MONEY YOU WANT TO TRANSFER"<<endl;
    cin>>amount;
    system("cls");
    cout<<"YOUR TRANSACTION HAS BEEN SUCCSESSFULLY COMPLETED\n\n"<<endl;
    cout<<"YOU HAVE TRASFERED "<<amount<<"ETB"<<" TO THE ACCOUNT NUMBER "<<accNo<<endl;
    system("pause");
    system ("cls");
    ExitOrContinue();
 }
void checkBalance()
 {
    cout<<"YOU'RE CURRENT AMMOUNT IS "<<endl;
    system("pause");
    system("cls");
    ExitOrContinue();
 }

void fastCash()
{
   cout<<"YOU'VE  SUCCESFULL WITHDRAW 100 ETB "<<endl;
   system("pause");
   system("cls");
   ExitOrContinue();
}

void exit()
{
    cout<<"THANKS FOR USNG OUR BANK"<<endl;

}


void changePin()
{
    int oldPin,newPin1,newPin2;
    cout<<"WRITE YOUR CURRENT PIN"<<endl;
    cin>>oldPin;
    cout<<"WRITE YOUR NEW PIN"<<endl;
    cin>>newPin1;
    cout<<"RE-ENTER YOUR NEW PIN"<<endl;
    cin>>newPin2;
    system("cls");

    if(newPin1!=newPin2)
    {
         for(int i =0;i<2;i++)
          {
             system("cls");
             cout<<"NEW PIN NUMBERS DOES NOT MUCH"<<endl;
             cout<<"WRITE YOUR NEW PIN AGAIN "<<endl;
             cin>>newPin1;
             cout<<"RE-ENTER YOU'RE NEW PIN"<<endl;
             cin>>newPin2;
             if(newPin1 == newPin2)
                {
                   cout<<"you have changed your pin "<<endl;
                   break;
                }
             else
                {
                   cout<<"you have  reached 3 trial "<<endl;
                }
          }
    }
    else
    {
         cout<<"you have changed your pin";
    }
}































































void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word


if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

