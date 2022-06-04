#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int ans(int n, int m, int x, int i, vector<int> till_now, vector<int> cost, vector<vector<int>> grid) {

    bool already = true;
    for(int xt : till_now) {
        if(xt < x) {
            already = false;
            break;
        }
    }
    if(already) {
        return 0;
    }

    //base case - only one book is left;
    if(i == n - 1) {
        for(int j = 0; j < m; ++j) {

            till_now[j] += grid[i][j];

            if(till_now[j] < x) {
                return -1;
            }
        }

        return cost[i];
    }

    //make two cases;

    //book ith is purchased;

    vector<int> till_now2(m);
    for(int j = 0; j < m; ++j) {
        till_now2[j] = till_now[j] + grid[i][j];
    }

    int ans1;

    if(ans(n, m, x, i + 1, till_now2, cost, grid) == -1) {
        ans1 = -1;
    }else {
        ans1 = cost[i] + ans(n, m, x, i + 1, till_now2, cost, grid);
    }


    // int ans1 = cost[i] + ans(n, m, x, i + 1, till_now2, cost, grid);
    int ans2 = ans(n, m, x, i + 1, till_now, cost, grid);

    // cout << ans1 << " " << ans2 << "\n";

    if(ans1 == -1 && ans2 == -1) {
        return -1;
    }

    if(ans1 == -1 || ans2 == -1) {
        if(ans1 == -1) {
            return ans2;
        }
        return ans1;
    }

    return min(ans1, ans2);

}


int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> cost(n);
    vector<vector<int>> grid(n, vector<int>(m));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= m; ++j) {
            int x;
            scanf("%d", &x);
            if(j == 0) {
                cost[i] = x;
            }else{
                grid[i][j - 1] = x; 
            }
        }
    }
    vector<int> till_now(m, 0);

    cout << ans(n, m, x, 0, till_now, cost, grid) << "\n";
}