#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctype.h>
#include<windows.h>
#include<limits>
using namespace std;
struct callerInfo
{
    string firstName,
           lastName,
           phoneNo;
    char gender;
};
int id = 1;
string toUpper(string name);
string capitalize(string);
void print(callerInfo,int);
void add(callerInfo[]);
void search(callerInfo[]);
bool isChar(string name);
bool isNumber(string& name);
void set(callerInfo x[]);
void option();
void remove(callerInfo []);
void sort(callerInfo list[],callerInfo insert);
void search(callerInfo []);
void searchByGender(callerInfo caller[], char gender);
void searchByPhoneNumber(callerInfo caller[], const string& phoneNumber);
void searchByName(callerInfo caller[], const string& name);
void modify(callerInfo []);
void read(callerInfo []);
void write(callerInfo[]);   
int main()
{
    callerInfo list[100];
    set(list);
    read(list);
    cout << "\033[32m";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t";
    system("pause");  
    system("cls");
    cout << "\033[0m";
    for(int i = 0; i < id - 1; i++)
    {
        print(list[i],i+1);
    }
    while(1)
    {
        cout << "Another example is being made."; 
        option();
        int reply;
        check1:
        cout << "\033[34mInput reply :\033[33m ";
        cin >> reply;
        if (cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\033[1;31mINVALID INPUT!!\n";
        goto check1;
        }
        cout << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       // system("cls");
        switch(reply)
        {
        case 1:
            system("cls");
            for(int i = 0; i < id - 1; i++)
            {
                print(list[i],i+1);
            }
            break;
        case 2:
            search(list);
            break;
        case 3:
            add(list);
            break;
        case 4:
            modify(list);
            break;
        case 5:
            remove(list);
            break;
        case 9:
               write(list);
            return 0;
        default:
            cout << "\033[1;31mInput Correct reply!!\033[0m\n";
            break;
        }
    }
    return 0;
}
string capitalize(string name)
{
    string temporary = "";
    temporary = char(toupper(name[0]));
    for(int i = 1; i < name.length(); i++)
        temporary += char(tolower(name[i]));
    return temporary;
}
void print(callerInfo caller,int n)
{
    cout << left;
    cout <<  "\033[36m---------------------------------------------------------------------------\n"
         << "\033[34m" <<setw(15)<< "ID:\033[33m " << n << endl
         <<  "\033[36m---------------------------------------------------------------------------\033[36m\n"
         <<"\033[34m" <<setw(15)<< "Full Name:\033[33m"<<caller.firstName <<" "<< caller.lastName<<endl<<endl
         <<"\033[34m" <<setw(15)<< "Gender:\033[33m"<<caller.gender<<endl<<endl
         <<"\033[34m" <<setw(15)<< "Phone No:\033[33m"<<caller.phoneNo<<endl
         <<  "\033[35m---------------------------------------------------------------------------\033[0m\n\n";
}
void add(callerInfo list[])
{
    string first,last,num;
    char gen;
    system("cls");
label:
    cout << "\033[34m Input First Name : \033[33m";
    cin >> first;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout <<"\033[34m Input Last Name  : \033[33m";
    cin >> last;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    check2:
    cout << "\033[34m Input Gender('M' for male or 'F' for female) : \033[33m";
    cin >> gen;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << " \033[1;31mINVALID INPUT!!\n ";
        goto check2;
        }
    cout << "\033[34m Input Phone Number : \033[33m";
    cin >> num;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    if(!(isChar(first)))
    {
        cout << "\033[1;31merror!! First Name can only have lettes!\n\033[0m";
        goto label;
    }
    if(!(isChar(last)))
    {
        cout << "\033[1;31merror!! Last Name can only have letters!\033[0m\n";
        goto label;
    }
    if(!(isNumber(num)))
    {
        cout << "\033[1;31merror!! Phone Number can only have numbers!\033[0m\n";
        goto label;
    }
    if(gen != 'M' && gen != 'm' && gen != 'F' && gen != 'f')
    {
        cout << "\033[1;31merror!! Gender can only be 'M' or 'F'!\033[0m\n";
        goto label;
    }
    if(num.length() < 9)
    {
        cout << "\033[1;31merror!! Phone Number must have atleast 9 digits!\033[0m\n";
        goto label;
    }

    callerInfo temporary;
    temporary.firstName = capitalize(first);
    temporary.lastName = capitalize(last);
    temporary.gender = char(toupper(gen));
    temporary.phoneNo = num;

    sort (list,temporary);

    cout << "\033[32mContact Successfully Added\n"
         << "\033[34mTo add another reply('y') :\033[33m ";
    string reply;
    cin >> reply;
    cout <<"\033[0m"<<endl;
    if(reply == "y" || reply == "Y")
        goto label;
    write(list);    
    system("cls");
    for(int i = 0; i < id - 1; i++)
    {
        print(list[i],i+1);
    }
}

