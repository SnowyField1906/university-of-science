#include <iostream>

using namespace std;

class Queue
{
private:
    struct Node
    {
        int data;
        Node *next;
    };

    Node *front;
    Node *rear;
    int size;

    // this function should be only called from deleteElement()
    void _deleteFixup(Node *prev, Node *temp)
    {
        if (prev == nullptr)
        {
            front = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        delete temp;
        size--;
    }

public:
    // Queue's constructor
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // enqueue an giving element into the end of Queue
    void enqueue(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = nullptr;

        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout << "Enqueued element " << val << endl;
    }

    // delete all elements having the given value
    void deleteElement(int val)
    {
        Node *temp = front;
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

    // return the front element and remove it from the queue
    int dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty.\n";
            exit(1);
        }

        Node *temp = front;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        int dequeuedVal = temp->data;
        delete temp;
        size--;
        return dequeuedVal;
    }

    // check if the Queue is empty
    bool isEmpty()
    {
        return (front == nullptr);
    }

    // return the size of the Queue
    int getSize()
    {
        return size;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(4);

    cout << "Queue size: " << q.getSize() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;

    cout << "Queue size: " << q.getSize() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;

    cout << "Queue size: " << q.getSize() << endl;
    q.deleteElement(4);

    cout << "Queue size: " << q.getSize() << endl;

    return 0;
}