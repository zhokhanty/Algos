#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	
	vector<int> v;
	int n;
	cin >> n;
	
	if(n < 1){
		cout << "Invalid input";
		return 0;
	}
	
	for(int i = 2; v.size() < 99999; i++){
		bool is_prime = true;
		for(int j = 2; j <= sqrt(i); j++){ 	
			if(i % j == 0){
				is_prime = false;
				break;
			}
		}
		if(is_prime){
			v.push_back(i);
		}
	}
	
	vector<int> w;
	for(int i = 2; w.size() <= n; i++){
		bool is_superprime = true;
		for(int j = 2; j <= sqrt(i); j++){
			if(i % j == 0){
				is_superprime = false;
				break;
			}
		}
		if(is_superprime){
			w.push_back(v[i - 1]);
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << w[n - 1];
		break;
	}
	
	return 0;
}
