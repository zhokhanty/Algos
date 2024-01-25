#include <bits/stdc++.h>

using namespace std;

int binarysearch(int arr[], int l, int r, int x){
	while(l <= r){
		int m = l + (r - l) / 2;

		if(arr[m] == x){
			return m;
		} else if(arr[m] < x){
			l = m + 1;
		} else {
			r = m - 1;
		}
	}

	return -1;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int k;
	cin >> k;
	int result = binarysearch(a, 0, n - 1, k);
	(result == -1)
		? cout << "No"
		: cout << "Yes";

	return 0;
}