#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left, *right;
};

vector<int> v;
int cnt = 0;

Node* insert(Node* root, int data, int level){
    if(root == NULL){
        Node* newnode = new Node();
        newnode->data = data;
        newnode->left = newnode->right = NULL;
        if(level >= v.size()){
            v.push_back(0);
        }
        v[level]++;
        return newnode;
    }

    if(data < root->data){
        root->left = insert(root->left, data, level + 1);
    } else {
        root->right = insert(root->right, data, level + 1);
    }
    return root;
}

void getSize(Node *root, int &cnt){
    if(root==NULL){
        return;
    }
    if(root->left && root->right){
        cnt++;
    }
    getSize(root->left, cnt);
    getSize(root->right, cnt);
}


int main(){

    int n;
    cin >> n;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int data;
        cin >> data;
        root = insert(root, data, 0);
    }
    int cnt = 0;
    getSize(root, cnt);

    cout << cnt;
    
    return 0;
}