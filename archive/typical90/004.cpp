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
  int H, W;
  cin >> H >> W;
  vvi A(H, vi(W));
  rep(i, H) rep(j, W) cin >> A[i][j];

  vi csum(H, 0), rsum(W, 0);
  rep(i, H) {
    int sum = 0;
    rep(j, W) {
      sum += A[i][j];
    }
    csum[i] = sum;
  }
  
  rep(i, W) {
    int sum = 0;
    rep(j, H) {
      sum += A[j][i];
    }
    rsum[i] = sum;
  }
  
  rep(i, H) {
    rep(j, W) {
      cout << csum[i] + rsum[j] - A[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}