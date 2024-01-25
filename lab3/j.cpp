#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> v, int h, int m){
    int sum = 0;
    for(int i = 0; i < v.size(); i++){
        sum += (v[i] + m -1) / m;
    }
    return sum <= h;
}

int main(){
    int n, x, h; 
    cin >> n >> h;
    vector <int> v;

    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    int l = 1;
    int r = *max_element(v.begin(), v.end()) + 1;
    while(r - l > 1){
        int mid = l + (r - l) / 2;
        if(check(v, h, mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r;
}