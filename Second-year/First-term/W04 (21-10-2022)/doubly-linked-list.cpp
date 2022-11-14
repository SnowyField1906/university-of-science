#include <iostream>

using namespace std;

struct DNODE {
    int key;
    DNODE* pNext;
    DNODE* pPrev;
};

struct DList {
    DNODE *pHead;
    DNODE *pTail;
};

// 1. Initialize a NODE from a given integer
DNODE *createNode(int data) {
    DNODE *p = new DNODE;
    p->key = data;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}

// 2. Initialize a List from a given NODE
DList* createList(DNODE* pNode) {
    DList* L = new DList;
    L->pHead = pNode;
    L->pTail = pNode;
    return L;
}

// 3. Insert an integer to the head of a given List
bool addHead(DList* L, int data) {
    DNODE* p = createNode(data);
    if (p == NULL) return false;
    p->pNext = L->pHead;
    L->pHead->pPrev = p;
    L->pHead = p;
    return true;
}

// 4. Insert an integer to the tail of a given List
bool addTail(DList* L, int data) {
    DNODE* p = createNode(data);
    if (p == NULL) return false;
    L->pTail->pNext = p;
    p->pPrev = L->pTail;
    L->pTail = p;
    return true;
}

// 5. Remove the first NODE of a given List:
bool removeHead(DList* L) {
    if (L->pHead == NULL) return false;
    DNODE* p = L->pHead;
    L->pHead = p->pNext;
    L->pHead->pPrev = NULL;
    delete p;
    return true;
}

// 6. Remove the last NODE of a given List
bool removeTail(DList* L) {
    if (L->pTail == NULL) return false;
    DNODE* p = L->pTail;
    L->pTail = p->pPrev;
    L->pTail->pNext = NULL;
    delete p;
    return true;
}

// 7. Remove all NODE from a given List
void removeAll(DList* L) {
    while (L->pHead != NULL) {
        removeHead(L);
    }
}

// 8. Remove node before the node has val value in a given List
void removeBefore(DList* L, int val) {
    DNODE* p = L->pHead;
    while (p != NULL) {
        if (p->key == val) {
            if (p->pPrev != NULL) {
                DNODE* q = p->pPrev;
                p->pPrev = q->pPrev;
                q->pPrev->pNext = p;
                delete q;
            }
            return;
        }
        p = p->pNext;
    }
}

// 9. Remove node after the node has val value in a given List
void removeAfter(DList* L, int val) {
    DNODE* p = L->pHead;
    while (p != NULL) {
        if (p->key == val) {
            if (p->pNext != NULL) {
                DNODE* q = p->pNext;
                p->pNext = q->pNext;
                q->pNext->pPrev = p;
                delete q;
            }
            return;
        }
        p = p->pNext;
    }
}

// 10. Insert an integer at a position of a given List
bool addPos(DList *&L, int data, int pos) {
    if (pos == 0) {
        addHead(L, data);
        return true;
    }
    DNODE* p = L->pHead;
    int i = 0;
    while (p != NULL) {
        if (i == pos - 1) {
            DNODE* q = createNode(data);
            q->pNext = p->pNext;
            q->pPrev = p;
            p->pNext = q;
            q->pNext->pPrev = q;
            return true;
        }
        p = p->pNext;
        i++;
    }
    return false;
}

// 11. Remove an integer at a position of a given List
void removePos(DList *&L, int pos) {
    if (pos == 0) {
        removeHead(L);
        return;
    }
    DNODE* p = L->pHead;
    int i = 0;
    while (p != NULL) {
        if (i == pos - 1) {
            DNODE* q = p->pNext;
            p->pNext = q->pNext;
            q->pNext->pPrev = p;
            delete q;
            return;
        }
        p = p->pNext;
        i++;
    }
}

// 12. Insert an integer before a value of a given List:
bool addBefore(DList* L, int data, int val) {
    DNODE* p = L->pHead;
    while (p != NULL) {
        if (p->key == val) {
            DNODE* q = createNode(data);
            q->pNext = p;
            q->pPrev = p->pPrev;
            p->pPrev = q;
            q->pPrev->pNext = q;
            return true;
        }
        p = p->pNext;
    }
    return false;
}
// 13. Insert an integer after a value of a given List:
bool addAfter(DList* L, int data, int val) {
    DNODE* p = L->pHead;
    while (p != NULL) {
        if (p->key == val) {
            DNODE* q = createNode(data);
            q->pNext = p->pNext;
            q->pPrev = p;
            p->pNext = q;
            q->pNext->pPrev = q;
            return true;
        }
        p = p->pNext;
    }
    return false;
}
// 14. Print all elements of a given List:
void printList(DList* L) {
    DNODE* p = L->pHead;
    while (p != NULL) {
        cout << p->key << " ";
        p = p->pNext;
    }
    cout << endl;
}
// 15. Count the number of elements List:
int countElements(DList* L) {
    int count = 0;
    DNODE* p = L->pHead;
    while (p != NULL) {
        count++;
        p = p->pNext;
    }
    return count;
}
// 16. Create a new List by reverse a given List:
DList* reverseList(DList* L) {
    
}
// 17. Remove all duplicates from a given List:
void removeDuplicate(DList* &L) {
    DNODE* p = L->pHead;
    while (p != NULL) {
        DNODE* q = p->pNext;
        while (q != NULL) {
            if (p->key == q->key) {
                DNODE* r = q;
                q = q->pNext;
                r->pPrev->pNext = r->pNext;
                r->pNext->pPrev = r->pPrev;
                delete r;
            }
            else q = q->pNext;
        }
        p = p->pNext;
    }
}
// 18. Remove all key value from a given List:
bool removeElement(DList* &L, int key) {
    DNODE* p = L->pHead;
    while (p != NULL) {
        if (p->key == key) {
            if (p == L->pHead) {
                removeHead(L);
                p = L->pHead;
            }
            else if (p == L->pTail) {
                removeTail(L);
                p = L->pTail;
            }
            else {
                DNODE* q = p;
                p = p->pNext;
                q->pPrev->pNext = q->pNext;
                q->pNext->pPrev = q->pPrev;
                delete q;
            }
        }
        else p = p->pNext;
    }
    return true;
}

