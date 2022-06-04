#include <bits/stdc++.h>

using namespace std;
  
struct Node {
  Node* child[26];
  int cnt;
  Node() {
    for(int r = 0; r < 10; r++) 
      this->child[r] = NULL;
    cnt = 0;
  }
};

void insert(Node* &root, const string& p) {
  Node* a = root;
  for(char ch : p) {
    int x = ch - 'a';
    if(!a -> child[x]) {
      a -> child[x] = new Node();
    }
    a = a -> child[x];
    a -> cnt++;
  }
}
void erase(Node* &root, const string& p) {
  Node* a = root;
  for(char ch : p) {
    int x = ch - 'a';
    a = a -> child[x];
    a -> cnt--;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int N;
  cin >> N;
  Node* root = new Node();
  vector<string> S(N);
  for(auto& s : S) {
    cin >> s;
    insert(root, s);
  }
  bool ok = true;
  for(auto s : S) {
    bool okk = false;
    erase(root, s);
    Node* a = root;
    for(char ch : s) {
      int x = ch - 'a';
      a = a -> child[x];
      if(a -> cnt <= 0) {
        okk = true;
        break;
      }
    }
    if(!okk) {
      ok = false;
      break;
    }
    insert(root, s);
  }
  cout << (ok ? "non vulnerable" : "vulnerable") << '\n';
}