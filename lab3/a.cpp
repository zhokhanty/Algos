#include <bits/stdc++.h>

using namespace std;

pair<int, int> Snake(vector<vector<int>> &w, int n, int m, int x) {
    for(int i = 0; i < n; i++){
        int l = 0;
        int r = m - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(w[i][mid] == x)
                return {i, mid};
            
            if(i % 2 == 0){
                if(w[i][mid] < x)
                    r = mid - 1;
                else 
                    l = mid + 1;
            } else {
                if(w[i][mid] < x)
                    l = mid + 1;
                else 
                    r = mid - 1;
            }
        }
    }

    return {-1, -1};
}

int main(){
    
    int t;
    cin >> t;
    vector<int> v(t);
    for(int i = 0; i < t; i++){
        cin >> v[i];
    }
    int n, m;
    cin >> n >> m;
    vector<vector<int>> w(n, vector<int>(m));
    for(int j = 0; j < n; j++){
        for(int k = 0; k < m; k++){
            cin >> w[j][k];
        }
    }
    pair<int, int> result;
    for(int i = 0; i < t; i++){
        result = Snake(w, n, m, v[i]);
        if(result.first == -1 && result.second == -1){
            cout << -1 << endl;
        } else {
            cout << result.first << " " << result.second << endl;
        }
    }

    return 0;
}