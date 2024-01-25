#include <iostream>

using namespace std;

int main(){
	
	int n;
	cin >> n;
	int cnt = 1;
	for(int i = 2; i <= n; i++){
		if(n % i == 0){
			cnt++;
		}
	}
	
	if(cnt == 2){
		cout << "YES";
	} else {
		cout << "NO";
	}
	
	return 0;
}
