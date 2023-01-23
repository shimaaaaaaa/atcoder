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
    string s, t;
    cin >> s >> t;
    
    if(s.size() > t.size()) {
        cout << "No" << endl;
        return 0;
    }
    
    int tsize = t.size(), ssize = s.size();
    int ti = 0;
    
    rep(i, ssize) {
        char c = s[i];
        if(ti>=tsize || t[ti]!=c) {
            cout << "No" << endl;
            return 0;
        }
        int scount = 1;
        while(i+1<ssize && s[i+1]==c) {
            i++;
            scount++;
        }
        int tcount = 1;
        while(ti+1<tsize && t[ti+1]==c) {
            ti++;
            tcount++;
        }
        //cout << c << " " << scount << " " << tcount << endl;
        if(!(tcount==1 || (scount>1 && tcount>1)) || scount > tcount) {
            cout << "No" << endl;
            return 0;
        }
        ti++;
    }
    
    if(ti<t.size()) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}