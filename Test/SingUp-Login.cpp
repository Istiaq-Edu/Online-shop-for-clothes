#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> users;

void signup() {
  string username, password;

  cout << "Enter username: ";
  cin >> username;

  cout << "Enter password: ";
  cin >> password;

  users[username] = password;

  cout << "Account created! \n\n";
}

bool login() {
  string username, password;

  cout << "Enter username: ";
  cin >> username;

  cout << "Enter password: ";
  cin >> password;

  if(users.count(username) > 0 && users[username] == password) {
    return true;
  } else {
    return false;
  }
}

int main() {

  int choice;

  do {
    cout << "1. Signup\n";
    cout << "2. Login \n";
    cout << "3. Exit\n\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
      case 1: signup(); break;
      case 2:
        if(login()) {
          cout << "\nLogin successful\n";
        } else {
          cout << "\nInvalid credentials\n";
        }
        break;
      default:
        exit(0);
    }
  } while(choice != 3);

  return 0;
}

