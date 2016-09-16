#include <bits/stdc++.h>
#include<iostream>

using namespace std;

//class password_safe;


int counter=0;    ///calendar
int counter1=0;   ///addressbook

typedef struct n             /// structure for storing the event details and construction of linked list
{
    int date;
    int month;
    int year;
    string event;
    struct n *next;
}node;

node *ptr=NULL,*start=NULL,*current=NULL;
int k=0;                                    /// counts the number of events made

 void addevent()
 {
     k++;
     ptr=new node;
     ptr->next=NULL;
     cout<<endl;
     cout<<"  EVENT "<<k<<endl<<endl;
     cout<<"    ->Enter the Event Date: ";
     cin>>ptr->date;
     cout<<"    ->Enter the Event Month: ";
     cin>>ptr->month;
     cout<<"    ->Enter the Event Year: ";
     cin>>ptr->year;
     cout<<"    ->Enter the Event Description: ";
     cin.ignore();
     getline(cin,ptr->event);
     if(start==NULL)
     {
         start=ptr;
         current=ptr;
     }
     else
     {
         current->next=ptr;
         current=ptr;
     }
 }

 void showevent()
 {
     int i=0;                                     /// shows the number of event
     cout<<endl<<"\n Your Events are: "<<endl<<endl;
     node *temp=NULL;
     temp=start;
     while(temp!=NULL)
     {
         i++;
         cout<<" "<<i<<".) Date : "<<temp->date<<"-"<<temp->month<<"-"<<temp->year<<"\n     Event is : "<<temp->event<<endl;
         temp=temp->next;
     }
 }

 void deleteevent()
 {
     int i,j;
     node *temp=NULL,*temp1=NULL;
     if(k==0)
        cout<<" No Events Made that can be deleted"<<endl;
     else
     {
      cout<<endl<<"Enter the number of event you want to delete: ";
      cin>>i;
      if(i==1)
      {
         temp=start;
         start=start->next;
         delete temp;
         cout<<" Event Deleted Successufully"<<endl;
      }
      else if(i!=k)
      {
         temp=start;
         for(j=1;j<i-1;j++)
         {
             temp=temp->next;
         }
         temp1=temp->next;
         temp->next=temp->next->next;
         delete temp1;
         cout<<" Event Deleted Successufully"<<endl;
      }
      else if(i==k)
      {
         int i;
         temp=start;
         for(i=1;i<k-1;i++)
         {
             temp=temp->next;
         }
         temp1=temp->next;
         temp->next=NULL;
         delete temp1;
         cout<<" Event Deleted Successufully"<<endl;
      }
    }
  }




class calendar           /// main calander class
{
protected:
    int year, first_day_of_month;
    int currentMonth;
    int num_of_days;

public:
    calendar()
    {
        year=0;
        first_day_of_month=0;
        currentMonth=1;
        num_of_days=0;
       // pass=NULL;

    }
  void main_work();
  int first_day_of_year (int );
  int num_Of_days_in_a_month (int);
  void print_cal (int);
  void print_month (int, int&);
  void skipToDay (int);
  static void view_holidays();
  void fullTraversal();
  //friend void link_calendar(password_safe &,calendar &);
};

void calendar::view_holidays()
{
    cout<<"\t\t   LIST OF HOLIDAYS"<<endl<<endl;
    cout<<" 26-JAN: REPUBLIC DAY, 15-AUG: INDEPENDENCE DAY, 02-OCT: GANDHI JAYANTI"<<endl;
    cout<<" 25-DEC: CHRISTMAS DAY, 25-NOV: GURU NANAK'S BIRTHDAY"<<endl;
    cout<<endl<<endl;
    system("PAUSE");
    system("cls");
}


