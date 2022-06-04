#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int N, K;
  cin >> N >> K;
 
  auto And = [&](int i, int j) {
    cout << "and " << i + 1 << " " << j + 1 << endl;
    long long x;
    cin >> x;
    return x;
  };  
 
  auto Or = [&](int i, int j) {
    cout << "or " << i + 1 << " " << j + 1 << endl;
    long long x;
    cin >> x;
    return x;
  };
 
  vector<long long> A;
  {
    long long S0 = And(0, 1) + Or(0, 1); 
    long long S1 = And(0, 2) + Or(0, 2); 
    long long S2 = And(1, 2) + Or(1, 2); 
 
    long long a = (S0 + S1 - S2) / 2;
    long long b = (S0 + S2 - S1) / 2;
    long long c = (S1 + S2 - S0) / 2;
    A.emplace_back(a);
    A.emplace_back(b);
    A.emplace_back(c);
  }
 
  for(int i = 3; i < N; ++i) {
    long long S = And(i, 0) + Or(i, 0);
    A.emplace_back(S - A[0]);
  }
 
  sort(A.begin(), A.end());
  cout << "finish " << A[K-1] << '\n';
}