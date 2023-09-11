#include <iostream>

using namespace std;

struct List
{
    double useful;
    List* next = nullptr;
};

List* createElement(double val)
{

    List* result = new List();
    result->useful = val;
    return result;
}

void addElement(List*& head, List* value)
{
    value->next = head;
    head = value;
}

void printList(List* head)
{
    cout << "head -> ";
    List* begunok = head;
    while (begunok != nullptr)
    {
        cout << "[" << begunok->useful << " ]";
        begunok = begunok->next;
    }
    cout << " -> end\n";
}

void findElement(List*& head, double element)
{
    List* list = head;
    while (list != nullptr && list->useful == element)
    {

        cout << list->useful;
        list = list->next;

    }
}

int main()
{
    List* my_present = nullptr;
    printList(my_present);
    addElement(my_present, createElement(6.7));
    printList(my_present);
    addElement(my_present, createElement(3.4));
    printList(my_present);
    addElement(my_present, createElement(-0.1));
    printList(my_present);
    double num;
    cout << "Введите номер: ";
    try
    {
        cin >> num;
        if (cin.fail())
        {
            throw invalid_argument("Неверный ввод: не double");
        }
        else
        {
            addElement(my_present, createElement(num));
        }
    }
    catch (const invalid_argument& e)
    {
        num = 0;
        addElement(my_present, createElement(num));
    }
    printList(my_present);
    return 0;
}