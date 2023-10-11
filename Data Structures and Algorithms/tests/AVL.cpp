#include <iostream>
#define COUNT 10

using namespace std;


struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
};

int getHeight(Node *root) {
    if (root == NULL)
        return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node *root) {
    Node *n = root->left;

    root->left = n->right;
    n->right = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));

    return n;
}

Node *leftRotate(Node *root) {
    Node *n = root->right;

    root->right = n->left;
    n->left = root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));

    return n;
}

Node* Insert(Node* root, int key) {
    if (root == NULL) return newNode(key);

    // Insertion
    if (key > root->key)
        root->right = Insert(root->right, key);
    else if (key < root->key)
        root->left = Insert(root->left, key);
    else
        return root;

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get balance factor
    int balance = getHeight(root->left) - getHeight(root->right);

    // Case
    if (balance > 1) {
        // Left Left
        if(key < root->left->key) return rightRotate(root);
        // Left Right
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balance < -1) {
        // Right Right
        if(key > root->right->key) return leftRotate(root);
        // Right Left
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

Node* Detete(Node* root, int key) {
    if (root == NULL) return root;

    // Delete
    if (key > root->key)
        root->right = Detete(root->right, key);
    else if (key < root->key)
        root->left = Detete(root->left, key);
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->key = temp->key;
            root->right = Detete(root->right, temp->key);
        }
    }

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get balance factor
    int balance = getHeight(root->left) - getHeight(root->right);

    // Case
    if (balance > 1) {
        // Left Left
        if(key < root->left->key) return rightRotate(root);
        // Left Right
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balance < -1) {
        // Right Right
        if(key > root->right->key) return leftRotate(root);
        // Right Left
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}