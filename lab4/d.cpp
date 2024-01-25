#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left, *right;
};

vector<int> sum;

Node* insert(Node* root, int data, int level){
    if(root == NULL){
        Node* newnode = new Node;
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        if(level >= sum.size()){
            sum.push_back(0);
        }
        sum[level] += data;
        return newnode;
    }

    if(data < root->data){
        root->left = insert(root->left, data, level + 1);
    } else {
        root->right = insert(root->right, data, level + 1);
    }

    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

int findLevel(Node* root){
    if(root == NULL){
        return 0;
    }

    int l = findLevel(root->left);
    int r = findLevel(root->right);

    return max(l, r) + 1;
}


int main(){

    Node* root = NULL;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        root = insert(root, a[i], 0);
    }
    cout << findLevel(root) << endl;

    for(int i = 0; i < sum.size(); i++){
        cout << sum[i] << " "; 
    }

    return 0;
}