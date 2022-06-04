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
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
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
  for(auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
  vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
  for(int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T> void pr(const set<T>& pq) {
  vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
  pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins

template <class F>
struct Point {
  F x, y;

  Point() : x(0), y(0) {}
  Point(const F &x, const F &y) : x(x), y(y) {}

  template <class F1> Point& operator += (const Point<F1>& other) {
    x += other.x; y += other.y; return *this; }
  template <class F1> Point& operator -= (const Point<F1>& other) {
    x -= other.x; y -= other.y; return *this; }
  template <class F1> Point& operator *= (const F1& factor) {
    x *= factor; y *= factor; return *this; }
  template <class F1> Point& operator /= (const F1& factor) {
    assert(factor != 0);
    x /= factor; y /= factor; return *this; }

  F length_sq(Point origin = Point(0, 0)) {
    return (this->x - origin.x) * (this->x - origin.x) + (this->y - origin.y) * (this->y - origin.y);
  }

  friend Point operator - (Point a, const Point b) { return Point(a.x - b.x, a.y - b.y); }
  friend Point operator + (Point a, const Point b) { return Point(a.x + b.x, a.y + b.y); }
  friend Point operator * (Point a, const Point b) { return Point(a.x * b.x, a.y * b.y); }
  friend Point operator / (Point a, const Point b) { return Point(a.x / b.x, a.y / b.y); }
  friend bool operator == (Point a, const Point b) { return a.x == b.x && a.y == b.y; }
  friend bool operator != (Point a, const Point b) { return a.x != b.x || a.y != b.y; }
};

template <class F> istream& operator >> (istream& is, Point<F>& point) { return is >> point.x >> point.y; }
template <class F> ostream& operator << (ostream& os, const Point<F>& point) { return os << point.x << " " << point.y << '\n'; }
template <class F> inline Point<F> make_point(const F& x, const F& y) { return Point<F>(x, y); }

template <class F> F dot_product(const Point<F> &a, const Point<F> &b) { return a.x * b.x + a.y * b.y; }
template <class F> F cross_product(const Point<F> &a, const Point<F> &b) { return a.x * b.y - a.y * b.x; }

template <class F>
bool form_valid_triangle(Point<F> a, Point<F> b, Point<F> c) {
  c -= a;
  b -= a;
  return cross_product(b, c) != 0;
}

void test_case() {
  int N;
  cin >> N;

  vector<Point<long long>> A(N);
  for(auto &p : A)
    cin >> p;

  int ans = 0;
  for(int i = 0; i < N; ++i)
    for(int j = i + 1; j < N; ++j)
      for(int k = j + 1; k < N; ++k)
        ans += form_valid_triangle(A[i], A[j], A[k]);

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  // cin >> tests;

  while(tests--) 
    test_case();
}