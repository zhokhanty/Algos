#include <bits/stdc++.h>

using namespace std;


int main() {

    int n, sum = 0;
    cin >> n;
    int a[n];
    int mini = 1e6;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mini = min(mini, a[i]);
        sum += a[i];
    }
    sum -= mini;
    cout << (n - 1) * mini + sum;

    return 0;
}
