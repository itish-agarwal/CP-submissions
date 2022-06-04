#include <bits/stdc++.h>
 
using namespace std; 
#define int long long
const int nax = 1e6 + 7;

int lpf[nax], mobius[nax]; 

void least_prime_factor() { 
	for (int i = 2; i < nax; i++) {
		if (!lpf[i]) {
      for (int j = i; j < nax; j += i) {
        if (!lpf[j]) {
          lpf[j] = i; 
        }
      }
    }
  }
  return;
} 
void mob() {
	for (int i = 1; i < nax; i++) { 
		if (i == 1) {
			mobius[i] = 1;
    }	else { 
			if (lpf[i / lpf[i]] == lpf[i]) {
        mobius[i] = 0;
      } else {
				mobius[i] = -1 * mobius[i / lpf[i]]; 
      }
    }
  }
  return;
} 
int gp(int a[], int n) {
	int maxi = 0; 
	int fre[nax] = {0}; 
	for (int i = 0; i < n; i++) { 
		fre[a[i]]++; 
		maxi = max(a[i], maxi); 
	} 
	least_prime_factor(); 
	mob(); 
	int ans = 0; 
  for (int i = 1; i <= maxi; i++) { 
		if (!mobius[i]) {
			continue; 
    }
		int temp = 0; 
		for (int j = i; j <= maxi; j += i) { 
      temp += fre[j]; 
    }
		ans += temp * (temp - 1) / 2 * mobius[i]; 
	} 
  return ans; 
} 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int gcd = 0;
  for(int i = 0; i < n; i++) {
    gcd = __gcd(gcd, a[i]);
  }
  int pairs = gp(a, n);
  if(pairs==(n*(n-1))/2) {
    cout << "pairwise coprime\n";
    return 0;
  }
  if(gcd==1) {
    cout << "setwise coprime\n";
    return 0;
  }
  cout << "not coprime\n";
  return 0;
}
