#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 21e7 + 9;

//Returns for every index, leftmost index to right of it
//having a value greater than or equal to itself
vector<int> next_greater_equal(const vector<int>& values) {
  int n = values.size();
  vector<int> res(n, n);

  stack<int> pq;
  for(int i = n - 1; i >= 0; --i) {
    while(!pq.empty() && values[i] > values[pq.top()])
      pq.pop();

    if(!pq.empty())
      res[i] = pq.top();

    pq.push(i);
  }

  return res;
}

//Returns for every index, rightmost index to left of it
//having a value strictly greater than itself
vector<int> previous_greater(const vector<int>& values) {
  int n = values.size();
  vector<int> res(n, -1);

  stack<int> pq;
  for(int i = 0; i < n; ++i) {
    while(!pq.empty() && values[i] >= values[pq.top()])
      pq.pop();

    if(!pq.empty())
      res[i] = pq.top();

    pq.push(i);
  }

  return res;
}

//Returns for every index, leftmost index to right of it 
//having a value strictly greater than itself
vector<int> next_greater(const vector<int>& values) {
  int n = values.size();
  vector<int> res(n, n);

  stack<int> pq;
  for(int i = n - 1; i >= 0; --i) {
    while(!pq.empty() && values[i] >= values[pq.top()])
      pq.pop();

    if(!pq.empty())
      res[i] = pq.top();

    pq.push(i);
  }

  return res;
}

template <class T>
struct SparseTable_Min {
public:
  int N;
  vector<int> compute;
  vector<vector<T>> tab;

  T merge(const T& a, const T& b) {
    return min(a, b);
  }

  SparseTable_Min(const vector<T>& values) {
    int N = values.size();
    compute.resize(N + 1);
    for(int i = 2; i <= N; ++i) 
      compute[i] = compute[i / 2] + 1;

    const int log = 32 - __builtin_clz(N);
    tab.resize(log);

    tab[0] = values;
    for(int j = 1; j < log; ++j) {
      tab[j].resize(N - (1 << j) + 1);
      for(int i = 0; i <= N - (1 << j); ++i)
        tab[j][i] = merge(tab[j-1][i], tab[j-1][i + (1 << (j-1))]);
    }
  }

  T query(int L, int R) {
    int j = compute[R - L + 1];
    return merge(tab[j][L], tab[j][R - (1 << j) + 1]);
  }
};

template <class T>
struct SparseTable_Max {
public:
  int N;
  vector<int> compute;
  vector<vector<T>> tab;

  T merge(const T& a, const T& b) {
    return max(a, b);
  }

  SparseTable_Max(const vector<T>& values) {
    int N = values.size();
    compute.resize(N + 1);
    for(int i = 2; i <= N; ++i) 
      compute[i] = compute[i / 2] + 1;

    const int log = 32 - __builtin_clz(N);
    tab.resize(log);

    tab[0] = values;
    for(int j = 1; j < log; ++j) {
      tab[j].resize(N - (1 << j) + 1);
      for(int i = 0; i <= N - (1 << j); ++i)
        tab[j][i] = merge(tab[j-1][i], tab[j-1][i + (1 << (j-1))]);
    }
  }

  T query(int L, int R) {
    int j = compute[R - L + 1];
    return merge(tab[j][L], tab[j][R - (1 << j) + 1]);
  }
};

