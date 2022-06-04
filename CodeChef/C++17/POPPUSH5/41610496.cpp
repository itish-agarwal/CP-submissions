#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

vector<vector<pair<int, int>>> g;

//void dfss(int u, int par, bool good) {
  //if((int)g[u].size()==1 && g[u][0].f==par) {
    //good_paths++;
    //leaves++;
    //return;
  //}
  //for(auto it : g[u]) {
    //if(it.f!=par) {
      //if(it.s==1) {
        //dfss(it.f, u, 0);
      //}
    //}
  //}
//}

int dfs(int u, int par) {
  if((int)g[u].size()==1 && g[u][0].f==par) {
    return 0;
  }
  int need = 0, answer = 0, must = 0;
  for(auto it : g[u]) {
    if(it.f!=par) {
      must += it.s==2;
      int add = dfs(it.f, u);
      if(add>0) {
        //if(it.s==2) {
          //need++;
        //} else {
          //need += add;
        //}
        need += add;
      } else {
        need += it.s==2;
      }
    }
  }
  //cout << u << " returns " << need << '\n';
  return need;
}
  

//void dfs(int u, int par, int already) {
  //int stock = already;
  //for(auto it : g[u]) {
    //if(it.f!=par) {
      //if(it.s==2) {
        //if(!stock) {
          //answer++;
          //dfs(it.f, u, 1);
        //} else {
          //dfs(it.f, u, 1);
          //stock--;
        //}1
      //} else {
        //dfs(it.f, u, stock);
      //}
    //}
  //}
//}
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  g.resize(n+1);
  for(int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  cout << dfs(1, -1) << '\n';
  return 0;
}
