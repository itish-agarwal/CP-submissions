#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		string s, p;
		cin >> s >> p;
		int k0 = 0, k1 = 0;
		for(char ch : s) k0 += ch;
		for(char ch : p) k1 += ch;

		int d = k1 - k0;
		if(d>=1 && d<=10) {
			puts("Rashmi");
		} else {
			if(d != 0) {
				puts("Mohit");
			} else {
				puts("No One");
			}
		}
	}
}