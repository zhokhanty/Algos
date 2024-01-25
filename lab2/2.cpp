#include <iostream>
#include <string>

using namespace std;

struct Node {
	string s;
	Node* next;
	Node(const string& s) : s(s), next(NULL) {}
};

Node* show(Node* head, int k){
	Node* value = head;
	for(int i = 0; i < k - 1; i++){
		value = value->next;
	}
	Node* new_head = value->next;
    value->next = NULL;

    Node* tail = new_head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = head;

    return new_head;
}

int main(){
	int n, k;
	cin >> n >> k;
	Node* head = NULL;
    Node* tail = NULL;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		Node* node = new Node(s);
		if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
	}
	head = show(head, k);

    Node* curr = head;
    while (curr) {
        cout << curr->s << " ";
        curr = curr->next;
    }

	return 0;
}