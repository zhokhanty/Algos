#include<iostream>
#include<unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    unordered_set<int> set;
    
    // Read the numbers from the first person and add them to the set
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        set.insert(num);
    }
    
    // Check the numbers from the second person and print the common ones
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if (set.find(num) != set.end()) {
            cout << num << " ";
            set.erase(num); // Remove the common number from the set to avoid duplicates
        }
    }
    
    return 0;
}
