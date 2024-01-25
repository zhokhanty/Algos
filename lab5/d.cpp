#include <bits/stdc++.h>

using namespace std;

int main(){
    
    priority_queue<long long, vector<long long>, greater<long long>> q;

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        q.push(d);
    }

    int cnt = 0;
    while(q.top() < m){
        if(q.size() == 1){
            cout << -1 << '\n';
            return 0;
        }
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        int mix = a + 2 * b;
        q.push(mix);
        cnt++;
    }

    cout << cnt;

    return 0;
}