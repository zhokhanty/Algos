#include <bits/stdc++.h>

using namespace std;

void operation(int a, int b){
    list<int> l;
    while(a != b){
        a *= 2;
        l.push_back(a);
        if(a == b){
            break;
        }
        a--;
        l.push_back(a);
    }
    cout << l.size() << endl;
    for(auto it = l.begin(); it != l.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){

    int a, b;
    cin >> a >> b;
    
    operation(a, b);

    return 0;
}