void Menu() {
    cout << endl << endl << "1. Initialize a NODE from a given value" << endl;
    cout << "2. Initialize a List from a give NODE" << endl;
    cout << "3. Insert an integer to the head of a given List" << endl;
    cout << "4. Insert an integer to the tail of a given List" << endl;
    cout << "5. Remove the first NODE of a given List" << endl;
    cout << "6. Remove the last of a given List" << endl;
    cout << "7. Remove all NODE from a given List" << endl;
    cout << "8. Remove node before the node has val value in a given List" << endl;
    cout << "9. Remove node after the node has val value in a given List" << endl;
    cout << "10. Insert an integer at a position of a given List" << endl;
    cout << "11. Remove an integer at a position of a given List" << endl;
    cout << "12. Insert an integer before a value of a given List" << endl;
    cout << "13. Insert an integer after a value of a given List" << endl;
    cout << "14. Print all elements of a given List" << endl;
    cout << "15. Count the number of elements List" << endl;
    cout << "16. Create a new List by reverse a given List" << endl;
    cout << "17. Remove all duplicates from a given List" << endl;
    cout << "18. Remove all key value from a given List" << endl;
    cout << "0. Exit" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    DNODE* p;
    DList* L, *L2;
    int data;
    int pos;

    switch (choice) {
    case 1:
        cout << "Enter data: "; cin >> data;
        p = createNode(data);
        cout << "NODE Initialized!" << endl;
        break;
    case 2:
        L = createList(p);
        cout << "List Initialized!";
        break;
    case 3:
        cout << "Enter data: "; cin >> data;
        if(addHead(L, data)) {
            cout << "Added to head!" << endl;
        }
        else {
            cout << "Failed!" << endl;
        }
        break;
    case 4:
        cout << "Enter data: "; cin >> data;
        if (addTail(L, data)) {
            cout << "Added to tail!" << endl;
        }
        else {
            cout << "Failed!" << endl;
        }
        break;
    case 5:
        removeHead(L);
        cout << "Removed head!";
        break;
    case 6:
        removeTail(L);
        cout << "Removed tail!";
        break;
    case 7:
        removeAll(L);
        cout << "Removed all!";
        break;
    case 8:
        int value;
        cout << "Enter value: "; cin >> value;
        removeBefore(L, data);
        cout << "Removed!";
        break;
    case 9:
        cout << "Enter value: "; cin >> value;
        removeAfter(L, data);
        cout << "Removed!";
        break;
    case 10:
        cout << "Enter position: "; cin >> pos;
        cout << "Enter data: "; cin >> data;
        if (addPos(L, pos, data)) {
            cout << "Inserted!" << endl;
        }
        else {
            cout << "Failed!" << endl;
        }
        break;
    case 11:
        cout << "Enter position: "; cin >> pos;
        removePos(L, pos);
        cout << "Removed!";
        break;
    case 12:
        cout << "Enter value: "; cin >> value;
        cout << "Enter data: "; cin >> data;
        if (addBefore(L, value, data)) {
            cout << "Inserted!" << endl;
        }
        else {
            cout << "Failed!" << endl;
        }
        break;
    case 13:
        cout << "Enter value: "; cin >> value;
        cout << "Enter data: "; cin >> data;
        if (addAfter(L, value, data)) {
            cout << "Inserted!" << endl;
        }
        else {
            cout << "Failed!" << endl;
        }
        break;
    case 14:
        printList(L);
        break;
    case 15:
        cout << "Number of elements: " << countElements(L) << endl;
        break;
    case 16:
        L2 = reverseList(L);
        cout << "Reversed!" << endl;
        printList(L2);
        break;
    case 17:
        removeDuplicate(L);
        cout << "Removed!";
        break;
    case 18:
        int key;
        cout << "Enter key: "; cin >> key;
        if (removeElement(L, key)) {
            cout << "Removed!" << endl;
        }
        else {
            cout << "Failed!" << endl;
        }
        break;
    case 0:
        exit(0);
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
}

int main() {
    while(true) {
        Menu();
    }
    return 0;
}