#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int L, R;
   string S;
   cin >> L >> R >> S;
   reverse(S.begin() + L - 1, S.begin() + R);
   cout << S << '\n';
}