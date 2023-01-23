#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 2100;
const int MOD = 1000000007;


//*******************
//コンビネーション関数(MOD)
//*******************
long long fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
void COMinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 二項係数計算(MODをとる)
long long COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//*******************
//ユークリッドの互除法
//*******************
unsigned euclidean_gcd(unsigned a, unsigned b) {
  if(a < b) return euclidean_gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

//三項演算子を用いると
ll euq_gcd(ll a, ll b) { return b ? euq_gcd(b, a%b) : a; }



//*******************
//累乗のMOD(m=MOD)
//*******************
ll mpow(ll a, ll b, ll m) {
    if(b == 0) return 1;
    else if(b%2 == 0) {
       ll temp = mpow(a, b/2, m);
       return (temp * temp) % m; 
    } else {
        ll temp = mpow(a, b-1, m);
        return (a * temp) % m;
    }
}


//*******************
//エラトステネスの篩
//*******************
const int MAX_N = 100050;
vector<bool> isPrime(MAX_N, true);

void eratosthenes() {
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<MAX_N; i++) {
        if(!isPrime[i]) continue;
        for(int j=i*2; j<MAX_N; j+=i) {
            isPrime[j] = false;
        }
    }
}


//*******************
//素因数分解（数え上げ）
//*******************
int soinsu(int n) {
    int res = 0;
    int a = 2;
    while(n >= a*a) {
        if(n%a == 0) {
            res++;
            while(n%a==0) n/=a;
        }
        a++;
    }
    if(n>1) res++;
    return res;
}
