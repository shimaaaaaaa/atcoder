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
  int n, k, d;
  cin >> n >> k >> d;
  vi a(n, 0);
  rep(i, n) {
    cin >> a[i];
  }
  
  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(d, -1)));
  
  dp[0][0][0] = 0;
  
  rep(i, n) {
    rep(j, k+1) {
      rep(w, d) {
        
        if(dp[i][j][w] == -1) continue;
        
        dp[i+1][j][w] = max(dp[i+1][j][w], dp[i][j][w]);
        
        if(j != k) dp[i+1][j+1][(w+a[i])%d] = max(dp[i+1][j+1][(w+a[i])%d], dp[i][j][w]+a[i]);
      }
    }
  }
  
  cout << dp[n][k][0] << endl;
  
  return 0;
}