#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif

void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(char x)  { cout << '\'' << x << '\''; }
void pr(long double x)  { cout << x; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(float x)  { cout << x; }
void pr(long x)  { cout << x; }
void pr(bool x)  { cout << x; }
void pr(int x)  { cout << x; }

template <class T, class V> void pr(const pair<T, V> &x);
template <class T, class V> void pr(const map<T, V>& mp);
template <class T, class... V> void pr(T t, V... v);
template <class T> void pr(const multiset<T>& pq);
template <class T> void pr(const vector<T>& v);
template <class T> void pr(const set<T>& pq);

template <class T, class V> void pr(const pair<T, V>& x) {
  cout << "{"; pr(x.first); cout << ", "; pr(x.second); cout << "}";
}
template <class T, class V> void pr(const map<T, V>& mp) {
  for(auto it = mp.begin(); it != mp.end(); ++it) {
    pr(*it); auto copy = it;
    if(++copy != mp.end()) 
      cout << " ";
  }
}
template <class T> void pr(const multiset<T>& pq) {
  vector<T> values;
  for(auto& value : pq) 
    values.push_back(value);

  pr(values);
}
template <class T> void pr(const vector<T>& v) {
  for(int i = 0; i < (int) v.size(); ++i) {
    pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : "");
  }
}
template <class T> void pr(const set<T>& pq) {
  vector<T> values;
  for(auto value : pq)
    values.push_back(value);

  pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
  pr(t); if(sizeof...(v)) cout << " | ";
  pr(v...);
}
//Global space begins
const int B = 31;

template <class T>
struct BitTrie {
  struct Node {
    Node* child[2];
    int cnt;
    Node() {
      this->child[0] = this->child[1] = NULL;
      cnt = 0;
    }
  };
  int B;
  Node* root;
  BitTrie(int bits) {
    root = new Node();
    B = bits;
  }
  inline void insert(const T& x) {
    Node* cur = root;
    for(int b = B; b >= 0; --b) {
      cur->cnt++;
      int p = (x & (1LL << b)) ? 1 : 0;
      if(!cur->child[p]) 
        cur->child[p] = new Node();
      cur = cur->child[p];
    }

    cur -> cnt++;
  }
  inline void erase(const T& x) {
    Node* cur = root; 
    for(int b = B; b >= 0; --b) {
      cur->cnt--;
      int p = (x & (1LL << b)) ? 1 : 0;
      cur = cur->child[p];
    }

    cur->cnt--;
  }
  //Returns kth minimum xor of x with any number present in trie
  //Assumes k <= number of numbers present in trie
  T kth_min_xor(T x, T k) {
    Node* cur = root;
    T ans = 0;
    for(int b = B; b >= 0; --b) {
      int p = (x & (1LL << b)) ? 1 : 0;
      if(cur->child[p]) {
        if(cur->child[p]->cnt >= k) {
          cur = cur->child[p];
        }
        else {
          k -= cur->child[p]->cnt;
          ans += 1LL << b;
          cur = cur->child[p^1];
        }
      }
      else {
        ans += 1LL << b;
        if(cur->child[1^p]->cnt < k) {
          k -= cur->child[1^p]->cnt;
        }
        cur = cur->child[1^p];
      }
    }
  }
  //Returns min xor of x with any number present in trie
  T min_xor(T x) {
    Node* cur = root;
    T ans = 0;
    for(int b = B; b >= 0; --b) {
      int p = (x & (1LL << b)) ? 1 : 0;
      if(cur->child[p] && cur->child[p]->cnt > 0) {
        cur = cur->child[p];
      }
      else if(cur->child[1^p] && cur->child[1^p]->cnt > 0) {
        cur = cur->child[1^p];
        ans += 1LL << b;
      }
      else {
        return ans;
      }
    }
    return ans;
  }
  //Returns max xor of x with any number present in trie
  T max_xor(T x) {
    Node* cur = root;
    T ans = 0;
    for(int b = B; b >= 0; --b) {
      int p = (x & (1LL << b)) ? 1 : 0;
      if(cur->child[1^p] && cur->child[1^p]->cnt > 0) {
        cur = cur->child[1^p];
        ans += 1LL << b;
      }
      else if(cur->child[p] && cur->child[p]->cnt > 0) {
        cur = cur->child[p];
      }
      else {
        return ans;
      }
    }
    return ans;
  }
  //Returns number of numbers present in trie such that number^y < k; 
  int xor_less_than_K(T y, T k) {
    Node* cur = root;
    int ans = 0;
    for(int b = B; b >= 0; --b) {
      if(!cur) {
        break;
      }
      if(y & (1LL << b)) {
        if(k & (1LL << b)) {
          ans += (cur->child[1] ? cur->child[1]->cnt : 0);
          cur = cur->child[0];
        }
        else {
          cur = cur->child[1];
        }
      }
      else {
        if(k & (1LL << b)) {
          ans += (cur->child[0] ? cur->child[0]->cnt : 0);
          cur = cur->child[1];
        }
        else {
          cur = cur->child[0];
        }
      }
    }

    return ans;
  }
};

void test_case() {
  int N;
  cin >> N;

  map<int, int> freq;
  vector<int> A(N);
  for(auto &a : A) {
    cin >> a;
    freq[a]++;
  }

  if(N == 1) {
    cout << 0 << '\n';
    return;
  }

  BitTrie<int> trie(B);
  for(auto &a: A)
    trie.insert(a);

  for(int i = 0; i < N; ++i) {
    int el = A[i];
    freq[el]--;
    trie.erase(el);
    int minimum_xor = trie.min_xor(el);
    int find = el ^ minimum_xor;
    cout << freq[find] << " ";
    trie.insert(el);
    freq[el]++;
  }
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;
  while(tests--)
    test_case();

}