#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UnionFind {
    vector<int> par;
    vector<int> rnk;

    UnionFind(int n) {
        par.assign(n, 0);
        rnk.assign(n, 0);
        for(int i=0; i<n; i++) {
            par[i] = i;
        }
    }

    void unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;
        if(rnk[x] < rnk[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if(rnk[x] == rnk[y]) rnk[x]++;
        }
    }

    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};


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
