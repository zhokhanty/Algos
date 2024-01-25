#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int q, k;
    cin >> q >> k;
    multiset<ll> s;
    ll sum = 0;
    for(int i = 0; i < q; ++i) {
        string command;
        cin >> command;
        if(command == "insert") {
            ll x;
            cin >> x;
            if(s.size() < k) {
                s.insert(x);
                sum += x;
            }
            else if(x > *s.begin()) {
                sum -= *s.begin();
                s.erase(s.begin());
                sum += x;
                s.insert(x);
            }
        }
        else if(command == "print") {
            cout << sum << "\n";
        }
    }
    
    return 0;
}