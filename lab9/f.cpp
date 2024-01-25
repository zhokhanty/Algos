#include <bits/stdc++.h>
using namespace std;

void search(string& pat, string txt){
	int M = pat.size();
	int N = txt.size();
    vector<int> v;
	for(int i = 0; i <= N - M; i++){
		int j;
		for(j = 0; j < M; j++){
			if(txt[i + j] != pat[j]){
				break;
            }
        }
		if (j == M){
			v.push_back(i + 1);
        }
	}

    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    
}

int main(){

    string txt;
    cin >> txt;
	string pat;
    cin >> pat;

	search(pat, txt);
	return 0;
}
