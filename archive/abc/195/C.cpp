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

    reverse(ALL(s));
    int res = 0;

    int ncnt = 0, tcnt = 0, cnt = 1, temp = 0;
    int pre = 0;

    rep(i, s.size()) {
        if(i%3==0 && i!=pre) {
            res += cnt+1;
            if(tcnt) res += (tcnt-1)*(ncnt+1);
            pre = i;
            tcnt = 0;
        } else if(i+1>s.size()-1) {
            res += cnt;
            tcnt *= 10;
            tcnt += int(s[i]-'0');
            res += (tcnt-1)*(ncnt+1);
        }
        tcnt *= 10;
        tcnt += int(s[i]-'0');
        temp += int(s[i]-'0');
        cnt *= 10;
        ncnt *= 10;
        ncnt += 9;
        cout << ncnt << " " << tcnt << " " << cnt << endl;
    }

    cout << res << endl;

    return 0;
}