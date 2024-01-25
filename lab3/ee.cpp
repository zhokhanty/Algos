#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> v;
    int x1, y1, x2, y2;
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back(max(x2, y2));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < k; i++){
        cout << v[k - 1] << " ";
        break;
    }
    

    return 0;
}


/*
10 7
5 1 7 8
1 3 5 4
5 8 8 10
7 1 8 5
9 1 10 5
4 4 7 5
1 6 7 7
5 7 9 10
4 8 5 9
4 2 5 3
*/