#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> ages(N);
    for (int i = 0; i < N; i++) {
        cin >> ages[i];
    }
    
    stack<int> younger;
    for (int i = 0; i < N; i++) {
        while (!younger.empty() && younger.top() > ages[i]) {
            younger.pop();
        }
        
        if (younger.empty()) {
            cout << -1 << " ";
        } else {
            cout << younger.top() << " ";
        }
        
        younger.push(ages[i]);
    }
    
    return 0;
}

