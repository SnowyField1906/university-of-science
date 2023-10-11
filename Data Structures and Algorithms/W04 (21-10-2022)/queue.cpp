#include <iostream>

using namespace std;

struct NODE {
    int key;
    NODE* pNext;
};

struct Queue {
    NODE* pHead;
    NODE* pTail;
};

void initialize(Queue& q, int x) {
    q.pHead->key = x;
    q.pHead->pNext = NULL;
    q.pTail = q.pHead;
}

void enqueue(Queue& q, int x) {
    NODE* p = new NODE;
    p->key = x;
    p->pNext = NULL;
    q.pTail->pNext = p;
    q.pTail = p;
}

int dequeue(Queue& q) {
    int x = q.pHead->key;
    if(q.pHead == q.pTail) {
        delete q.pHead;
        q.pHead = q.pTail = NULL;
    }
    else {
        NODE* p = q.pHead;
        q.pHead = q.pHead->pNext;
        delete p;
    }
    return x;
}

int count(Queue& q) {
    int count = 0;
    NODE* p = q.pHead;
    while (p != NULL) {
        count++;
        p = p->pNext;
    }
    return count;
}

bool ísEmpty(Queue& q) {
    return q.pHead == NULL;
}

void menu() {
    cout << "1. Initialize a queue from a given key" << endl;
    cout << "2. Enqueue a key into the queue" << endl;
    cout << "3. Dequeue an element out of a given queue, return the key's value" << endl;
    cout << "4. Count the number of elements of a given queue" << endl;
    cout << "5. Determine if a given queue is empty" << endl;
    cout << "0. Exit" << endl;

    Queue q;
    int x;
    int choice;
    do {
        cout << "Your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter a key: ";
                cin >> x;
                initialize(q, x);
                break;
            case 2:
                cout << "Enter a key: ";
                cin >> x;
                enqueue(q, x);
                break;
            case 3:
                cout << "Dequeued value: " << dequeue(q) << endl;
                break;
            case 4:
                cout << "The number of elements: " << count(q) << endl;
                break;
            case 5:
                if(ísEmpty(q)) {
                    cout << "The queue is empty!" << endl;
                } else {
                    cout << "The queue is not empty!" << endl;
                }
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}