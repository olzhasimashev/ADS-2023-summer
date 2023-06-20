#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* node, int data) {
    if(node == NULL) return newNode(data);
    if(data < node->data) node->left = insert(node->left, data);
    else if(data > node->data) node->right = insert(node->right, data);
    return node;
}

int diameter(Node* tree);
int _diameter(Node* tree, int& height);

int main() {
    int n;
    cin >> n;
    Node *root = NULL;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(root == NULL) root = insert(root, x);
        else insert(root, x);
    }
    cout << diameter(root);
    return 0;
}

int diameter(Node* tree) {
    int height = 0;
    return _diameter(tree, height);
}

int _diameter(Node* tree, int& height) {
    int lh = 0, rh = 0;
    int ldiameter = 0, rdiameter = 0;

    if(tree == NULL) {
        height = 0;
        return 0;
    }

    ldiameter = _diameter(tree->left, lh);
    rdiameter = _diameter(tree->right, rh);

    height = max(lh, rh) + 1;

    return max(lh + rh + 1, max(ldiameter, rdiameter));
}