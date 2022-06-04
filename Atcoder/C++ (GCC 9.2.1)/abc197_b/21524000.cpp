#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	--x;
	--y;
	int g[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; ++j) {
			char ch;
			cin >> ch;
			if(ch == '.') {
				g[i][j] = 1;
			} else {
				g[i][j] = -1;
			}
		}
	}
	int ans = 1;
	for(int i = x + 1; i < n; ++i) {
		if(g[i][y] == -1) break;
		ans++;
	}
	for(int i = x - 1; i >= 0; --i) {
		if(g[i][y] == -1) break;
		ans++;
	}
	for(int j = y + 1; j < m; ++j) {
		if(g[x][j] == -1) break;
		ans++;
	}
	for(int j = y - 1; j >= 0; --j) {
		if(g[x][j] == -1) break;
		ans++;
	}
	cout << ans << '\n';
}