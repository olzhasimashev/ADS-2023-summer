#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
    }
    else if (value < root->value) {
        root->left = insertNode(root->left, value);
    }
    else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

bool checkPath(Node* root, string path) {
    for (char dir : path) {
        if (root == NULL) {
            return false;
        }
        if (dir == 'L') {
            root = root->left;
        } else if (dir == 'R') {
            root = root->right;
        }
    }
    return (root != NULL);
}

int main() {
    int N, M;
    cin >> N >> M;

    Node* root = NULL;
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        root = insertNode(root, value);
    }

    for (int i = 0; i < M; ++i) {
        string path;
        cin >> path;
        if (checkPath(root, path)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}