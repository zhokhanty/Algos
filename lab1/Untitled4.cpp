#include <iostream>
#include <string>
#include <deque>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){
	
	string s;
	cin >> s;
	deque<char> d;
	d.push_front(s[0]);
	
	for(int i = 1; i < s.size(); ++i){
		if(s[i] != d.front()){
			d.push_front(s[i]);
		} else if(s[i] == d.front()){
			d.pop_front();
		}
	}
	
	if(d.empty()){
		cout << "YES";
	} else {
		cout << "NO";
	}
	
	return 0;
	
}
