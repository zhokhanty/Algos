#include <bits/stdc++.h>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

struct BST {
private:

	void _inorder(Node* node) {
		if (!node) return;
		_inorder(node->left);
		cout << node->val << " ";
		_inorder(node->right);
	}

	void _preorder(Node* node) {
		if (!node) return;
		cout << node->val << " ";
		_preorder(node->left);
		_preorder(node->right);
	}

	void _postorder(Node* node) {
		if (!node) return;
		_postorder(node->left);
		_postorder(node->right);
		cout << node->val << " ";
	}

	Node* _insert(Node* cur, int val) {
		if (!cur) {
			return new Node(val);
		}
		if (val > cur->val) {
			cur->right = _insert(cur->right, val);
		} else if (val < cur->val) {
			cur->left = _insert(cur->left, val);
		}
		return cur;
	}

	int _rightmost(Node* cur) {
		if (!cur) return -1;
		if (!cur->right) return cur->val;
		return _rightmost(cur->right);
	}

	Node* _remove(Node* cur, int target) {
		if (!cur) return NULL;
		if (cur->val == target) {
			if (!cur->right && !cur->left) {
				delete cur;
				return NULL;
			} else if (cur->left && !cur->right) {
				Node* temp = cur->left;
				delete cur;
				return temp;
			} else if (cur->right && !cur->left) {
				Node* temp = cur->right;
				delete cur;
				return temp;
			} else if (cur->right && cur->left) {
				cur->val = _rightmost(cur->left);
				cur->left = _remove(cur->left, cur->val);
			}
		} else if (cur->val < target) {
			cur->right = _remove(cur->right, target);
			return cur;
		} else if (cur->val > target) {
			cur->left = _remove(cur->left, target);
			return cur;
		}
		return cur;
	}

	int _getHeight(Node* node) {
		if (!node) return 0;
		return _getHeight(node->left) + _getHeight(node->right) + 1;
	}

	Node* _search(Node* cur, int target) {
		if (!cur) return NULL;
		if (cur->val == target) return cur;
		if (cur->val > target) return _search(cur->left, target);
		return _search(cur->right, target);
	}

public:
	Node * root;
	BST() {
		this->root = NULL;
	}

	void inorder() {
		_inorder(root);
		cout << endl;
	}
	
	void preorder() {
		_preorder(root);
		cout << endl;
	}
	
	void postorder() {
		_postorder(root);
		cout << endl;
	}

	void insert(int val) {
		Node* newNode = _insert(root, val);
		if (!root) root = newNode;
	}

	void remove(int target) {
		_remove(root, target);
	}

	Node* search(int target) {
		return _search(root, target);
	}

	void getHeight() {
		cout << _getHeight(root) << endl;
	}
    
    Node * balanced_tree(vector<int> &v, int l, int r){
        if(l > r) return NULL;
        int m = l + (r - l) / 2;
        Node * root = new Node(v[m]);
        root -> left = balanced_tree(v, l, m - 1);
        root -> right = balanced_tree(v, m + 1, r);
        return root;
    }
};

int main(){
    BST bst;
    int n;
    cin >> n;
    int sz = pow(2, n) - 1;
    vector<int> v(sz);
    for(int i = 0; i < sz; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    bst.root = bst.balanced_tree(v, 0, sz - 1);
    bst.preorder();
}