#include <bits/stdc++.h>

using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  set<char> st;
  for(char ch : s) {
    st.insert(ch);
  }
  if(st.size()==1) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
  return 0;
}
