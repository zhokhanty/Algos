#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n; cin >> n;
	string s; cin >> s;
	deque<int> d1, d2;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'K') {
			d1.push_back(i);
		} else {
			d2.push_back(i);
		}
	}
	while(!d1.empty() && !d2.empty()){
		int a = d1.front();
		int b = d2.front();
		d1.pop_front();
		d2.pop_front();
		if(a > b){
			d2.push_back(a + n);
		} else {
			d1.push_back(b + n);
		}
	}
	if(d1.empty()){
		cout << "SAKAYANAGI";
	} else {
		cout << "KATSURAGI";
	}
	
	
	return 0;
}
