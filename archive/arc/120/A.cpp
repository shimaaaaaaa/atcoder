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
  int N;
  cin >> N;

  vi tmax(N, 0);
  vi tsum(N, 0);
  rep(i, N) {
    int a;
    cin >> a;
    if(i==0) {
      tmax[i] = a;
      tsum[i] = a;
    } else {
      tmax[i] = max(a, tmax[i - 1]);
      tsum[i] = tsum[i - 1] + a;
    }
  }

  int mcnt = 0;
  rep(i, N) {
    cout << tsum[i] + tmax[i] * (i + 1) << endl;
  }

  return 0;
}