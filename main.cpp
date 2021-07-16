#include <iostream>
#define max 5
using namespace std;

struct employee {
    string name;
    long int code;
    string designation;
    int exp;
    int age;
};
 
int num;
void showMenu();

employee emp[max], tempemp[max],
    sortemp[max], sortemp1[max];

void build()
{
    cout << "::Build The Table::\n";
    cout << "Maximum Entries:: "
         << max << "\n";
 
    cout << "Enter the number of "
         << "Entries required::";
    cin >> num;
 
    if (num > 5) {
        cout << "!!!Maximum number of "
             << "Entries are 5 !!!\n";
        num = 5;
    }
    cout << "Enter the following data:\n";
 
    for (int i = 0; i < num; i++) {
        cout << "Name:: ";
        cin >> emp[i].name;
 
        cout << "Employee ID:: ";
        cin >> emp[i].code;
 
        cout << "Designation:: ";
        cin >> emp[i].designation;
 
        cout << "Experience:: ";
        cin >> emp[i].exp;
 
        cout << "Age:: ";
        cin >> emp[i].age;
    }
 
    showMenu();
}

void insert()
{
    if (num < max) {
        int i = num;
        num++;
 
        cout << "Enter the information "
             << "of the Employee::\n";
        cout << "Name:: ";
        cin >> emp[i].name;
 
        cout << "Employee ID :: ";
        cin >> emp[i].code;
 
        cout << "Designation:: ";
        cin >> emp[i].designation;
 
        cout << "Experience:: ";
        cin >> emp[i].exp;
 
        cout << "Age:: ";
        cin >> emp[i].age;
    }
    else {
        cout << "::::Employee Table Full::::\n";
    }
 
    showMenu();
}

void deleteIndex(int i)
{
    for (int j = i; j < num - 1; j++) {
        emp[j].name = emp[j + 1].name;
        emp[j].code = emp[j + 1].code;
        emp[j].designation
            = emp[j + 1].designation;
        emp[j].exp = emp[j + 1].exp;
        emp[j].age = emp[j + 1].age;
    }
    return;
}

void deleteRecord()
{
    cout << "Enter the Employee ID "
         << "to Delete Record::";
 
    int code;
 
    cin >> code;
    for (int i = 0; i < num; i++) {
        if (emp[i].code == code) {
            deleteIndex(i);
            num--;
            break;
        }
    }
    cout <<"::Entry Deleted::\n";
    showMenu();

}
 
void searchRecord()
{
    cout << "Enter the Employee"
         << " ID to Search Record::";
 
    int code;
    cin >> code;
 
    for (int i = 0; i < num; i++) {

        if (emp[i].code == code) {
            cout << "Name:: "
                 << emp[i].name << "\n";
 
            cout << "Employee ID:: "
                 << emp[i].code << "\n";
 
            cout << "Designation:: "
                 << emp[i].designation << "\n";
 
            cout << "Experience:: "
                 << emp[i].exp << "\n";
 
            cout << "Age::"
                 << emp[i].age << "\n";
            break;
        }
    }
 
    showMenu();
}

void showMenu()
{
 
    cout << "::Shubham Rao Employee:: \n"<< " <<Management System>>\n\n::";
    cout << "::Availiable Options::\n\n";
    cout << "1> Create Table \n";
    cout << "2> Insert New Entry  \n";
    cout << "3> Delete \n";
    cout << "4> Search \n";
    cout << "5> Exit   \n";
 
    int option;

    cin >> option;

    if (option == 1) {
        build();
    }
    else if (option == 2) {
        insert();
    }
    else if (option == 3) {
        deleteRecord();
    }
    else if (option == 4) {
        searchRecord();
    }
    else if (option == 5) {
        return;
    }
    else {
        cout << ":::Expected Options"
             << " are 1/2/3/4/5:::";
        showMenu();
    }
}

int main()
{
    showMenu();
    return 0;
}