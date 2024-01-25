# include <iostream>
# include <algorithm>
# include <cassert>
 
using namespace std;
 
struct Node {
    int val;
    Node *next;
 
    Node() {
        val = 0;
        next = NULL;
    }
};
 
int findMaxSum(int n, Node *head) {
	int max1 = head->val;
    int max2 = head->val;     
    Node* current = head->next;

    while (current) {
        max1 = max(current->val, max1 + current->val);

        // Update the maximum sum found so far
        max2 = max(max2, max1);

        // Move to the next node
        current = current->next;
    }

    return max2;
}
 
int main() {
    int n;
    cin >> n;
 
    Node *head, *tail;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        Node *cur = new Node();
        cur -> val = x;
 
        if (i == 1) {
            head = tail = cur;
        } else {
            tail -> next = cur;
            tail = cur;
        }
    }
 
    cout << findMaxSum(n, head) << "\n";
    return 0;
}