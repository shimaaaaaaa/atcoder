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

//改良
 struct UnionFind {
    vector<int> par;
    vector<int> rnk;

    UnionFind(int n) {
        par.assign(n, 0);
        rnk.assign(n, 1);
        for(int i=0; i<n; i++) {
            par[i] = i;
        }
    }

    void unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;
        if(rnk[x] < rnk[y]) swap(x, y);
        rnk[x] += rnk[y];
        par[y] = x;
    }

    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return rnk[find(x)];
    }
};


signed main() {
  
  
    

    return 0;
}