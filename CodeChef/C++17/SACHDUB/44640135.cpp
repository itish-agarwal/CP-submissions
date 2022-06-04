#include <bits/stdc++.h>

using namespace std;

bool prime(int n) {
	for(int i = 2; i * i <= n; ++i) {
		if(n%i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto& it : a) {
			cin >> it;
		}
		int s = 0;
		for(int i = 0; i < n/2; ++i) {
			s += abs(a[i] - a[n-1-i]);
		}
		if(s == 0 || s == 1) {
			puts("KITKAT");
		} else {
			if(prime(s)) {
				puts("KIT");
			} else {
				puts("KAT");
			}
		}
	}
}