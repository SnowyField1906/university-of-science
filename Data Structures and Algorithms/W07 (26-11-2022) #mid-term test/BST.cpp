#include <iostream>

using namespace std;

struct NODE {
    int key;
    NODE* pLeft;
    NODE* pRight;
};


// 1. Initialize a NODE from a given value:
NODE* createNode(int data) {
    NODE* p = new NODE;
    p->key = data;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

// 2. Add a NODE with given value into a given Binary Search Tree:
void Insert(NODE* &pRoot, int x) {
    if (pRoot == NULL) pRoot = createNode(x);
    else {
        if (x < pRoot->key) Insert(pRoot->pLeft, x);
        else if (x > pRoot->key) Insert(pRoot->pRight, x);
        else cout << "The value " << x << " is already existed" << endl;
    }
}

// 3. Pre-order Traversal:
void NLR(NODE* pRoot) {
    if (pRoot != NULL) {
        cout << pRoot->key << " ";
        NLR(pRoot->pLeft);
        NLR(pRoot->pRight);
    }
}

// 4. In-order Traversal:
void LNR(NODE* pRoot) {
    if (pRoot != NULL) {
        LNR(pRoot->pLeft);
        cout << pRoot->key << " ";
        LNR(pRoot->pRight);
    }
}

// 5. Post-order Traversal:
void LRN(NODE* pRoot) {
    if (pRoot != NULL) {
        LRN(pRoot->pLeft);
        LRN(pRoot->pRight);
        cout << pRoot->key << " ";
    }
}

// 6. Level-order Traversal:
void LevelOrder(NODE* pRoot) {
    if (pRoot != NULL) {
        NODE* queue[100];
        int front = 0, rear = 0;
        queue[rear++] = pRoot;
        while (front != rear) {
            NODE* p = queue[front++];
            cout << p->key << " ";
            if (p->pLeft != NULL) queue[rear++] = p->pLeft;
            if (p->pRight != NULL) queue[rear++] = p->pRight;
        }
    }
}

// 7. Calculate the height of a given Binary Tree;
int Height(NODE* pRoot) {
    if (pRoot == NULL) return 0;
    else {
        int leftHeight = Height(pRoot->pLeft);
        int rightHeight = Height(pRoot->pRight);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

// 8. Count the number of NODE from a given Binary Tree:
int countNode(NODE* pRoot) {
    if (pRoot == NULL) return 0;
    else return countNode(pRoot->pLeft) + countNode(pRoot->pRight) + 1;
}

// 9. Calculate the total value of all NODEs from a given Binary Tree:
int sumNode(NODE* pRoot) {
    if (pRoot == NULL) return 0;
    else return sumNode(pRoot->pLeft) + sumNode(pRoot->pRight) + pRoot->key;
}

// 10. Find and return a NODE with given value from a given Binary Search Tree:
NODE* Search(NODE* pRoot, int x) {
    if (pRoot == NULL) return NULL;
    else {
        if (x < pRoot->key) return Search(pRoot->pLeft, x);
        else if (x > pRoot->key) return Search(pRoot->pRight, x);
        else return pRoot;
    }
}

// 11. Remove a NODE with given value from a given Binary Search Tree:
void Remove(NODE* &pRoot, int x) {
    if (pRoot == NULL) cout << "The value " << x << " is not existed" << endl;
    else {
        if (x < pRoot->key) Remove(pRoot->pLeft, x);
        else if (x > pRoot->key) Remove(pRoot->pRight, x);
        else {
            NODE* p = pRoot;
            if (pRoot->pLeft == NULL) pRoot = pRoot->pRight;
            else if (pRoot->pRight == NULL) pRoot = pRoot->pLeft;
            else {
                NODE* q = pRoot->pLeft;
                while (q->pRight != NULL) q = q->pRight;
                q->pRight = pRoot->pRight;
                pRoot = pRoot->pLeft;
            }
            delete p;
        }
    }
}

// 12. Initialize a Binary Search Tree from a given array:
NODE* createTree(int a[], int n) {
    NODE* pRoot = NULL;
    for (int i = 0; i < n; i++) Insert(pRoot, a[i]);
    return pRoot;
}

// 13. Completely remove a given Binary Search Tree:
void removeTree(NODE* &pRoot) {
    if (pRoot != NULL) {
        removeTree(pRoot->pLeft);
        removeTree(pRoot->pRight);
        delete pRoot;
        pRoot = NULL;
    }
}

// 14. Calculate the height of a NODE with given value: (return -1 if value not exist)
int heightNode(NODE* pRoot, int value) {
    if (pRoot == NULL) return -1;
    else {
        if (value < pRoot->key) return heightNode(pRoot->pLeft, value);
        else if (value > pRoot->key) return heightNode(pRoot->pRight, value);
        else return Height(pRoot);
    }
}

// 15. * Calculate the level of a given NODE:
int Level(NODE* pRoot, NODE* p) {
    if (pRoot == NULL) return -1;
    else {
        if (pRoot == p) return 1;
        else {
            int leftLevel = Level(pRoot->pLeft, p);
            int rightLevel = Level(pRoot->pRight, p);
            if (leftLevel == -1 && rightLevel == -1) return -1;
            else return (leftLevel > rightLevel ? leftLevel : rightLevel) + 1;
        }
    }
}

// 16. * Count the number leaves from a given Binary Tree:
int countLeaf(NODE* pRoot) {
    if (pRoot == NULL) return 0;
    else {
        if (pRoot->pLeft == NULL && pRoot->pRight == NULL) return 1;
        else return countLeaf(pRoot->pLeft) + countLeaf(pRoot->pRight);
    }
}

// 17. * Count the number of NODE from a given Binary Search Tree which key value is less than a given value:
int countLess(NODE* pRoot, int x) {
    if (pRoot == NULL) return 0;
    else {
        if (x < pRoot->key) return countLess(pRoot->pLeft, x);
        else if (x > pRoot->key) return countLess(pRoot->pLeft, x) + countNode(pRoot->pRight) + 1;
        else return countNode(pRoot->pLeft);
    }
}

// 18. * Count the number of NODE from a given Binary Search Tree which key value is greater than a given value:
int countGreater(NODE* pRoot, int x) {
    if (pRoot == NULL) return 0;
    else {
        if (x < pRoot->key) return countGreater(pRoot->pLeft, x) + countNode(pRoot->pRight) + 1;
        else if (x > pRoot->key) return countGreater(pRoot->pRight, x);
        else return countNode(pRoot->pRight);
    }
}

// 19. * Determine if a given Binary Tree is Binary Search Tree:
bool isBST(NODE* pRoot) {
    if (pRoot == NULL) return true;
    else {
        if (pRoot->pLeft != NULL && pRoot->pLeft->key > pRoot->key) return false;
        if (pRoot->pRight != NULL && pRoot->pRight->key < pRoot->key) return false;
        return isBST(pRoot->pLeft) && isBST(pRoot->pRight);
    }
}

// 20. * Determine if a given Binary Tree is a Full Binary Search Tree:
bool isFullBST(NODE* pRoot) {
    if (pRoot == NULL) return true;
    else {
        if (pRoot->pLeft == NULL && pRoot->pRight == NULL) return true;
        if (pRoot->pLeft != NULL && pRoot->pRight != NULL) return isFullBST(pRoot->pLeft) && isFullBST(pRoot->pRight);
        return false;
    }
}


void menu() {
    cout << "1. Initialize a NODE from a given value" << endl;
    cout << "2. Add a NODE with given value into a given Binary Search Tree" << endl;
    cout << "3. Pre-order Traversal" << endl;
    cout << "4. In-order Traversal" << endl;
    cout << "5. Post-order Traversal" << endl;
    cout << "6. Level-order Traversal" << endl;
    cout << "7. Calculate the height of a given Binary Tree;" << endl;
    cout << "8. Count the number of NODE from a given Binary Tree" << endl;
    cout << "9. Calculate the total value of all NODEs from a given Binary Tree" << endl;
    cout << "10. Find and return a NODE with given value from a given Binary Search Tree" << endl;
    cout << "11. Remove a NODE with given value from a given Binary Search Tree" << endl;
    cout << "12. Initialize a Binary Search Tree from a given array" << endl;
    cout << "13. Completely remove a given Binary Search Tree" << endl;
    cout << "14. Calculate the height of a NODE with given value: (return -1 if value not exist)" << endl;
    cout << "15. Calculate the level of a given NODE" << endl;
    cout << "16. Count the number leaves from a given Binary Tree" << endl;
    cout << "17. Count the number of NODE from a given Binary Search Tree which key value is less than a given value" << endl;
    cout << "18. Count the number of NODE from a given Binary Search Tree which key value is greater than a given value" << endl;
    cout << "19. Determine if a given Binary Tree is Binary Search Tree" << endl;
    cout << "20. Determine if a given Binary Tree is a Full Binary Search Tree" << endl;
    cout << "0. Exit" << endl << endl;

    NODE *pRoot, *p;
    int *a, n, value, choice;

    cout << "Enter your choice: "; cin >> choice;

    switch (choice) {
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
            cout << "Pre-order Traversal: "; NLR(pRoot); cout << endl;
            break;
        case 4:
            cout << "In-order Traversal: "; LNR(pRoot); cout << endl;
            break;
        case 5:
            cout << "Post-order Traversal: "; LRN(pRoot); cout << endl;
            break;
        case 6:
            cout << "Level-order Traversal: "; LevelOrder(pRoot); cout << endl;
            break;
        case 7:
            cout << "Height of Binary Tree: " << Height(pRoot) << endl;
            break;
        case 8:
            cout << "Number of NODEs: " << countNode(pRoot) << endl;
            break;
        case 9:
            cout << "Total value of all NODEs: " << sumNode(pRoot) << endl;
            break;
        case 10:
            cout << "Enter value: "; cin >> value;
            p = Search(pRoot, value);
            if (p == NULL) cout << "NODE not found!" << endl;
            else cout << "NODE found!" << endl;
            break;
        case 11:
            cout << "Enter value: "; cin >> value;
            Remove(pRoot, value);
            cout << "NODE removed!" << endl;
            break;
        case 12:
            cout << "Enter number of elements: "; cin >> n;
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++) cin >> a[i];
            pRoot = createTree(a, n);
            cout << "Binary Search Tree created!" << endl;
            break;
        case 13:
            removeTree(pRoot);
            cout << "Binary Search Tree removed!" << endl;
            break;
        case 14:
            cout << "Enter value: "; cin >> value;
            cout << "Height of NODE: " << heightNode(pRoot, value) << endl;
            break;
        case 15:
            cout << "Enter value: "; cin >> value;
            cout << "Level of NODE: " << Level(pRoot, Search(pRoot, value)) << endl;
            break;
        case 16:
            cout << "Number of leaves: " << countLeaf(pRoot) << endl;
            break;
        case 17:
            cout << "Enter value: "; cin >> value;
            cout << "Number of NODEs: " << countLess(pRoot, value) << endl;
            break;
        case 18:
            cout << "Enter value: "; cin >> value;
            cout << "Number of NODEs: " << countGreater(pRoot, value) << endl;
            break;
        case 19:
            if (isBST(pRoot)) cout << "Binary Tree is Binary Search Tree!" << endl;
            else cout << "Binary Tree is not Binary Search Tree!" << endl;
            break;
        case 20:
            if (isFullBST(pRoot)) cout << "Binary Tree is Full Binary Search Tree!" << endl;
            else cout << "Binary Tree is not Full Binary Search Tree!" << endl;
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
    cout << endl;
}

int main() {
    while (true) {
        menu();
    }
    return 0;
}