#include <iostream>
#include <string>
using namespace std;

class Catalogue
{

public:

    void menu()
    {
        int choice;
        while(true)
        {
            cout<<"0. <-- Go back <-- \n";
            cout<<"1. Please Select your Gender.\n";
            cout<<"2. Please Select the Season you want to shop for.\n";
            cout<<"3. Please Select the Body-part you want to shop for.\n";
            cout<<"4. Please Select the Item you want to buy.\n";
            cout<<"5. Please Select a size of the Item you want to buy.\n";
            cout<<"6. Please Enter a Quantity of the item you want to buy.\n";
            cout<<"7. Add to cart.\n";
            cout<<"8. View cart.\n";
            cout<<"9. Remove from cart.\n";
            cout<<"10. Please confirm your order.\n";
            cout<<"11. View your Order.\n";
            cout<<"99. To Exit.\n";

            cin>>choice;

            switch(choice)
            {
            case 0:
                GoBack();
                break;

            case 1:
                SelectGender();
                break;

            case 2:
                SelectSeason();
                break;

            case 3:
                SelectBodyPart();
                break;

            case 4:
                SelectItem();
                break;

            case 5:
                SelectSize();
                break;

            case 6:
                EnterQuantity();
                break;

            case 7:
                AddToCart();
                break;

            case 8:
                ViewCart();
                break;

            case 9:
                RemoveCart();
                break;

            case 10:
                ConfirmOrder();
                break;

            case 11:
                ViewOrder();
                break;

            default:
                exit(0);
            }
        }
    }

    void GoBack()
    {

    }

    void SelectGender()
    {

    }

    void SelectSeason()
    {

    }

    void SelectBodyPart()
    {


    void SelectItem()
    {

    }

    void SelectSize()
    {

    }

    void EnterQuantity()
    {

    }

    void AddToCart()
    {

    }

    void ViewCart()
    {

    }

    void RemoveCart()
    {

    }

    void ConfirmOrder()
    {

    }

    void ViewOrder()
    {

    }

private:

};


int main()
{

    Catalogue c;
    c.menu();

    return 0;
}
