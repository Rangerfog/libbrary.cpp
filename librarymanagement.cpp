#include <iostream>
#include <conio.h>
#include <stdio.h>
#include<stdlib.h>
#include <fstream>
using namespace std;
class library
{
public:
    void controle_panel();
    void add_book();
    void display_book();
};
void library ::controle_panel()
{
    system("cls");
    cout << "contronal panel" << endl << endl;
    cout << "1. add new book" << endl;
    cout << "2. display book" << endl;
    cout << "3. cheak spesific book" << endl;
    cout << "4. update book" << endl;
    cout << "5. delete book" << endl;
    cout << "6. exit" << endl;
}
void library ::add_book()
{
    system("cls");
    fstream file;
    string b_name, a_name;
    cout << "add new book..." << endl
         << endl;
    cout << "enter book name:";
    cin >> b_name;
    cout << "enter auther name:";
    cin >> a_name;
    file.open("C://book//Book.txt", ios::out | ios::app);
    file << " " << b_name << " " << a_name << endl;
    file.close();
}
void library ::display_book()
{
    system("cls");
    fstream file;
    string b_name, a_name;
    file.open("C://book//Book.txt", ios::in);
    if (!file)
    {
        cout << "Path Error...";
    }
    else
    {
        file >> b_name >> a_name;
        while (!file.eof())
        {
            cout << " " << b_name << " " << a_name;
            file >> b_name >> a_name;
        }
        file.close();
    }
}
int main()
{
    int enter;
    char x;
    library b;
    b.controle_panel();
    cout << "What do you want: ";
    cin >> enter;

    switch (enter)
    {
    case 1:
        do
        {
            b.add_book();
            cout << "do you want to add another (Y/N):";
            cin >> x;
        } while (x == 'y');
        break;
    case 2:
        b.display_book();
        break;
    case 6:
        
        break;

    default:
        cout << "Please attempt right selection";
        break;
    }
    return 0;
}