void calendar::main_work()
{
    char c='y';
    char cd='y';
    int opt;
       cout<<"\t\t\tWELCOME TO GOOGLE CALENDAR"<<endl<<endl;
    cout << "Type the Year which you want to display calendar for : ";
    cin >>year;
    first_day_of_month=first_day_of_year(year);
    while(cd=='y'){
    cout<<"\nPlease Select your Option : ";
    cout<<"\n1.) Full view of calendar for year "<<year<<endl;
    cout<<"2.) Month wise view for year "<<year<<endl;
    cout<<"Enter your option : ";
    cin>>opt;
    cout<<endl;
    switch(opt)
    {
    case 1  :  this->fullTraversal();
              return;
    case 2  : cd='n';
              break;
    default : cout<<"Plz Enter valid option !\n";
              cd='y';
    }
    }
        while(c=='y'){
        cout<<"Enter the month no. : ";
        cin>>currentMonth;
        if(currentMonth<=12 && currentMonth>0){
        cout <<"\nYear is : "<< year << endl<<endl;
        num_of_days = num_Of_days_in_a_month(currentMonth);
        print_cal(currentMonth);
        print_month(num_of_days, first_day_of_month);
        cout << endl << endl << endl;
        currentMonth = 1;
        c='n';
        }
        else
        {
            cout<<"\nPlz Enter valid month ! "<<endl;
            c='y';
        }
        }

    //cout << endl;

   //system("PAUSE");
}

void calendar::fullTraversal()
{
        cout <<"\nYear is : "<< year << endl<<endl;
        while (currentMonth <= 12)
        {
        num_of_days = num_Of_days_in_a_month(currentMonth);
        print_cal(currentMonth);
        print_month(num_of_days, first_day_of_month);
        cout << endl << endl << endl;
        currentMonth = currentMonth + 1;
        }

   // cout << endl;

}

int calendar::first_day_of_year(int year)     /// Calculates the first day of given year
    {
        int day_start;
        int x1, x2, x3;
        x1 = (year - 1)/ 4;
        x2 = (year - 1)/ 100;
        x3 = (year - 1)/ 400;
        day_start = (year + x1 - x2 + x3) %7;
        return day_start;
    }

int calendar:: num_Of_days_in_a_month (int m)    /// gives the number pf days in the respective month
    {
        if (m == 1)
           return(31);
        else if (m == 2)
             return(28);
        else if (m == 3)
             return(31);
        else if (m == 4)
             return(30);
        else if (m == 5)
             return(31);
        else if (m == 6)
             return(30);
        else if (m == 7)
             return(31);
        else if (m == 8)
            return(31);
        else if (m == 9)
            return(30);
        else if (m == 10)
            return(31);
        else if (m == 11)
            return(30);
        else if (m == 12)
            return(31);
    }

void calendar:: print_cal (int m)    /// displays the calendar in the proper given format
    {
        if (m == 1){

    cout << "Month is : January" << endl;
    }
    else if (m == 2) {
         cout << "Month is : February" << endl; }
    else if (m == 3) {
         cout << "Month is : March" << endl; }
    else if (m == 4) {
         cout << "Month is : April" << endl; }
    else if (m == 5) {
         cout << "Month is : May" << endl; }
    else if (m == 6) {
         cout << "Month is : June" << endl; }
    else if (m == 7) {
         cout << "Month is : July" << endl; }
    else if (m == 8) {
         cout << "Month is : August" << endl; }
    else if (m == 9) {
         cout << "Month is : September" << endl; }
    else if (m == 10) {
         cout << "Month is : October" << endl; }
    else if (m == 11) {
         cout << "Month is : November" << endl; }
    else if (m == 12) {
         cout << "Month is : December" << endl; }


    cout << "\n S  M  T  W  T  F  S" <<endl;
    cout << "\n_____________________\n" << endl;
  }

void skip (int i)
     {
        while (i > 0) {
            cout << " ";
            i = i - 1;
        }
    }

void calendar:: print_month (int numDays, int &weekDay)   /// displays the date with day in the proper format
    {
        int day = 1;
        skipToDay(weekDay);
        while (day <= numDays) {
            cout << setw(2) << day << " ";
            if (weekDay == 6){
                cout << endl;
                weekDay = 0;
            }
        else weekDay = weekDay + 1;
        day = day + 1;
        }
    }


