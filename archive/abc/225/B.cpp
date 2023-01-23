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
    int n, k;
    cin >> n >> k;
    vi A(k);
    rep(i, k) {
      cin >> A[i];
    }
    V(P) xy(n);
    rep(i, n) {
      double x, y;
      cin >> x >> y;
      xy[i] = P(x, y);
    }
    
    double d = 10005.0;
    rep(i, k) {
        double a = sqrt(pow(xy[A[i]-1].fi-xy[A[i]-1].se, 2) + pow(xy[A[i]-1].se*xy[A[i]-1].se);
        if(a < d) d = a;
    }
    
    cout << double(d) << endl;

    return 0;
}