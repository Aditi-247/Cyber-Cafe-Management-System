//CYBER CAFE MANAGEMENT [ABHAY < ADITYA < Aditi < AKANKSHA];
#include <iostream>     //cout , cin
#include <stdio.h>
#include <conio.h>   //delay(0) , getch() etc.
#include <ctype.h>   //toupper() , tolower() etc.
#include <string.h>  //strcmp() , strcpy() , strlen() etc.
#include <stdlib.h>
#include <fstream> //file handling
using namespace std;
//Global Variables
char ans = 0;
int b, valid = 0;
void Title(void);
class login
{
private:
    string userid , first, last , surname, password, passwo, gender, eaddress, temps, temp ;

public:
    void login_details()
    {
        system("cls");
        Title();
        cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t--------------------------------";
        cout << "\n\t\t\t\t\t\t\t\t\t\t    LOGIN";
        cout << "\n\t\t\t\t\t\t\t\t\t--------------------------------";
        cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tHello Budddy!!! \n\t\t\t\t\t\t\t\t\t\t---------------\n\n\t\t\t\t\t\t\tPlease Enter the use-id (10-digits phone numner) :     ";
        cin >> userid;
        fstream file;
        file.open(userid + ".xls");
        file >> temp>>first>>last>>temps;
        if (temp == userid)
        {
            cout << "\n\n\t\t\t\t\t\t\tEnter the password                               :     ";
            cin >> password;
            if (password == temps)
            {
                cout << "\n\n\t\t\t\t\t\t\tCongratulation! your logged in our system successfully.";
            }
            else
            {
                cout << "\n\n\t\t\t\t\t\t\tWarning : Incorrect Password, please Try again...";
            }
        }
        else
        {
            cout << "\n\n\t\t\t\t\t\t\tWarning : Incorret userid pleease Try again";
        }
    }
    void signup()
    {
        // Registration for new member
        system("cls");
        Title();
        cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t--------------------------------";
        cout << "\n\t\t\t\t\t\t\t\t\t\t    SIGN UP";
        cout << "\n\t\t\t\t\t\t\t\t\t--------------------------------";
        cout<<"\n\n\n\n\t\t\t\t\t\t\tEnter the user-id (10-digit phone no)   :          ";
        cin >> userid;
        ifstream file;
        file.open(userid + ".xls");
        if (file)
        {
            cout<<"\n\n\t\t\t\t\t\t\tWarning : userid already exists, Please try to login...";
        }
        else
        {
            cout<<"\n\t\t\t\t\t\t\tEnter your first name                   :          ";
            cin>>first;
            cout<<"\n\t\t\t\t\t\t\tEnter your last name                    :          ";
            cin>>last;
            abhay:
            cout<<"\n\t\t\t\t\t\t\tEnter the new password                  :          ";
            cin >> password;
            cout<<"\n\t\t\t\t\t\t\tPlease re-enter the password            :          ";
            cin>>passwo;
            if(password != passwo)
            {
                cout<<"\t\t\t\t\t\t\t(Warning : password does't match)\n";
                goto abhay;
            }
            gend:
            cout<<"\n\t\t\t\t\t\t\tEnter your Gender(M/F)                  :          ";
            cin>>gender;
            if(gender=="Male"||gender=="male"||gender=="female"||gender=="Female"||gender=="m"||gender=="M"||gender=="f"||gender=="F")
                {
            cout<<"\n\t\t\t\t\t\t\tEnter your e-mail eaddress              :          ";
            cin>>eaddress;

                }
            else
            {
                goto gend;
            }

            ofstream file, fout;
            ifstream fin;
            file.open(userid + ".xls");
            file<<userid << "\t" <<first<<"\t"<<last<<"\t"<< password<<"\t"<<gender<<"\t"<<eaddress;
            file.close(); // now the file has been closed
            // here to again open the file in read mode
            string text;
            fin.open(userid + ".xls");
            fout.open("master.xls", ios::app);
            while (getline(fin,text))
            {
                fout<<endl<<text;
            }
            fin.close();
            fout.close();
            cout<<"\n\n\t\t\t\t\t\t\tCongratulations!! you account has been created successfully...";
        }
    }

