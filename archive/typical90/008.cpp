#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}
const int mod = 1e9 + 7;

signed main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int a = 0, t = 0, c = 0, o = 0, d = 0, e = 0, r = 0;

  int res = 0;
  rep(i, n) {
    if(s[i]=='a') {
      a += 1;
      a %= mod;
    } else if(s[i]=='t') {
      t += a;
      t %= mod;
    } else if(s[i]=='c') {
      c += t;
      c %= mod;
    } else if(s[i]=='o') {
      o += c;
      o %= mod;
    } else if(s[i]=='d') {
      d += o;
      d %= mod;
    } else if(s[i]=='e') {
      e += d;
      e %= mod;
    } else if(s[i]=='r') {
      r += e;
      r %= mod;
    }
  }

  cout << r << endl;

  return 0;
}