#include <bits/stdc++.h>
using namespace std;

int binary(int l1, int r1, int l2, int r2, int x){
    int cnt = 0;
    if((l1 <= x && x <= r1) || (l2 <= x && x <= r2)){
        cnt++;
    }
    return cnt;
}

int main(){
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < q; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int sum = 0;
        
        for(int j = 0; j < n; j++){
            sum += binary(l1, r1, l2, r2, a[j]);
        }
        cout << sum << endl;
    }
    
    return 0;
}