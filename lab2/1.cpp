#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int _data) : data(_data), next(NULL) {}
};

int main() {
    int n, k;
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cin >> k;

    int min_distance;
    int min_offset = 0;
    Node* current = head;

    for (int i = 0; i < n; ++i) {
        int distance = abs(current->data - k);
        if (distance < min_distance) {
            min_distance = distance;
            min_offset = i;
        }

        current = current->next;
    }

    cout << min_offset << endl;

    return 0;
}