void calendar::skipToDay (int d)    /// print spaces accordingly in the calander
    {
        return skip(3*d);
    }

void cal_fun()
{
   int b;     /// string holds yes/no to add a event
   string c;
   cout<<endl<<"   CALENDER FUNCTIONS ->"<<endl;;
   cout<<" 1. Do you wish to add an Event to your Calendar: "<<endl;
   cout<<" 2. Do you wish to delete an Event from your Calendar: "<<endl;
   cout<<" 3. Exit: "<<endl;
   cout<<" Enter your Choice: ";
   cin>>b;
   switch(b)
   {
   case 1:
    {
        addevent();
        cout<<"\n Event added Successfully"<<endl;
        showevent();
        break;
    }
   case 2:
    {
        deleteevent();
        if(k!=0)
        {
          showevent();
        }
        break;
    }
    case 3:
        {
            return;
            break;
        }
    default:
        {
            break;
        }
   }
     cout<<endl<<" Do you wish to further repeat CALENDAR FUNCTIONS: (Y/N) ";
     cin>>c;
     if(c=="y"||c=="Y")
     {
       cal_fun();
     }
     else if(c=="n"||c=="N")
     {
         cout<<endl<<"\t THANK YOU FOR USING GOOGLE CALENDAR"<<endl;
     }
}




class contacts                              ///Contacts Class starts
{
protected:
    string mob_no;
    string phone_no;
    string address;
public:
    contacts(string m,string p, string a)
    {
        mob_no=m;
        phone_no=p;
        address=a;
    }
    virtual void display()
    {
        cout<<"Mobile no. is : "<<mob_no;
        cout<<"Phone no. is : "<<phone_no;
        cout<<"Address is : \n"<<address;
    }
};

class person : public contacts
{
    string first_name;
    string last_name;
    public:
        person(string f, string l, string mob, string phone, string addr): contacts(mob,phone,addr)
        {
            first_name=f;
            last_name=l;
        }
        string getname()
        {
            return first_name;
        }
        void display()
        {
        cout<<" Name is : "<<first_name<<" "<<last_name<<endl;
        cout<<" Mobile no. is : "<<mob_no<<endl;
        cout<<" Phone no. is : "<<phone_no<<endl;
        cout<<" Address is : "<<address<<endl;
        }

        string getlastname()
        {
            return last_name;
        }
};

class org : public contacts
{
    string org_name;
    string org_type;
public:
    org(string f, string l, string mob, string phone, string addr):contacts(mob,phone,addr)
        {
            org_name=f;
            org_type=l;
        }
        void display()
        {
        cout<<" Org Name is : "<<org_name<<endl;
        cout<<" Org type is : "<<org_type<<endl;
        cout<<" Mobile no. is : "<<mob_no<<endl;
        cout<<" Phone no. is : "<<phone_no<<endl;
        cout<<" Address is : "<<address<<endl;
        }
        string getorg()
        {
            return org_name;
        }
        string getorgtype()
        {
            return org_type;
        }
};

