#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    Node() : left(NULL), right(NULL) {}
};

int main() {
    int n;
    cin >> n;

    vector<Node*> nodes(n + 1);
    for(int i = 1; i <= n; ++i) {
        nodes[i] = new Node();
    }
    
    for(int i = 1; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if(z == 0) {
            nodes[x]->left = nodes[y];
        } else {
            nodes[x]->right = nodes[y];
        }
    }
    
    queue<Node*> q;
    q.push(nodes[1]);
    int maxWidth = 0;
    
    while(!q.empty()) {
        int width = q.size();
        maxWidth = max(maxWidth, width);
        for(int i = 0; i < width; ++i) {
            Node* temp = q.front();
            q.pop();
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }

    cout << maxWidth << endl;
    return 0;
}