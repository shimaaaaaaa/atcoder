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

    vector<string> res;

    rep(i, 1<<N) {
        int t = i;
        string tmp = "";
        rep(j, N) {
            if(t&1) {
                tmp += "(";
            } else {
                tmp += ")";
            }
            t >>= 1;
        }

        int cnt = 0;
        bool ok = true;
        rep(i, N) {
            cnt += (tmp[i] == '(' ? 1 : -1);
            if(cnt < 0)
                ok = false;
        }

        if(ok && cnt==0)
            res.pb(tmp);
    }

    SORT(res);
    rep(i, res.size()) cout << res[i] << endl;

    return 0;
}