class addressbook
{
    person *p[100];
    org *o[100];
    list<person>ptr;
    list<person>::iterator per_it;
    list<org>ptr1;
    list<org>::iterator org_it;
    int count;
    int count1;
    int count2;
public:
    addressbook()
    {
        int i;
        count=0;
        count1=0;
        count2=0;
        for(i=0;i<100;i++)
        {
            p[i]=NULL;
            o[i]=NULL;
        }

        p[count1]=new person("Shahbaz","Hussain","8860937649","","Jaipuria");
        ptr.push_back(*p[count1]);
        count1++;
        count++;
    }
    //friend void link_addressbook(password_safe &, addressbook &);
    void add_to_contacts_person()
    {
        string f,l,mob,phone,addr;
        char c;
        if(count<=100){
        cout<<"\n Enter the first name of the person : ";
        cin>>f;
        cout<<" Enter the last name of the person : ";
        cin>>l;
        cout<<" Enter the mobile no. of the person : ";
        cin>>mob;
        cout<<" Do you want to add a Phone no. for this contact ? (Y/N) : ";
        cin>>c;
        if(c=='y' || c=='Y'){
        cout<<" Enter the Phone no. : ";
        cin>>phone;}
        else
        phone="";
        cin.ignore();
        cout<<" Enter the Person's Address : ";
        getline(cin,addr);
        p[count1]= new person(f,l,mob,phone,addr);
        ptr.push_back(*p[count1]);
        count1++;
        count++;
        cout<<"\t\t CONTACT ADDED SUCCESSFULLY :D \n\n";
        }
    }
    void add_to_contacts_org()
    {
        string f,mob,phone,addr;
        string l;
        char c,d;
        if(count<=100)
        {
        cout<<"\n Enter the Organisation name : ";
        getline(cin,f);
        cout<<" Enter the Organisation Type : ";
        getline(cin,l);
        cout<<" Enter the mobile no. of the contact : ";
        cin>>mob;
        cout<<" Do you want to add a Phone no. for this contact ? (Y/N) : ";
        cin>>c;
        if(c=='y' || c=='Y'){
        cout<<" Enter the Phone no. : ";
        cin>>phone;}
        else
        phone="";
        cin.ignore();
        cout<<" Enter the Contact's Address : ";
        getline(cin,addr);
        o[count2]= new org(f,l,mob,phone,addr);
        ptr1.push_back(*o[count2]);
        count2++;
        count++;
        cout<<"\t\t CONTACT ADDED SUCCESSFULLY :D \n\n";
        }
    }
    void search()
    {
        string name;
        cout<<" Enter the name to be Searched : ";
        cin>>name;
        int i=0;
        while(p[i]!=NULL || o[i]!=NULL)
        {
            if(p[i]!=NULL)
            {
            if(name==p[i]->getname() || name==p[i]->getlastname())
            {
                p[i]->display();
                cout<<endl;
            }
            else
            {
                cout<<" Match Not Found \n";
            }
            }
            if(o[i]!=NULL)
            {
            if(name==o[i]->getorg() || name==o[i]->getorgtype())
            {
                o[i]->display();
                cout<<endl;
            }
            else
            {
                cout<<" Match Not Found \n";
                return;
            }
            }
            i++;
        }
    }

    void display_contents()
    {
        per_it=ptr.begin();
        org_it=ptr1.begin();
        if(per_it==ptr.end() && org_it==ptr1.end())
        {
          cout<<" There are No Contacts Saved in the address book"<<endl;
          return;
        }
        if(per_it!=ptr.end())
        {
        cout<<" Displaying for Personalised Contacts : "<<endl<<endl;
        while(per_it!=ptr.end())
        {
                per_it->display();
                cout<<endl;
                per_it++;
        }
        }
        if(org_it!=ptr1.end())
        {
         cout<<" Displaying for Organisation Contacts : "<<endl<<endl;
         while(org_it!=ptr1.end())
         {
                org_it->display();
                cout<<endl;
                org_it++;
         }
        }
    }

    void del()
    {
        int i=0;
        char c;
        string name;
        cout<<"\n Enter the Contact/Organisation Name to be Deleted : ";
        cin>>name;
        cout<<" Are you Sure you want to delete the contact Permanently (Y/N)? ";
        cin>>c;
        if(c=='y'||c=='Y')
        {
            cout<<"Contact Deleted Successfully :) "<<endl<<endl;
            per_it=ptr.begin();
            org_it=ptr1.begin();
        while(per_it!=ptr.end() || org_it!=ptr1.end())
        {
            if(per_it!=ptr.end())
            {
            if(name==per_it->getname())
            {
                ptr.erase(per_it);
                count--;
                count1--;
                break;
            }
            }
            if(org_it!=ptr1.end())
            {
            if(name==org_it->getorg())
            {
                ptr1.erase(org_it);
                count--;
                count2--;
                break;
            }
            }
            org_it++;
            per_it++;
        }
    }
    else
    {
        cout<<"Contact Not Deleted :) "<<endl<<endl;
    }
    }
};



class password_safe
{
string password;
public:

