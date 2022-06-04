#include <bits/stdc++.h>

using namespace std;
const int LOG = 23;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;
  while(tt--) {
    int N;
    cin >> N;
    vector<int> A(N + 1), P(N + 1);
    for(int i = 1; i <= N; i++) {
      cin >> A[i];
    }
    for(int i = 1; i <= N; i++) {
      cin >> P[i];
    }

    vector<vector<int>> C;
    vector<int> vis(N + 1);

    for(int i = 1; i <= N; i++) {
      if(!vis[i]) {
        vis[i] = 1;
        vector<int> c{i};
        int nxt = P[i];
        while(nxt != i) {
          c.push_back(nxt);
          vis[nxt] = 1;
          nxt = P[nxt];
        }
        reverse(c.begin(), c.end());
        C.push_back(c);
      }
    }

    vector<pair<int, int>> located(N + 1);

    //cycle number, position in cycle
    for(int i = 0; i < (int)C.size(); i++) {
      for(int j = 0; j < (int)C[i].size(); j++) {
        located[C[i][j]] = {i, j};
      }
    }

    int qq;
    cin >> qq;

    int K = 0;
    while(qq--) {

      int t;
      cin >> t;
      if(t == 1) {
        K++;
      } else if(t == 2) {
        int i1, i2;
        cin >> i1 >> i2;
        int index_in_cycle = located[i1].second;
        int cycle_size = C[located[i1].first].size();

        index_in_cycle = (index_in_cycle + K) % cycle_size;

        i1 = C[located[i1].first][index_in_cycle];

        index_in_cycle = located[i2].second;
        cycle_size = C[located[i2].first].size();
        index_in_cycle = (index_in_cycle + K) % cycle_size;
        i2 = C[located[i2].first][index_in_cycle];

        int ttmp = A[i1];
        A[i1] = A[i2];
        A[i2] = ttmp;

      } else {
        int i;
        cin >> i;

        int index_in_cycle = located[i].second;
        int cycle_size = C[located[i].first].size();

        index_in_cycle = (index_in_cycle + K) % cycle_size;

        cout << A[C[located[i].first][index_in_cycle]] << '\n';

      }
    }
  }
}
