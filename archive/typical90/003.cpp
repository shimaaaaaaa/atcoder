//003 Longest Circular Road
//木の直径

//どの頂点から出発しても、その頂点から最大の距離にある頂点は、
//必ず木の直径の端点になる

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

void dfs(vvi &G, vi &dist, int now, int pre) {
  rep(i, G[now].size()) {
    if(G[now][i]!=pre) {
      dist[G[now][i]] += dist[now] + 1;
      dfs(G, dist, G[now][i], now);
    }
  }
}

int calcMaxIndex(vi &dist, int st) {
  rep(i, dist.size()) {
    if(dist[st] < dist[i])
      st = i;
  }

  return st;
}


signed main() {
  int N;
  cin >> N;

  vvi G(N, vi(0));
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].pb(b);
    G[b].pb(a);
  }

  vi dist(N, 0);
  dfs(G, dist, 0, 0);
  int u = calcMaxIndex(dist, 0);

  vi dist2(N, 0);
  dfs(G, dist2, u, u);
  int t = calcMaxIndex(dist2, u);

  cout << dist2[t] + 1 << endl;

  return 0;
}