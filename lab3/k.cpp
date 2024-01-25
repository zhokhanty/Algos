#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> arr(n);

  for(int i = 0; i < n; ++i)
    cin >> arr[i];

  int sum = 0, idx = 0, result = INT_MAX;

  for (int i = 0; i < n; ++i) {
    sum += arr[i];

    while (sum >= k) {
      result = min(result, i - idx + 1);
      sum -= arr[idx++];
    }
  }

  cout << result;
  return 0;
}
