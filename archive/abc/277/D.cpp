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

int M;

bool cmp(int a, int b) {
  return a%M <= b%M;
}

signed main() {
  int n, m;
  cin >> n >> m;
  
  M = m;
  
  vi a(n, 0);
  int sum = 0;
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  sort(ALL(a), cmp);
  
  int tp = a[n-1];
  rep(i, n) {
    if(a[i]==tp || a[i]==(tp+1)%m) {
      a.pb(a[i]);
      tp = a[i];
    } else break;
  }
  
  //rep(i, a.size()) cout << a[i] << " ";
  //cout << endl;
  
  int prev = -1, tsum = 0, mx = 0;
  
  rep(i, a.size()) {
    if(prev == -1) {
      prev = a[i];
      tsum = a[i];
    } else if(a[i]==prev || a[i]==(prev+1)%m) {
      prev = a[i];
      tsum += a[i];
    } else {
      prev = a[i];
      if(tsum > sum) tsum = sum;
      mx = max(tsum, mx);
      tsum = a[i];
    }
    //cout << tsum << endl;
  }
  if(tsum > sum) tsum = sum;
  mx = max(tsum, mx);
  
  //cout << mx << endl;
  cout << sum - mx << endl;
  
  
  return 0;
}