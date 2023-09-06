#include <bits/stdc++.h>
using namespace std;
void menu();
void first();
void calling_resident();
void calling_visitor();
void calling_staff();
void calling_secretary();
class account
{
    string user_id;

public:
    string name;
    int age;
    string contact_no;
    void create_new_account()
    {
        fflush(stdin);
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your contact number: ";
        fflush(stdin);
        getline(cin, contact_no);
    }
    void display_details()
    {
    abc:
        cout << "Enter the contact no. to display the respective details:\n";
        cin >> user_id;
        if (contact_no == user_id && contact_no != "")
        {
            cout << "NAME : " << name << endl;
            cout << "AGE : " << age << endl;
            cout << "CONTACT NO. : " << contact_no << endl;
        }
        else
        {
            if (contact_no == "")
            {
                cout << "Account not found!!\n";
                cout << "Create new account\n";
                create_new_account();
                display_details();
            }
            else
            {
                cout << "Wrong input:\n";
                goto abc;
            }
        }
    }
    void modify_details()
    {
        int choose, New_age;
        string pno;
        string New_Name;
        char n;
    xyz:
        cout << "Enter your registered contact number to open your account: ";
        cin >> user_id;
        if (user_id.compare(contact_no) == 0 && contact_no != "")
        {
            do
            {
            y:
                cout << "Choose the detail you want to modify : " << endl;
                cout << "\t 1. NAME\n";
                cout << "\t 2. AGE\n";
                cout << "\t 3. CONTACT NUMBER\n";
                cin >> choose;
                switch (choose)
                {
                case 1:
                    cout << "\n enter new name : ";
                    fflush(stdin);
                    cin >> New_Name;
                    name = New_Name;
                    cout << " The modified details are : " << endl;
                    cout << "Name = " << name << "\nAge = " << age << "\nContact number =
                                                                      "<<contact_no;
                        break;
                case 2:
                    cout << "\n enter new age : ";
                    cin >> New_age;
                    age = New_age;
                    cout << " The modified details are : " << endl;
                    cout << "Name = " << name << "\nAge = " << age << "\nContact number =
                                                                      "<<contact_no;
                        break;
                case 3:
                    cout << "\n enter new contact number : ";
                    fflush(stdin);
                    cin >> pno;
                    contact_no = pno;
                    cout << " The modified details are : " << endl;
                    cout << "Name = " << name << "\nAge = " << age << "\nContact number =
                                                                      "<<contact_no;
                        break;
                default:
                    " Invalid choice! Task failed. Please try again. ";
                    goto y;
                }
                cout << "\n\nWant to edit more details? Y/N " << endl;
                fflush(stdin);
                cin >> n;
            } while (toupper(n) == 'Y');
        }
        else
        {
            if (contact_no == "")
            {
                cout << "\nPlease create an account first\n";
                create_new_account();
                char option;
                cout << "\nDo you want to edit your details\n";
                cin >> option;
                if (toupper(option) == 'Y')
                    modify_details();
            }
            else
            {
                cout << "Invalid contact number. Please try again !!!";
                goto xyz;
            }
        }
    }
};
class resident
{
    string user_id;

public:
    account acc;
    void payments()
    {
        double rent = 0, dep = 0, maintain = 0, pay = 0;
        int ch;
        char xy;
    xyz:
        cout << "Enter your registered contact number to open payment portal: ";
        cin >> user_id;
        if (user_id.compare(acc.contact_no) == 0 && acc.contact_no != "")
        {
            do
            {
            h:
                cout << "\n\nEnter your choice : ";
                cout << "\n1 . To pay monthly rent ." << endl;
                cout << "2 . To pay security deposit ." << endl;
                cout << "3 . To pay maintainence charges ." << endl;
                cin >> ch;
                switch (ch)
                {
                case 1:
                    cout << "\nEnter the amount you are paying : ";
                    cin >> pay;
                    rent = rent + pay;
                    cout << "Payment successful !!!";
                    break;
                case 2:
                    cout << "\nEnter the amount you are paying : ";
                    cin >> pay;
                    dep = dep + pay;
                    cout << "Payment successful !!!";
                    break;
                case 3:
                    cout << "\nEnter the amount you are paying : ";
                    cin >> pay;
                    maintain = maintain + pay;
                    cout << "Payment successful !!!";
                    break;
                default:
                    cout << "\n\nInvalid choice, please choose again";
                    goto h;
                }
                cout << "\n\nPress Y for another payment." << endl;
                cin >> xy;
            } while (toupper(xy) == 'Y');
        }
        else
        {
            if (acc.contact_no == "")
            {
                cout << "Please create an account first\n";
                acc.create_new_account();
                payments();
            }
            else
            {
                cout << "Invalid contact number. Please try again !!!";
                goto xyz;
            }
        }
    }
    void menu1()
    {
        cout << "\n\t\t\t\t\t*****************************************************";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t* 1.Create new_account *";
        cout << "\n\t\t\t\t\t* 2.Display details *";
        cout << "\n\t\t\t\t\t* 3.Modify details *";
        cout << "\n\t\t\t\t\t* 4.Payment portal *";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t*****************************************************";
    }
};
class secretary
{
    float total_rent_rec;
    float mothly_expenditure;
    string user_id;
    resident *r;

public:
    void enter_monetary_details()
    {
    klm:
        cout << "Enter your registered contact number to enter monetary details : ";
        cin >> user_id;
        if (user_id.compare(r->acc.contact_no) == 0 && r->acc.contact_no != "")
        {
            cout << "Enter the following details :\n ";
            cout << "\tTotal Rent : ";
            cin >> total_rent_rec;
            cout << "\tMonthly Expenditure : ";
            cin >> mothly_expenditure;
        }
        else
        {
            if (r->acc.contact_no == "")
            {
                cout << "Please create an account first\n";
                r->acc.create_new_account();
                enter_monetary_details();
            }
            else
            {
                cout << "Invalid contact number. Please try again !!!";
                goto klm;
            }
        }
    }
    void addresident(resident *r2)
    {
        r = r2;
    }
    void display_secretary()
    {
    pqr:
        cout << "Enter your registered contact number to display details : ";
        cin >> user_id;
        if (user_id.compare(r->acc.contact_no) == 0 && r->acc.contact_no != "")
        {
            r->acc.display_details();
            cout << "\nHere's the data for this month:";
            cout << "\nTotal rent collected : " << total_rent_rec;
            cout << endl
                 << "Monthly expenditure : " << mothly_expenditure << endl;
        }
        else
        {
            if (r->acc.contact_no == "")
            {
                cout << "Please create an account first\n";
                r->acc.create_new_account();
                display_secretary();
            }
            else
            {
                cout << "Invalid contact number. Please try again !!!";
                goto pqr;
            }
        }
    }
    void menu4()
    {
        cout << "\n\t\t\t\t\t*****************************************************";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t* 1.Create new_account *";
        cout << "\n\t\t\t\t\t* 2.Modify details *";
        cout << "\n\t\t\t\t\t* 3.Payment portal *";
        cout << "\n\t\t\t\t\t* 4.Enter monetary details *";
        cout << "\n\t\t\t\t\t* 5.Display monetary details *";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t*****************************************************";
    }
};
class visitor
{
private:
    string destination;
    string date;
    int hr, min;

public:
    account acc;
    void visitor_details()
    {
        cout << " Enter the apartment no. you want to visit : ";
        fflush(stdin);
        getline(cin, destination);
        cout << " Enter check-in date : ";
        fflush(stdin);
        getline(cin, date);
        cout << "Check-in time : ";
        cout << " enter Hours : ";
        cin >> hr;
        cout << "\t\tenter Minutes : ";
        cin >> min;
        cout << " Thank you " << acc.name << ", for visiting our society on " << date << " at " << hr << "
            : "<<min;
    }
    void menu2()
    {
        cout << "\n\t\t\t\t\t*****************************************************";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t* 1.Create new_account *";
        cout << "\n\t\t\t\t\t* 2.Display details *";
        cout << "\n\t\t\t\t\t* 3.Visiting details *";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t*****************************************************";
    }
};
class staff
{
private:
    char type[20];
    char entry_time[10];
    char date[20];
    char exit_time[10];
    int wrk_hrs;
    string staff_id;

public:
    account acc;
    void enter_jobdetails()
    {
        cout << "\nEnter your staff id:";
        fflush(stdin);
        cin >> staff_id;
        cout << "\nEnter the type of task:";
        fflush(stdin);
        cin >> type;
        cout << "\nEnter the date:";
        fflush(stdin);
        cin >> date;
        cout << "\nEnter the entry time";
        fflush(stdin);
        cin >> entry_time;
        cout << "\nEnter the exit time:";
        fflush(stdin);
        cin >> exit_time;
        cout << "\nEnter working hours:";
        cin >> wrk_hrs;
    }
    void display_jobdetails()
    {
        string staff_userId;
    k:
        cout << "Enter the staff Id : ";
        cin >> staff_userId;
        if (staff_id == staff_userId && staff_id != "")
        {
            cout << "\nStaff Id: " << staff_userId;
            cout << "\nJob Type: " << type;
            cout << "\nDate: " << date;
            cout << "\nEntry time: " << entry_time;
            cout << "\nExit time: " << exit_time;
            cout << "\nWorking hours: " << wrk_hrs;
        }
        else
        {
            if (staff_id == "")
            {
                if (acc.contact_no == "")
                {
                    cout << endl
                         << "Please create an account first. ";
                    acc.create_new_account();
                    cout << "Account details:\n";
                    acc.display_details();
                }
                cout << "Please enter job details first:\n";
                enter_jobdetails();
            }
            else
                cout << endl
                     << "Invalid Input. Try again. " << endl;
            goto k;
        }
    }
    void menu3()
    {
        cout << "\n\t\t\t\t\t*****************************************************";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t* 1.Create new_account *";
        cout << "\n\t\t\t\t\t* 2.Display details *";
        cout << "\n\t\t\t\t\t* 3.Modify details *";
        cout << "\n\t\t\t\t\t* 4.Enter Job details *";
        cout << "\n\t\t\t\t\t* 5.Display Job details *";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t* *";
        cout << "\n\t\t\t\t\t*****************************************************";
    }
};
int main()
{
    first();
    char ch;
    do
    {
    aa:
        int choice;
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            calling_resident();
            break;
        case 2:
            calling_visitor();
            break;
        case 3:
            calling_staff();
            break;
        case 4:
            calling_secretary();
            break;
        default:
            cout << "\t\t\t\t\t\tInvalid entry, please choose again !!!\n";
            goto aa;
        }
        cout << "Continue? Y/N: ";
        fflush(stdin);
        cin >> ch;
    } while ('Y' == toupper(ch));
    return 0;
}
void menu()
{
    cout << "";
    cout << "The categories available for management in the society are as follows :
            "<<endl<<endl;
        cout
         << "\n\t\t\t\t\t*****************************************************";
    cout << "\n\t\t\t\t\t* *";
    cout << "\n\t\t\t\t\t* 1.Residents *";
    cout << "\n\t\t\t\t\t* 2.Visitors *";
    cout << "\n\t\t\t\t\t* 3.Staff *";
    cout << "\n\t\t\t\t\t* 4.Secretary Portal *";
    cout << "\n\t\t\t\t\t* *";

    cout << "\n\t\t\t\t\t*****************************************************\n\n\n";
    cout << "Enter your choice for the management category : ";
}
void first()
{
    cout << "\n\t\t\t\t\t*****************************************************";
    cout << "\n\t\t\t\t\t* *";
    cout << "\n\t\t\t\t\t* WELCOME *";
    cout << "\n\t\t\t\t\t* TO *";
    cout << "\n\t\t\t\t\t* HOUSING SOCIETY MANAGEMENT SYSTEM *";
    cout << "\n\t\t\t\t\t* *";

    cout << "\n\t\t\t\t\t*****************************************************" << endl
         << endl
         << endl;
}
void calling_resident()
{
    resident r;
    char cont;
    do
    {
    x:
        r.menu1();
        int ch;
        cout << "\n\nEnter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            r.acc.create_new_account();
            break;
        case 2:
            r.acc.display_details();
            break;
        case 3:
            r.acc.modify_details();
            break;
        case 4:
            r.payments();
            break;
        default:
            cout << "Invalid choice !!!";
            goto x;
        }
        cout << "\n\nTo continue press 'Y' and to end press 'N' " << endl;
        fflush(stdin);
        cin >> cont;
    } while (toupper(cont) == 'Y');
    return;
}
void calling_visitor()
{
    visitor v;
    int c;
    char co;
    do
    {
    vi:
        v.menu2();
        cout << "\n\nEnter your choice" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            v.acc.create_new_account();
            break;
        case 2:
            v.acc.display_details();
            break;
        case 3:
            v.visitor_details();
            break;
        default:
            cout << "Invalid choice , please enter again" << endl;
            goto vi;
        }
        cout << "\n\nTo continue press 'Y' and to end press 'N' " << endl;
        fflush(stdin);
        cin >> co;
    } while ('Y' == toupper(co));
}
void calling_staff()
{
    staff s;
    char a;
    do
    {
    ab:
        s.menu3();
        int choice3;
        cout << "\n\nEnter choice";
        cin >> choice3;
        // system("cls");
        switch (choice3)
        {
        case 1:
            s.acc.create_new_account();
            break;
        case 2:
            s.acc.display_details();
            break;
        case 3:
            s.acc.modify_details();
            break;
        case 4:
            s.enter_jobdetails();
            break;
        case 5:
            s.display_jobdetails();
            break;
        default:
            cout << "Invalid entry, Please Renter!!!";
            goto ab;
        }
        cout << "\n\nContinue?\n";
        cout << "Enter y:Yes and n:NO\n";
        fflush(stdin);
        cin >> a;
    } while (toupper(a) == 'Y');
}
void calling_secretary()
{
    secretary s;
    resident *r1 = new resident;
    int choice;
    char c;
    do
    {
        s.addresident(r1);
    abd:
        s.menu4();
        cout << "\n\nEnter choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            r1->acc.create_new_account();
            break;
        case 2:
            r1->acc.modify_details();
            break;
        case 3:
            r1->payments();
            break;
        case 4:
            s.enter_monetary_details();
            break;
        case 5:
            s.display_secretary();
            break;
        default:
            cout << "\nInvalid input , Please try again!!!" << endl;
            goto abd;
        }
        cout << "\n\nContinue?\n";
        cout << "Enter y:Yes and n:NO\n";
        fflush(stdin);
        cin >> c;
    } while (toupper(c) == 'Y');
}