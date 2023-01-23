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
const int MINF = -1e18;

//?_Vや?_E等の定数は問題に応じて変える

//****************************************
//ベルマンフォード法（負の辺を持つ有向グラフ）
//****************************************
const int B_V, B_E; //頂点の数、辺の数
struct B_edge{int f, t, c;}; //from, to, cost
V(B_edge) b_es(B_E);
vi b_ds(B_V, INF);
vi updated(B_V, false); //各頂点について更新したかを記録する配列

//更新可能なら更新し、更新したことを記録する関数
bool update(int &x, int y) {
    if(x < y) {
        x = y;
        return true;
    }
    return false;
}

//ベルマンフォード法（負の辺を含む有効グラフにおける最短距離を求める）
void bellmanford(int s) {
    b_ds[s] = 0;
    rep(i, B_V) {
        rep(j, B_E) {
            updated[b_es[j].t] = update(b_ds[b_es[j].t],
            b_ds[b_es[j].f]+b_es[j].c);
        }
    }
}

//ある頂点vについて、bellmanford関数の実行終了後もupdated[v]がtrueならば、
//グラフはvを含む負の閉路を持つ。

//--------------------------------------------------


//****************************************
//ダイクストラ法（正の辺のみを持つ有向グラフ）
//****************************************
const int D_V, D_E; //頂点の数、辺の数
V(V(P)) d_es(D_E); //隣接リスト（行先の頂点番号、コスト）
vi d_ds(D_V, INF); //各頂点の最小コスト（場合によっては関数内で別途用意する）

//ダイクストラ法（正の辺のみを持つ有効グラフにおける最短距離を求める）
void dijkstra(int s, vi &cost, V(V(P)) &edge) {
    priority_queue<P, V(P), greater<P>> q; //（コスト、頂点番号）の形で格納
    cost[s] = 0;
    q.push(P(0, s));
    while(!q.empty()) {
        P p = q.top();
        q.pop();
        int v = p.se;
        if(cost[v] < p.fi) continue;
        rep(i, edge[v].size()) {
            if(cost[edge[v][i].fi] > cost[v]+edge[v][i].se) {
                cost[edge[v][i].fi] = cost[v]+edge[v][i].se;
                q.push(P(cost[edge[v][i].fi], edge[v][i].fi));
            }
        }
    }
}

//--------------------------------------------------


//****************************************
//クラスカル法（最小全域木）
//****************************************
const int K_V; //頂点の数

//UnionFindが必要
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

//辺の構造体
struct K_edge {
    int u, v, cost;
};

//コストが低い順に辺を並び替えるための関数
bool k_cmp(K_edge a, K_edge b) {
    return a.cost < b.cost;
}

V(K_edge) k_es;

//クラスカル法（最小全域木の総コストを求める）
int kruskal() {
    int res = 0;
    UnionFind uf(K_V+1);
    sort(ALL(k_es), k_cmp); //辺の並び替え

    //コストの小さい辺から追加していく
    //必要のない辺は追加しない
    rep(i, k_es.size()) {
        if(!uf.same(k_es[i].u, k_es[i].v)) {
            res += k_es[i].cost;
            uf.unite(k_es[i].u, k_es[i].v);
        }
    }
    return res;
}
//--------------------------------------------------