    void show_record()
    {
        system("cls");
        Title();
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t--------------------------------";
        cout << "\n\t\t\t\t\t\t\t\t\t\t    RECORD";
        cout << "\n\t\t\t\t\t\t\t\t\t--------------------------------";
        fstream file;
        int i;
        file.open("master.xls",ios::in);
        i=1;
        while(!file.eof())
        {
        file>>userid>>first>>last>>password>>gender>>eaddress;
        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t ------------";
        cout<<"\n\t\t\t\t\t\t\t\t\t\t Record no. "<<i;
        cout<<endl<<"\t\t\t\t\t\t\t\t\t\t ------------";
        cout<<endl;
        cout<<"\t\t\t\t\t\t\t\tUser-id               :           "<<userid<<endl;
        cout<<"\t\t\t\t\t\t\t\tFirst Name            :           "<<first<<endl;
        cout<<"\t\t\t\t\t\t\t\tLast Name             :           "<<last<<endl;
        cout<<"\t\t\t\t\t\t\t\tPassword              :           "<<password<<endl;
        cout<<"\t\t\t\t\t\t\t\tGender                :           "<<gender<<endl;
        cout<<"\t\t\t\t\t\t\t\tMail id               :           "<<eaddress<<endl;
        i++;
        }
    file.close();
    }

