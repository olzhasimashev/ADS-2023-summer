#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int count;
    Node* left;
    Node* right;

    Node(int key) : key(key), count(1), left(nullptr), right(nullptr) {}
};

Node* insert(Node* node, int key) {
    if (node == nullptr)
        return new Node(key);

    if (key == node->key)
        node->count++;
    else if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;

    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->count > 1) {
            root->count--;
            return root;
        }
        if (root->left == nullptr) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == nullptr) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->count = temp->count;
        if (temp->count > 1)
            temp->count--;
        else
            root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int getCount(Node* root, int key) {
    if (root == nullptr) return 0;
    if (root->key == key) return root->count;
    if (root->key < key) return getCount(root->right, key);
    return getCount(root->left, key);
}

int main() {
    int Q;
    cin >> Q;
    Node* root = nullptr;
    while (Q--) {
        string query;
        int key;
        cin >> query >> key;
        if (query == "insert")
            root = insert(root, key);
        else if (query == "delete")
            root = deleteNode(root, key);
        else if (query == "cnt")
            cout << getCount(root, key) << "\n";
    }
    return 0;
}