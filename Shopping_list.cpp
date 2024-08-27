#include <iostream>
#include <vector>
using namespace std;

class Shopping
{
    string item_name;
    float item_price;
    float item_quantity;

public:
    Shopping(string name, float price, float quantity)
        : item_name(name), item_price(price), item_quantity(quantity) {}
    void getItem(vector<Shopping> &list);
    void deleteItem(vector<Shopping> &list, string &key);
    void displayItem(vector<Shopping> &list);
    void totalPrice(vector<Shopping> &list);
};

void Shopping::getItem(vector<Shopping> &list)
{
    string name;
    float price, quantity;
    cout << "Enter item name: ";
    cin >> name;
    cout << "Enter item price: ";
    cin >> price;
    cout << "Enter item quantity(in kg): ";
    cin >> quantity;
    list.push_back(Shopping(name, price, quantity));
}

void Shopping::deleteItem(vector<Shopping> &list, string &key)
{
    for (auto it = list.begin(); it != list.end(); it++)
    {
        if (it->item_name == key)
        {
            list.erase(it);
            cout << "Item deleted successfully." << endl;
            return;
        }
    }
    cout << "Item is not found." << endl;
}

void Shopping::displayItem(vector<Shopping> &list)
{
    cout << "Items are: " << endl;
    for (auto it : list)
    {
        cout << "Name: " << it.item_name << " "
             << " Price: " << it.item_price << " Rupees. "
             << "Quantity: " << it.item_quantity << " kg." << endl;
    }
}

void Shopping::totalPrice(vector<Shopping> &list)
{
    float total = 0;
    cout << "Total price of all items: ";
    for (auto it : list)
    {
        total += (it.item_price * it.item_quantity);
    }
    cout << total << " Rupees." << endl;
}

int main()
{
    vector<Shopping> list;
    int choice;
    do
    {
        cout << "1.Add item: " << endl;
        cout << "2.Delete item: " << endl;
        cout << "3.Display items: " << endl;
        cout << "4.check Total amount: " << endl;
        cout << "5.exit: " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            list.back().getItem(list);
            break;
        }
        case 2:
        {
            string key;
            cout << "Enter item name to delete from list: ";
            cin >> key;
            list.back().deleteItem(list, key);
            break;
        }
        case 3:
            list.back().displayItem(list);
            break;
        case 4:
            list.back().totalPrice(list);
            break;
        case 5:
            cout << "Exiting the program." << endl;
            break;
        }
        cout << endl;
    } while (choice != 5);
    return 0;
}
