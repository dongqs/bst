#include <iostream>

struct Node
{
    Node(int val);
    Node(int val, Node* left, Node* right);

    int val;
    Node* left;
    Node* right;
};
