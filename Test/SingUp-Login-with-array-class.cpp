#include <iostream>
#include <string>

using namespace std;

class Admin
{
private:
    string username;
    string password;
    bool isAdminSet;

public:
    Admin() : isAdminSet(false) {}

    void setAdminCredentials(string uname, string pwd)
    {
        username = uname;
        password = pwd;
        isAdminSet = true;
    }

    bool isAdminSetFlag() const
    {
        return isAdminSet;
    }

    bool login(string user, string pass)
    {
        return (isAdminSet && user == username && pass == password);
    }
};

class SignupLogin
{
private:
    static const int MAX_USERS = 100;
    string users[MAX_USERS][2];
    int numUsers = 0;
    Admin admin;

public:
    void signup()
    {
        string username, password;

        cout << "Enter username: ";
        cin >> username;

        bool usernameExists = false;
        for (int i = 0; i < numUsers; i++)
        {
            if (users[i][0] == username)
            {
                usernameExists = true;
                break;
            }
        }

        if (usernameExists)
        {
            cout << "Username already exists!\n";
            return;
        }

        cout << "Enter password: ";
        cin >> password;

        if (password.length() < 8)
        {
            cout << "Password too short!\n";
            return;
        }

        users[numUsers][0] = username;
        users[numUsers][1] = password;
        numUsers++;

        cout << "Account created!\n\n";
    }

    bool login()
    {
        string username, password;

        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

        bool credentialsValid = false;
        for (int i = 0; i < numUsers; i++)
        {
            if (users[i][0] == username && users[i][1] == password)
            {
                credentialsValid = true;
                cout << "\nWelcome " << username << "!\n";
                break;
            }
        }

        if (!credentialsValid)
        {
            cout << "\nInvalid credentials\n";
        }

        return credentialsValid;
    }

    void forgotPassword()
    {
        string username;
        cout << "Enter your username: ";
        cin >> username;

        bool usernameFound = false;
        for (int i = 0; i < numUsers; i++)
        {
            if (users[i][0] == username)
            {
                usernameFound = true;
                break;
            }
        }

        if (!usernameFound)
        {
            cout << "Username not found!\n";
            return;
        }

        string newPassword;
        cout << "Enter new password: ";
        cin >> newPassword;

        if (newPassword.length() < 8)
        {
            cout << "Password too short!\n";
            return;
        }

        for (int i = 0; i < newPassword.length(); i++)
        {
            newPassword[i] += 1;
        }

        for (int i = 0; i < numUsers; i++)
        {
            if (users[i][0] == username)
            {
                users[i][1] = newPassword;
                break;
            }
        }

        cout << "Password changed successfully!\n";
    }

    bool adminLogin()
    {
        if (!admin.isAdminSetFlag())
        {
            cout << "Admin credentials not set. Please set admin credentials first.\n";
            return false;
        }

        string adminUsername, adminPassword;

        cout << "Enter admin username: ";
        cin >> adminUsername;

        cout << "Enter admin password: ";
        cin >> adminPassword;

        if (admin.login(adminUsername, adminPassword))
        {
            cout << "ADMIN LOGIN SUCCESSFUL!\n";
            return true;
        }
        else
        {
            cout << "Invalid admin credentials\n";
            return false;
        }
    }

    void setAdminCredentials()
    {
        if (!admin.isAdminSetFlag())
        {
            string adminUsername, adminPassword;

            cout << "Set admin username: ";
            cin >> adminUsername;

            cout << "Set admin password: ";
            cin >> adminPassword;

            admin.setAdminCredentials(adminUsername, adminPassword);
            cout << "Admin credentials set successfully!\n";
        }
        else
        {
            cout << "Admin credentials already set.\n";
        }
    }
};

int main()
{
    SignupLogin auth;

    int choice;

    while (1)
    {
        cout << "1. Signup\n";
        cout << "2. Login\n";
        cout << "3. Forgot Password\n";
        cout << "4. ADMIN LOGIN (Set credentials first)\n";
        cout << "5. Set Admin Credentials\n";
        cout << "6. Exit\n\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            auth.signup();
            break;
        case 2:
            auth.login();
            break;
        case 3:
            auth.forgotPassword();
            break;
        case 4:
            auth.adminLogin();
            break;
        case 5:
            auth.setAdminCredentials();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
