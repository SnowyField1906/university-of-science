#include <iostream>

using namespace std;

struct NODE {
    int key;
    NODE* pNext;
};

struct Stack {
    NODE* pTop;
};

void initialize(Stack& s, int x) {
    s.pTop->key = x;
    s.pTop->pNext = NULL;
}

void push(Stack& s, int x) {
    NODE* p = new NODE;
    p->key = x;
    p->pNext = s.pTop;
    s.pTop = p;
}

int pop(Stack& s) {
    int x = s.pTop->key;
    if (s.pTop->pNext == NULL) {
        delete s.pTop;
        s.pTop = NULL;
    }
    else {
        NODE *p = s.pTop;
        NODE *q = s.pTop;
        p = p->pNext;
        delete q;
        s.pTop = p;
    }
    return x;
}

int count(Stack& s) {
    int count = 0;
    NODE* p = s.pTop;
    while (p != NULL) {
        count++;
        p = p->pNext;
    }
    return count;
}

bool ísEmpty(Stack& s) {
    return s.pTop == NULL;
}

void menu() {
    cout << "1. Initialize a stack from a given key" << endl;
    cout << "2. Push a key into the stack" << endl;
    cout << "3. Pop an element out of a given stack, return the key's value" << endl;
    cout << "4. Count the number of elements of a given stack" << endl;
    cout << "5. Determine if a given stack is empty" << endl;
    cout << "0. Exit" << endl;

    Stack s;
    int choice, x;
    do {
        cout << "Your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter a key: ";
                cin >> x;
                initialize(s, x);
                break;
            case 2:
                cout << "Enter a key: ";
                cin >> x;
                push(s, x);
                break;
            case 3:
                cout << "Popped value: " << pop(s) << endl;
                break;
            case 4:
                cout << "The number of elements: " << count(s) << endl;
                break;
            case 5:
                cout << "The stack is " << (ísEmpty(s) ? "empty" : "not empty") << endl;
                break;
            default:
                break;
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
