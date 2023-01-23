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
    return a.fi < b.fi;
}

signed main() {
    int N, C;
    cin >> N >> C;

    V(P) TL;
    rep(i, N) {
        int a, b, c;
        cin >> a >> b >> c;
        TL.pb(P(a, c));
        TL.pb(P(b+1, -c));
    }
    sort(ALL(TL), e);

    int res = 0;
    int sum = 0;
    int pre = TL[0].fi;

    rep(i, TL.size()) {
        if(TL[i].fi==pre) sum += TL[i].se;
        else {
            res += min(sum, C)*(TL[i].fi-pre);
            sum += TL[i].se;
        }
        pre = TL[i].fi;
    }

    cout << res << endl;

    return 0;

}