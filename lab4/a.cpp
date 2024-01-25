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

string print(Node* root, string path){
    for(int i = 0; i < path.length(); i++){
        if(root == NULL){
            return "NO";
        }
        if(path[i] == 'L'){
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return (root != NULL) ? "YES" : "NO";
}

int main(){

    struct Node *root = NULL;
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int data;
        cin >> data;
        if(i == 0){
            root = getNode(data);
        } else {
            insertNode(root, data);
        }
    }
    string path;
    for(int i = 0; i < m; i++){
        cin >> path;
        cout << print(root, path) << endl;
    }

    return 0;
}