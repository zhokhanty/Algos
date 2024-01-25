#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void solve(string s){
    priority_queue<char, vector<char>, greater<char>> vowels;
    priority_queue<char, vector<char>, greater<char>> consonants;

    for (int i=0; i<s.length(); i++){
        if (isVowel(s[i]))
            vowels.push(s[i]);
        else
            consonants.push(s[i]);
    }

    string res = "";
    while (!vowels.empty()) {
        res += vowels.top();
        vowels.pop();
    }

    while (!consonants.empty()) {
        res += consonants.top();
        consonants.pop();
    }

    cout << res << "\n";
}

int main(){

    int n;
    cin >> n;

    string s;
    cin >> s;

    solve(s);
    return 0;
}
