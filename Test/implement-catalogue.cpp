#include <iostream>
#include <string>

using namespace std;

class CatalogItem
{
public:
    string itemName;
    double price;
    CatalogItem()
    {
        price = 0.0;
    }
    CatalogItem(string name, double p)
    {
        itemName = name;
        price = p;
    }
};

class Admin
{
private:
    string username;
    string password;
    bool isAdminSet;

public:
    Admin()
    {
        isAdminSet=(false);
    }

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

    int getNumSummerItems() const
    {
        return numSummerItems;
    }

    int getNumWinterItems() const
    {
        return numWinterItems;
    }

    const CatalogItem* getSummerItems() const
    {
        return summerItems;
    }

    const CatalogItem* getWinterItems() const
    {
        return winterItems;
    }
};

class CustomerCatalog
{
private:
    static const int MAX_CART_ITEMS = 20;
    string customerCart[MAX_CART_ITEMS];
    double cartTotal = 0.0;
    int numItemsInCart = 0;

public:
    void viewSummerCatalog(Catalog& catalog)
    {
        catalog.viewSummerCatalog();
    }

    void viewWinterCatalog(Catalog& catalog)
    {
        catalog.viewWinterCatalog();
    }

    void addToCart(const CatalogItem& item)
    {
        if (item.itemName.empty())
        {
            cout << "Item not found in the catalog.\n";
            return;
        }
        if (numItemsInCart < MAX_CART_ITEMS)
        {
            customerCart[numItemsInCart++] = item.itemName;
            cartTotal += item.price;
            cout << item.itemName << " added to your cart.\n";
        }
        else
        {
            cout << "Your cart is full. Cannot add more items.\n";
        }
    }

    void viewCart()
    {
        if (numItemsInCart == 0)
        {
            cout << "Your cart is empty.\n";
        }
        else
        {
            cout << "Items in your cart:\n";
            for (int i = 0; i < numItemsInCart; ++i)
            {
                cout << i + 1 << ". " << customerCart[i] << "\n";
            }
            cout << "Total: " << cartTotal << "-BTD\n";
        }
    }

    void makePayment(int paymentOption)
    {
        if (numItemsInCart == 0)
        {
            cout << "Your cart is empty. Cannot proceed to payment.\n";
            return;
        }

        switch (paymentOption)
        {
        case 1:
            cout << "Payment successful! Paid with card.\n";
            break;
        case 2:
            cout << "Payment successful! Paid with cash.\n";
            break;
        default:
            cout << "Invalid payment option\n";
            return;
        }

        clearCart();
    }

    void clearCart()
    {
        numItemsInCart = 0;
        cartTotal = 0.0;
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



    void customerSignup()
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
    bool customerLogin()
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

    void customerForgotPassword()
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
};

CatalogItem findItemInCatalog(string itemName, Catalog& catalog)
{
    for (int i = 0; i < catalog.getNumSummerItems(); ++i)
    {
        if (catalog.getSummerItems()[i].itemName == itemName)
        {
            return catalog.getSummerItems()[i];
        }
    }

    for (int i = 0; i < catalog.getNumWinterItems(); ++i)
    {
        if (catalog.getWinterItems()[i].itemName == itemName)
        {
            return catalog.getWinterItems()[i];
        }
    }

    return CatalogItem();
}

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

        cin.ignore();

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

    while (true)
    {

        int userType;
        cout << "Select user type:\n";
        cout << "1. Customer\n";
        cout << "2. Admin\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> userType;

        if (userType == 1)
        {
            int customerChoice;

            while (1)
            {
                cout << "\nCustomer Menu:\n";
                cout << "1. Signup\n";
                cout << "2. Login\n";
                cout << "3. Forgot Password\n";
                cout << "4. Exit\n\n";

                cout << "Enter your choice: ";
                cin >> customerChoice;

                switch (customerChoice)
                {
                case 1:
                    auth.customerSignup();
                    break;
                case 2:
                    if (auth.customerLogin())
                    {
                        CustomerCatalog customerCatalog;

                        int customerCategory;

                        cout << "Choose a category:\n";
                        cout << "1. Summer Items\n";
                        cout << "2. Winter Items\n";
                        cout << "Enter your choice: ";
                        cin >> customerCategory;

                        switch (customerCategory)
                        {
                        case 1:
                            customerCatalog.viewSummerCatalog(catalog);
                            break;
                        case 2:
                            customerCatalog.viewWinterCatalog(catalog);
                            break;
                        default:
                            cout << "Invalid category choice\n";
                            return 0;
                        }
                        int cartAction;
                        cout << "Choose an action:\n";
                        cout << "1. Add to Cart\n";
                        cout << "2. View Cart\n";
                        cout << "3. Make Payment\n";
                        cout << "4. Back to Main Menu\n";
                        cout << "Enter your choice: ";
                        cin >> cartAction;
                        string itemName;
                        CatalogItem item;
                        switch (cartAction)
                        {
                        case 1:
                            cout << "Enter the item name to add to the cart: ";
                            cin.ignore();
                            getline(cin, itemName);
                            item = findItemInCatalog(itemName, catalog);
                            if (item.itemName != "")
                                customerCatalog.addToCart(item);
                            break;
                        case 2:
                            customerCatalog.viewCart();
                            break;
                        case 3:
                            int paymentOption;
                            cout << "Choose a payment option:\n";
                            cout << "1. Card\n";
                            cout << "2. Cash\n";
                            cout << "Enter your choice: ";
                            cin >> paymentOption;
                            customerCatalog.makePayment(paymentOption);
                            break;
                        case 4:
                            return 0;
                        default:
                            cout << "Invalid choice\n";
                        }
                    }
                    break;
                case 3:
                    auth.customerForgotPassword();
                    break;
                case 4:
                    return 0;
                default:
                    cout << "Invalid choice\n";
                }
            }
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
        else if (userType==3)
        {
            break;
        }
        else
        {
            cout << "Invalid user type\n";
        }
    }
    return 0;
}
