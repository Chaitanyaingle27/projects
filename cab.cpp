#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class cab {
private:
    string username;
    string password;
    string loggedInUser;
    string loggedInPass;
    string current;
    string destination;
    int total;
    int dis;

public:
    cab() {
        username = "";
        password = "";
        loggedInUser = "";
        loggedInPass = "";
        current ="none";
        destination ="none";
        total = 0;
        dis=0;
    }

    void setusername(string id) {
        username = id;
    }

    void setpassword(string pass) {
        password = pass;
    }

    string getusername() {
        return username;
    }

    string getpassword() {
        return password;
    }

    void book() {
        if (loggedInUser.empty() || loggedInPass.empty()) {
            cout << "\t---Please login first!----" << endl;
            Sleep(2000);
            login();
            if (loggedInUser.empty() || loggedInPass.empty()) {
                return;
            }
        }

        system("cls");
        string destination, current, s, su, l;
        s = "sedan";
        su = "SUV";
        l = "Luxury";
        cout << "\t1. Sedan RS 30/km" << endl;
        cout << "\t2. SUV RS 60/km" << endl;
        cout << "\t3. Luxury RS 100/km" << endl;
        cout << "\tEnter Your Choice: ";
        int va, dis, total;
        cin >> va;
        if (va == 1) {
            cout << "\tYou selected " << s << endl;
            cout << "\tEnter the place from where you start: ";
            cerr << "\tFrom: ";
            cin >> current;
            cerr << "\tTo: ";
            cin >> destination;
            cerr << "\tEnter the distance between them: ";
            cin >> dis;
            total = dis * 30;
            cout << "\tYour ride to " << destination << " from " << current << " will cost around: RS " << total << endl;
        } else if (va == 2) {
            cout << "\tYou selected " << su << endl;
            cout << "\tEnter the place from where you start: ";
            cerr << "\tFrom: ";
            cin >> current;
            cerr << "\tTo: ";
            cin >> destination;
            cerr << "\tEnter the distance between them: ";
            cin >> dis;
            total = dis * 60;
            cout << "\tYour ride to " << destination << " from " << current << " will cost around: RS " << total << endl;
        } else if (va == 3) {
            cout << "\tYou selected " << l << endl;
            cout << "\tEnter the place from where you start: ";
            cerr << "\tFrom: ";
            cin >> current;
            cerr << "\tTo: ";
            cin >> destination;
            cerr << "\tEnter the distance between them: ";
            cin >> dis;
            total = dis * 100;
            cout << "\tYour ride to " << destination << " from " << current << " will cost around: RS " << total << endl;
        }

        string y;
        cout << "\tConfirm Your ride (yes/no): ";
        cin >> y;
        if(y=="no")
        {
            cerr<<"THANKYOU WISIT AGAIN!"<<endl;
        }

        ofstream outfile("D:/code/project/tempcab.txt");
        ifstream infile("D:/code/project/CAB.txt");
        if (!infile.is_open() || !outfile.is_open()) {
            cerr << "\tError in booking!" << endl;
            return;
        }

        string line;
        bool found = false;
        while (getline(infile, line)) {
            stringstream li(line);
            string userid, userpw;
            char delimiter;

            // Read the userid
            getline(li, userid, ':');
            // Read the userpw
            getline(li, userpw, ':');
            userid.erase(remove_if(userid.begin(), userid.end(), ::isspace), userid.end());
            userpw.erase(remove_if(userpw.begin(), userpw.end(), ::isspace), userpw.end());
           
            if ( y == "yes" && loggedInUser == userid && loggedInPass == userpw)
            {
                found = true;
                cerr << "\tYour Ride Is confirmed!" << endl;
                outfile << "\t"<<userid << ":" << userpw << ": From " << current << " :TO " << destination << ":" << dis << "KM: " << total << endl;
                break;
            } 
            else{
                outfile << line << endl;
            }
        
        }
        if (!found)
        {
            outfile << line << endl;
            cout << "\tNot Valid Account No. Or Password" << endl;
        }
       // Ensure the files are closed before renaming
        infile.close();
        outfile.close();
        remove("D:/code/project/CAB.txt");
        rename("D:/code/project/tempcab.txt", "D:/code/project/CAB.txt");

        Sleep(2000);
    }

    void viewbooking()
    {
        // Implement the viewbooking function
        system("cls");
        ifstream infile("D:/code/project/tempcab.txt");
        string line,userid,userpw;
        if (!infile.is_open()) {
            cerr << "\tError in opening file!" << endl;
            return;
        }
        bool found=false;
        while (getline(infile, line))
        {
            stringstream li(line);
            string current,destination,totalStr,disStr;
            // Read the userid
            getline(li, userid, ':');
            // Read the userpw
            getline(li, userpw, ':');
            getline(li, current, ':');
            getline(li, destination, ':');
            getline(li, totalStr, ':');
            getline(li, disStr, ':');
           // total = stoi(totalStr);
           // dis = stoi(disStr);
            //to remove the white spaces
            userid.erase(remove_if(userid.begin(), userid.end(), ::isspace), userid.end());
            userpw.erase(remove_if(userpw.begin(), userpw.end(), ::isspace), userpw.end());
           
            if(loggedInUser==userid && loggedInPass==userpw)
            {
                found=true;
                cout<<"\tWelcome Back "<<userid<<"!"<<endl;
                cout<<"\tYour booking was "<<current<<" "<<destination<<endl;
                cout<<"\tDistance : "<<totalStr<<endl;
                cout<<"\tRent : "<<disStr<<"RS"<<endl;
                
            }

        }
        infile.close();
        int key;
        cerr<<"\tEnter any key to go back.";
        cin>>key;
        Sleep(800);

    }

    void reg() {
        system("cls");
        string id, pass;
        cout << "\tEnter the username: ";
        cin >> id;
        setusername(id);
        cout << "\tEnter the password: ";
        cin >> pass;
        setpassword(pass);
        ofstream outfile("CAB.txt", ios::app);
        ifstream infile("CAB.txt");
        string line,userid;
        if (!infile.is_open()||!outfile.is_open()) {
            cerr << "\tError in opening file!" << endl;
            return;
        }
        bool found=false;
        while (getline(infile, line))
        {
            stringstream li(line);
            string userid;
            // Read the userid
            getline(li, userid, ':');
            userid.erase(remove_if(userid.begin(), userid.end(), ::isspace), userid.end());
            if(id == userid )
            {
                found=true;
                cerr<<"\tThe username is already exist in are system!"<<endl;
            }
           
        }
        if(!found)
        {
            outfile << "\t" << getusername() << ":" << getpassword() << ":" << endl;
            cout << "\tYour account is opened successfully!" << endl;
        }
        outfile.close();
        infile.close();
        Sleep(3000);
    }

    void login() {
        system("cls");

        ifstream infile("D:/code/project/CAB.txt");
        string line, id, pass, userid, userpw;
        if (!infile.is_open()) {
            cerr << "\tError in opening file!" << endl;
            return;
        }
        bool found = false;

        cout << "\tEnter User ID: ";
        cin >> id;
        cout << "\tEnter Password: ";
        cin >> pass;

        while (getline(infile, line)) {
            stringstream li(line);
            string userid, userpw;
            char delimiter;
            // Read the userid
            getline(li, userid, ':');
            // Read the userpw
            getline(li, userpw, ':');
            //to remove the white spaces
            userid.erase(remove_if(userid.begin(), userid.end(), ::isspace), userid.end());
            userpw.erase(remove_if(userpw.begin(), userpw.end(), ::isspace), userpw.end());
            

            if (id == userid && pass == userpw) {
                found = true;
                loggedInUser = id;
                loggedInPass = pass;
                system("cls");
                cerr << "\t------Welcome To Dashboard " << id << "! ---------" << endl;
                cerr << "\t1. Book a Cab" << endl;
                cerr << "\t2. View The Booking" << endl;
                cerr << "\t3. Logout" << endl;
                cerr << "\tEnter Your Choice: ";
                int a;
                cin >> a;
                if (a == 1) {
                    cout << "\tbook your ride" << endl;
                    book();
                } else if (a == 2) {
                    viewbooking();
                } else if (a == 3) {
                    cerr << "\t----Logout----" << endl;
                    loggedInUser = "";
                    loggedInPass = "";
                    break;
                } else {
                    cerr << "\tInvalid input!" << endl;
                }
            }
        }
        if (!found) {
            cout << "\tEnter Valid User ID Or Password" << endl;
        }
        infile.close();
        Sleep(3000);
    }
};

int main() {
    while (1) {
        system("cls");
        cab user;
        int num;
        cout << "\t----WELCOME TO CAB CART!----" << endl;
        cout << "\t1. Registration" << endl;
        cout << "\t2. Login to the account" << endl;
        cout << "\t3. Book a cab" << endl;
        cout << "\t4. Exit!" << endl;
        cout << "\tEnter your choice: ";
        cin >> num;

        if (num == 1) {
            user.reg();
        } else if (num == 2) {
            user.login();
        } else if (num == 3) {
           user.book();
        } else if (num == 4) {
            cout << "\tExit!" << endl;
            break;
        } else {
            cout << "\tInvalid Input!" << endl;
            break;
        }
        Sleep(2000);
    }
}





