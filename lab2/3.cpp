#include <bits/stdc++.h>

using namespace std;

struct Node {
	int num;
	Node* next;
	Node(int _num) : num(_num), next(NULL) {}
};

Node* show(Node* head){
    
    Node* prev = head;
    Node* curr = head->next;

    while (curr != NULL && prev != NULL) {
        prev->next = curr->next;
        delete curr;
        curr = prev->next;

        if (curr != NULL) {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

int main(){
	int n;
	cin >> n;
	Node* head = NULL;
	Node* tail = NULL;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		Node* node = new Node(num);
		if(head == NULL){
			head = tail = node;
		} else {
            tail->next = node;
            tail = node;
        }
	}

	head = show(head);
	Node* curr = head;
	while(curr){
		cout << curr->num << " ";
		curr = curr->next;
	}

	return 0;
}