    password_safe()
    {
        cout<<"\n App Installed Successfully ";
        cout<<"\n Enter Your New PASSWORD to Begin : ";
        cin>>password;
        cout<<"\n Your PASSWORD Has Been Set. THANK YOU.. \n";
    }

void password_generator()
{
    char pass[100];
    char t;
    char mpass[15];
    int i,k=0;
    cout<<" Enter any sentence which you can remember easily : ";
    //cin>>pass;
    cin.ignore();
    cin.getline(pass,50);
    int len=strlen(pass);
    for(i=0;i<len;i++)
    {   if(pass[i]==' '|| i==0)
        {
         if(i==0){
         mpass[k]=pass[i];
         k++;}
         else
         {
             i++;
             mpass[k]=pass[i];
             k++;
         }
        }
    }
    mpass[k]='\0';
    for(i=0;i<k;i++)
    {
        if(mpass[i]=='a' || mpass[i]=='A')
            mpass[i]='@';
        if(mpass[i]=='I' || mpass[i]=='i')
            mpass[i]='!';
        if(mpass[i]=='S' || mpass[i]=='s')
            mpass[i]='$';
        if(mpass[i]=='c' || mpass[i]=='C')
            mpass[i]='(';
        if(mpass[i]=='o' || mpass[i]=='O')
            mpass[i]='0';
    }
    t=mpass[0];
    mpass[0]=mpass[k-1];
    mpass[k-1]=t;
    cout<<"\n\n Here's Your Unhackable password : "<<mpass<<"\nENJOY ! :D\n";
}

void change_password()
{
string oldpass,newpass;
cout<<"ENTER OLD PASSWORD : "<<endl;
cin>>oldpass;

for(int i=0;i<3;i++)
{
if(oldpass==password)
{
cout<<"ENTER NEW PASSWORD : "<<endl;
cin>>newpass;
password=newpass;
cout<<"\nPASSWORD CHANGED SUCCESSFULLY"<<endl;
break;
}

else{
cout<<"WRONG PASSWORD ENTERED!"<<endl;
cout<<"YOU HAVE "<<2-i<<" "<<"Chances left"<<endl;
}
}
}

void view_password()
{
cout<<"THE PASSWORD YOU HAVE SET IS : "<<password<<endl<<endl;
}

string retpass()
{
    return password;
}

};

///to link password class with calendar,addressbook,mails
///Basically friend function to all classes


void link_calendar()
{
  counter=1;
  cout<<" Calendar Locked \n\n";
}

void link_addressbook()
{
  counter1=1;
  cout<<" Contacts Locked \n\n";
}