    void search_record()
    {
        system("cls");
        Title();
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t--------------------------------";
        cout << "\n\t\t\t\t\t\t\t\t\t\t    SEARCH";
        cout << "\n\t\t\t\t\t\t\t\t\t--------------------------------";
        fstream file;
        string search ;
        cout<<"\n\n\t\t\t\t\t\t\tEnter user-id for search (10-digit phone no) : ";
        cin>>search;
        file.open("master.xls",ios::in);
        file>>userid;
        while(!file.eof())
    {

        if(search == userid)
        {
            file>>first>>last>>password>>gender>>eaddress;
            cout<<"\n\t\t\t\t\t\t\tUser-id         =     "<<userid<<"\n\t\t\t\t\t\t\tFirst Name      =     "<<first<<"\n\t\t\t\t\t\t\tLast Name       =     "<<last<<"\n\t\t\t\t\t\t\tpassword        =     "<<password<<"\n\t\t\t\t\t\t\tGender          =     "<<gender<<"\n\t\t\t\t\t\t\tE-mail address  =     "<<eaddress;
            break;
        }
        file>>userid;
    }
        if(search!=userid){
            cout<<"\n\t\t\t\t\t\t\tRecord not found";
        }
        getch();
        file.close();
    }


int search(string search)
{
        fstream file;
        file.open("master.xls",ios::in);
        file>>userid;
        while(!file.eof())
    {

        if(search == userid)
        {
            file>>first>>last>>password>>gender>>eaddress;
            cout<<"\n\t\t\t\t\t\t\tUser-id         =     "<<userid<<"\n\t\t\t\t\t\t\tFirst Name      =     "<<first<<"\n\t\t\t\t\t\t\tLast Name       =     "<<last<<"\n\t\t\t\t\t\t\tpassword        =     "<<password<<"\n\t\t\t\t\t\t\tGender          =     "<<gender<<"\n\t\t\t\t\t\t\tE-mail address  =     "<<eaddress;
            return 1;
        }
        file>>userid;
    }
        if(search!=userid){
            cout<<"\t\t\t\t\t\t\tWarning : Record not found";
            return 0;
        }
        getch();
        file.close();
}

int Edit_Rec(){
    system("cls");
    Title();
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t--------------------------------";
        cout << "\n\t\t\t\t\t\t\t\t\t\t  UPDATE RECORD";
        cout << "\n\t\t\t\t\t\t\t\t\t--------------------------------";
    fstream file,file1;
    int search_result, choi;
    string userid1;

    cout<<endl<<"\n\n\t\t\t\t\t\t\tEnter the userid you want to update(10-digit phone no) : ";
    cin>>userid1;

    search_result = search(userid1);
    if(search_result)
    {
    file1.open("master.xls",ios::in);

    if(!file1){
        cout<<"\n\t\t\t\t\t\t\tWarning : File does not exist....";
        file1.close();
        goto p;
    }
    file.open("update.xls",ios::out|ios::app);
    //search in master
    sahu:
    cout<<"\n\n\t\t\t\t\t\t\tWhich recod do you want to update : \n\t\t\t\t\t\t\t1)User-id\n\t\t\t\t\t\t\t2)First name\n\t\t\t\t\t\t\t3)Last name\n\t\t\t\t\t\t\t4)Password\n\t\t\t\t\t\t\t5)Gender\n\t\t\t\t\t\t\t6)E-mail\n\n\t\t\t\t\t\t\tEnter your Choice : ";
    cin>>choi;
    switch(choi)
    {
        case 1:
        while (!file1.eof())
    {
        file1>>userid>>first>>last>>password>>gender>>eaddress;
    if(userid1==userid){
        cout<<endl<<"\t\t\t\t\t\t\tEnter the new User-id(10-digit phone no)  :   ";
        cin>>userid;
        file<<endl<<userid<<"\t"<<first<<"\t"<<last<<"\t"<<password<<"\t"<<gender<<"\t"<<eaddress;
        cout<<"\n\t\t\t\t\t\t\tYour record has been updated.....";
    }
    else{
        file<<endl<<userid<<"\t"<<first<<"\t"<<last<<"\t"<<password<<"\t"<<gender<<"\t"<<eaddress;
    }
    //file1>>userid>>password;
    }
    break;

    case 2:
        while (!file1.eof())
    {
        file1>>userid>>first>>last>>password>>gender>>eaddress;
    if(userid1==userid){
        cout<<"\t\t\t\t\t\t\tEnter the new first name   :    ";
        cin>>first;
        file<<endl<<userid<<"\t"<<first<<"\t"<<last<<"\t"<<password<<"\t"<<gender<<"\t"<<eaddress;
        cout<<"\n\t\t\t\t\t\t\tYour record has been updated.....";
    }
    else{
        file<<endl<<userid<<"\t"<<first<<"\t"<<last<<"\t"<<password<<"\t"<<gender<<"\t"<<eaddress;
    }
    //file1>>userid>>password;
    }

    case 3:
        while (!file1.eof())
    {
        file1>>userid>>first>>last>>password>>gender>>eaddress;
    if(userid1==userid){
        cout<<endl<<"\t\t\t\t\t\t\tEnter the new last name  :    ";
        cin>>last;
        file<<endl<<userid<<"\t"<<first<<"\t"<<last<<"\t"<<password<<"\t"<<gender<<"\t"<<eaddress;
        cout<<"\n\t\t\t\t\t\t\tYour record has been updated.....";
    }
    else{
        file<<endl<<userid<<"\t"<<first<<"\t"<<last<<"\t"<<password<<"\t"<<gender<<"\t"<<eaddress;
    }
    //file1>>userid>>password;
    }
    break;

    case 4:
        while (!file1.eof())
    {
        file1>>userid>>first>>last>>password>>gender>>eaddress;
    if(userid1==userid){
        cout<<endl<<"\t\t\t\t\t\t\tEnter the new password    :   " ;
        cin>>password;
        file<<endl<<userid<<"\t"<<first<<"\t"<<last<<"\t"<<password<<"\t"<<gender<<"\t"<<eaddress;
        cout<<"\n\t\t\t\t\t\t\tYour record has been updated.....";
    }
    else{
        file<<endl<<userid<<"\t"<<first<<"\t"<<last<<"\t"<<password<<"\t"<<gender<<"\t"<<eaddress;
    }
    //file1>>userid>>password;
    }
    break;

    case 5:
        while (!file1.eof())
    {
        file1>>userid>>first>>last>>password>>gender>>eaddress;
    if(userid1==userid){
        cout<<endl<<"\t\t\t\t\t\t\tEnter the new Gender  :   " ;
        cin>>gender;
        file<<endl<<userid<<"\t"<<first<<"\t"<<last<<"\t"<<password<<"\t"<<gender<<"\t"<<eaddress;
        cout<<"\n\t\t\t\t\t\t\tYour record has been updated.....";
    }
    else{
        file<<endl<<userid<<"\t"<<first<<"\t"<<last<<"\t"<<password<<"\t"<<gender<<"\t"<<eaddress;
    }
    //file1>>userid>>password;
    }
    break;

    case 6:
        while (!file1.eof())
    {
        file1>>userid>>first>>last>>password>>gender>>eaddress;
    if(userid1==userid){
        cout<<endl<<"\t\t\t\t\t\t\tEnter the new E-mail eaddress    :   " ;
        cin>>eaddress;
        file<<endl<<userid<<"\t"<<first<<"\t"<<last<<"\t"<<password<<"\t"<<gender<<"\t"<<eaddress;
        cout<<"\n\t\t\t\t\t\t\tYour record has been updated.....";
    }
    else{
        file<<endl<<userid<<"\t"<<first<<"\t"<<last<<"\t"<<password<<"\t"<<gender<<"\t"<<eaddress;
    }
    //file1>>userid>>password;
    }
    break;

        default:
        cout<<"\n\t\t\t\t\t\t\tWarning : Wrong choice.";
        cout<<"\n\t\t\t\t\t\t\tPlease select right choice";
        goto sahu;
    }
    file1.close();
    file.close();
    remove("master.xls");
    rename("update.xls","master.xls");
    p:
    return 0;
    }
}

int delete_record(){
     system("cls");
     Title();
    fstream file,file1,file3; // file name is for reading the data from previous data and file1 data for write new file
       string  searchfilename,extension;

       cout<<"\n\n\t\t\t\t\t\t\t\tEnter the username you wanna delete : ";
       cin>>searchfilename;
       file.open("master.xls",ios::in);
       if(!file)
       {
              cout<<"\n\n\t\t\t\t\t\t\t\tWarning : File not found";
              file.close();
            //   goto g;
       }
      file1.open("master1.xls",ios::app|ios::out) ;
      while (!file.eof())  //when file data is present in file then
      {
        file>>userid>>first>>last>>password>>gender>>eaddress;
       if(searchfilename!=userid){
            file1<<endl<<userid<<"\t"<<first<<"\t"<<last<<"\t"<<password<<"\t"<<gender<<"\t"<<eaddress;
       }
       else{
           cout<<"\n\n\t\t\t\t\t\t\t\tRecord deleted successfully;";
       }
      }
      file.close();
      file1.close();
      remove("master.xls");
      rename("master1.xls","master.xls");
      extension=searchfilename + ".xls";
      int n = extension.length();
      char char_array[n + 1];
      strcpy(char_array, extension.c_str());

    for (int i = 0; i < n; i++){
         char_array[i];
    }
   remove(char_array);
    //   g:
      return 0;
}

};

