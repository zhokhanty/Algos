#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e5 + 5;
ll a[MAXN], prefix[MAXN];
int n, k;

bool isPossible(ll mid) {
    int blocks = 1, i = 1;
    ll curr_sum = 0;
    while(i <= n) {
        if((curr_sum + a[i]) > mid) {
            curr_sum = 0;
            blocks++;
        }
        curr_sum += a[i];
        i++;
    }
    if(blocks <= k)
        return true;
    else
        return false;
}

int main() {
    cin >> n >> k;
    ll sum = 0, maxn = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        maxn = max(maxn, a[i]);
    }

    ll low = maxn, high = sum;

    while(low < high){
        ll mid = (low + high) / 2;
        if (isPossible(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low;
    return 0;
}
