#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int key) {
    if(root == NULL) {
        return new Node(key);
    }
    if(root->val > key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

vector<int> levelSum(Node* root) {
    queue<Node*> q;
    q.push(root);
    vector<int> sums;
    while(!q.empty()) {
        int n = q.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            Node* temp = q.front();
            q.pop();
            sum += temp->val;
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
        sums.push_back(sum);
    }
    return sums;
}

int main() {
    int n;
    cin >> n;
    vector<int> permutation(n);
    for(int i = 0; i < n; i++) {
        cin >> permutation[i];
    }
    Node* root = NULL;
    for(auto p : permutation) {
        root = insert(root, p);
    }
    vector<int> sums = levelSum(root);
    cout << sums.size() << endl;
    for(auto sum : sums) {
        cout << sum << " ";
    }
    return 0;
}