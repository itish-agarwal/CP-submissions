#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> mp;
const int nax = 1e5 + 4;
vector<int> edges[nax];


int main() {
    
    int n, e;
    cin >> n >> e;

    while(e--) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> ans(n + 1, -1);

    queue<int> q;
    q.push(1);

    ans[1] = 0;

    while(!q.empty()) {


        int top = q.front();
        q.pop();

        for(int b : edges[top]) {
            if(ans[b] == -1) {
                ans[b] = top;
                q.push(b);
            }
        }
    }

    bool ok = true;

    for(int i = 2; i <= n; ++i) {
        if(ans[i] == -1) {
            ok = false;
            break;
        }
    }

    if(ok) {
        cout << "Yes\n";
        for(int i = 2; i <= n; ++i) {
            cout << ans[i] << "\n";
        }
    }else{
        cout << "No\n";
    }
}