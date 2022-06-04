#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define int long long

void test_case(){
	int n,k;
	cin >> n >> k;
	int carry = 0,today = 0, ans = -1;

	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		today = min(k,carry+x);
		carry = carry+x-today;

		if(ans==-1 && today<k) ans = i+1;
	}
	
	if(ans==-1){
		ans = n+carry/k+1;
	}
	cout << ans << endl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	cin >> t;

	while(t--) test_case();
	
	return 0;
}







