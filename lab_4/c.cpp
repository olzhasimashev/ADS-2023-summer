#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }
    Node* current_node = root;
    while (true) {
        if (current_node->val < key) {
            if (current_node->right == NULL) {
                current_node->right = new Node(key);
                break;
            }
            else {
                current_node = current_node->right;
            }
        }
        else {
            if (current_node->left == NULL) {
                current_node->left = new Node(key);
                break;
            }
            else {
                current_node = current_node->left;
            }
        }
    }
    return root;
}

void preorder(Node* root) {
    if (root) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void findAndPrint(Node* root, int k) {
    if (root) {
        if (root->val == k) {
            preorder(root);
        }
        else if (root->val < k) {
            findAndPrint(root->right, k);
        }
        else {
            findAndPrint(root->left, k);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> gifts(n);
    for (int i = 0; i < n; i++) {
        cin >> gifts[i];
    }
    int k;
    cin >> k;
    Node* root = NULL;
    for (auto gift : gifts) {
        root = insert(root, gift);
    }
    findAndPrint(root, k);
    return 0;
}