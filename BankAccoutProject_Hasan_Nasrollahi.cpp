#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>    //  header file for gotoxy
#include <iostream> //header file for standard input output

using namespace std;



COORD coord= {0,0}; // this is global variable
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


void enter();                     // تابع دریافت اطلاعات
void trans();                     // ثبت تراکنش های جدید
void maxBal();                    // بیشترین موجودی
void report();                    // گزارش گیری از وضعیت حساب
void closeacc();                  // بستن اکانت
int menu();                       // نمایش منوی مدیریت برنامه

struct Customer
{
    int stat ;                    // فیل وضعیت رکورد
    char name[21];                // نام مشتری
    int bal;                      // موجودی
    int account;                  // شماره حساب
    int kind;                     // نوع حساب

};

int main()
{
int menuselection ;
   do
    {

       system("cls");
       menuselection = menu ();

       switch(menuselection)
       {
           case 1: enter(); break ;
           case 2: trans(); break ;
           case 3: maxBal(); break ;
           case 4: closeacc();; break ;
           case 5: report(); break ;
           default: cout << "pls Enter a valid number from 1 - 6 ...! \n press a key to continue " << endl;getch(); break ;
       }

    }while(menuselection != 6);

}


int menu()
{
    cout << "*******************************************" <<endl ;
    cout << "1. Enter data :" << endl ;
    cout << "2. Transaction :" << endl ;
    cout << "3. Maximum banace :" << endl ;
    cout << "4. Close customer account :" << endl ;
    cout << "5. Report information :" << endl ;
    cout << "6. Terminate program :" << endl ;
    cout << "*******************************************" <<endl ;

    cout << "Enter your selection (1 - 6) : " <<endl ;
    int p ;
    cin >> p ;
    cin.get();



    return p ;
}
//تابع افتتاح حساب
void enter()
{
    system("cls");
    Customer cust ;
    fstream file ;
    file.open("text.abc",ios::out | ios::in | ios::binary);
    if (!file)
    {
        file.open("text.abc",ios::out  | ios::binary);
        if(!file)
            cout << "Error opening file .. " <<endl ;

        else cout << "file successfully created ! "  ;

    }
    else
    {
        cout << "Name:         Balance:        Account# :        kind ( 1 or 2 ) :" <<endl;
        gotoxy(1 , 2);
        cin.getline(cust.name , 20) ;
        gotoxy(20 , 2);
        cin>>cust.bal ;
        gotoxy(35 , 2);
        cin>>cust.account;
        gotoxy(45 , 2);
        cin>>cust.kind;
        //باز کردن حساب جدید
        cust.stat=1;



        file.seekp(sizeof(struct Customer) * cust.account , ios::beg) ;
        file.write((char *)&cust , sizeof(struct Customer));
        file.close();

    }
    cout << "press a key to continue ..." ;

getch();



}
//تابع گزارش گیری
void report()
{
    system("cls");

    cout << "Name:         Balance:        Account# :        kind ( 1 or 2 ) :" <<endl;
    ifstream file ;
    file.open("text.abc" , ios::in |ios::binary);
    if(!file)
    {
        cout << "Error opening file ..." <<endl ;
    }

    else {
            Customer cust ;
            int row = 2 ;
            while(file.read((char *)&cust        ,          sizeof(struct Customer)  )       )
            {
                if(cust.stat == 1)
                {
                    gotoxy(1 , row);
                cout<<cust.name ;
                gotoxy(20 , row);
                cout<<cust.bal ;
                gotoxy(35 , row);
                cout<<cust.account;
                gotoxy(45 , row);
                cout<<cust.kind;
                row++ ;
                }

            }

        //باز کردن حساب جدید
      //  cust.stat=1;
        file.close();


        }
        cout << "\npress a key to continue ....";
        getch();

}
//تابع بستن حساب

void closeacc()
{
    int acnum ;
    Customer cust ;
    cout << "Enter an account number for close : " <<endl ;
    cin >> acnum ;
    fstream file ;
    file.open("text.abc" , ios::out | ios::in | ios::binary);
    if(!file)
    {
        cout<< "Error opening file ... " <<endl ;
    }
    else
    {
        file.seekg(sizeof(struct Customer)* acnum , ios::beg);
        file.read((char *)&cust , sizeof(struct Customer));
        if(cust.stat == 1)
        {
        cust.stat = 0 ;
        file.seekp(sizeof(struct Customer)* acnum , ios::beg);
        file.write((char *)&cust , sizeof(struct Customer));
        cout << "Account successfully close !" <<endl ;
        }
        else cout << "Account not exist !" <<endl;

        file.close();

    }
    getch();
}

void trans()
{
    int acnum , amount ;
    char tran ;
    Customer cust ;
    system("cls");
    cout << "Enter accoutn number to change balance : " ;
    cin >> acnum ;

    fstream file ;
    file.open("text.abc" , ios::out | ios::in | ios::binary);
    if(!file)
    {
        cout<< "Error opening file ... " <<endl ;
    }
    else
    {
        //خواندن یک بلوک از اطلاعات و ذخیره در متغیر کاست
        file.seekg(sizeof(struct Customer)* acnum , ios::beg);
        file.read((char *)&cust , sizeof(struct Customer));

        cout << "Do you want to increament (i) or decrement (d :)" ;
        cin >> tran ;
        cout << "Enter amount to decrement or increment : " ;
        cin >> amount ;
        int doSave = 0 ;
        switch(tran)
        {
             case 'i':
                  cust.bal+=amount ;
                  doSave = 1 ;
                  break ;

             case 'd':
                if (cust.bal < amount)
                {
                    cout << "Blanace is less than amount , can not change balance !" ;
                }
                else {
                    cust.bal -= amount ;
                    doSave = 1 ;
                }
                break ;
              default : "Error Please cose i for increament or d for decrement !" ;

        }
        if (doSave ==1)
        {
            file.seekp(sizeof(struct Customer) * acnum , ios ::beg);
            file.write((char *)&cust , sizeof(struct Customer));
            cout << "Balance successfully changed ." ;
        }
          cout << "press a key to continue ..." << endl ;
          getch();
      }

    }




void maxBal()
{
    int r = 2 ;
    system("cls");
    Customer cust , cust1 ;
    cust1.bal = 0;
    fstream file ;
    file.open("text.abc" , ios::out | ios::in | ios::binary) ;
    if(!file)
    {
        cout << "Error opening file..." << endl ;
    }
    else
    {
        while (file.read((char *)&cust , sizeof(struct Customer)))
        {
            if(cust.stat == 1)
            {
                if(cust.bal > cust1.bal)
                {
                    cust1 = cust ;
                }
            }
        }

        cout << "name            balance            account3            kind(1,2)" ;
        gotoxy(1,r);
        cout << cust1.name ;
        gotoxy(20,r);
        cout << cust1.bal ;
        gotoxy(35,r);
        cout << cust1.account ;
        gotoxy(55,r);
        cout <<cust1.kind;
        getch();
    }
}










