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

int N;
vvi G(100050);

void func(int prev, int now, V(bool) &judge) {
  judge[now] = !judge[prev];
  rep(i, G[now].size()) {
    if(G[now][i] == prev)
      continue;
    func(now, G[now][i], judge);
  }
}

signed main() {
  int Q;
  cin >> N >> Q;
  
  rep(i, N-1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].pb(b);
    G[b].pb(a);
  }

  V(bool) judge(N, true);
  func(0, 0, judge);
  //rep(i, N) cout << judge[i] << endl;

  rep(i, Q) {
    int c, d;
    cin >> c >> d;
    c--;
    d--;
    cout << ((judge[c] == judge[d]) ? "Town" : "Road") << endl;
  }

  return 0;
}