//FUNCTION DECLARATION
void WelcomeScreen(void);
int LoginScreen(login);
void AddRec(void);
void ShowRec(void);
void SearchRec(void);
void EditRec(void);
void DelRec(void);
void MainMenu(login);
void exet(void);

class Customer
{
    int Age;
    char FirstName[20];
    char LastName[20];
    char ContactNo[15];
    char eaddress[30];
    char Email[30];
};

// LOG IN CLASS IF STARTED HERE

int main(void)
{
    system("cls");
    int z;
    Customer c, c1, c2;
    login l1;
    WelcomeScreen();
    //calling function Login screen
    LoginScreen(l1);
    return 0;
}

// ========================================WELCOME SCREEN============================================
void WelcomeScreen(void) //function
{
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t#######################################################";
    cout << "\n\t\t\t\t\t\t\t\t##\t\t\tWELCOME TO\t\t     ##";
    cout << "\n\t\t\t\t\t\t\t\t##\t      CYBER CAFE MANAGEMENT PROGRAM.\t     ##";
    cout << "\n\t\t\t\t\t\t\t\t#######################################################";
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue.";
    getch();
    system("cls");
}
// =========================================TITLE HEADER=============================================
void Title(void)
{
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t---------------------------------------------------------------";
    cout << "\n\t\t\t\t\t\t\t\t\t CYBER CAFE MANAGEMENT SYSTEM";
    cout << "\n\t\t\t\t\t\t\t---------------------------------------------------------------";
}
// ==========================================LOGIN SCREEN==============================================
int LoginScreen(login a)
{
    int turns = 0;
    char Username[15];
    char Password[15];
    char Org_Username[15] = "Cyber";
    char Org_Password[15] = "12345";


    do
    {
        Title();
        cout << "\n\n\n\n\t\t\t\t\t\t\tCAFE OWNER LOGIN CREDENTIALS";
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t USERNAME  :  ";
        cin.sync();
        gets(Username);
        Username[0] = toupper(Username[0]);
        cout << "\n\t\t\t\t\t\t\t\t\t\t PASSWORD  :  ";
        cin.sync();
        gets(Password);
        if (strcmp(Username, Org_Username) == 0 && strcmp(Password, Org_Password) == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\t------------------------\n";
            cout << "\n\t\t\t\t\t\t\t\t\t\t    Login successful\n";
            cout << "\n\t\t\t\t\t\t\t\t\t\t------------------------\n";
            cout << "\n\t\t\t\t\t\t\tPress any key to continue.";
            getch();
            MainMenu(a);
            break;
        }
        else
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\t!!  Unauthorized credentials  !!\n";
            cout << "\n\t\t\t\t\t\t\t\t\t\tPress ENTER to Retry...\n";
            getch();
            system("cls");
            turns++;
        }
    } while (turns < 3);
    if (turns >= 3)
    {
        Title();
        cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tYou have crossed the limit.\n";
    }
    system("cls");
    return 0;
}
// ==========================================MAIN MENU==============================================

