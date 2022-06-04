#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  string s;
  cin >> s;
  for(char ch:s) {
  	if(ch=='o') {
  		x++;
  	} else {
  		if(x>0) x--;
  	}
  }
  cout << x << endl;
  return 0;
}