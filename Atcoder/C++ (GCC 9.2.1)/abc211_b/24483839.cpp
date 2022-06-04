#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<string> S(4);
  for(auto& s : S) 
    cin >> s;

  sort(S.begin(), S.end());

  if(S[0]=="2B" && S[1]=="3B" && S[2]=="H" && S[3]=="HR")
    cout << "Yes" << '\n';

  else
    cout << "No" << '\n';

}