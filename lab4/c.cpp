#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* left, *right;
};

Node* getNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data){
    if(root == NULL){
        return getNode(data);
    }
    if(data < root->data){
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
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

void findSubtree(Node* root, int k){
    if(root == NULL){
        return;
    }

    if(root->data == k){
        inorder(root);
        return;
    }

    if(k < root->data){
        findSubtree(root->left, k);
    } else {
        findSubtree(root->right, k);
    }
}

int main(){

    struct Node *root = NULL;
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int data;
        cin >> data;
        if(i == 0){
            root = getNode(data);
        } else {
            insertNode(root, data);
        }
    }

    int k;
    cin >> k;
    findSubtree(root, k);

    return 0;
}