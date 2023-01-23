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



string dfs(int a, int b, int k, vvi &dp) {
  
  if(a==0)
    return string(b, 'b');
    
  if(b==0)
    return string(a, 'a');

  if(k <= dp[a-1][b])
    return 'a' + dfs(a - 1, b, k, dp);
    
  else
    return 'b' + dfs(a, b - 1, k - dp[a - 1][b], dp);
}


signed main() {
  int a, b, k;
  cin >> a >> b >> k;

  vvi dp(a + 1, vi(b + 1, 0));
  dp[0][0] = 1;

  rep(i, a+1) {
    rep(j, b+1) {
      if(i>0)
        dp[i][j] += dp[i - 1][j];
      if(j>0)
        dp[i][j] += dp[i][j - 1];
    }
  }

  cout << dfs(a, b, k, dp) << endl;

  return 0;
}

