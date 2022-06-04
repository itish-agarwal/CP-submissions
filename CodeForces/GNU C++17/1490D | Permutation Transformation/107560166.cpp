#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif
 
using namespace std;
#define int long long 
const int nax = 1e3;
int a[nax], ans[nax], pos[nax];
 
struct node {
  int val;
  node* left;
  node* right;
  node(int x) {
    val = x;
    left = right = NULL;
  }
};
node* build(int a[], int n) {
  if(n == 0) return NULL;
  if(n == 1) {
    node* newNode = new node(a[0]);
    return newNode;
  }
  int mx = -1, in = -1;
  for(int i = 0; i < n; ++i) {
    if(a[i] > mx) {
      mx = a[i];
      in = i;
    }
  }
  node* root = new node(a[in]);
  node* leftT = build(a, in);
  node* rightT = build(a+in+1, n-1-in);
  root->left = leftT;
  root->right = rightT;
  return root;
}
int d(node* root) {
  if(!root) return 0;
  return 1 + max(d(root->left), d(root->right));
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
      pos[a[i]] = i;
    }
    node* root = build(a, n);
    for(int i = 0; i <= n; ++i) {
      ans[i] = -1;
    }
    //cout << root->val << '\n';
    ans[pos[root->val]] = 0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
      node* u  =q.front();
      q.pop();
      if(u->left) {
        int l = u->left->val;
        if(ans[pos[l]] == -1) {
          ans[pos[l]] = ans[pos[u->val]] + 1;
          q.push(u->left);
        }
      }
      if(u->right) {
        int r = u->right->val;
        if(ans[pos[r]] == -1) {
          ans[pos[r]] = ans[pos[u->val]] + 1;
          q.push(u->right);
        }
      }
    }
    for(int i = 0; i < n; ++i) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
}