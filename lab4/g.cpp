#include<bits/stdc++.h>

using namespace std;

struct Node {
	int value;
	Node* left, * right;
	Node(int value) {
		this->value = value;
		left = right = NULL;
	}
};

struct BST {
	Node* root;
	BST() {
		root = NULL;
	}

private:
	void inorder(Node* node) {
		if (!node) return;
		this->inorder(node->left);
		cout << node->value << " ";
		this->inorder(node->right);
	}
	void preorder(Node* node) {
		if (!node) return;
		cout << node->value << " ";
		this->preorder(node->left);
		this->preorder(node->right);
	}
	void postorder(Node* node) {
		if (!node) return;
		this->postorder(node->left);
		this->postorder(node->right);
		cout << node->value << " ";
	}

	Node* findBlankNode() {
		queue<Node*> q;
		q.push(this->root);
		while (q.front()->left && q.front()->right) {
			if (q.front()->left) q.push(q.front()->left);
			if (q.front()->right) q.push(q.front()->right);
			q.pop();
		}
		return q.front();
	}

    Node * push(Node * cur, int val){
        if(cur == NULL) return new Node(val);
        if(val < cur -> value) cur -> left = push(cur -> left, val);
        if(val > cur -> value) cur -> right = push(cur -> right, val);
        return cur;
    }

    Node * ascOrder(Node * cur){
        if(cur != NULL){
            ascOrder(cur -> left);
            cout << cur -> value << " ";
            ascOrder(cur -> right);
        }
    }
    Node * descOrder(Node * cur){
        if(cur != NULL){
            descOrder(cur -> right);
            cout << cur -> value << " ";
            descOrder(cur -> left);
        }
    }

    int noOgLevels(Node * cur){
        if(cur == NULL) return 0;
        return max(noOgLevels(cur -> left), noOgLevels(cur -> right)) + 1;
    }


public:
	void inorder() {
		this->inorder(this->root); // left - node - right -> sort
	}

	void preorder() {
		this->preorder(this->root); // node - left - right
	}

	void postorder() {
		this->postorder(this->root); // left - right - node
	}

    void ascOrder(){
        ascOrder(root);
    }

    void descOrder(){
        descOrder(root);
    }

    int noOgLevels(){
        return noOgLevels(root);
    }

	void insert(int value) {
		root = push(root, value);
	}

	void remove(int value) {
		queue<Node*> q;
		q.push(this->root);
		while (q.front()->left->value != value && q.front()->right->value != value) {
			if (q.front()->left) q.push(q.front()->left);
			if (q.front()->right) q.push(q.front()->right);
			q.pop();
		}
		Node* cur = q.front();
		if (cur->left->value == value)
			cur->left = NULL;
		else
			cur->right = NULL;
	}

	int getHeight(Node * cur, int &d){ 
		if (cur == NULL) return 0;
		int left = getHeight(cur -> left, d);
		int right = getHeight(cur -> right, d);
		d = max(d, right + left + 1);
		return max(left, right) + 1;
	}

	int findDiameter(){
		int d = 0;
		getHeight(root, d);
		return d;
	}
};

int main() {
	BST tree;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        tree.insert(x);
    }
	cout << tree.findDiameter();
}