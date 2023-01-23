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
    string s;
    cin >> s;

    int len = s.size();

    int res = 0;
    if(len%2) {
        int t = len/2;
        int cnt = 9;
        rep(i, t) {
            res += cnt;
            cnt *= 10;
        }
    } else {
        int r = 0;
        rep(i, len/2) {
            r *= 10;
            r += int(s[i]-'0');
        }
        int l = 0;
        for(int i=len/2; i<len; i++) {
            l *= 10;
            l += int(s[i]-'0');
        }
        if(r > l) res = r-1;
        else res = r;
    }

    cout << res << endl;

    return 0;
}