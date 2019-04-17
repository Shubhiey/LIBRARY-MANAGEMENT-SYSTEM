//admin password admin@123
#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
static long long int idd=0;                           //admin password admin@123
static long long int ids=0;
class books{
    public:
    string name;
    string author;
    string genre;
    string subject;
    string publish;
    string available="AVAILABLE";
    private:
    string last_issued="never";
    long long int id;
    //static long long int idd;
    public:
    books(string n,string a,string g,string sub,string pub)
    {
        name=n;
        author=a;
        subject=sub;
        publish=pub;
        genre=g;
        id=++idd;
    }
    void display_book() const
    {
        cout<<"Book id:\n\t"<<id<<"\n";
        cout<<"Name:\n\t"<<name<<"\n";
        cout<<"Author:\n\t"<<author<<"\n";
        cout<<"Publisher:\n\t"<<publish<<"\n";
        cout<<"Subject:\n\t"<<subject<<"\n";
        cout<<"Genre:\n\t"<<genre<<"\n";
        cout<<"Last issued:\n\t"<<last_issued<<"\n";
        cout<<"Availability:\n\t"<<available<<"\n";
    }
    void get_issued()
    {

    time_t tt;
    struct tm * ti;
    time (&tt);
    ti = localtime(&tt);

    cout << "The book is being issued at:\n\t "
         << asctime(ti);


        last_issued=asctime(ti);
        available="NOT AVAILABLE";
    }


    void return_back()
    {
        available="AVAILABLE";
         time_t tt;
    struct tm * ti;
    time (&tt);
    ti = localtime(&tt);
    string ret_time;
    cout << "The book is being Returned at:\n\t "
         << asctime(ti)<<"\n";
        ret_time=asctime(ti);
        cout<<"\nPlease charge the necessary fine if applicable\n";

        }

    };


class student{
            string name;
            int year;
            int roll;
            long long int lid;
            long long int phone;
            vector <books> isb;
            public:
            student(string n,int y,int r,long long int p)
            {
                name=n;
                year=y;
                roll=r;
                phone=p;
                lid=++ids;
            }
            void display_student() const
            {
                cout<<"Student Library id:\n\t"<<lid<<"\n";
                cout<<"Name:\n\t"<<name<<"\n";
                cout<<"Roll Number:\n\t"<<roll<<"\n";
                cout<<"Year:\n\t"<<year<<"\n";
                cout<<"Phone:\n\t"<<phone<<"\n";
                cout<<"Details of the Books issued:\n\t";
                if((isb.size())>0){
                for (int i=0;i<(isb.size());i++)
               {
                   cout<<"\n\n\n\n";
                    isb[i].display_book();

               }}
               else
                cout<<"This Students has no issued book\n\t";
            }
            /*
            void issued()
            {
            for (int i=0;i<(isb.begin()-isb.end()+1);i++)
               {
                   cout<<"\n\n\n\n";
                    isb[i].display_book();

               }                 //last_issued=;
            }*/
            void issue_book(books b1)
            {
            isb.push_back(b1);               //last_issued=;
            }


            };



vector <books> bk;
vector <student>st;
void AdminMenu(void);
void studentmenu(void);

void addnew_book();
void addnew_student();
void reqnew_book();
void search_book(string);
void search_book(string,int);
int main()
{
    system("CLS");
    cout<<"                                                               Welcome to XYZ University/College/School                                     "<<"\n";
    cout<<"                                                                               Library                                                      "<<"\n";
    cout<<"Enter the following choice"<<endl;
    cout<<"1. Student "<<endl;
    cout<<endl;
    cout<<"2. Admin" <<endl;
    cout<<endl;
     cout<<"3. About us" <<endl;
    int num;
    cin>>num;
    string s;
    system("CLS");
    switch(num)
    {
        case 1:studentmenu();
        break;
        case 3:cout<<"Library Management system" <<endl;
            cout<<"Developed by"<<endl;
            cout<<"Three Amigos"<<endl;
             cout<<"Shubham Singh"<<endl;
            cout<<"Sharif Nawaz"<<endl;
             cout<<"Arpit Verma"<<endl;
             break;


        case 2:system("CLS");
             cout<<"Please Enter the Admin Password:\n\t\t\t";
             cout<<"*********\n\t\t\t";
             cin>>s;
             if(s=="admin@123")
                AdminMenu();
             else
             {
                 system("CLS");
                  cout<<"The Entered Password is wrong you will be taken back shortly\n\t\t";
                long long int n=3500000000;
                  while(n--);
                  main();
             }
        break;
        default:
             cout<<"Invalid Choice! The Application will END";
    }


}

