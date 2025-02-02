#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

class passwordManager {
public:
    string platform;
    string username;
    string email;
    string password;

    passwordManager(string plt) {
        platform = plt;
    }

    void getInfo(ofstream &prt) {
        prt << "Platform : " << platform << endl;
        prt << "Username : " << username << endl;
        prt << "Email    : " << email << endl;
        prt << "Password : " << password << endl;
        prt << "---------------------------" << endl;
    }
};

void addAccount() {
    ofstream prt("pwm.txt", ios::app);
    if (!prt) {
        cout << "Error opening file!" << endl;
        return;
    }

    string platform;
    cout << "Enter Platform: ";
    cin >> platform;

    passwordManager pwm(platform);

    cout << "Enter Username: ";
    cin >> pwm.username;

    cout << "Enter Password: ";
    cin >> pwm.password;

    cout << "Enter Email: ";
    cin >> pwm.email;

    pwm.getInfo(prt);

    cout << "Data saved successfully!" << endl;
    prt.close();

    system("cls");
}

void searchAccount() {
    ifstream prt("pwm.txt");
    if (!prt) {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "Enter Platform to search: ";
    string searchPlat;
    cin >> searchPlat;

    string line;
    bool found = false;

    while (getline(prt, line)) {
        if (line.find("Platform : " + searchPlat) != string::npos) {
            found = true;
            cout << "\n---------------------------";
            cout << "\nAccount found:\n";
            cout << line << endl;

            for (int i = 0; i < 3; i++) {
                if (getline(prt, line))
                    cout << line << endl;
            }
            cout << "---------------------------" << endl;
        }
    }

    if (!found) {
        cout << "---------------------------------------" << endl;
        cout << "No account found for platform: " << searchPlat << endl;
        cout << "---------------------------------------" << endl;
    }

    prt.close();
    cout<<"Click anything to continue . . .";
    getch();
    system("cls");
}

int main() {
    char n;
    while (true) {
        cout << "Welcome to Password Manager\n";
        cout << "1. Add Account\n2. Search Account\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> n;

        switch (n) {
            case '1':
                addAccount();
                break;
            case '2':
                searchAccount();
                break;
            case '3':
                return 0;
            default:
                system("cls");
        }
    }
}