class mobile
{
    int model_no;
    string model_name;
    addressbook *cl;
    calendar *cal;
    password_safe *pwd;
    int count,count1,count2;
public:
    mobile()
    {
     cout<<"\tWELCOME TO YOUR NEW PHONE 'THE BANANA PHONE'...YOU'LL ENJOY IT ";
     cout<<"\n\n\t\t   Enter Your Mobile Details ";
     cout<<"\n\nEnter Model no. : ";
     cin>>model_no;
     cout<<"Enter Model Name : ";
     cin.ignore();
     getline(cin,model_name);
     cl=NULL;
     cal=NULL;
     pwd=NULL;
     count=count1=count2=0;
    }
    void app_install()
    {
        int a;
    char c='y';
    while(c=='y' || c=='Y')
    {
      cout<<"\n\n APPLICATIONS AVAILABLE IN APP MARKET : ";
      cout<<"\n 1. Contact List ";
      cout<<"\n 2. Calendar ";
      cout<<"\n 3. Password Safe ";
      cout<<"\n Enter Your Choice : ";
      cin>>a;
      switch(a)
    {
    case 1:
        {
            if(count>=1)
            {
                cout<<"\n App Already Installed\n ";
                break;
            }
            else
            {
            add_contacts();
            count++;
            cout<<"\n App Installed Successfully\n ";
            break;
            }
        }
    case 2:
        {
            if(count1>=1)
            {
                cout<<"\n App Already Installed\n ";
                break;
            }
            else
            {
             add_calendar();
             count1++;
             cout<<"\n App Installed Successfully\n ";
             break;
            }
        }
    case 3:
        {
            if(count2>=1)
            {
                cout<<"\n App Already Installed\n ";
                break;
            }
            else
            {
             add_passwordlock();
             count2++;
             break;
            }
        }
    default:
        {
            cout<<" Please Enter Valid Choice ";
            cout<<"\n Do You Want To Continue (y/n) : ";
            cin>>c;
            if(c=='n' || c=='N')
                return;
            break;
        }
    }
     if(count+count1+count2<3)
     {
      cout<<"\n Do You Want To Install Any other App (y/n) : ";
            cin>>c;
     }
     else
     {
         cout<<"\nAll APPS are installed ! ";
         break;
     }
    }
   // return;
    }
    void show_details()        /// have to include this function in main class as an option
    {
        cout<<"\t\t\t MOBILE PHONE DETAILS"<<endl;
        cout<<"Model Name : "<<model_name<<endl;
        cout<<"Model Number : "<<model_no<<endl;
        if(cl!=NULL || cal!=NULL || pwd!=NULL)
        {
            cout<<"The Installed Apps are : "<<endl;
            if(cl!=NULL)
            cout<<" Contact List "<<endl;
            if(cal!=NULL)
            cout<<" Calender "<<endl;
            if(pwd!=NULL)
            cout<<" Password Safe "<<endl;
        }
        else
        {
            cout<<"There are currently no Installed apps on your phone"<<endl;
        }
    }
    void add_calendar()
    {
       cal=new calendar;
    }

    void add_contacts()
    {
        cl=new addressbook;
    }

    void add_passwordlock()
    {
        pwd=new password_safe;
    }




     void app_passwordsafe()
    {
     int opt=1,con;
     char c,d='y',m='y';
     if(pwd!=NULL)
     {
         while(d=='y' || d=='Y')
         {
            if(m=='y' || m=='Y')
            {
            string a;
            cout<<"Enter The Stored Password For Password Safe : ";
            cin>>a;
         if(pwd->retpass()==a)
         {
    while(m=='y' || m=='Y')
    {
     cout<<"\t\t\tPASSWORD SAFE\n\n";
     cout<<"  1.) View Password\n";
     cout<<"  2.) Generate New Password\n";
     cout<<"  3.) Change Password\n";
     cout<<"  4.) Lock Contacts\n";
     cout<<"  5.) Lock Calendar\n";
     cout<<" Press '6' to Exit Password Safe Application\n\n";
     cout<<" Please Select the Option no. : ";
     cin>>opt;
     cout<<"\n";
     if(opt==6)
     {
      cout<<"\n\n Password Safe Closed\n\n";
      return;
     }
     switch(opt)
     {
       case 1 :      pwd->view_password();
                     break;
       case 2 :      pwd->password_generator();
                     break;
       case 3 :      pwd->change_password();
                     break;
       case 4 :      if(cl!=NULL)
                     link_addressbook();
                     else
                     cout<<"\n Contact List App is not installed!\n\n";
                     break;
       case 5 :      if(cal!=NULL)
                     link_calendar();
                     else
                     cout<<"\n Calendar App is not Installed!\n\n";
                     break;
       default :     cout<<"Please Select Valid Option\n";
     }
     cout<<" Do you want to perform some other actions in Password Safe ? (Y/N) : ";
     cin>>m;
     }

    }
    else
            {
                cout<<"Password Incorrect. Please Try Again..";
                cout<<"\nDo You Want To Try Again (Y/N) : ";
                cin>>d;
            }
     }
     else
        return;
         }
     }
    else
    cout<<"\n\n\t APP NOT INSTALLED\n\n";
    }


