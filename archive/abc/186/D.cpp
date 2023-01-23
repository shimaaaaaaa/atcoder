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

    vi Pl, Mi;
    int psum=0, msum=0;
    rep(i, N) {
        int a;
        cin >> a;
        if(a >= 0) {
            Pl.pb(a);
            psum += a;
        } else {
            Mi.pb(a*(-1));
            msum += a*(-1);
        }
    }
    SORT(Pl); SORT(Mi);

    vi Plsum(Pl.size()+1, 0), Misum(Mi.size()+1, 0);
    rep(i, Pl.size()) {
        int t = Pl.size()-1-i;
        Plsum[t] = Plsum[t+1] + Pl[t];
    }
    rep(i, Mi.size()) {
        int t = Mi.size()-1-i;
        Misum[t] = Misum[t+1] + Mi[t];
    }

    int res = 0;
    rep(i, Pl.size()) {
        res += msum + Pl[i]*Mi.size();
        res += Plsum[i+1] - Pl[i]*(Pl.size()-(i+1));
    }
    //cout << res << endl;
    rep(i, Mi.size()) {
        //res += psum + Mi[i]*Pl.size();
        res += Misum[i+1] - Mi[i]*(Mi.size()-(i+1));
    }
        
    cout << res << endl;
    
    return 0;
}