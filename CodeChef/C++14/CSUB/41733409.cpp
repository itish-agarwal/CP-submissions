#include <iostream>
using namespace std;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
	    int n;
	    cin >> n;
	    long long p = 0;
	    while(n--) {
	        char ch;
	        cin >> ch;
	        p += ch=='1';
	    }
	    cout << p*(p+1)/2 << '\n';
	}
	return 0;
}
