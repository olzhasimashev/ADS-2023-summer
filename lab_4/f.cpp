#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data): data(data), left(nullptr), right(nullptr) {}
};

Node* insert(Node* node, int data) {
    if(node == nullptr) return new Node(data);

    if(data < node->data) {
        node->left = insert(node->left, data);
    } else if(data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

int countTriangles(Node* node) {
    if(node == nullptr) return 0;

    int triangles = countTriangles(node->left) + countTriangles(node->right);

    if(node->left != nullptr && node->right != nullptr) triangles++;

    return triangles;
}

int main() {
    int N;
    cin >> N;

    Node* root = nullptr;

    for(int i = 0; i < N; i++) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    cout << countTriangles(root) << endl;
    
    return 0;
}