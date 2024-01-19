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
    CatalogItem summerItems[MAX_ITEMS];
    CatalogItem winterItems[MAX_ITEMS];
    int numSummerItems = 0;
    int numWinterItems = 0;

public:
    void addSummerItem(string itemName, double price)
    {
        if (numSummerItems < MAX_ITEMS)
        {
            summerItems[numSummerItems++] = CatalogItem(itemName, price);
            cout << itemName << " added to the summer catalog.\n";
        }
        else
        {
            cout << "Summer catalog is full. Cannot add more items.\n";
        }
    }

    void addWinterItem(string itemName, double price)
    {
        if (numWinterItems < MAX_ITEMS)
        {
            winterItems[numWinterItems++] = CatalogItem(itemName, price);
            cout << itemName << " added to the winter catalog.\n";
        }
        else
        {
            cout << "Winter catalog is full. Cannot add more items.\n";
        }
    }

    void removeSummerItem(string itemName)
    {
        for (int i = 0; i < numSummerItems; ++i)
        {
            if (summerItems[i].itemName == itemName)
            {
                for (int j = i; j < numSummerItems - 1; ++j)
                {
                    summerItems[j] = summerItems[j + 1];
                }
                numSummerItems--;
                cout << itemName << " removed from the summer catalog.\n";
                return;
            }
        }
        cout << "Item not found in the summer catalog.\n";
    }

    void removeWinterItem(string itemName)
    {
        for (int i = 0; i < numWinterItems; ++i)
        {
            if (winterItems[i].itemName == itemName)
            {
                for (int j = i; j < numWinterItems - 1; ++j)
                {
                    winterItems[j] = winterItems[j + 1];
                }
                numWinterItems--;
                cout << itemName << " removed from the winter catalog.\n";
                return;
            }
        }
        cout << "Item not found in the winter catalog.\n";
    }

    void viewSummerCatalog()
    {
        if (numSummerItems == 0)
        {
            cout << "The summer catalog is empty.\n";
        }
        else
        {
            cout << "Items in the summer catalog:\n";
            for (int i = 0; i < numSummerItems; ++i)
            {
                cout << summerItems[i].itemName << " - " << summerItems[i].price << "-BTD\n";
            }
        }
    }

    void viewWinterCatalog()
    {
        if (numWinterItems == 0)
        {
            cout << "The winter catalog is empty.\n";
        }
        else
        {
            cout << "Items in the winter catalog:\n";
            for (int i = 0; i < numWinterItems; ++i)
            {
                cout << winterItems[i].itemName << " - " << winterItems[i].price << "-BTD\n";
            }
        }
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

void adminMenu(SignupLogin &auth, Catalog &catalog)
{
    int choice;

    while (1)
    {
        cout << "\nAdmin Menu:\n";
        cout << "1. View Summer Catalog\n";
        cout << "2. Add Item to Summer Catalog\n";
        cout << "3. Remove Item from Summer Catalog\n";
        cout << "4. View Winter Catalog\n";
        cout << "5. Add Item to Winter Catalog\n";
        cout << "6. Remove Item from Winter Catalog\n";
        cout << "7. Logout\n\n";

        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // Consume the newline character left in the input buffer

        switch (choice)
        {
        case 1:
            catalog.viewSummerCatalog();
            break;
        case 2:
        {
            string itemName;
            double price;
            cout << "Enter the item name to add to the summer catalog: ";
            getline(cin,itemName);
            cout << "Enter the price of the item: ";
            cin >> price;
            catalog.addSummerItem(itemName, price);
            break;
        }
        case 3:
        {
            string itemName;
            cout << "Enter the item name to remove from the summer catalog: ";
            getline(cin, itemName);
            catalog.removeSummerItem(itemName);
            break;
        }
        case 4:
            catalog.viewWinterCatalog();
            break;
        case 5:
        {
            string itemName;
            double price;
            cout << "Enter the item name to add to the winter catalog: ";
            getline(cin, itemName);
            cout << "Enter the price of the item: ";
            cin >> price;
            catalog.addWinterItem(itemName, price);
            break;
        }
        case 6:
        {
            string itemName;
            cout << "Enter the item name to remove from the winter catalog: ";
            getline(cin, itemName);
            catalog.removeWinterItem(itemName);
            break;
        }
        case 7:
            return;
        default:
            cout << "Invalid choice\n";
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

        cout << "Will add it letter.\n";
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
