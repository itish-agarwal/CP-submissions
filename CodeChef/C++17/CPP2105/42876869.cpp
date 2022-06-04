#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define trace(x) cerr << #x << ": " << x << " " << endl;
#define vi vector<int>
#define pii pair<int,int>
#define traverse(container, it)  for(auto it = container.begin(); it != container.end(); it++)
#define all(c) c.begin(), c.end()
#define repeat(n) for(int i=0;i<n;i++)
#define PI 3.1415926535897932384626;



int mod = 1e9+7;
int fact[1000000+123]={0}; // 1e6

int power(int a, int b){int ans = 1;a %= mod;while(b){if(b&1){ans = (ans*a)%mod;b--;}a = (a*a)%mod;b/=2;}return ans;}

// ax+by = gcd (give it a and b it will give gcd, x and y)
int gcd(int a, int b, int& x, int& y){
	if(b==0){x=1; y=0;return a;}int x1,y1,g = gcd(b, a%b, x1, y1);
	x = y1;y = x1 - y1*(a/b);return g;
}

int fermat_inv(int x){
	return power(x, mod-2);    // (a/b)%mod = (a*(fermat_inv(b)))%mod
}

void compute_fact(int N){
	assert(N<=1e6);fact[0]=1;for(int i=2;i<=N;i++) fact[i] = (i*fact[i-1])%mod;
}

int ncr(int n,int r){
	assert(fact[0]!=0);int num = fact[n];
	int den = (fact[n-r]*fact[r])%mod;
	den = fermat_inv(den);return (num*den)%mod;
}

//print a vector directly
template <typename T>
ostream& operator << (ostream& stream, const vector<T>& v) {
	for(T x : v){stream << x << " ";} return stream;
}

// read a vector directly
template <typename T>
void operator >> (istream& stream, vector<T>& v){
	assert(v.size()>0);for(T &x : v) {cin >> x ;}
}




void test_case(){
	// write your code for each testcase here

	int n;
	cin >> n;
	vi v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	
	int dp[3][n];
	dp[0][0] = v[0]-1;
	dp[1][0] = v[0];
	dp[2][0] = v[0]+1;


	for(int ind=1;ind<n;ind++){

		for(int j=0;j<3;j++){
			dp[j][ind] = -1e10;

			for(int i=0;i<3;i++){
				int here = __gcd(v[ind]+(j-1) , dp[i][ind-1]);
				dp[j][ind] = max( dp[j][ind] , here);
			}

		}
	}

	// for(int i=0;i<n;i++) cout << dp[0][i] <<" "; cout <<"\n";
	// for(int i=0;i<n;i++) cout << dp[1][i] <<" "; cout <<"\n";
	// for(int i=0;i<n;i++) cout << dp[2][i] <<" "; cout <<"\n";
	int ans = max(dp[0][n-1] , max(dp[1][n-1], dp[2][n-1]));
	ans = max(ans, 3LL);
	cout << ans << '\n';

}




   
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	// compute_fact(1000000);

	int tt=1, i=1;
	cin >> tt;
	while(tt--){
		//cout << "Case " << i++ <<": ";
		test_case();
	} 

	return 0;
}

