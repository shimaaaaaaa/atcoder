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

//***********************************
//mintを定義
//***********************************
const int mod = 1000000007;
struct mint {
  int x;
  mint(int x=0):x(x%mod){}   //メンバ変数xをx%modで初期化
  int get() const { return (int)x; }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;           //thisは暗黙的に左辺のポインタ
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }

  //累乗
  mint mpow(int t) const {
    if (!t) return 1;
    mint a = mpow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  //除算
  mint minv() const {
    return mpow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.minv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

//標準出力
ostream& operator<<(ostream& st, const mint a) 
{ st << a.get(); return st; };
//--------------------------------------------------

//***********************************
//場合の数の計算
//***********************************
const int MAX = 200010;
mint fac[MAX], finv[MAX];

//前計算
inline void INIT_F(){
    fac[0] = finv[0] = 1;
    for(int i=1; i<MAX-1; i++) {
        fac[i] = (fac[i-1]*mint(i));
        finv[i] = (finv[i-1]/mint(i));
    }
}

//nCk
mint mcomb(int n, int k) {
    if(n<k || k<0) return 0;
    else return ((fac[n]*finv[k])*finv[n-k]);
}

//nHk
mint mhcomb(int n, int k) {
  return mcomb(n+k-1, k);
}
//--------------------------------------------------

signed main() {


  return 0;
}