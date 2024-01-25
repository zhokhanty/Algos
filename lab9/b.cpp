#include <bits/stdc++.h>
using namespace std;

void search(string& pat, string txt, int k){
    int cnt = 0;
	int M = pat.size();
	int N = txt.size();

	for(int i = 0; i <= N - M; i++){
		int j;
		for(j = 0; j < M; j++){
			if(txt[i + j] != pat[j]){
				break;
            }
        }
		if (j == M){
			cnt++;
        }
	}
    if(cnt >= k){
        cout << "YES";
    } else {
        cout << "NO";
    }
}

int main(){

	string pat;
    int k;
    cin >> pat >> k;

    string txt;
    cin >> txt;

	search(pat, txt, k);
	return 0;
}
