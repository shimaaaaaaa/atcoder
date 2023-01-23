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

signed main() {
  int n, x;
  cin >> n >> x;
  vi a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  
  vi minb(n);
  minb[0] = b[0];
  FOR(i, 1, n) minb[i] = min(minb[i-1], b[i]);
  
  vi asum(n+1);
  vi bsum(n+1);
  rep(i, n) {
    asum[i+1] = asum[i] + a[i];
    bsum[i+1] = bsum[i] + b[i];
  }
  
  int res = 5e18;
  rep(i, n) {
    int cost = asum[i+1]+bsum[i+1] + max(0, (x-(i+1)))*minb[i];
    res = min(res, cost);
  }
  
  cout << res << endl;
  
  return 0;
}