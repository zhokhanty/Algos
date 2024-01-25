#include <bits/stdc++.h>

using namespace std;

pair<int, int> Farmer(vector<vector<int>> v, int n){
    int max = 0;
    for(int i = 0; i < n; i++){
        int l = 0;
        int r = 3;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(w[i][mid] < max){
                max = w[i][mid];
                return max;
            }
        }
    }
}

int main(){

    int n, k;
    cin >> n >> k;
    int x1, y1, x2, y2;
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
    }
    const int max = 2e5 + 5;
    int result = Farmer()

    return 0;
}