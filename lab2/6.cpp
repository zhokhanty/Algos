#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertNode(Node* head, int data, int position) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    for (int i = 0; i < position - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

Node* buildLinkedList(int n) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printLinkedList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = buildLinkedList(n);

    int data, position;
    cin >> data >> position;

    head = insertNode(head, data, position);

    printLinkedList(head);

    return 0;
}