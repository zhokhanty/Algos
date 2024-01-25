#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    priority_queue<int> q;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.push(x);
    }

    while(q.size() > 1){
        long long int a = q.top();
        q.pop();
        long long int b = q.top();
        q.pop();
        if(a != b){
            q.push(abs(b - a));
        }
    }
    
    if(q.empty()){
        cout << 0;
    } else {
        cout << q.top();
    }
}