 #include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<algorithm>
#include <windows.h> // For Sleep function

using namespace std;
class account
{
    private:
    string accountno;
    string password;
    int balence;
    public:
    account()
    {
       accountno ="";
        password="";
        balence=0;
    }
    string setaccountno(string id)
    {
        accountno=id;
    }
    string setpassword(string pass)
    {
        password=pass;
    }
    double setbalence(int bal){
        balence=bal;
    }
    string getaccountno(){
        return accountno;
    }
    string getpassword(){
        return password;
    }
    double getbalence(){
        return balence;
    }
    ///////////////////////////////////
    void open()
    {
        system("cls");
            string id,pass;
            cout<<"\tenter the account no :\t";
            cin>>id;
            setaccountno(id);
            cout<<"\tenter the password :\t";
        
            cin>>pass;
            setpassword(pass);
            setbalence(0);
        ofstream outfile("account.txt",ios::app);
            if(!outfile){
                cout<<"\tdata not stored!"<<endl;
            }
            else{
                outfile<<"\t"<<getaccountno()<<":"<<getpassword()<<":"<<getbalence()<<endl;
                cout<<"\tyour account is successfully opend"<<endl;
            }
            outfile.close();
            Sleep(2000);
    }
    void add() {
        system("cls");
        string id;
        cout << "\tenter account no.: ";
        cin >> id;

        ifstream infile("d:/code/project/account.txt");
        ofstream outfile("d:/code/project/temp.txt");

        if (!infile.is_open() || !outfile.is_open()) {
            cerr << "Error opening file" << endl;
            return;
        }

        string line;
        bool found = false;

        while (getline(infile, line)) {
            stringstream li(line);
            string userid, userpw;
            double userbalence;
            char delimiter;
            // Read the userid
            getline(li, userid, ':');
            // Read the userpw
            getline(li, userpw, ':');
            // Read the userbalence
            li >> userbalence;
            userid.erase(remove_if(userid.begin(), userid.end(), ::isspace), userid.end());

            li >> userid >> delimiter >> userpw >> delimiter >> userbalence;

            if (id == userid) {
                found = true;
                double cash;
                cout << "\t enter the cash: ";
                cin >> cash;
                userbalence += cash;

                outfile << userid << ":" << userpw << ":" << userbalence << endl;
                cout << "\tyour current balance is: " << userbalence << endl;
            } 
            else {
                outfile << line << endl;
            }
        }

        if (!found) {
                cerr << "Error in opening file" << endl;
        }

        infile.close();
        outfile.close();

        // Replace the original file with the updated file
        remove("d:/code/project/account.txt");
        rename("d:/code/project/temp.txt", "d:/code/project/account.txt");

        Sleep(2000);
    }

    void withdraw() {
        system("cls");
        string id,PW;
        cout << "\tenter account no.: ";
        cin >> id;
        cout<<"\tenter the password :";
        cin>>PW;

        ifstream infile("d:/code/project/account.txt");
        ofstream outfile("d:/code/project/temp.txt");

        if (!infile.is_open() || !outfile.is_open()) {
            cerr << "Error opening file" << endl;
            return;
        }

        string line;
        bool found = false;

        while (getline(infile, line)) {
            stringstream li(line);
            string userid, userpw;
            double userbalence;
            char delimiter;
            // Read the userid
            getline(li, userid, ':');
            // Read the userpw
            getline(li, userpw, ':');
            // Read the userbalence
            li >> userbalence;
            userid.erase(remove_if(userid.begin(), userid.end(), ::isspace), userid.end());
            userpw.erase(remove_if(userpw.begin(), userpw.end(), ::isspace), userpw.end());


            if (id == userid && PW == userpw) {
                found = true;
                double am;
                cout << "\twithdraw cash: ";
                cin >> am;
                if (userbalence >= am) {
                    userbalence -= am;
                    outfile << userid << ":" << userpw << ":" << userbalence << endl;
                    cout << "\tyour current balance is: " << userbalence << endl;
                
                }
            } else {
                outfile << line << endl;
            }
        }

        if (!found) {
            cout << "\t enter valid account no. or password" << endl;
        }

        infile.close();
        outfile.close();

        // Replace the original file with the updated file
        remove("d:/code/project/account.txt");
        rename("d:/code/project/temp.txt", "d:/code/project/account.txt");

        Sleep(2000);
    }
    void balen()
{
    system("cls");
    string id,PW;
    cout << "\tenter account no.: ";
    cin >> id;
    cout<<"\tenter the password :";
    cin>>PW;
    ifstream infile("d:/code/project/account.txt");
    if (!infile.is_open() ) {
        cerr << "Error opening file" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(infile, line)) {
        stringstream li(line);
        string userid, userpw;
        double userbalence;
        char delimiter;
           // Read the userid
        getline(li, userid, ':');
        // Read the userpw
        getline(li, userpw, ':');
        // Read the userbalence
        li >> userbalence;
         userid.erase(remove_if(userid.begin(), userid.end(), ::isspace), userid.end());
         userpw.erase(remove_if(userpw.begin(), userpw.end(), ::isspace), userpw.end());

        if (id == userid && PW == userpw)
        {
            found = true;
            int a;

            cerr<<"\tYour Account balence is :"<<userbalence<<endl;
            cout<<"\tPress any key too exit"<<endl;
            cin>>a;
            cerr<<"\twisit again!"<<endl;
           
        }
    }
    if(!found)
    {
        cerr<<"\tNo Data Found!"<<endl;
    }
    infile.close();
    Sleep(2000);
}    
};
int main()
{
    account user;
   
    while(1)
    {
        system("cls");
        int val;
        cout<<"\t welcome to the mini bank"<<endl;
        cout<<"\t 1. open account in the bank"<<endl;
        cout<<"\t 2. Add a cash"<<endl;
        cout<<"\t 3. withdraw the cash"<<endl;
        cout<<"\t 4. check balence"<<endl;
        cout<<"\t 5. exit"<<endl;
        cout<<"\t enter your choice : ";
        cin>>val;
        if(val==1){
            user.open();

        }
        else if(val==2){
            
            user.add();
        }
        else if(val==3){
            user.withdraw();
        }
        else if(val==4){
           user.balen();
        }
        else if(val==5)
        {
            cout<<"exit"<<endl;
            break;
        }
        else{
            cout<<"invalid choice"<<endl;
        }
        Sleep(2000);
    }
}