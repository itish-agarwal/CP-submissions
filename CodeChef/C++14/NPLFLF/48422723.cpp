#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node* child[26];
  int cnt;
  Node() {
    for(int r = 0; r < 26; r++) 
      this->child[r] = NULL;
    cnt = 0;
  }
};

Node* root;
void insert(const string& p) {
  Node* a = root;
  for(int j = 0; p[j]; j++) {
    a -> cnt++;
    int x = p[j] - 'a';
    if(!a -> child[x]) {
      a -> child[x] = new Node();
    }
    a = a -> child[x];
  }
  a -> cnt++;
}
void erase(const string& p) {
  Node* a = root;
  for(int j = 0; p[j]; j++) {
    a -> cnt--;
    int x = p[j] - 'a';
    a = a -> child[x];
  }
  a -> cnt--;
}bool query(int k, int l) {
  if(!root || root -> cnt < k) 
    return false;
  priority_queue<pair<int, Node*>> pq;
  pq.push({0, root});
  while(!pq.empty()) {
    auto it = pq.top();
    pq.pop();
    if(it.first >= l)
      return true;
    for(int x = 0; x < 26; x++) {
      if(it.second -> child[x] && it.second -> child[x] -> cnt >= k) {
        pq.push({it.first + 1, it.second -> child[x]});
      }
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int Q;
  cin >> Q;

  root = new Node();

  vector<string> deleted(Q);

  for(int r = 0; r < Q; r++) {
    int tt;
    cin >> tt;
    if(tt == 1) {
      string p;
      cin >> p;
      reverse(p.begin(), p.end());
      insert(p);
      deleted[r] = p;
    } else if(tt == 3) {
      int q;
      cin >> q;
      q--;
      if(!deleted[q].empty()) {
        erase(deleted[q]);
        deleted[q] = "";
      }
    } else {
      int k, l;
      cin >> k >> l;
      cout << (query(k, l) ? "YES" : "NO") << '\n';
    }
  }
}