#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    string data;
    Node* next;
    Node* prev;
    Node(const string& d, Node* nxt = NULL, Node* prv = NULL) 
        : data(d), next(nxt), prev(prv) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    ~DoublyLinkedList() {
        clear(false);
    }

    void add_front(const string& d){
        Node* newnode = new Node(d, head, NULL);
        if(head != NULL){
            head->prev = newnode;
        }
        head = newnode;
        if(tail == NULL){
            tail = newnode;
        }
        cout << "ok\n";
    }

    void add_back(const string& d){
        Node* newnode = new Node(d, NULL, tail);
        if(tail != NULL){
            tail->next = newnode;
        }
        tail = newnode;
        if(head == NULL){
            head = newnode;
        }
        cout << "ok\n";
    }

    void erase_front(){
        if(head == NULL){
            cout << "error" << endl;
            return;
        }
        Node* curr = head;
        cout << curr->data << "\n";
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
        delete curr;
    }

    void erase_back(){
        if(tail == NULL){
            cout << "error" << endl;
            return;
        }
        Node* curr = tail;
        cout << curr->data << "\n";
        tail = tail->prev;
        if(tail != NULL)
            tail->next = NULL;
        else   
            head = NULL;
        delete curr;
    }

    void front(){
        if(head == NULL){
            cout << "error\n";
            return;
        }
        cout << head->data << "\n";
    }

    void back(){
        if(tail == NULL){
            cout << "error\n";
            return;
        }
        cout << tail->data << "\n";
    }

    void clear(bool printOk = true){
        while(head != NULL){
            Node* curr = head;
            head = head->next;
            delete curr;
        }
        tail = NULL;
        if(printOk){
            cout << "ok\n";
        }
    }
    
};

int main(){
    DoublyLinkedList d;
    string c, b;
    while(cin >> c){
        if(c == "add_front"){
            cin >> b;
            d.add_front(b);
        } else if(c == "add_back"){
            cin >> b;
            d.add_back(b);
        } else if(c == "erase_front"){
            d.erase_front();
        } else if(c == "erase_back"){
            d.erase_back();
        } else if(c == "front"){
            d.front();
        } else if(c == "back"){
            d.back();
        } else if(c == "clear"){
            d.clear();
        } else if(c == "exit"){
            cout << "goodbye\n";
            break;
        }
    }

    return 0;
}