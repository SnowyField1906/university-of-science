#include <iostream>

using namespace std;

struct NODE {
    int key;
    NODE* pLeft;
    NODE* pRight;
    int height;
};


int getBalance(NODE* n) {
    if (n == NULL) return 0;
    return n->pLeft->height - n->pRight->height;
}

NODE *leftRotate(NODE *x) {
    NODE *y = x->pRight;
    NODE *T2 = y->pLeft;
 
    y->pLeft = x;
    x->pRight = T2;
 
    x->height = max(x->pLeft->height, x->pRight->height) + 1;
    y->height = max(y->pLeft->height, y->pRight->height) + 1;
 
    return y;
}

NODE *rightRotate(NODE *y) {
    NODE *x = y->pLeft;
    NODE *T2 = x->pRight;
 
    x->pRight = y;
    y->pLeft = T2;
 
    y->height = max(y->pLeft->height, y->pRight->height) + 1;
    x->height = max(x->pLeft->height, x->pRight->height) + 1;
 
    return x;
}


// 1. Initialize a node with key is a given value:
NODE* createNode(int data) {
    NODE* p = new NODE;
    p->key = data;
    p->pLeft = NULL;
    p->pRight = NULL;
    p->height = 1;
    return p;
}

// 2. Add a node with given value x into a given AVL tree (Notify if the given value existed):
NODE* Insert(NODE* &n, int x) {
    if (n == NULL) {
        n = createNode(x);
        return n;
    }
 
    if (x < n->key) n->pLeft = Insert(n->pLeft, x);
    else if (x > n->key) n->pRight = Insert(n->pRight, x);
    else return n;
 
    n->height = 1 + max(n->pLeft->height, n->pRight->height);
 
    int balance = getBalance(n);
 

    if (balance > 1 && x < n->pLeft->key) return rightRotate(n);
 
    if (balance < -1 && x > n->pRight->key) return leftRotate(n);
 
    if (balance > 1 && x > n->pLeft->key) {
        n->pLeft = leftRotate(n->pLeft);
        return rightRotate(n);
    }
 
    if (balance < -1 && x < n->pRight->key) {
        n->pRight = rightRotate(n->pRight);
        return leftRotate(n);
    }
 
    return n;
}

// 3. Remove a node with given value x from a given AVL tree (Notify if the given value not existed):
NODE* Remove(NODE* &n, int x) {
    if (n == NULL) return n;
 
    if (x < n->key) n->pLeft = Remove(n->pLeft, x);
    else if (x > n->key) n->pRight = Remove(n->pRight, x);
    else {
        if ((n->pLeft == NULL) || (n->pRight == NULL)) {
            NODE *temp = n->pLeft ? n->pLeft : n->pRight;
 
            if (temp == NULL) {
                temp = n;
                n = NULL;
            } else *n = *temp;
            free(temp);
        } else {
            NODE* temp = min(n->pRight->pLeft, n->pRight->pRight);
            n->key = temp->key;
            n->pRight = Remove(n->pRight, temp->key);
        }
    }
 
    if (n == NULL) return n;
 
    n->height = 1 + max(n->pLeft->height, n->pRight->height);
 
    int balance = getBalance(n);
 
    if (balance > 1 && getBalance(n->pLeft) >= 0) return rightRotate(n);
 
    if (balance > 1 && getBalance(n->pLeft) < 0) {
        n->pLeft = leftRotate(n->pLeft);
        return rightRotate(n);
    }
 
    if (balance < -1 && getBalance(n->pRight) <= 0) return leftRotate(n);
 
    if (balance < -1 && getBalance(n->pRight) > 0) {
        n->pRight = rightRotate(n->pRight);
        return leftRotate(n);
    }
 
    return n;
}

// 4. * Determine if a given Binary Tree is an AVL Tree:
bool isAVL(NODE* n) {
    if(n == NULL) return 1;
    int left = n->pLeft->height;
    int right = n->pRight->height;    
    if(abs(left - right) <= 1 && isAVL(n->pLeft) && isAVL(n->pRight)) return true;
    return false;
}


void menu() {
    cout << "1. Initialize a node with key is a given value" << endl;
    cout << "2. Add a node with given value x into a given AVL tree (Notify if the given value existed)" << endl;
    cout << "3. Remove a node with given value x from a given AVL tree (Notify if the given value not existed)" << endl;
    cout << "4. Determine if a given Binary Tree is an AVL Tree" << endl;
    cout << "0. Exit" << endl << endl;

    NODE *pRoot;
    int value, choice;

    cout << "Enter your choice: "; cin >> choice;

    switch(choice) {
        case 1:
            cout << "Enter value: "; cin >> value;
            pRoot = createNode(value);
            cout << "NODE created!" << endl;
            break;
        case 2:
            cout << "Enter value: "; cin >> value;
            Insert(pRoot, value);
            cout << "NODE added!" << endl;
            break;
        case 3:
            cout << "Enter value: "; cin >> value;
            Remove(pRoot, value);
            cout << "NODE removed!" << endl;
            break;
        case 4:
            if (isAVL(pRoot)) cout << "The tree is an AVL tree!" << endl;
            else cout << "The tree is not an AVL tree!" << endl;
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
    }
    cout << endl;
}

int main() {
    while (true) {
        menu();
    }
    return 0;
}