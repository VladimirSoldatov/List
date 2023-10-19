#include <iostream>
#include <initializer_list>
using namespace std;

struct Node
{
    Node* next;
    Node* prev;
    int value;
    Node(int _value)
    {
        value = _value;
        next = NULL;
        prev = NULL;
    }

};

struct List
{
    Node* HEAD;
    Node* last;
    List()
    {
        HEAD = NULL;
        last = NULL;
    }
    void AddNode(int _value)
    {
        Node* temp = new Node(_value);
        if (HEAD != NULL)
        {

            last->next = temp;
            temp->prev = last;
            last = temp;
        }
        else
        {
            HEAD = temp;
            last = temp;
        }
    }

    bool isEmpty()
    {
        if (HEAD == NULL && last == NULL)
            return true;
        else
            return false;
    }
    void DeleteNodeByValue(int key)
    {

        if (isEmpty())
            return;
        Node* temp = HEAD;
        do
        {
            if (temp->value == key)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                break;
            }
            temp = temp->next;
        } while (temp != NULL);
    }
    void AddNewValueAfterValue(int _search, int _value)
    {
        if (isEmpty())
        {
            AddNode(_value);
            return;
        }
        Node* searchNode = HEAD;// Поисковая Node
        while (searchNode != NULL) //Пока не кончился список
        {
            if (searchNode->value == _search) //Сравнение значения Value поисковыой головы со аргументом
            {
                Node* newNode = new Node(_value);//Создаем новую Node
                newNode->prev = searchNode; // Назад новая Node ссылается на поисковую Node
                newNode->next = searchNode->next; // Перед новой Node ссфлается на next поисковой
                searchNode->next = newNode; //Посковая нода перед ссыдается на новую ноду
                if (newNode->next != NULL) // Next новой ноды существует, если существует, то prev указывает NewNode
                    newNode->next->prev = newNode;
                else
                    last = newNode;
                break;
            }
            searchNode = searchNode->next;
        }
    }
    void Print() 
    {
        if (isEmpty())
        {
            return;
        }
        Node* temp = HEAD;
        while (temp != NULL)
        {
            std::cout << "Value:" << temp->value << "\n";
            temp = temp->next;
        }
    }
     
};

template<typename T, typename K>
T foo(T a, K b)
{

}
void foo(initializer_list<int> i)
{
    for (int item : i)
    {
        cout << item << "\t";
    }
    cout << endl;
}
struct Memeber
{
    int a;
    int b;
    int c;

int main()
{

    foo({ 1, 2, 3, 4, 5 });

    
    List a;
    a.AddNode(5);
    a.AddNode(10);
    a.AddNode(15);
    //a.DeleteNodeByValue(10);
    a.AddNewValueAfterValue(15, 20);
    a.Print();

    

}
