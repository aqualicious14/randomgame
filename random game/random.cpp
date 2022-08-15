#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
using namespace std;

bool checklog(string username,string password) {
    string un,pw;
    ifstream read("C:\\Users\\aryan\\OneDrive\\Documents\\Computing\\C++\\random game\\users\\" + username + ".txt");
    getline(read,un);
    getline(read,pw);

    if (un == username && pw == password) {
        return true;
    } else {
        return false;
    }
}
int random(int level) {
    int r = (rand() % 10) + 1;
    int guess;
    cout << "Guess the number between 1 to 10: ";
    cin >> guess;
    if (guess == r) {
        cout << "\nCongratulations! You got it!\n";
        level = level + 1;
        cout << "You leveled up! You are now level " << level <<"!\n";
        return 1;
    } else {
        cout << "\nClose one! Better luck next time!\n";
        return 0;
    }
}

int main() {
    int c;
    cout << "Welcome to the random game!\n\n1.Register\n2.Login\n3.Leave\nYour choice: ";
    cin >> c;
    if (c==1) {
        string user,password;
        cout << "Enter a username: ";
        cin >> user;
        cout << "Enter a password: ";
        cin >> password;

        ofstream file;
        file.open("C:\\Users\\aryan\\OneDrive\\Documents\\Computing\\C++\\random game\\users\\" + user + ".txt");
        file << user << endl << password << endl << 0;
        file.close();

        main();
    } else if(c==2) {
        string us,pw;
        cout << "Enter a username: ";
        cin >> us;
        cout << "Enter a password: ";
        cin >> pw;
        bool status = checklog(us,pw);
        if (!status) {
            cout << "\nLogin failed! Try again!";
            main();
        } else {
            cout << "\nLogin successful!\nWelcome to the random game!\n";
            int choice;
            int level;
            string u,p,l;
            ifstream read("C:\\Users\\aryan\\OneDrive\\Documents\\Computing\\C++\\random game\\users\\" + us + ".txt");
            getline(read,u);
            getline(read,p);
            getline(read,l);
            
            stringstream convert(l);
            convert >> level;
            cout << "\n1.Play\n2.Leave\nYour choice: ";
            cin >> choice;
            if (choice == 1) {
                bool t = true;
                while (t) {
                    int newlevel = random(level);
                    if (newlevel == 1) {
                        level = level + 1;
                        string strnew;
                        stringstream convertnew;
                        convertnew << level;
                        convertnew >> strnew;
                        // code to change level in text file here
                        string pathtodel = "C:\\Users\\aryan\\OneDrive\\Documents\\Computing\\C++\\random game\\users\\" + us + ".txt";
                        remove(pathtodel.c_str());
                        fstream file;
                        file.open("C:\\Users\\aryan\\OneDrive\\Documents\\Computing\\C++\\random game\\users\\" + us + ".txt");
                        file << u << endl << p << endl << level;
                        file.close();

                    }
                    int retry;
                    cout << "\nWould you like to try again?\n1.Yes\n2.No\nYour choice: ";
                    cin >> retry;
                    if (retry == 2) {
                        cout << "\nHope to see you again soon!";
                        t = false;
                    }
                }
            } else if (choice == 2) {
                cout << "\nHope to see you again soon!";
                return 0;
            }
        }
    } else if (c==3) {
        cout << "\nHope to see you again soon!\n";
        return 0;
    }
}