void AdminMenu()
{
 int adminchoice;

    system("CLS");
	cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\t\t\t\t\t\t\t\t          ADMININSTRATOR'S MENU:-";
	cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n\t\t\t\t 1. SEARCH BOOK  \t\t\t 2. ADD NEW STUDENT  \n\n\t\t\t\t 3. ADD NEW BOOK  \t\t\t 4. RETURN BOOK \n\n\t\t\t\t 5.EDIT STUDENT DETAILS \t\t 6.Go Back To Main Menu \n\n\t\t\t\t [ESC]. RETURN "<<"\n\nEnter Choice :";
    cin>>adminchoice;
    string str;
    int x=0;
   switch(adminchoice)
    {
        case 1:
            system("CLS");
            cout<<"Enter Name of the book to be searched\n";

           cin>>str;
           search_book(str,x);
           break;
        case 2:addnew_student();
        break;
        case 3:addnew_book();
        break;
        case 4:cout<<"Enter the ID of the Book\n\t";
        int k;
        cin>>k;
        bk[k].return_back();
         break;/*
         case 5:Edit_studetails();
         break;*/
         case 6:main();
         break;
         default:
            cout<<"Wrong choice entered"<<endl;

    }

	}

void studentmenu()
{
 int studchoi;
  system("CLS");

	cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\t\t\t\t\t\t\t\t          STUDENT'S MENU:-";
	cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n\t\t\t\t 1. SEARCH BOOK  \t\t\t 2. ISSUE BOOKS \n\n\t\t\t\t 3. REQUEST NEW BOOKS AS ANONYMOUS  \t 4.Go back to Main Menu" <<"\n\nEnter Choice :";
    cin>>studchoi;
    string str;
    switch(studchoi)
    {

       case 1:
           system("CLS");
           cout<<"Enter Name of the book to be searched\n";
           cin>>str;
           search_book(str);
            break;
        case 2:
            system("CLS");
           cout<<"Enter Name of the book to be issued\n";
           cin>>str;
           search_book(str);
         break;
        case 3:reqnew_book();
        break;
        case 4:main();
        break;
         default:
            cout<<"Wrong choice entered"<<endl;

    }


  }

void addnew_book()
{
    string name;
    string author;
    string genre;
    string subject;
    string publish;
    system("CLS");
    cout<<"Enter The Following Details\nPress any key to continue";
    char q;
    cin>>q;
    system("CLS");
    cout<<"Enter Name of the Book:\n";
    cin>>name;
    system("CLS");
    cout<<"Enter Name of the Author of the Book:\n";
    cin>>author;
    system("CLS");
    cout<<"Enter Genre of the Book:\n";
    cin>>genre;
    system("CLS");
    cout<<"Enter Subject of the Book:\n";
    cin>>subject;
    system("CLS");
    cout<<"Enter Name of the Publisher of the Book:\n";
    cin>>publish;
    books temp(name,author,genre,subject,publish);
    bk.push_back(temp);
    system("CLS");
    cout<<"The Following details have been entered and generated:\n";
    (bk.back()).display_book();
    cout<<"\n\n\nEnter e to exit or b to return back to admin page:\n";
    cin>>q;
    if(q=='b')
    AdminMenu();
    else if(q=='e')
        exit(0);
}




