#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> mp;
const int nax = 1e4;

int main() {

    int k;
    cin >> k;
    string s; cin >> s;

    if(s.length() <= k) {
        cout << s << "\n";
    }else {
        string t = s.substr(0, k);
        t += "...";
        cout << t << "\n";
    }
    return 0;
}


