#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

//------------------------------------------------------------------------------------

const ll mod = 998244353;

struct Mat {
  ll n, m;
  vector<vector<ll>> a;
  Mat() { }
  Mat(ll _n, ll _m) {n = _n; m = _m; a.assign(n, vector<ll>(m, 0)); }
  Mat(vector< vector<ll> > v) { n = v.size(); m = n ? v[0].size() : 0; a = v; }
  inline void make_unit() {
    assert(n == m);
    for (ll i = 0; i < n; i++)  {
      for (ll j = 0; j < n; j++) a[i][j] = i == j;
    }
  }
  inline Mat operator + (const Mat &b) {
    assert(n == b.n && m == b.m);
    Mat ans = Mat(n, m);
    for(ll i = 0; i < n; i++) {
      for(ll j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
      }
    }
    return ans;
  } 
  inline Mat operator - (const Mat &b) {
    assert(n == b.n && m == b.m);
    Mat ans = Mat(n, m);
    for(ll i = 0; i < n; i++) {
      for(ll j = 0; j < m; j++) {
        ans.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
      }
    }
    return ans;
  }
  inline Mat operator * (const Mat &b) {
    assert(m == b.n);
    Mat ans = Mat(n, b.m);
    for(ll i = 0; i < n; i++) {
      for(ll j = 0; j < b.m; j++) {
        for(ll k = 0; k < m; k++) {
          ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % mod) % mod;
        }
      }
    }
    return ans;
  }
  inline Mat pow(long long k) {
    assert(n == m);
    Mat ans(n, n), t = a; ans.make_unit();
    while (k) {
      if (k & 1) ans = ans * t;
      t = t * t;
      k >>= 1;
    }
    return ans;
  }
  inline Mat& operator += (const Mat& b) { return *this = (*this) + b; }
  inline Mat& operator -= (const Mat& b) { return *this = (*this) - b; }
  inline Mat& operator *= (const Mat& b) { return *this = (*this) * b; }
  inline bool operator == (const Mat& b) { return a == b.a; }
  inline bool operator != (const Mat& b) { return a != b.a; }
};

void chal() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n, m, k; cin >> n >> m >> k;
  Mat a(n, m);
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> a.a[i][j];
    }
  } 
  Mat b(m, k);
  for (ll i = 0; i < m; i++) {
    for (ll j = 0; j < k; j++) {
      cin >> b.a[i][j];
    }
  }
  Mat ans = a * b;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < k; j++) {
      cout << ans.a[i][j] << ' ';
    }
    cout << '\n';
  }

}