void test_case() {
  int N;
  cin >> N;

  vector<int> A(N);
  for(auto& a : A)
    cin >> a;

  vector<int> preffix_sum(N, A[0]);
  for(int i = 1; i < N; ++i)
    preffix_sum[i] = preffix_sum[i-1] + A[i];

  SparseTable_Min<int> arr_min(A);
  SparseTable_Max<int> arr_max(A);
  
  SparseTable_Min<int> st_min(preffix_sum);
  SparseTable_Max<int> st_max(preffix_sum);

  auto get_sum = [&](int l, int r) {
    return preffix_sum[r] - (l > 0 ? preffix_sum[l-1] : 0);
  };

  int ans = -INF;

  vector<int> next_ge = next_greater_equal(A);
  vector<int> prev_g = previous_greater(A);
  vector<int> next_g = next_greater(A);

  //equal, equal
  for(int i = 0; i < N; ++i) {
    int right_end = next_ge[i];
    // int candidate = -INF;
    if(right_end < N && A[right_end] == A[i]) {
      int candidate = get_sum(i, right_end), original = candidate;

      int in = prev_g[i];
      in += 1;

      if(i > 0) {
        int L = max(0LL, in - 1), R = i - 2;
        if(L >= 0 && R >= 0 && R >= L) {
          candidate += max(0LL, preffix_sum[i-1] - st_min.query(L, R));
        }

        candidate = max(candidate, original + max(0LL, get_sum(in, i - 1)));
      }

      in = next_g[i];
      in -= 1;

      if(in >= right_end + 1) {
        int L = right_end + 1, R = in;
        if(L >= 0 && R >= 0 && R >= L) {
          candidate += max(0LL, st_max.query(L, R) - preffix_sum[right_end]);
        }

        // candidate = max(candidate, candidate + max(0LL, get_sum(right_end)))
      }
      ans = max(ans, candidate - 2 * A[i]);
    }
  }

  //smaller, greater
  for(int i = 0; i < N; ++i) {
    int right_end = next_g[i];
    if(right_end < N) {

      int candidate = get_sum(i, right_end), original = candidate;

      int in = prev_g[i];
      in += 1;

      if(i > 0) {
        int L = max(0LL, in - 1), R = i - 1;
        if(L >= 0 && R >= 0 && R >= L) {
          candidate += max(0LL, preffix_sum[i-1] - st_min.query(L, R));
        }
        
        candidate = max(candidate, original + max(0LL, get_sum(in, i - 1)));
      }

      // original = candidate;
      int lo = right_end + 1, hi = N - 1, best = -1;

      if(lo < N) {
        while(lo <= hi) {
          int mid = (lo + hi) / 2;
          if(arr_max.query(right_end + 1, mid) <= A[i]) {
            best = mid;
            lo = mid + 1;
          } 

          else {
            hi = mid - 1;
          }
        }

        if(best >= right_end && best < N) {
          int L = right_end + 1, R = best;
          if(L >= 0 && R >= 0 && R >= L) {
            candidate += max(0LL, st_max.query(L, R) - preffix_sum[right_end]);
          }
        }
      }

      ans = max(ans, candidate - A[i] - A[right_end]);
    }
  }

  //greater, smaller
  for(int i = 0; i < N; ++i) {
    int left_end = prev_g[i];
    if(left_end >= 0) {

      int candidate = get_sum(left_end, i), original = candidate;

      int in = next_g[i];
      in -= 1;

      int L = i + 1, R = in;
      if(L >= 0 && R >= 0 && R >= L) {
        candidate += max(0LL, st_max.query(L, R) - preffix_sum[i]);
      }

      original = candidate;

      int lo = 0, hi = left_end - 1, best = N + 1;
      if(hi >= 0) {
        while(lo <= hi) {
          int mid = (lo + hi) / 2;
          if(arr_max.query(mid, left_end - 1) <= A[i]) {
            best = mid;
            hi = mid - 1;
          }

          else {
            lo = mid + 1;
          }
        }
        
        int L = max(0LL, best - 1), R = left_end - 2;
        if(L >= 0 && R >= 0 && R >= L) {
          candidate += max(0LL, preffix_sum[left_end-1] - st_min.query(L, R));
        }

        if(best < left_end) { 
          candidate = max(candidate, original + max(0LL, get_sum(best, left_end - 1)));
        }
      }

      ans = max(ans, candidate - A[i] - A[left_end]);
    }
  }

  cout << ans << '\n';  
} 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while(T--)
    test_case();
}