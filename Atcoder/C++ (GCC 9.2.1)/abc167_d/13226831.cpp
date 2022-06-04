#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll nax = 2e5 + 2;
vector<ll> edges[nax];
bool visited[nax];

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> aa(n + 1);

    for(ll i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        aa[i] = x;

        edges[i].push_back(aa[i]);
    }
    for(ll i = 1; i <= n; ++i) {
        visited[i] = false;
    }
    ll a = 1;
    ll cnt = 0;

    while(1) {

        if(cnt == k) {
            cout << a << "\n";
            break;
        }

        visited[a] = true;
        ll b = edges[a][0];


        if(a == b) {
            cout << a << "\n";
            return 0;
        }

        if(visited[b]) {

            bool vis[n + 1];
            for(ll i = 1; i <= n; ++i) {
                vis[i] = false;
            }

            ll len = 1;

            vis[a] = true;

            while(!vis[edges[a][0]]) {
                a = edges[a][0];
                ++len;
                vis[a] = true;
            }


            ll rem = (k - cnt) % len;
            ++rem;

            while(rem--) {
                a = edges[a][0];
            }

            cout << a << "\n";
            break;

        }else {
            a = edges[a][0];
        }
        ++cnt;
    }
}