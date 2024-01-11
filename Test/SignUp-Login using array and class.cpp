#include <iostream>
#include <string>
using namespace std;

class SignupLogin {
string users[100][2];
int numUsers = 0;

public:
void signup() {
string username, password;
cout << "Enter username: ";
cin >> username;

int i;
for(i=0; i<numUsers; i++) {
if(users[i][0] == username) {
cout << "Username already exists!\n"; 
return;
}
}

cout << "Enter password: ";
cin >> password; 

if(password.length() < 8) {
cout << "Password too short!\n";
return; 
}

// Encoding the password by increasing its ASCII value +1. 
for(int i=0; i<password.length(); i++) {
password[i] += 1; 
}

users[numUsers][0] = username;
users[numUsers][1] = password;
numUsers++;
  
cout << "Account created!\n\n";  
}

bool login() {
string username, password;
cout << "Enter username: ";
cin >> username;  
cout << "Enter password: ";
cin >> password;
   
// Decode entered password by decreasing its ASCII value -1.
for(int i=0; i<password.length(); i++) {
password[i] -= 1;  
}

for(int i=0; i<numUsers; i++) {
if(users[i][0] == username && users[i][1] == password) {
cout << "\nWelcome " << username << "!\n";
return true;
} 
}
  
cout << "\nInvalid credentials\n";
return false;
}
};

int main() {  
SignupLogin auth;
int choice;  

while(1) {
cout << "1. Signup\n"; 
cout << "2. Login\n";
cout << "3. Exit\n\n";  
cout << "Enter your choice: ";
cin >> choice;

if(choice == 1) {
auth.signup();  
}
else if(choice == 2) {  
auth.login();
}
else {
break;  
}
}
 
return 0;  
}
