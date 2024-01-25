#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL) {}
    Node(int x): val(x), next(NULL) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    node->next = NULL;

    if (p == 0) {
        node->next = head;
        return node;
    }

    Node* curr = head;
    for (int i = 0; i < p - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    node->next = curr->next;
    curr->next = node;

    return head;
}
 
Node* remove(Node* head, int p){
    if(head == NULL){
        return NULL;
    }
    if (p == 0) {
        Node* tempNode = head->next;
        delete head;
        return tempNode;
    }
    Node* currentNode = head;
    int pos = 0;
    while (currentNode->next != NULL && pos < p - 1) {
        currentNode = currentNode->next;
        pos++;
    }
    if (currentNode->next == NULL) {
        return head;
    }
    Node* tempNode = currentNode->next;
    currentNode->next = tempNode->next;
    delete tempNode;
    
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    if (p1 == p2) return head; 

    Node *prev = NULL, *current = head;
    Node *node1 = NULL, *prev1 = NULL;
    int count = 0;

    while (current != NULL) {
        if (count == p1) {
            node1 = current;
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            current = current->next;
            node1->next = NULL;
        } else {
            prev = current;
            current = current->next;
        }
        count++;
    }
    
    if (node1 == NULL) return head;

    current = head;
    prev = NULL;
    count = 0;
    while (current != NULL && count != p2) {
        prev = current;
        current = current->next;
        count++;
    }

    if (prev != NULL) { 
        prev->next = node1;
    } else { 
        head = node1;
    }
    node1->next = current;
    
    return head;
}

 
Node* reverse(Node* head){
    Node* prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
 
void print(Node* head){
    while (head != NULL) {
        if(head != NULL) {
            cout << head->val << ' ';
            head = head->next;
        } else {
            cout << -1;
        }
    }
    
    cout << "\n";
}
 
Node* cyclic_right(Node* head, int x){
    if (!head) return head;

    Node* tail = head;
    int len = 1;

    while (tail->next) {
        tail = tail->next;
        len++;
    }

    int k = x % len;
    tail->next = head;

    for (int i = 0; i < len - k; i++) {
        tail = tail->next;
    }

    head = tail->next;
    tail->next = NULL;

    return head;
}

Node* cyclic_left(Node* head, int x){
    return cyclic_right(head, -x);
}
 
int main(){
    Node* head = NULL;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}