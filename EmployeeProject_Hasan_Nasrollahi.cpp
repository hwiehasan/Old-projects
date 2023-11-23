#include <iostream>

using namespace std;
//=======counters=======
int Employee_num = 0;
int Monthly_num  = 0;
int Hourly_num   = 0;
//======class 1=========
class Employee{
    protected:
        string fname;
        string lname;
        string id;
        double netPay;
    public:
        virtual double finalPay() = 0;
        //constructors
        Employee();
        Employee(string fname,string lname,string id);
        //setter
        void setFname(string fname){this->fname = fname;}
        void setLname(string lname){this->lname = lname;}
        void setId   (string id)   {this->id = id;}
        //getter
        string getFname (){return this->fname;}
        string getLname (){return this->lname;}
        string getId    (){return this->id;}
        double getNetPay(){return this->netPay;}
};
Employee::Employee(){
    ::Employee_num++;
    cout << "Enter Employee["<<::Employee_num <<"] First Name: "; cin  >> this->fname;
    cout << "Enter Employee["<<::Employee_num <<"] Last Name: ";  cin  >> this->lname;
    cout << "Enter Employee["<<::Employee_num <<"] Id: ";         cin  >> this->id;
}
Employee::Employee(string fname,string lname,string id){
    ::Employee_num++;
    this->fname = fname;
    this->lname = lname;
    this->id    = id;
}
//========class 2=========
class HourlyEmployee:public Employee{
    private:
        double hour_worked;
        double pay_per_hour;
    public:
        //constructors
        HourlyEmployee();
        HourlyEmployee(string fname,string lname,string id,double hour_worked,double pay_per_hour);
        //setter
        void setPPH(double pph){this->pay_per_hour = pph;}
        void setHW (double hw) {this->hour_worked = hw;}
        //getter
        double getPPH(){return this->pay_per_hour;}
        double getHW() {return this->hour_worked;}
        double finalPay(){return this->netPay = this->hour_worked * this->pay_per_hour;}
};
HourlyEmployee::HourlyEmployee(){
    ::Hourly_num++;
    cout << "Enter Employee["<<::Employee_num<<"] work hours: ";    cin >> this->hour_worked;
    cout << "Enter Employee["<<::Employee_num<<"] pay per hour: "; cin >> this->pay_per_hour;
}
HourlyEmployee::HourlyEmployee(string fname,string lname,string id,double hour_worked,double pay_per_hour)
: Employee(fname,lname,id)
{
    ::Hourly_num++;
    this->hour_worked  = hour_worked;
    this->pay_per_hour = pay_per_hour;
}
//===========class 3============
class MonthlyEmployee : public Employee{
    private:
        double work_months;
        double pay_per_month;
    public:
        //constructors
        MonthlyEmployee();
        MonthlyEmployee(string fname,string lname,string id,double pay_per_month,double work_months);
        //setter
        void setPPM(double ppm){this->pay_per_month = ppm;}
        void setWM  (double wm){this->work_months = wm;}
        //getter
        double getPPM  (){return this->pay_per_month;}
        double getWM   (){return this->work_months;}
        double finalPay(){return this->netPay = this->pay_per_month * this->work_months;}
};
MonthlyEmployee::MonthlyEmployee(){
    ::Monthly_num++;
    cout << "Enter Employee["<<::Employee_num<<"] Pay Per Month: "; cin >> this->pay_per_month;
    cout << "Enter Employee["<<::Employee_num<<"] Work Months: ";   cin >> this->work_months;
}
MonthlyEmployee::MonthlyEmployee(string fname,string lname,string id,double pay_per_month,double work_months)
: Employee(fname,lname,id)
{
    ::Monthly_num++;
    this->pay_per_month = pay_per_month;
    this->work_months   = work_months;
}
//=========Change Employees Info=================
void ChangeInfo(HourlyEmployee *ptr,int limit = 0){
    int i=0,n;
    n = (limit == 0) ? ::Hourly_num : limit;
    while(i < n){
        string fname,lname,id;
        double pph,hw;
        cout << "========Change["<<i+1<<"]===========\n";
        cout << "Enter HourlyEmployee["<<i+1<<"] First Name: ";   cin >> fname;
        cout << "Enter HourlyEmployee["<<i+1<<"] Last Name: ";    cin >> lname;
        cout << "Enter HourlyEmployee["<<i+1<<"] Id: ";           cin >> id;
        cout << "Enter HourlyEmployee["<<i+1<<"] work hours: ";   cin >> hw;
        cout << "Enter HourlyEmployee["<<i+1<<"] pay per hour: "; cin >> pph;
        ptr->setFname(fname);
        ptr->setLname(lname);
        ptr->setId(id);
        ptr->setHW(hw);
        ptr->setPPH(pph);
        i++;
        ptr++;
    }
}void ChangeInfo(MonthlyEmployee *ptr,int limit = 0){
    int i=0,n;
    n = (limit == 0) ? ::Monthly_num : limit;
    while(i < n){
        string fname,lname,id;
        double ppm,wm;
        cout << "========Change["<<i+1<<"]===========\n";
        cout << "Enter MonthlyEmployee["<<i+1<<"] First Name: ";   cin >> fname;
        cout << "Enter MonthlyEmployee["<<i+1<<"] Last Name: ";    cin >> lname;
        cout << "Enter MonthlyEmployee["<<i+1<<"] Id: ";           cin >> id;
        cout << "Enter MonthlyEmployee["<<i+1<<"] work months: ";  cin >> wm;
        cout << "Enter MonthlyEmployee["<<i+1<<"] pay per month: "; cin >> ppm;
        ptr->setFname(fname);
        ptr->setLname(lname);
        ptr->setId(id);
        ptr->setWM(wm);
        ptr->setPPM(ppm);
        i++;
        ptr++;
    }
}
//========Show Employees Info===========
void ShowAllInfo(auto *ptr,string type,int limit = 0){
    int i=0,n;
    if(limit ==0){
        n = (type == "Hourly") ? ::Hourly_num : ::Monthly_num;
    }else{
        n = limit;
    }
    while(i < n){
        cout <<"======Show["<<i+1<<"]======\n";
        cout <<"First Name : "<< ptr->getFname()<< endl;
        cout <<"Last Name : " << ptr->getLname()<< endl;
        cout <<"Id : "        << ptr->getId()   << endl;
        cout <<"Salary : "    << ptr->finalPay()<< endl;
        i++;
        ptr++;
    }
}
//========get status========
void getStatus(){
    cout << "======Status=====\n";
    cout << "All Employees : "<< ::Employee_num<<endl;
    cout << "Monthly Employees : "<< ::Monthly_num<<endl;
    cout << "Hourly Employees : "<< ::Hourly_num<<endl;
}
//========main==============
int main()
{
    MonthlyEmployee *p;
    HourlyEmployee  *q;
    //this >>
    p = new MonthlyEmployee[2] { {"ali","karimi","42",2,7} , {"mohammad","karami","322",5,3} };
    q = new HourlyEmployee[2]  { {"sadeq","rezaei","43",4,7} , {"sina","farhadi","92",7,3} };
    /*or
    int n , n2;
    cout << "Enter HourlyEmployees  Count : " ;cin >> n;
    cout << "Enter MonthlyEmployees Count : " ;cin >> n2;
    p = new MonthlyEmployee[n2];
    q = new HourlyEmployee[n];
    */
    ShowAllInfo(p,"Monthly"); //type must be passed to show all employees
    ShowAllInfo(q,"Hourly");  //show all employees with limit = 1
    ChangeInfo(p);            //change employees info
    ChangeInfo(&p[1],1);      //change one employee info
    ShowAllInfo(&p[1],"",1);  //show one Employee info
    getStatus();              //get status
    return 0;
}