    void app_addressbook()
    {

     int opt=1,con;
     char c,m='y';
     if(cl!=NULL)
     {
      while(m=='y' || m=='Y')
        {
        if(pwd!=NULL && counter1==1)
         {
             string a;
             cout<<"Enter The Password For Address Book: ";
             cin>>a;
             if(pwd->retpass()==a)
            {

     cout<<"\t\t\tAddress Book\n\n";
     while(opt!=5)
     {

     cout<<"  1.) View All Contacts\n";
     cout<<"  2.) Add New Contact\n";
     cout<<"  3.) Delete Contact\n";
     cout<<"  4.) Search Contact\n";
     cout<<" Press '5' to Exit Address Book Application\n\n";
     cout<<" Please Select the Option no. : ";
     cin>>opt;
     cout<<"\n";
     if(opt==5)
     {
       return;
       break;
     }
     switch(opt)
     {
        case 1 :      cl->display_contents();
                      break;
        case 2 :      cout<<"\t\t 1.) Add Personalised Contact\n";
                      cout<<"\t\t 2.) Add Organisational Contact\n";
                      cout<<"\n Select your Option no.(Personalised Contacts or Organisational Contact) : ";
                      cin>>con;
                      cin.ignore();
                      switch(con)
                      {
                          case 1 :    cl->add_to_contacts_person();
                                      break;
                          case 2 :    cl->add_to_contacts_org();
                                      break;
                          default :   cout<<"Please Select Valid Option\n";
                      }
                      break;
       case 3 :      cl->del();
                     break;
       case 4 :      cl->search();
                     break;
       default :     cout<<"Please Select Valid Option\n";
     }
     cout<<" Do you want to perform some other actions in Address Book ? (Y/N) : ";
     cin>>c;
     cout<<"\n";
     if(c=='n' || c=='N')
     {
         return;
     }
     if(c=='y'||c=='Y')
     opt=1;
     else
     opt=5;
     }
     cout<<"\n\n Address Book Closed...Your Changes are Saved Successfully :)"<<endl<<endl;
     opt=0;
     con=0;
            }
            else
            {
                cout<<"Password Incorrect. Please Try Again..";
                cout<<"\nDo You Want To Try Again (y/n) ";
                cin>>m;
         }
         }
        // }

    else if(pwd!=NULL && counter1==0)
    {
     cout<<"\t\t\tAddress Book\n\n";
     while(opt!=5)
     {
     cout<<"  1.) View All Contacts\n";
     cout<<"  2.) Add New Contact\n";
     cout<<"  3.) Delete Contact\n";
     cout<<"  4.) Search Contact\n";
     cout<<" Press '5' to Exit Address Book Application\n\n";
     cout<<" Please Select the Option no. : ";
     cin>>opt;
     cout<<"\n";
     if(opt==5)
     {
       return;
       break;
     }
     switch(opt)
     {
        case 1 :      cl->display_contents();
                      break;
        case 2 :      cout<<"\t\t 1.) Add Personalised Contact\n";
                      cout<<"\t\t 2.) Add Organisational Contact\n";
                      cout<<"\n Select your Option no.(Personalised Contacts or Organisational Contact) : ";
                      cin>>con;
                      cin.ignore();
                      switch(con)
                      {
                          case 1 :    cl->add_to_contacts_person();
                                      break;
                          case 2 :    cl->add_to_contacts_org();
                                      break;
                          default :   cout<<"Please Select Valid Option\n";
                      }
                      break;
       case 3 :      cl->del();
                     break;
       case 4 :      cl->search();
                     break;
       default :     cout<<"Please Select Valid Option\n";
     }
     cout<<" Do you want to perform some other actions in Address Book ? (Y/N) : ";
     cin>>c;
     cout<<"\n";
      if(c=='n' || c=='N')
     {
         return;
     }
     if(c=='y'||c=='Y')
     opt=1;
     else
     opt=5;
     }
     cout<<"\n\n Address Book Closed...Your Changes are Saved Successfully :)"<<endl<<endl;
     opt=0;
     con=0;
      }


    else if(pwd==NULL)
    {
     cout<<"\t\t\tAddress Book\n\n";
     while(opt!=5)
     {
     cout<<"  1.) View All Contacts\n";
     cout<<"  2.) Add New Contact\n";
     cout<<"  3.) Delete Contact\n";
     cout<<"  4.) Search Contact\n";
     cout<<" Press '5' to Exit Address Book Application\n\n";
     cout<<" Please Select the Option no. : ";
     cin>>opt;
     cout<<"\n";
     if(opt==5)
     {
       return;
       break;
     }
     switch(opt)
     {
        case 1 :      cl->display_contents();
                      break;
        case 2 :      cout<<"\t\t 1.) Add Personalised Contact\n";
                      cout<<"\t\t 2.) Add Organisational Contact\n";
                      cout<<"\n Select your Option no.(Personalised Contacts or Organisational Contact) : ";
                      cin>>con;
                      cin.ignore();
                      switch(con)
                      {
                          case 1 :    cl->add_to_contacts_person();
                                      break;
                          case 2 :    cl->add_to_contacts_org();
                                      break;
                          default :   cout<<"Please Select Valid Option\n";
                      }
                      break;
       case 3 :      cl->del();
                     break;
       case 4 :      cl->search();
                     break;
       default :     cout<<"Please Select Valid Option\n";
     }
     cout<<" Do you want to perform some other actions in Address Book ? (Y/N) : ";
     cin>>c;
     cout<<"\n";
      if(c=='n' || c=='N')
     {
         return;
     }
     if(c=='y'||c=='Y')
     opt=1;
     else
     opt=5;
     }
     cout<<"\n\n Address Book Closed...Your Changes are Saved Successfully :)"<<endl<<endl;
     opt=0;
     con=0;
      }
     }


    }
    else
    cout<<"\n\n\t APP NOT INSTALLED\n\n";
    }

