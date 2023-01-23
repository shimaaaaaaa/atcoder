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

int X[4] = {0, 1, 0, -1};
int Y[4] = {1, 0, -1, 0};

signed main() {
  int h, w;
  cin >> h >> w;
  V(string) C(h);
  int sy, sx;
  queue<P> q;
  rep(i, h) {
    cin >> C[i];
    rep(j, w) if(C[i][j] == 'S') {
      sy = i;
      sx = j;
      q.push(P(i, j));
    }
  }
  
  int dots = 0;
  rep(i, 4) if(sy+Y[i]>=0 && sy+Y[i]<h && sx+X[i]>=0 && sx+X[i]<w) {
    if(C[sy+Y[i]][sx+X[i]] == '.') dots++;
  }
  
  int step = 0;
  bool flag = false;
  while(!q.empty()) {
    P p = q.front();
    q.pop();
    
    int y = p.fi, x = p.se;
    int ny, nx;
    rep(i, 4) {
      if(y+Y[i]>=0 && y+Y[i]<h && x+X[i]>=0 && x+X[i]<w) {
        ny = y+Y[i];
        nx = x+X[i];
      } else continue;
        
      if(C[ny][nx] == '#') continue;
      if(C[ny][nx] == 'S' && step > dots) {
        cout << "Yes" << endl;
        return 0;
      }
      q.push(P(ny, nx));
    }
    
    if(step!=0) C[y][x] = '#';
    step++;
  }
  
  cout << "No" << endl;
  
  return 0;
}