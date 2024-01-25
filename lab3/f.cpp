#include <bits/stdc++.h>

using namespace std;

pair<int, long long> Fight(int arr[], int n, int x){
    sort(arr, arr + n);
    int l = 0;
    int r = n - 1;
    int cnt = 0;
    long long total = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        int midVal = arr[mid];
        if (midVal <= x) {
            cnt = mid + 1;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    for(int i = 0; i < cnt; i++){
        total += arr[i];
    }

    return make_pair(cnt, total);

}

int main(){

    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int q;
    cin >> q;
    while(q--){
        int power;
        cin >> power;
        pair<int, long long> result = Fight(a, n, power);
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}