    void app_calendar()
    {
      if(cal!=NULL)
      {
          char b='y';
          while(b=='y' || b=='Y')
          {
           if(counter==1)
         {
             string a;
             cout<<"Enter The Password For Google Calendar: ";
             cin>>a;
             if(pwd->retpass()==a)
             {

              cal->main_work();
              cout<<endl;
              cal->view_holidays();
              cal_fun();
              return;
            }
             else
             {
                 cout<<"Password Incorrect. Please Try Again..";
                 cout<<"\nDo You Want To Try Again (y/n) ";
                 cin>>b;
             }
         }
        //  }
          else if(counter==0)
          {
             cal->main_work();
             cout<<endl;
             cal->view_holidays();
             cal_fun();
             return;
          }
      }
    }
    else
    cout<<"\n\n\t APP NOT INSTALLED\n\n";
    }

   void app_uninstall()
   {
       if(pwd==NULL && cal==NULL && cl==NULL)
       {
           cout<<"\n No Apps Are Installed ";
       }
       else
       {
        counter=0;
        counter1=0;
       pwd=NULL;
       cl=NULL;
       cal=NULL;
         cout<<"\n All Apps Are Uninstalled Successfully ";
       count=count1=count2=0;
       }
   }

};


int main()
{
    mobile obj;
    char c='y';
    int a;
    while(c=='y' || c=='Y')
    {
    cout<<"\n APP MENU ";
    cout<<"\n 1.) Install An App. ";
    cout<<"\n 2.) Uninstall An App. ";
    cout<<"\n 3.) Address Book. ";
    cout<<"\n 4.) Calendar. ";
    cout<<"\n 5.) Password Safe. ";
    cout<<"\n 6.) Mobile Details. ";
    cout<<"\n 7.) Switch Off. ";
       cout<<"\n Please Enter your choice : ";
       cin>>a;
       switch(a)
       {
           case 1 :    obj.app_install();
                       break;
           case 2 :    obj.app_uninstall();
                       break;
           case 3:     obj.app_addressbook();
                       break;
           case 4:     obj.app_calendar();
                       break;
           case 5:     obj.app_passwordsafe();
                       break;
           case 6:     obj.show_details();
                       break;
           case 7:     exit(1);
                       break;
           default:
               cout<<"\n Invalid Choice.Please Select Valid Option ";
               break;
       }
    }
    //obj.app_install();

    return 0;
}