void MainMenu(login b)
{   menu:
    system("cls");
    int choice;
    Title();
    cout << "\n\n\n\n\t\t\t\t\t\t\t1. Sign up your ID\n";
    cout << "\t\t\t\t\t\t\t2. Log in your ID\n";
    cout << "\t\t\t\t\t\t\t3. view User Record\n";
    cout << "\t\t\t\t\t\t\t4. search User Record\n";
    cout << "\t\t\t\t\t\t\t5. update User Record\n";
    cout << "\t\t\t\t\t\t\t6. Delete User Record\n";
    cout << "\t\t\t\t\t\t\t7. Exit\n";

    cout << "\n\n\n\t\t\t\t\t\t\tEnter Choice  :  ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        b.signup();
        getch();
       goto menu;
        break;
    case 2:
        b.login_details();
        getch();
         goto menu;
        break;
    case 3:
        b.show_record();
        getch();
        goto menu;
        break;
    case 4:
        b.search_record();
        getch();
        goto menu;
        break;
    case 5:
        b.Edit_Rec();
        getch();
        goto menu;
        break;
    case 6:
        b.delete_record();
        getch();
        goto menu;
        break;
    case 7:
        exit(1);
        break;



    default:
        cout << "\t\t\tInvalid Entry.Please Enter Choice from 1 to 6.";
        goto menu;
        getch();

    }


}
