#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K, best = 0;
  cin >> N >> K;
  
  map<int, int> freq;

  vector<int> C(N);
  for(auto& c : C)
    cin >> c;

  for(int i = 0; i < K; ++i) {
    freq[C[i]]++;
  }

  best = int(freq.size());

  for(int i = K; i < N; ++i) {
    freq[C[i]]++;
    freq[C[i-K]]--;
    if(freq[C[i-K]] == 0) {
      freq.erase(C[i-K]);
    }
    best = max(best, int(freq.size()));
  }

  cout << best << '\n';
}

