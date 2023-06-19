#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

void insert(Node* &root, int data) {
    if (root == nullptr) {
        root = new Node(data);
    }
    else if (data <= root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

void inOrder(Node* node, vector<int>& nodes) {
    if (node == nullptr) return;
    inOrder(node->left, nodes);
    nodes.push_back(node->data);
    inOrder(node->right, nodes);
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }
    vector<int> nodes;
    inOrder(root, nodes);
    int sum = 0;
    for (int i = nodes.size() - 1; i >= 0; i--) {
        sum += nodes[i];
        nodes[i] = sum;
    }
    for (int i = nodes.size() - 1; i >= 0; i--) {
        cout << nodes[i] << " ";
    }
    return 0;
}