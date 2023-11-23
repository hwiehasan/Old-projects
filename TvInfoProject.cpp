#include <iostream>
#include <windows.h>    //  header file for gotoxy
#include <iostream> //header file for standard input output
COORD coord= {0,0}; // this is global variable
void gotoxy(int x,int y){    coord.X=x;    coord.Y=y;    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);}


using namespace std;

class TV {
    friend class LinkList;
//*****DATA*****
    char brand[20];
    int price;
    int screen;
//*****POINTER*****
    TV *next;

};

class LinkList{
    public:
        LinkList();
        ~LinkList();
        void addNode();
        void deleteNode();
        void display();
    private:
        TV *first;
        TV *last;

};

LinkList::LinkList()
{
    first = last = NULL;
}

void LinkList::addNode()
{
    TV *newPtr = new TV();
    if(!newPtr){
        cout<<"Failed allocation"<<endl;
    }
    newPtr -> bext = NULL;

    cout<<"Lotfan Brand ra vared konid :"<< endl;
    cin>> newPtr -> brand;
    cout<<"Lotfan price ra vared konid :"<< endl;
    cin>> newPtr -> price;
    cout<<"Lotfan screnn size ra vared konid :"<< endl;
    cin>> newPtr -> screen;

    //اگر اولین گره بود
    if(first == NULL){
        first = last = newPtr;
    }
    //اگر تلوزیون های بعدی باشد
    else
    {
        last -> next = newPtr;
        last = newPtr;
    }

}

void LinkList::display()
{
    int r = 2;
    system("cls");
    cout << "Brand      Price       screen size"<< endl;
    TV *cutPtr = first;
    while(cutPtr)
    {
        gotoxy(1,r);
        cout<< cutPtr->brand;
        gotoxy(20,r);
        cout<< cutPtr->price;
        gotoxy(30,r);
        cout<< cutPtr->screeb;
        //
        gotoxy(1,r);
        cutPtr = cutPtr->next;
        r++

    }
};

int main()
{



    return 0;
}


