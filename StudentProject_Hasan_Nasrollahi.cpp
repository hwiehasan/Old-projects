#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>    //  header file for gotoxy
#include <iostream>     //header file for standard input output

//HASAN NASROLLAHI

using namespace std;


COORD coord= {0,0}; // this is glomark variable
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void enterInfo();               // تابع دریافت اطلاعات
void editInfo();                // ویزایش اطلاعات
void maxMark();                 // بالاترین معدل
void showInfo();                // نمایش اطلاعات
void closeAcc();                // بستن اکانت
int menu();                     // نمایش منوی مدیریت برنامه
void studentSearch();           //جستجوی دانشجو
void minMark();                 //پایین ترین معدل
void avgMark();                 //میانگین معدل ها

struct Daneshju
{
    int stat ;                    // فیل وضعیت رکورد
    char name[21];                // نام مشتری
    int mark;                     // معدل دانشجو
    int id;                       // شماره دانشجویی
    int gender;                      // جنسیت 1 اقا 2 خانم
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
           case 1: enterInfo(); break ;
           case 2: editInfo(); break ;
           case 3: closeAcc();; break ;
           case 4: showInfo(); break ;
           case 5: studentSearch(); break ;
           case 6: maxMark(); break ;
           case 7: minMark(); break ;
           case 8: avgMark(); break ;
           default: cout << "Lotfan yek adad bain 1 - 9 vared konid...! \n Press a key to continue " << endl;getch(); break ;
       }

    }while(menuselection != 9);

}


int menu()
{
    cout << "*******************************************" <<endl ;
    cout << "1. Enter Information :" << endl ;
    cout << "2. Edit Information :" << endl ;
    cout << "3. Close Student Account by ID :" << endl ;
    cout << "4. Show information :" << endl ;
    cout << "5. Find Student by ID :" << endl ;
     cout <<"6. Maximum Mark :" << endl ;
    cout << "7. Minimum Mark :" << endl ;
    cout << "8. Average Mark :" << endl ;
    cout << "9. Terminate program :" << endl ;
    cout << "*******************************************" <<endl ;

    cout << "Enter your selection (1 - 9) : " <<endl ;
    int p ;
    cin >> p ;
    cin.get();

    return p ;
}
//تابع ورود اطلاعات
void enterInfo()
{
    system("cls");
    Daneshju student ;
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
        cout << "Name:         mark:        id# :        gender ( 1 or 2 ) :" <<endl;
        gotoxy(1 , 2);
        cin.getline(student.name , 20) ;
        gotoxy(20 , 2);
        cin>>student.mark ;
        gotoxy(35 , 2);
        cin>>student.id;
        gotoxy(45 , 2);
        cin>>student.gender;
        student.stat=1;



        file.seekp(sizeof(struct Daneshju) * student.id , ios::beg) ;
        file.write((char *)&student , sizeof(struct Daneshju));
        file.close();

    }
    cout << "press a key to continue ..." ;

getch();



}
//نمایش
void showInfo()
{
    system("cls");

    cout << "Name:         mark:        id# :        gender ( 1 or 2 ) :" <<endl;
    ifstream file ;
    file.open("text.abc" , ios::in |ios::binary);
    if(!file)
    {
        cout << "Error opening file ..." <<endl ;
    }

    else {
            Daneshju student ;
            int row = 2 ;
            while(file.read((char *)&student        ,          sizeof(struct Daneshju)  )       )
            {
                if(student.stat == 1)
                {
                    gotoxy(1 , row);
                cout<<student.name ;
                gotoxy(20 , row);
                cout<<student.mark ;
                gotoxy(35 , row);
                cout<<student.id;
                gotoxy(45 , row);
                cout<<student.gender;
                row++ ;
                }

            }
        file.close();


        }
        cout << "\npress a key to continue ....";
        getch();

}

//تابع بستن حساب
void closeAcc()
{
    int idnum ;
    Daneshju student ;
    cout << "Enter an id number for close : " <<endl ;
    cin >> idnum ;
    fstream file ;
    file.open("text.abc" , ios::out | ios::in | ios::binary);
    if(!file)
    {
        cout<< "Error opening file ... " <<endl ;
    }
    else
    {
        file.seekg(sizeof(struct Daneshju)* idnum , ios::beg);
        file.read((char *)&student , sizeof(struct Daneshju));
        if(student.stat == 1)
        {
        student.stat = 0 ;
        file.seekp(sizeof(struct Daneshju)* idnum , ios::beg);
        file.write((char *)&student , sizeof(struct Daneshju));
        cout << "id successfully close !" <<endl ;
        }
        else cout << "ID Does Not Exists !" <<endl;

        file.close();

    }
    cout << "\nPress a key to continue " << endl;getch();
}

