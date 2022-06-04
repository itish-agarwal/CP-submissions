#include <bits/stdc++.h>

using namespace std;
const int LOG = 21;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		vector<int> edges[n];
		for(int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		vector<int> d(n), par(n);
		vector<vector<int>> up(n, vector<int> (LOG));
		function<void(int, int)> Dfs = [&](int u, int pr) {
			for(int v : edges[u]) {
				if(v != pr) {
					d[v] = d[u] + 1;
					up[v][0] = u;
					par[v] = u;
					for(int j = 1; j < LOG; j++) {
						up[v][j] = up[ up[v][j-1] ][j-1];
					}
					Dfs(v, u);
				}
			}
		};
		Dfs(0, -1);
		auto get_lca = [&](int a, int b) {
			if(d[b] > d[a]) 
				swap(a, b);
			int k = d[a] - d[b];
			for(int j = LOG - 1; j >= 0; j--) {
				if(k & (1 << j)) {
					a = up[a][j];
				}
			}
			if(a == b)
				return a;
			for(int j = LOG - 1; j >= 0; j--) {
				if(up[a][j] != up[b][j]) {
					a = up[a][j];
					b = up[b][j];
				}
			}
			return up[a][0];
		};
		auto get_dist = [&](int a, int b) {
			int lca = get_lca(a, b);
			return d[a] + d[b] - 2 * d[lca];
		};
		int Q;
		cin >> Q;
		for(int q = 0; q < Q; q++) {
			int K;
			cin >> K;
			vector<int> nodes;
			for(int i = 0; i < K; i++) {
				int a;
				cin >> a;
				a--;
				nodes.push_back(a);
			}
      int one_end = -1, max_dist = -1, from = nodes[0];
      for(auto it : nodes) {
        if(get_dist(it, from) > max_dist) {
          max_dist = get_dist(it, from);
          one_end = it;
        }
      }
      int other_end = -1;
      max_dist = -1;
      from = one_end;
      for(auto it : nodes) {
        if(get_dist(it, from) > max_dist) {
          max_dist = get_dist(it, from);
          other_end = it;
        }
      }
			//sort(nodes.begin(), nodes.end(), [&](int a, int b) {
				//return d[a] < d[b];
			//});
			//int one_end = nodes.back();
			//int other_end = -1, max_dist = -1;
			//for(int it : nodes) {
				//if(get_dist(one_end, it) > max_dist) {
					//other_end = it;
					//max_dist = get_dist(one_end, it);
				//}
			//}
			bool ok = 1;
			int L = get_dist(one_end, other_end);
			for(auto it : nodes) {
				if(get_dist(one_end, it) + get_dist(other_end, it) != L) {
					ok = 0;
					break;
				}
			}
			cout << (ok ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}
