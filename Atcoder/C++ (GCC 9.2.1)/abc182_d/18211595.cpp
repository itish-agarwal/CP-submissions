#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), pre(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(i > 0) {
			pre[i] = pre[i-1] + a[i];
		} else {
			pre[i] = a[i];
		}
	}
	int ans = 0;
	priority_queue<int> s;
	int moved = 0;
	for(int i = 0; i < n; i++) {
		s.push(pre[i]);
		ans = max(ans, moved + s.top());
		moved += pre[i];
	}
	cout << ans << '\n';
	return 0;	
}