bool isChar(string name)
{
    for(char c : name)
        if(!(isupper(c) || islower(c)))
            return false;
    return true;
}
bool isNumber(string& name)
{
    for(char c : name)
    {
        if(!(isdigit(c)))
            return false;
    }
    return true;
}
void option()
{
    cout <<"\033[32m"
         <<"please choose:\033[0m\n\n"
         << "\033[34m1.\033[33mView all contacts\n"
         << "\033[34m2.\033[33mSearch for contact\n"
         << "\033[34m3.\033[33mAdd new contact\n"
         << "\033[34m4.\033[33mModify existing contact\n"
         << "\033[34m5.\033[33mRemove existing contact\n"
         << "\033[34m9.\033[33mexit \033[0m\n";
}
void set(callerInfo x[])
{
    x[0].firstName = "zzzzzzz";
    x[0].lastName = "zzzzzzz";
    x[0].gender = '\0';
    x[0].phoneNo= "";
}
void remove(callerInfo list[])
{
    system("cls");
    cout << "\033[32mWhich contact do you want delete\n";
    check5:
    cout << "\033[34mInput Id :\033[33m ";
 int choice;
    cin >> choice;
    if (cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << " \033[1;31mINVALID INPUT!!\n";
        goto check5;
        }

    cout << "\033[0m";

    if(choice > id - 1)
        cout << "\033[1;31mNo contact by that Id.\033[0m\n";
    else
    {
        callerInfo temp = list[choice - 1];
        cout << "\033[34mDo you wanto remove \033[33m"<<temp.firstName << " "<<temp.lastName<<"\033[34m.(y/n) :\033[33m ";
        string reply;
        cin >> reply;
        cout << "\033[0m";
        if(reply == "y" || reply == "Y")
        {
            for(int i = choice - 1; i < id ; i++)
            {
                list[i] = list[i + 1];
            }
            id --;
            cout << "\033[32mSuccessfully Removed\033[32m " <<temp.firstName << " "<<temp.lastName<<"\033[32m.\033[34m\n";
             system("pause");
             write(list);
        }
    }
    system("cls");
}
void sort(callerInfo list[],callerInfo insert)
{
    for(int i = 0; i < id; i++)
    {
        if(insert.firstName < list[i].firstName)
        {
            callerInfo temp = list[i];
            list[i] = insert;
            callerInfo swap[id - i];
            swap[0] = temp;
            int n = i;
            for(int j = 1 ; j < id  - i ; j++)
            {
                swap[j] = list[n + 1];
                n++;
            }
            n = 0;
            for(int k = i + 1; k <= id ; k++)
            {
                list[k] = swap[n];
                n++;
            }

            goto skip;
        }
        else if(insert.firstName == list[i].firstName)
        {
            if(insert.lastName < list[i].lastName)
            {
                callerInfo temp = list[i];
                list[i] = insert;
                callerInfo swap[id - i];
                swap[0] = temp;
                int n = i;
                for(int j = 1 ; j < id  - i ; j++)
                {
                    swap[j] = list[n + 1];
                    n++;
                }
                n = 0;
                for(int k = i + 1; k <= id ; k++)
                {
                    list[k] = swap[n];
                    n++;
                }

                goto skip;
            }
        }

    }
skip:
    id++;
}
void search(callerInfo caller[])
{
    system("cls");
    int n = 1;
    do {
        cout << "\033[32mSearch by:\n"
             << "\033[34m1.\033[33m Name\n"
             << "\033[34m2.\033[33m Phone Number\n"
             << "\033[34m3.\033[33m Gender\n"
             << "\033[34m4.\033[33m Back to main menu\n"
             << "\033[34mEnter your choice: \033[33m";

        int searchChoice;
        cin >> searchChoice;
        cout << "\033[0m";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (searchChoice) {
            case 1:
            {
                cout << "\033[34mEnter Name: \033[33m";
                string name;
                getline(cin, name);
                cout << "\033[0m";
                searchByName(caller, name);
                break;
            }
            case 2:
            {
                cout << "\033[34mEnter Phone Number: \033[33m";
                string phoneNumber;
                cin >> phoneNumber;
                cout << "\033[0m";
                searchByPhoneNumber(caller, phoneNumber);
                break;
            }
            case 3:
            {
                cout << "\033[34mEnter Gender ('M' or 'F'): \033[33m";
                char gender;
                cin >> gender;
                cout << "\033[0m";
                searchByGender(caller, gender);
                break;
            }
            case 4:
                n = 0; 
                system("cls");
                return;
            default:
                cout << "\033[1;31mInvalid choice. Please select a valid option.\033[0m\n";
                break;
        }
        cout << "\033[34mDo you want to search again (y/n): \033[33m";
        string reply;
        cin >> reply;
        cout << "\033[0m" << endl;

        if (reply != "y" && reply != "Y")
            n = 0; 

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (n == 1);

    system("cls");
}

void searchByName(callerInfo caller[], const string& name)
{
    bool found = false;

    for (int i = 0; i < id; i++)
    {
        string fullName = caller[i].firstName + " " + caller[i].lastName;

        if (toUpper(name) == toUpper(fullName.substr(0, name.length())))
        {
            if (!found)
            {
                cout << "\033[34mSearch Results:\n";
                found = true;
            }
            print(caller[i], i + 1);
            for(int j = i + 1; j < id;j++)
            {
                string fullName = caller[j].firstName + " " + caller[j].lastName;

        if (toUpper(name) == toUpper(fullName.substr(0, name.length())))
        {
            print(caller[j], j + 1);
        }
        else break;
        }
        break;
    }
    }
    if (!found)
        cout << "\033[1;31mNo contacts found with the specified name.\033[0m\n";
}

void searchByPhoneNumber(callerInfo caller[], const string& phoneNumber)
{
    bool found = false;

    for (int i = 0; i < id; i++)
    {
        if (phoneNumber == caller[i].phoneNo.substr(0,phoneNumber.length()))
        {
            if (!found)
            {
                cout << "\033[34mSearch Results:\n";
                found = true;
            }
            print(caller[i], i + 1);
        }
    }

    if (!found)
        cout << "\033[1;31mNo contacts found with the specified phone number.\033[0m\n";
}

void searchByGender(callerInfo caller[], char gender)
{
    bool found = false;

    for (int i = 0; i < id; i++)
    {
        if (toupper(gender) == caller[i].gender)
        {
            if (!found)
            {
                cout << "\033[34mSearch Results:\n";
                found = true;
            }
            print(caller[i], i + 1);
        }
    }

    if (!found)
        cout << "\033[1;31mNo contacts found with the specified gender.\033[0m\n";
}
void modify(callerInfo caller[])
{
    system("cls");
    check3:
    cout << "\033[34mInput tbe ID number of the person :\033[33m ";
    int reply;    
    cin >> reply;
    if (cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << " \033[1;31mINVALID INPUT!!\n";
        goto check3;
        }
        cout << "\033[0m";
    if(caller[reply-1].firstName != "")
    {
        print(caller[reply - 1],reply);
error:
        cout << "\033[32mWhat do you want to modify\n"
             << "\033[34m1.\033[33mFirst Name\n"
             << "\033[34m2.\033[33mLast Name\n"
             << "\033[34m3.\033[33mGender\n"
             << "\033[34m4.\033[33mPhone Number\n"
             << "\033[34m9.\033[33mexit\n";
      check4:
        cout << "\033[34mInput choice :\033[33m ";
        int choice;
        string name;
        cin >> choice;
        if (cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << " \033[1;31mINVALID INPUT!!\n";
        goto check4;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\033[0m";
        switch(choice)
        {
        case 1 :
            cout << "\033[34mInput First Name :\033[33m ";
            cin >> name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (!(isChar(name)))
            {
                cout << "\033[1;31merror!! First Name can only have lettes!\033[0m\n";
                goto error;
            }
            else
            {
                caller[reply - 1].firstName = capitalize(name);
                cout << "\033[32mChanged successfully.\033[0m\n";
                print(caller[reply - 1],reply);
                cout << "\033[34m";
                 system("pause");
                 write(caller);
            }
            break;
        case 2:
            cout << "\033[34mInput Last Name :\033[33m ";
            cin >> name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (!(isChar(name)))
            {
                cout << "\033[1;31merror!! Last Name can only have lettes!\033[0m\n";
                goto error;
            }
            else
            {
                caller[reply - 1].lastName = capitalize(name);
                cout << "\033[32mChanged successfully.\n\033[0m";
                print(caller[reply - 1],reply);
                cout << "\033[34m";
                 system("pause");
                write(caller);
            }
            break;
        case 3:
            if(caller[reply - 1].gender == 'M')
                caller[reply - 1].gender = 'F';
            else caller[reply - 1].gender = 'M';
            cout << "\033[32mChanged successfully.\033[0m\n";
            print(caller[reply - 1],reply);
            cout << "\033[34m";
             system("pause");
             write(caller);
            break;
        case 4:
            cout << "\033[34mInput number :\033[33m ";
            cin >> name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(!(isNumber(name)))
            {
                cout << "\033[1;31merror!! Phone Number can only have number!\033[0m\n";
                goto error;
            }
            if(name.length() < 9)
           {
            cout << "\033[1;31merror!! Phone Number must have atleast 9 digits!\033[0m\n";
             goto error;
           }
            else
            {
                caller[reply - 1].phoneNo = name;
                cout << "\033[32mChanged successfully.\033[0m\n";
                print(caller[reply - 1],reply);
                cout << "\033[34m";
                system("pause");
                write(caller);
            }
            break;
        case 9:
            system("cls");
            break;
        default :
            cout << "\033[1;31mInput correct choice!\033[0m\n";
            goto error;
        }
    }
    else cout << "\033[1;31mNo contact by that ID.\033[0m\n";
    system("cls");
}
void read(callerInfo callerId[])
{
    fstream infile("callerId.dat",ios::in | ios::binary);
    if(!infile)
    {
        cout << "\033[32m PHONEBOOK!\n";
    }
    else
    {
        infile.read((char*)&id,sizeof(id));
        infile.close();
        infile.open("callerInfo.dat", ios::in | ios::binary);
         if(!infile)
        cout << "cann't open the file!!\n";
        else
        {
        for(int i = 0 ; i < id ; i++)
        infile.read(reinterpret_cast<char*>(&callerId[i]), sizeof(callerInfo));
        infile.close();
        }
    }
   
}
void write(callerInfo callerId[])
{
    fstream outfile("callerId.dat",ios::out | ios::binary);
    if(!outfile)
    {
        cout << "Error opening the file!";
    }
    else
    {
        outfile.write((char*)&id,sizeof(id));
        outfile.close();
        outfile.open("callerInfo.dat",ios::out | ios::binary);
        if(!outfile)
        cout << "cann't open the file!!\n";
        else
        {
        for(int i = 0 ; i < id ; i++)
        outfile.write(reinterpret_cast<char*>(&callerId[i]) , sizeof(callerId[i]));
        outfile.close();
        }
    }
}
string toUpper(string name)
{
    string temp = "";
for(char c : name)
temp += toupper(c);
return temp;
}