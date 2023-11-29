#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

class Stack
{
public:
    Node *top;
    Node *head = nullptr;

    void push(string data)
    {
        Node *newNode = new Node{data};
        if (top == NULL)
        {
            top = newNode;
            return;
        }
        else
        {
            newNode->data = data;
            newNode->next = top;
            top = newNode;
        }
    }

    void pop(string data)
    {
        Node *temp = top;
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        else
        {
            temp = top;
            top = top->next;
            free(temp);
        }
    }
    void display()
    {

        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Node *temp = top;
        while (temp != nullptr)
        {

            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    void disp()
    {

        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Node *temp = top;
        while (temp != nullptr)
        {
            if (temp->data == "+")
            {
                cout << "+" << endl;
            }
        }
        cout << temp->data << endl;
        temp = temp->next;
    }
};
int main()
{
    Stack s;
    s.push("a");
    s.push("+");
    s.push("b");
    s.disp();
    return 0;
}