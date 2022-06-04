#include <bits/stdc++.h>

using namespace std;
#define int long long 

bool prime(int s) {
	if(s == 1) return false;
	if(s == 2) return true;
	for(int i = 2; i*i <= s; ++i) {
		if(s%i == 0) {
			return false;
		}
	}
	return true;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		int a[4], b[4];
		for(int i = 0; i < 4; ++i) cin >> a[i];
		for(int i = 0; i < 4; ++i) cin >> b[i];

		int s = 0;
		for(int i = 0; i < 4; ++i) {
			int x = min(a[i], b[i]), y = max(a[i], b[i]);
			s += y % x;
		}
		if(prime(s) || s==0) {
			cout << "Access Denied\n";
		} else {
			cout << "Access Granted\n";
		}
	}
}