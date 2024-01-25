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

int getMaxWidth(Node* root){
    if(root == NULL) 
        return 0;
    
    int maxWidth = 0;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int count = q.size();
        maxWidth = max(maxWidth, count);
        
        while(count--){
            Node* temp = q.front();
            q.pop();
            
            if (temp->left != NULL)
                q.push(temp->left);
            
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }

    return maxWidth;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        insert(x, y, z);
    }

    cout << getMaxWidth(nodes[1]);

    return 0;
}
