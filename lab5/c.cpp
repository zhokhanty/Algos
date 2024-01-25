#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){

    ll n, x;
    cin >> n >> x;

    priority_queue<ll> p;
    int a[n];
    for(int i = 0; i < n; i++){
        ll data;
        cin >> data;
        p.push(data);
    }
    
    ll money = 0;
    for(int i = 0; i < x; i++){
        ll a = p.top();
        money += a;

        p.pop();
        if(--a > 0){
            p.push(a);
        }
    }
    cout << money;

    return 0;
}