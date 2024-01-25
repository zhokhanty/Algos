#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left, *right;
};

map<int, Node*> nodes;

Node* getNode(int data) {
    if(nodes[data] == NULL){
        Node* newnode = new Node();
        newnode->data = data;
        newnode->left = newnode->right = NULL;
        nodes[data] = newnode;
    }
    return nodes[data];
}

void insert(int x, int y, int z){
    Node* parentNode = getNode(x);
    Node* childNode = getNode(y);

    if(z == 0){
        parentNode->left = childNode;
    }
    else if(z == 1){
        parentNode->right = childNode;
    }
}

void getMaxWidth(Node* root, int &cnt){
    if(root == NULL) 
        return;
    
    if(root->left == NULL && root->right == NULL){
        cnt++;
    }

    getMaxWidth(root->left, cnt);
    getMaxWidth(root->right, cnt);
    
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        insert(x, y, z);
    }
    int cnt = 0;
    getMaxWidth(nodes[1], cnt);
    cout << cnt;

    return 0;
}
