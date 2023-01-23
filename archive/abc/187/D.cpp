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

bool e(P a, P b) {
    return a.fi*2+a.se > b.fi*2+b.se;
}

signed main() {
    int N;
    cin >> N;

    int asum = 0;
    V(P) ab(N);
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        asum += a;
        ab[i] = P(a, b);
    }
    sort(ALL(ab), e);

    int t = 0;
    rep(i, ab.size()) {
        t += ab[i].fi*2 + ab[i].se;
        if(t > asum) {
            cout << i+1 << endl;
            return 0;
        }
    }
    
    return 0;
}