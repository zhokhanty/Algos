#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<int> b(5);
    vector<int> n(5);
    for(int i = 0; i < 5; i++){
    	cin >> b[i];
	}
	
	for(int i = 0; i < 5; i++){
    	cin >> n[i];
	}
	
	int moves = 0;
	
	while(!b.empty() && !n.empty()){
		int b1 = b.front();
		int n2 = n.front();
		
		b.erase(b.begin());
		n.erase(n.begin());
		
		if(b1 == 9 && n2 == 0){
			n.push_back(b1);
			n.push_back(n2);
		} else if(b1 == 0 && n2 == 9){
			b.push_back(b1);
			b.push_back(n2);
		} else if(b1 < n2){
			n.push_back(b1);
			n.push_back(n2);
		} else if(b1 > n2){
			b.push_back(b1);
			b.push_back(n2);
		}
		
		moves++;
	}
	
	if(moves >= 1000000){
		cout << "blin nichya";
	}
	
	if(n.empty()){
		cout << "Boris " << moves << endl;
	} else if(b.empty()){
		cout << "Nursik " << moves << endl;
	}
    
    return 0;
}

