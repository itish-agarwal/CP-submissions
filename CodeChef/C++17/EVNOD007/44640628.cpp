#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		int n, a, odd = 0, even = 0;
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> a;
			if(a % 2) odd++;
			else even++;
		}
		int o = (n % 2 ? n/2 + 1 : n/2);
		int e = n - o;
		if(odd==o && even==e) {
			cout << "YES";
		} else {
			cout << "NO";
		}
		cout << '\n';
	}
}