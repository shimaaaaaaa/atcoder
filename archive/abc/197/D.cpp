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
const int INF = 1e18;

signed main() {
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) cin >> A[i];

    int res = INF;

    rep(i, 1<<(N-1)) {
        int ti = i;
        int temp = 0;
        int t = 0;
        rep(j, N-1) {
            t |= A[j];
            if(1&ti) {
                temp ^= t;
                t = 0;
            }
            ti >>= 1;
        }
        t |= A[N-1];
        temp ^= t;
        res = min(res, temp);
        //cout << "A" << endl;
    }

    cout << res << endl;

    return 0;

}