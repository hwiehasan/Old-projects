#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;
//پروژه میان ترم حسن نصرالهی
void menu ();
void student();
void sayerEmkanat();

int FINAL[5][5],v,vs;
string dars[5];
string *d=dars;
int daneshjoo,doroos;
int id,ido=9999;
int &idostad=ido;
int ids[5]={9400,9500,9600,9700,9800};
string info[5]={"ID","NAM","NAM KHANEVADEGI","ADRESS","PHONE"};
int sotunINFO;
string vinfo[5][5];

/*.............................................امکانات کلی برنامه..................................................*/

void bazgashtSayer()
    {cout << "Braye bazgashte be Panel Emkanat \" 1 \" va baraye Khorooj \" 2 \" ra vared konid:\t"<<endl;
    cin >> vs;
    switch(vs)
    {   case 1 : sayerEmkanat () ; break;
        case 2 : menu() ; break;}}


void sayerEmkanat ()
{   cout << "Lotfan amaliat movred nazar khod ra vared konid:"<<endl;
    cout << "1)Moshahede Daneshjooyan har vorudi \n2)Moshahede Daneshjooyan ba doroos oftade"<<endl;
    cout << "3)Moshahede Tamami Daneshjooyan \n4)Moshahede Doroos eraee shode \n5)Bazgasht be menu qabl"<<endl;
    cin >> v;
    int i;
    if (v==1){
         cout << "Baraye Moshahede Daneshjooyan har vorudi gozine ra enetekhab konid:"<<endl;
         for (int i=94 ; i<99 ; i++)
            cout << i-94 << ") " << i << endl;
         cin >> daneshjoo;
         for (sotunINFO=0 ; sotunINFO<3 ; sotunINFO++)
                    cout << vinfo[daneshjoo][sotunINFO] << setw(15) ;
         cout <<"\n";
         bazgashtSayer();}

    else if (v==2){
        cout << "Baraye Moshahede Daneshjooyan OFTADE dar hadeaghal yek dars vorudi ra entekhab konid:"<<endl;
        for (int i=94 ; i<99 ; i++)
            cout << i-94 << ") " << i << endl;
        cin>>daneshjoo;
        for (doroos=0;doroos<5;doroos++)
            {   if (FINAL[daneshjoo][doroos]<10)
                {cout << "In Daneshjoo ba ID: " <<(daneshjoo+94)*100 << " " << "dar hade aghal yek dars oftade ast"<<endl;
                    break;}}
            bazgashtSayer();}

    else if (v==3){
            cout << "List Tamami daneshjooyan:"<<endl;
            for (int i=0;i<5;i++)
                cout << *(ids+i) << endl;
            bazgashtSayer();}

    else if (v==4){
        cout << "List Tamami Doroos eraee shode:"<<endl;
        for (int i=0;i<5;i++)
            cout << *(d+i) << endl;
        bazgashtSayer();}

    else
        {student();}
}

/*...............................................بخش دانشجویان................................................*/

void bazgashtStudent()
    {cout << "Braye bazgashte be Panel \" 1 \" va baraye Khorug \" 2 \" ra vared konid:\t"<<endl;
    cin >> vs;
    switch(vs)
    {   case 1 : student() ; break;
        case 2 : menu() ; break;}}

void vahed ()
{    cout << "List doroos eraee shode :\n Braye Entekhab tamam doroos 1 ra vared konid"<<endl;
     for (int i=0 ; i<5 ; i++)
        cout << *(d+i) << endl;
     cin>>vs;
     bazgashtStudent();}

void etelaat ()
{   cout << "Baraye vorud Etelaat,ID khod ra taiid konid:"<<endl;
    for (int i=0 ; i<5 ; i++)
            cout << i << ") "<< ids[i] <<endl;
    cin>>daneshjoo;
    for (sotunINFO=0 ; sotunINFO<5 ; sotunINFO++)
    {
        cout << info[sotunINFO] << ":\t" ;
        cin>>vinfo[daneshjoo][sotunINFO];
        cout << "\n";
    }
    bazgashtStudent();
}

