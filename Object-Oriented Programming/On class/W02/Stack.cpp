#include <iostream>

using namespace std;

class Stack
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *top;
    int size;

    // this function should be only called from deleteElement()
    void _deleteFixup(Node *prev, Node *temp)
    {
        if (prev == nullptr)
        {
            top = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        delete temp;
        size--;
    }

public:
    // Stack's constructor
    Stack()
    {
        top = nullptr;
        size = 0;
    }

    // push an element into the top of the Stack
    void push(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        size++;
        cout << "Pushed element: " << val << endl;
    }

    // delete an element with a given value
    void deleteElement(int val)
    {
        Node *temp = top;
        Node *prev = nullptr;

        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                _deleteFixup(prev, temp);
                temp = prev;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Deleted all elements with value " << val << endl;
    }

    // pop the top element from the stack and return its value
    int pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty.\n";
            exit(1);
        }

        Node *temp = top;
        top = top->next;
        int poppedVal = temp->data;
        delete temp;
        size--;
        return poppedVal;
    }

    // check if the Stack is empty
    bool isEmpty()
    {
        return (top == nullptr);
    }

    // return the size of the Stack
    int getSize()
    {
        return size;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Stack size: " << s.getSize() << endl;
    cout << "Popped element: " << s.pop() << endl;

    cout << "Stack size: " << s.getSize() << endl;
    cout << "Popped element: " << s.pop() << endl;

    cout << "Stack size: " << s.getSize() << endl;
    s.deleteElement(1);

    cout << "Stack size: " << s.getSize() << endl;

    return 0;
}
