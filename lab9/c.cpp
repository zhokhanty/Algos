#include <bits/stdc++.h>
using namespace std;

void cycle(string & shifted, string orig){
    
    int n1 = orig.size();
    int n2 = shifted.size();

    if(n1 != n2){
        cout << -1;
        return;
    }

    string doubleOrig = orig + orig;
    int n = doubleOrig.size();

    for(int i = 0; i <= n - n2; i++){
		int j;
		for(j = 0; j < n2; j++){
			if(doubleOrig[i + j] != shifted[j]){
				break;
            }
        }
		if (j == n2){
			cout << n2 - i << endl;
            return;
        } 
	}

    cout << -1 << endl;

}

int main(){

    string orig;
    cin >> orig;

    string shifted;
    cin >> shifted;

    cycle(shifted, orig);
	
	return 0;
}
