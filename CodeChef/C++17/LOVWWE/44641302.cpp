#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		int A, R, Z;
		cin >> A >> R >> Z;
		//Z rupees per food item
		int before = A/Z + R/Z;
		int after = (A + R)/Z;
		if(before == after) {
			cout << "0\n";
		} else {
			cout << min(Z - A%Z, Z - R%Z) << '\n';
		}
	}
}
	