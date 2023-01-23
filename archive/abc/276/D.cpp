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
  int n;
  cin >> n;
  
  int mintwo = 1005;
  int minthree = 1005;
  
  vi Atwo(n, 0), Athree(n, 0);
  
  int pre = 0;
  rep(i, n) {
    int a;
    cin >> a;
    
    int cnt = 0;
    while(a%2 == 0) {
      a /= 2;
      cnt++;
    }
    Atwo[i] = cnt;
    mintwo = min(mintwo, cnt);
    
    cnt = 0;
    while(a%3 == 0) {
      a /= 3;
      cnt++;
    }
    Athree[i] = cnt;
    minthree = min(minthree, cnt);
    
    if(i!=0 && a!=pre) {
      cout << -1 << endl;
      return 0;
    }
    
    pre = a;
  }
  
  int res = 0;
  rep(i, n) {
    res += Atwo[i] - mintwo;
    res += Athree[i] - minthree;
  }
  
  cout << res << endl;
  
  return 0;
}