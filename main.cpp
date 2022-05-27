

// Login and Registration project using c++
// complete project 

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void login();
void registration();
void forgot();


// Main function start 
int main()
{
    int c;
    cout << "\t\t\t____________________________________________________\n\n\n";
    cout << "\t\t\t              Welcome to the Login page              \n\n\n";
    cout << "\t\t\t______________          MENU           _______________\n\n";
    cout << "                                                             \n\n";
    cout << "\t| Press 1 to LOGIN                        |" << endl;
    cout << "\t| Press 2 to REGISTER                     |" << endl;
    cout << "\t| Press 3 to if you forgot your password  |" << endl;
    cout << "\t| Press 4 to EXIT                         |" << endl;
    cout << "\n\t\t\t Please enter your choice : ";
    cin >> c;
    cout << endl;

    switch (c)
    {
        case 1:
            login();  // calling login function
            break;

        case 2:
            registration();  //calling registration function
            break;

        case 3:
            forgot();  // calling forgot function
            break;

        case 4:
            cout << "\t\t\t Thankyou! \n\n";
            break;

    default:
        system("cls");
        cout << "\t\t\t Please select from the option given above \n" << endl;
        main();
    }
}
// Main function end

// Login function start
    void login()
    {
        
        string userID, password,id,pass;
        system("cls");

        cout << "\t\t\t Please enter the username and password : " << endl;
        cout << "\t\t\t USERNAME : ";
        cin >> userID;
        cout << "\t\t\t PASSWORD : ";
        cin >> password;

        int count=0;
        ifstream f1("records.txt");   //file handling 

        while(f1>>id>>password)
        {
            if(id==userID && pass==password){
                count=1;
                system("cls");
            }
        }
        f1.close();

        if(count==1)
        {
            cout << userID << "\n Your LOGIN is successfull \n Thanks for logging in ! \n";
            main();
        }else{
            cout << "\n LOGIN ERROR \n Please check your username and password \n";
            main();
        }
    }
// Login function end

// Registration function start
    void registration()
    {
        string ruserID,rpassword,rid,rpass;
        system("cls");
        cout << "\t\t\t Enter the username : ";
        cin >> ruserID;
        cout << "\t\t\t Enter the password : ";
        cin >> rpassword;
        
        ofstream f1("records.txt", ios::app);    //File Handling

        f1 << ruserID << ' '<< rpassword << endl;
        system("cls");

        cout << "\n\t\t\t Registration is successfull! \n";
        main(); 
    
    }
// Registration function end

//Forgot function start
    void forgot()
    {
        int option;
        system("cls");
        cout << "\t\t\t You forgot the password? No worries \n";
        cout << "Press 1 to search your id by username "<< endl;
        cout << "Press 2 to go back to the main menu " << endl;
        cout << "\t\t\t Enter your choice : ";
        cin >> option;
        
        switch (option)
        {
        case 1 :
        {
            int count=0;
            string suserId, sId, spass;
            cout << "\n\t\t\tEnter the username which you remembered : ";
            cin >> suserId;

            ifstream f2("records.txt");   //File handling
            while(f2>>sId>>spass)
            {
                if(sId==suserId){
                    count = 1;
                }
            }
            f2.close();
            if(count==1){
                cout << "\n\n Your account is found! \n";
                cout << "\n\n Your password is : " << spass;
                main();
            }else{
                cout << "\n\t Sorry! your account is not found! \n";
                main();
            }
            break;
        }

            case 2 :
            {
                main();
            }

        default:
            cout << "\t\t\t Wrong choice ! Please try again " << endl;
            forgot();
        
    }
        
}
// Forgot function end


// Programe end