void list_nd ()
{   cout << "Baraye Moshahede list doroos va nomarat,ID khod ra taiid konid:"<<endl;
    for (int i=0 ; i<5 ; i++)
            cout << i << ") "<< ids[i] <<endl;
    cin>>daneshjoo;
    for (doroos=0;doroos<5;doroos++){cout << *(d+doroos) << ":\t" << FINAL[daneshjoo][doroos]<<endl;}
    bazgashtStudent();
}

void oftade ()
{   cout << "Baraye Moshahede list doroos Oftade,ID khod ra taiid konid:"<<endl;
    for (int i=0 ; i<5 ; i++)
            cout << i << ") "<< *(ids+i) <<endl;
    cin>>daneshjoo;
    for (doroos=0;doroos<5;doroos++)
        {   if (FINAL[daneshjoo][doroos]<10)
                cout << *(d+doroos) << ":\t" << FINAL[daneshjoo][doroos]<<endl;}
    bazgashtStudent();}

void student()
{   //پنل دانشجو
    cout << "Shomare amaliat ra entekhab konid:\n1) Vorud Etelaat \n2) Entekhab Vahed \n3) Moshahede list Doroos va Nomarat"<< endl;
    cout << "4) Doroos Oftade\n5) Sayer Emkanat \n6) Khorug"<< endl;
    cin >> vs;
    switch(vs)
    {   case 1:etelaat();break;
        case 2:vahed();break;
        case 3:list_nd();break;
        case 4:oftade();break;
        case 5:sayerEmkanat();break;
        case 6:menu();break;
    }
}


/*..............................................بخش استاد.................................................*/

template <class T>
T listdars (T *dars[5])
{   for (int i=0 ; i<5 ; i++)
        cin>>*(d+i);}

void ostad ()
{   //پنل استاد
    cout << "Shomare amaliat ra entekhab konid:\n1) Tarif doroos \n2) Vared kardan Noamarat\n3) Khorug"<< endl;
    int a;
    cin>>a;
    if (a==1)
    {
        cout << "List Doroosi ke mikhahid ra vared konid:"<<endl;
        listdars(&d);
        ostad(); /*بعد از دریافت لیست درس به پنل استاد بازگردد*/}

    else if (a==2)
    {   // پنج بار اجرا میشود تا نمرات پنج درس پنج دانشجو بطور کامل وارد شود
        int tekrar=0;
        do{
        cout << "Shomare daneshjoo ra entekhab konid:"<<endl;
        int i;
        for (i=0 ; i<5 ; i++)
            cout << i << ") " << *(ids+i) << endl;
        cin >> daneshjoo;
        if (daneshjoo>=0 && daneshjoo<5)
            {   cout << "Nomre haye in daneshjoo ra be tartib vared konid:" <<endl;
                for (i=0 ; i<5 ; i++)
                    cout << i << ") "<< *(d+i) << ":" <<endl;
                for (doroos=0;doroos<5;doroos++)
                        {cin >> v;
                        FINAL[daneshjoo][doroos]=v;}}
                tekrar++;}while (tekrar != 5);
        }
    else if (a==3)
                menu();
    else
        {   cout << "VORUDI ESHTEBAH AST! \n";
                ostad (); }

        //پس از وارد شدن لیست درس و همه نمرات همه دانشجو ها به استاد امکان خروج و یا تغییرات میدهیم
        cout << "Baraye bazgasht be Panel Ostad adad \"1\" va baraye raftan be menu Login adad \"2\" ra vared konid:\n";
        cin >> v;
        switch(v){
        case 1 : ostad();break;
        case 2 : menu() ;break;}
}

void menu ()
{
    cout << "Baraye vorud ID khod ra vared konid:"<< endl;
    cin>>id;
    if(id==idostad)
        {   cout << "Shoma be onvan Ostad vared shodid."<< endl;
            ostad();
        }
    else if(id==9400||id==9500||id==9600||id==9700||id==9800)
    {
        cout << "Shoma be onvan Daneshjoo vared shodid."<< endl;
        student();
    }
    else
        {cout << "ID ESHTEBAH AST!" <<endl;
        menu();}

}

int main()
{
        menu();
        return 0;
}
