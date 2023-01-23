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

const int MAX_N = 1000050;
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

signed main() {
  int k;
  cin >> k;
  
  int mul = 1;
  //int tk = k;
  int mxp = 1;
  
  for(int i=2; i*i <= k; i++) {
    mul = (mul*i) % k;
    //cout << mul << endl;
    if(mul == 0) {
      cout << i << endl;
      return 0;
    }
    if(isPrime[i] && k%i==0) mxp = i;
    //if(tk%i == 0) tk /= i;
  }
  
  if(k/mxp == mxp) cout << mxp*2 << endl;
  else cout << k/mxp << endl;
  
  return 0;
}