void editInfo()
{
    int idnum , amount ;
    char edit ;
    Daneshju student;
    system("cls");
    cout << "Enter Student number to change information : " ;
    cin >> idnum ;

    fstream file ;
    file.open("text.abc" , ios::out | ios::in | ios::binary);
    if(!file)
    {
        cout<< "Error opening file ... " <<endl ;
    }
    else
    {
        //خواندن یک بلوک از اطلاعات و ذخیره در متغیر کاست
        file.seekg(sizeof(struct Daneshju)* idnum , ios::beg);
        file.read((char *)&student , sizeof(struct Daneshju));

        cout << "If you want to change Name press(n) / to change Student ID press (i) / to change Mark press (m) :" ;
        cin >> edit ;
       // cout << "Enter amount  : " ;
        //cin >> amount ;
        int doSave = 0 ;
        switch(edit)
        {
             case 'i':
                  cout << "Enter amount  : " ;
                  cin >> amount ;
                  student.id=amount ;
                  doSave = 1 ;
                  break ;

             case 'n':
                cout << "Enter amount  : " ;
                cin >> student.name ;
                doSave = 1 ;
                break ;

            case 'm':
                  cout << "Enter amount  : " ;
                  cin >> amount ;
                  student.mark=amount ;
                  doSave = 1 ;
                  break ;

              default : "Wrong value (n) for Name - (i) for ID - (m) for Mark !" ;

        }
        if (doSave==1)
        {
            file.seekp(sizeof(struct Daneshju) * idnum , ios ::beg);
            file.write((char *)&student , sizeof(struct Daneshju));

            cout << "successfully changed ." ;
        }
          cout << "press a key to continue ..." << endl ;
          getch();
      }

    }

void maxMark()
{
    int r = 2 ;
    system("cls");
    Daneshju student , student1 ;
    student1.mark = 0;
    fstream file ;
    file.open("text.abc" , ios::out | ios::in | ios::binary) ;
    if(!file)
    {
        cout << "Error opening file..." << endl ;
    }
    else
    {
        while (file.read((char *)&student , sizeof(struct Daneshju)))
        {
            if(student.stat == 1)
            {
                if(student.mark > student1.mark)
                {
                    student1 = student ;
                }
            }
        }

        cout << "name            mark            id            gender(1,2)" ;
        gotoxy(1,r);
        cout << student1.name ;
        gotoxy(20,r);
        cout << student1.mark ;
        gotoxy(35,r);
        cout << student1.id ;
        gotoxy(55,r);
        cout <<student1.gender;
        cout << "\nPress a key to continue ... " << endl;getch();

    }
}

void minMark()
{
    int r = 2 ;
    system("cls");
    Daneshju student , student1 ;
    student1.mark = 20;
    fstream file ;
    file.open("text.abc" , ios::out | ios::in | ios::binary) ;
    if(!file)
    {
        cout << "Error opening file..." << endl ;
    }
    else
    {
        while (file.read((char *)&student , sizeof(struct Daneshju)))
        {
            if(student.stat == 1)
            {
                if(student.mark < student1.mark)
                {
                    student1 = student ;
                }
            }
        }

        cout << "name            mark            id            gender(1,2)" ;
        gotoxy(1,r);
        cout << student1.name ;
        gotoxy(20,r);
        cout << student1.mark ;
        gotoxy(35,r);
        cout << student1.id ;
        gotoxy(55,r);
        cout <<student1.gender;
        cout << "\nPress a key to continue ..." << endl;getch();
    }
}


void avgMark()
{
    int avg , sum=0 , row = 2 ;
    system("cls");
    Daneshju student , student1 ;
    student1.mark = 0;
    fstream file ;
    file.open("text.abc" , ios::out | ios::in | ios::binary) ;
    if(!file)
    {
        cout << "Error opening file..." << endl ;
    }
    else
    {
        while (file.read((char *)&student , sizeof(struct Daneshju)))
        {
            if(student.stat == 1)
            {
                    sum = sum + student.mark ;
                    row++ ;
            }
        }

        cout << "Majmoo Nomarat = " << sum << endl ;
        cout << "Miangin Nomarat = " << sum/(row-2) << endl ;
        cout << "\nPress a key to continue ..." << endl;getch();
    }
}

void studentSearch()
{
    int idnum ;
    Daneshju student ;
    cout << "Enter an id number to show : " <<endl ;
    cin >> idnum ;
    fstream file ;
    file.open("text.abc" , ios::out | ios::in | ios::binary);
    if(!file)
    {
        cout<< "Error opening file ... " <<endl ;
    }

    else
    {
        file.seekg(sizeof(struct Daneshju)* idnum , ios::beg);
        file.read((char *)&student , sizeof(struct Daneshju));
        if(student.stat == 1)
        {
        system("cls");
        file.seekp(sizeof(struct Daneshju)* idnum , ios::beg);
        int row;
                gotoxy(1 , row);
                cout<<student.name ;
                gotoxy(20 , row);
                cout<<student.mark ;
                gotoxy(35 , row);
                cout<<student.id;
                gotoxy(45 , row);
                cout<<student.gender;
        }
        else cout << "Id Dose Not exist !" <<endl;

        file.close();
        cout << "\nPress a key to continue " << endl;getch();
    }
}







