#include <bits/stdc++.h>
using namespace std;
const int d = 26;
vector<int> search(string s, string pattern, int q = 1e9 + 7) {
 int p = 0, t = 0, h = 1, i, j;
 vector<int> ans;
 for (i = 0; i < pattern.size() - 1; i++)
  h = (h * d) % q;

 for (i = 0; i < pattern.size(); i++) {
  p = (d * p + pattern[i]) % q;
  t = (d * t + s[i]) % q;
 }

 for (i = 0; i <= s.size() - pattern.size(); i++) {
  if (p == t) {
   for (j = 0; j < pattern.size(); j++) {
    if (s[i + j] != pattern[j]) break;
   }
   if (j == pattern.size()) {
    ans.push_back(i);
   }
  }

  if (i < s.size() - pattern.size()) {
   t = (d * (t - s[i] * h) + s[i + pattern.size()]) % q;
   if (t < 0) t += q;
  }
 }
 return ans;
}
int main() {
    string s; cin >> s;
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int x , y;
        cin >> x >> y;
        vector<int> v = search(s, s.substr(x - 1, y - x + 1));
        if(v.size() == 0) cout<<1<<endl;
        else{
        cout<<v.size()<<endl;
        }
    }
}