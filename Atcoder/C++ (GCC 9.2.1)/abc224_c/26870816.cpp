#include <bits/stdc++.h>

using namespace std;

//Point class
template <class F = long long>
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

  F lensq(Point origin = Point(0, 0)) {
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
template <class F> bool form_valid_triangle(Point<F> a, Point<F> b, Point<F> c) { return cross_product(b - a, c - a) != 0; }

//Line class
template <class F = long long>
struct Line {
  Point<F> a, ab;

  Line() : a(), ab() {}
  Line(const Point<F> &a, const Point<F> &b, bool twoPoints = true) : a(a), ab(twoPoints ? b - a : b) {}
  Line(const F& xa, const F& ya, const F& xb, const F& yb) : a(xa, ya), ab(xb - xa, yb - ya) {}

  Point<F> b() const { return a + ab; }
  operator bool () const { return ab != Point<F>(); }
};

template <class F> inline Line<F> make_line(const Point<F>& a, const Point<F>& b, bool twoPoints = true) { return Line<F>(a, b, twoPoints); }
template <class F1, class F2> bool onLine(const Point<F1> &point, const Line<F2> &line) { if(!line) return point == line.a; return cross_product(point - line.a, line.ab) == 0; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  vector<Point<long long>> A(N);
  for(auto &p : A)
    cin >> p;

  int ans = 0;
  for(int i = 0; i < N; ++i) {
    for(int j = i + 1; j < N; ++j) {
      Line L(A[i], A[j], true);
      for(int k = j + 1; k < N; ++k) {
        ans += !onLine(A[k], L);
      }
    }
  }

  cout << ans << '\n';
}