void addnew_student()
{
    string name;
    int year;
    int r;
    long long int ph;
    system("CLS");
    cout<<"Enter The Following Details\nPress any key to continue";
    char q;
    cin>>q;
    system("CLS");
    cout<<"Enter Name of the Student:\n";
    cin>>name;
    system("CLS");
    cout<<"Enter Year of the Students:\n";
    cin>>year;
    system("CLS");
    cout<<"Enter Roll Number of the Student:\n";
    cin>>r;
    system("CLS");
    cout<<"Enter Phone number of the Student:\n";
    cin>>ph;
    student temp(name,year,r,ph);
    st.push_back(temp);
    system("CLS");
    cout<<"The Following details have been entered and generated:\n";
    st[(st.begin()-st.end()+1)].display_student();
    cout<<"\n\n\nEnter e to exit or b to return back to admin page:\n";
    cin>>q;
    if(q=='b')
    AdminMenu();
    else if(q=='e')
        exit(0);
}
void reqnew_book(void)
{

    string name;
    string author;
    string genre;
    string subject;
    string publish;
    system("CLS");
    cout<<"Enter The Following Details\nPress any key to continue";
    char q;
    cin>>q;
    system("CLS");
    cout<<"Enter Name of the Book:\n";
    cin>>name;
    system("CLS");
    cout<<"Enter Name of the Author of the Book:\n";
    cin>>author;
    system("CLS");
    cout<<"Enter Genre of the Book:\n";
    cin>>genre;
    system("CLS");
    cout<<"Enter Subject of the Book:\n";
    cin>>subject;
    system("CLS");
    cout<<"Enter Name of the Publisher of the Book:\n";
    cin>>publish;
    books temp(name,author,genre,subject,publish);
    bk.push_back(temp);
    system("CLS");
    cout<<"Thanks for suggestion\n";
   // bk[(bk.begin()-bk.end()+1)].display_book();
    cout<<"\n\n\nEnter e to exit or b to return back to student page:\n";
    cin>>q;
    if(q=='b')
    studentmenu();
    else if(q=='e')
        exit(0);
}

void search_book(string b1)
{
    int i;
    if((bk.size())>0){
                for (i=0;i<(bk.size());i++)
               {
                   if(bk[i].name==b1)
                   {
                       cout<<"THE DETAILS OF THE BOOK MENTIONED BY YOU ARE AS FOLLOWS\n";
                       bk[i].display_book();
                       break;
                   }
               }
    }
    else
                {cout<<"Sorry the library has Currently No books\n\t";
                cout<<"\n\n\nEnter e to exit or b to return back to student page:\n";
    char q;
    cin>>q;
    if(q=='b')
    studentmenu();
    else if(q=='e')
        exit(0);}

if(bk[i].available=="AVAILABLE"){
    cout<<"\n\n\nEnter i to issue this book, e to exit or b to return back to student page:\n";
    char q;
    cin>>q;
    if(q=='b')
    studentmenu();
    else if(q=='e')
        exit(0);
    else if(q=='i')
        bk[i].get_issued();
        cout<<"\n\n\nEnter e to exit or b to return back to student page:\n";
    cin>>q;
    if(q=='b')
    studentmenu();
    else if(q=='e')
        exit(0);
        }

    else
    {
        cout<<"\n\n\nEnter e to exit or b to return back to student page:\n";
    char q;
    cin>>q;
    if(q=='b')
    studentmenu();
    else if(q=='e')
        exit(0);
    }
}


void search_book(string b1 ,int x)
{
    if((bk.size())>0){
                for (int i=0;i<(bk.size());i++)
               {
                   if(bk[i].name==b1)
                   {
                        cout<<"THE DETAILS OF THE BOOK MENTIONED BY YOU ARE AS FOLLOWS\n";
                       bk[i].display_book();
                       break;
                   }
               }
    }
    else
                cout<<"Sorry the library has Currently No books\n\t";


    cout<<"\n\n\n e to exit or b to return back to student page:\n";
    char q;
    cin>>q;
    if(q=='b')
        AdminMenu();
    else if(q=='e')
        exit(0);
}



