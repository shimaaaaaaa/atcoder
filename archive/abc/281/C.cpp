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
  int n, t;
  cin >> n >> t;
  vi a(n, 0);
  int sum = 0;
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  t %= sum;
  
  rep(i, n) {
    if(t >= a[i]) t -= a[i];
    else {
      cout << i+1 << " " << t << endl;
      break;
    }
  }
    
    return 0;
}