#include <bits/stdc++.h>

using namespace std;

//TODO: See integer limit(initially set for integer limit). Insert and erase may be tweaked
struct BitTrie {
  struct Node {
    Node* child[2];
    int cnt;
    Node() {
      this->child[0] = this->child[1] = NULL;
      cnt = 0;
    }
  };
  Node* root;
  BitTrie() {
    root = new Node();
  }
  inline void insert(int x) {
    Node* cur = root;
    for(int bit = 30; bit >= 0; bit--) {
      cur -> cnt += 1;
      int p = (x & (1 << bit)) ? 1 : 0;
      if(!cur -> child[p]) {
        cur -> child[p] = new Node();
      }
      cur = cur -> child[p];
    } 
    cur -> cnt += 1;
  }
  inline void erase(int x) {
    Node* cur = root;
    for(int bit = 30; bit >= 0; bit--) {
      cur -> cnt -= 1;
      int p = (x & (1 << bit)) ? 1 : 0;
      cur = cur -> child[p];
    }
    cur -> cnt -= 1;
  }
  int kth_min_xor(int x, int k) {
    //returns kth minimum xor of x with any number present in the trie
    //assumes k <= numbers present in trie currently
    int ans = 0;
    Node* cur = root;
    for(int bit = 30; bit >= 0; bit--) {
      int p = (x & (1 << bit)) ? 1 : 0;
      if(cur -> child[p]) {
        if(cur -> child[p] -> cnt >= k) {
          cur = cur -> child[p];
        } else {
          k -= cur -> child[p] -> cnt;
          ans += 1 << bit;
          cur = cur -> child[1^p];
        }
      } 
      else {
        ans += 1 << bit;
        if(cur -> child[1^p] -> cnt < k) {
          k -= cur -> child[1^p] -> cnt;
        }
        cur = cur -> child[1^p];
      }
    }
    return ans;
  }
  int min_xor_query(int x) {
    //returns the minimum xor of x with any number present in the trie
    int ans = 0;
    Node* cur = root;
    for(int bit = 30; bit >= 0; bit--) {
      int p = (x & (1 << bit)) ? 1 : 0;
      if(cur -> child[p] && cur -> child[p] -> cnt > 0) {
        cur = cur -> child[p];
      } else if(cur -> child[1^p] && cur -> child[1^p] -> cnt > 0) {
        ans += 1 << bit;
        cur = cur -> child[1^p];
      } else {
        break;
      }
    }
    return ans;
  }
  int max_xor_query(int x) {
    //returns the maximum xor of x with any number present in the trie
    int ans = 0;
    Node* cur = root;
    for(int bit = 30; bit >= 0; bit--) {
      int p = (x & (1 << bit)) ? 1 : 0;
      if(cur -> child[1^p] && cur -> child[1^p] -> cnt > 0) {
        ans += 1 << bit;
        cur = cur -> child[1^p];
      } else if(cur -> child[p] && cur -> child[p] -> cnt > 0) {
        cur = cur -> child[p];
      } else {
        break;
      }
    }
    return ans;
  }
  int xor_lt_k(int y, int k) {
    //returns the number of numbers currently in trie such that number^y < k;
    //returns the number of numbers currently in trie such that number^y < k;
    Node* cur = root;
    int res = 0;
    for(int bit = 30; bit >= 0; bit--) {
      if(!cur) 
        break;
      if(y & (1 << bit)) {
        if(k & (1 << bit)) {
          res += (cur -> child[1] ? cur -> child[1] -> cnt : 0);
          cur = cur -> child[0];
        } else {
          cur = cur -> child[1];
        }
      } else {
        if(k & (1 << bit)) {
          res += (cur -> child[0] ? cur -> child[0] -> cnt : 0);
          cur = cur -> child[1];
        } else {
          cur = cur -> child[0];
        }
      }
    }
    return res;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k, x = 0, a;
    cin >> n >> k;
    long long ans = 0;
    BitTrie trie;
    trie.insert(0);
    while(n--) {
      cin >> a;
      x ^= a;
      ans += trie.xor_lt_k(x, k);
      trie.insert(x);
    }
    cout << ans << '\n';
  }
  return 0;
}