#include <iostream>
#include <string>

using namespace std;

class CatalogItem
{
public:
    string itemName;
    double price;
    CatalogItem() : price(0.0) {}
    CatalogItem(string name, double p) : itemName(name), price(p) {}
};

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

class Catalog
{
private:
    static const int MAX_ITEMS = 100;
    CatalogItem items[MAX_ITEMS];
    int numItems = 0;

public:
    void addItem(string itemName, double price)
    {
        if (numItems < MAX_ITEMS)
        {
            items[numItems++] = CatalogItem(itemName, price);
            cout << itemName << " Added to the catalog.\n";
        }
        else
        {
            cout << "Catalog is full. Cannot add more items.\n";
        }
    }

    void removeItem(string itemName)
    {
        for (int i = 0; i < numItems; ++i)
        {
            if (items[i].itemName == itemName)
            {
                for (int j = i; j < numItems - 1; ++j)
                {
                    items[j] = items[j + 1];
                }
                numItems--;
                cout << itemName << " Removed from the catalog.\n";
                return;
            }
        }
        cout << "Item not found in the catalog.\n";
    }

    void viewCatalog()
    {
        if (numItems == 0)
        {
            cout << "The catalog is empty.\n";
        }
        else
        {
            cout << "Items in the catalog:\n";
            for (int i = 0; i < numItems; ++i)
            {
                cout << items[i].itemName << " - TK" << items[i].price << "\n";
            }
        }
    }

    const CatalogItem *getItems() const
    {
        return items;
    }

    int getNumItems() const
    {
        return numItems;
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
            cout << "Invalid admin credentials.\n";
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
void adminMenu(SignupLogin &auth, Catalog &catalog)
{
    int choice;

    while (1)
    {
        cout << "\nAdmin Menu:\n";
        cout << "1. View Catalog\n";
        cout << "2. Add Item to Catalog\n";
        cout << "3. Remove Item from Catalog\n";
        cout << "4. Logout\n\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            catalog.viewCatalog();
            break;
        case 2:
        {
            string itemName;
            double price;
            cout << "Enter the item name to add to the catalog: ";
            cin >> itemName;
            cout << "Enter the price of the item: ";
            cin >> price;
            catalog.addItem(itemName, price);
            break;
        }
        case 3:
        {
            string itemName;
            cout << "Enter the item name to remove from the catalog: ";
            cin >> itemName;
            catalog.removeItem(itemName);
            break;
        }
        case 4:
            return;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
int main()
{
    SignupLogin auth;
    Catalog catalog;

    int userType;
    cout << "Select user type:\n";
    cout << "1. Customer\n";
    cout << "2. Admin\n";
    cout << "Enter your choice: ";
    cin >> userType;

    if (userType == 1)
    {
        cout << "will be included later on\n";
    }
    else if (userType == 2)
    {
        auth.setAdminCredentials();

        while (!auth.adminLogin())
        {
            cout << "Invalid credentials. Please try again.\n";
        }
        adminMenu(auth, catalog);
    }
    else
    {
        cout << "Invalid user type\n";
    }

    return 0;
}
