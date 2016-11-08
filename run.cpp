#include <iostream>
using namespace std;

#include "bst.h"

Node* root = new Node(5);

bool search(Node *root, int value);
Node *insert(Node *root, int val);
Node *deleteNode(Node *root, int val);
int main()
{
    // Node* result = NULL;
    // result = node->search(3);
    cout << search(root, 3) << endl;
    insert(root, 3);
    cout << search(root, 3) << endl;
    cout << search(root, 7) << endl;
    insert(root, 7);
    insert(root, 2);
    cout << search(root, 7) << endl;
    // node->insert(3);
    // node->insert(7);
    // node->insert(2);

    // delete node .....
    root = deleteNode(root, 7);
    cout << search(root, 7) << endl;
    root = deleteNode(root, 5);
    cout << root -> val << endl;

    return 0;
}

bool search(Node *root, int value) {
    if (!root) return false;
    if (root -> val == value) return true;
    if (root -> val < value) return search(root -> right, value);
    else return search(root -> left, value); 
}

Node *insertNode(Node *tree1, Node *tree2);
Node *insert(Node *root, int val) {
    Node *newNode = new Node(val);
    return insertNode(root, newNode);
}

Node *insertNode(Node *tree1, Node *tree2) {
    if (tree1 -> val < tree2 -> val) {
        if (tree1 -> right) insertNode(tree1 -> right, tree2);
        else tree1 -> right = tree2;
    } else {
        if (tree1 -> left) insertNode(tree1 -> left, tree2);
        else tree1 -> left = tree2;
    }

    return tree1;
}

Node *deleteNode(Node *root, int val) {
    if (!root) return NULL;
    if (root -> val == val) {
        if (root -> left && root -> right) return insertNode(root -> left, root -> right);
        if (root -> left) return root -> left;
        if (root -> right) return root -> right;
        return NULL;
    }

    if (root -> val < val) root -> right = deleteNode(root -> right, val);
    else root -> left = deleteNode(root -> left, val);
    return root;
}
