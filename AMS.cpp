#include<iostream>
#include<fstream>
#include<string.h>
#include<unistd.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){
    int choice;
    system("cls");
    cout<<"------Welcome to the Administrator Login Page------"<<endl;
    cout<<"Your Passwords are end-to-end Encrypted!!!\n";
    cout<<"----------------Made By @0xChirantan---------------"<<endl;
    cout<<" ________________________________"<<endl;
    cout<<"|                                |"<<endl;
    cout<<"|    Press 1: to Login           |"<<endl;
    cout<<"|    Press 2: to Register        |"<<endl;
    cout<<"|    Press 3: to Reset-Password  |"<<endl;
    cout<<"|    Press 4: to exit            |"<<endl;
    cout<<"|    Press 5: CREDITS            |"<<endl;
    cout<<"|________________________________|"<<endl;
    cout<<"\n";
    cout<<"|    Please Enter your choice: ";
    cin>>choice;
    cout<<endl;

    switch(choice){
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout<<"\n   Thank You!!!    \n";
            sleep(3);
            break;
        case 5:
            system("cls");
            cout<<"\n-----------------------------CREDITS------------------------------\n";
            cout<<"\nThis Admin-Management-System is created and managed by @0xchirantan\n";
            cout<<"\nKindly follow for more coding stuff\n";
            cout<<"\n---Thank You!!!---\n";
            sleep(7);
            main();
            break;
        default:
            system("cls");
            cout<<"\n   Please select from the options given above!!!   \n";
            main();
    }
}

void login(){
    int count;
    string userID, id, pass, x, encryptPasswd={0};
    char passwd[500];
    char password[500];
	int encrypted_password[500];
    system("cls");
    cout<<"Please Enter the username and Password>>> "<<endl;
    cout<<"Username: ";
    cin>>userID;
    cout<<"Password: ";
    cin>>passwd;
    for(int i=0; i<strlen(passwd); i++){
        encrypted_password[i]=passwd[i]+12;
        x=to_string(encrypted_password[i]);
        encryptPasswd+=('0'+x+'1');
    }
    ifstream input("admin_records.csv");
    while (input>>id>>pass){
        if(id==userID && pass==encryptPasswd){
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<userID<<"\nYour Login is Successfull"<<endl;
        sleep(2);
        main();
    }
    else{
        cout<<"LOGIN ERROR\nPlease check your id and password\n";
        sleep(2);
        main();
    }
}


void registration(){
    string ruserID, rid, rpass, x, encryptPasswd={0};
    char rpasswd[500];
    char password[500];
	int encrypted_password[500];
    system("cls");
    cout<<"Enter your Username: ";
    cin>>ruserID;
    cout<<"Enter your Password: ";
    cin>>rpasswd;
    for(int i=0; i<strlen(rpasswd); i++){
        encrypted_password[i]=rpasswd[i]+12;
        x=to_string(encrypted_password[i]);
        encryptPasswd+=('0'+x+'1');
    }

    ofstream f1("admin_records.csv", ios::app);    //  App mode
    f1<<ruserID<<" "<<encryptPasswd<<endl;
    system("cls");
    cout<<"Registration is SUCCESSFULL! \n";
    sleep(2);
    main();
}


void forgot(){
    int option;
    system("cls");
    cout<<"Reset your password from below Options\n";
    cout<<"Press 1 to search your ID by Username,"<<endl;
    cout<<"Press 2 to go back to the main menu,"<<endl;
    cout<<"\nEnter your choice: ";
    cin>>option;

    if(option==1){
        int count=0;
        string suserID, sID, spass;
        ifstream f2("admin_records.csv");
        cout<<"Enter the Username which you remembered: ";
        cin>>suserID;
        while(f2>>sID>>spass){
            if(sID==suserID){
                count=1;
                break;
            }
        }
        f2.close();
        if(count==1){
            cout<<"Your account is found!!! \n";
            sleep(2);
            cout<<"Your password is(Decrypt it if you can xD): "<<spass;
            sleep(2);
            cout<<"\n\nThe Password Cannot be Decrypted,\nThere is the Challenge for you, \nDecrypt it If you can!!! \n\n";
            system("pause");
        }
        else{
            cout<<"Your account is NOT found!!! \n";
            sleep(2);
            main();
        }
    }
    else if(option==2){
        main();
    }
    else{
        cout<<"Wrong choice!!! Please try again "<<endl;
        system("pause");        
        forgot();
    }
}