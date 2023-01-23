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
    int N, M;
    cin >> N >> M;

    vi A(M, 0);
    rep(i, M) {
        cin >> A[i];
        A[i]--;
    }
    SORT(A);
    A.push_back(N);

    vi B;
    int mi = 1e8, mx = 0;
    int prev = -1;
    rep(i, M+1) {
        if(A[i]-prev-1 > 0) {
            //cout << A[i]-prev-1 << endl;
            B.pb(A[i]-prev-1);
            mi = min(mi, A[i]-prev-1);
            mx = max(mx, A[i]-prev-1);
        }
        prev = A[i];
    }
    
    if(mx==0) cout << 0 << endl;
    else {
        //cout << mi << endl;
        int res = 0;
        rep(i, B.size()) {
            res += B[i]/mi + (B[i]%mi ? 1 : 0);
        }
        cout << res << endl;
    }
    
    return 0;
}