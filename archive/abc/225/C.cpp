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
  int x, a, d, n;
  cin >> x >> a >> d >> n;
  
  x -= a;
  
  rep(i, d+1) {
    int l, r;
    bool f = false;
    if((x+i)%d==0) {
      f = true;
      if((x+i)/d<=n)
    }
    }
    if((x-i)%d==0 && (x-i)/d<=n) {
      cout << i << endl;
      return 0;
    }
  }
    

    return 0;
}