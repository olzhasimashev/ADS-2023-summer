#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return(newNode(data));
    } else {
        if (data <= node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }
}

pair<int, int> diameter(Node* root) {
    if (root == NULL) {
        return {0, 0};
    }

    pair<int, int> l = diameter(root->left);
    pair<int, int> r = diameter(root->right);

    int height = max(l.first, r.first) + 1;
    int diameter = max({l.first + r.first + 1, l.second, r.second});

    return {height, diameter};
}

int main() {
    int N;
    cin >> N;

    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    pair<int, int> res = diameter(root);
    cout << res.second << endl;

    return 0;
}