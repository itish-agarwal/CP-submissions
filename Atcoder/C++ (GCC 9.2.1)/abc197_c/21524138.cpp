#include <bits/stdc++.h>

using namespace std;
const int INF = 2e9 + 7;
int n, a[40], ans = INF;

void fun(int i, vector<int> ret) {
	if(i == n) {
		int x = 0;
		for(auto it : ret) x ^= it;
		ans = min(ans, x);
		return;
	}
	ret.push_back(a[i]);
	fun(i + 1, ret);
	ret.pop_back();
	if(!ret.empty()) {
		int l = ret.back();
		ret.back() |= a[i];
		fun(i + 1, ret);
		ret.back() = l;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	vector<int> ret;
	fun(0, ret);
	cout << ans << '\n';
}