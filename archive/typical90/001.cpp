
//001 Yokan Party
//二分探索（最小値の最大化）

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
    int N, L, K;
    cin >> N >> L >> K;

    vi A(N);
    rep(i, N) cin >> A[i];

    int l = 0, r = L, mid;
    while(abs(l-r) > 1) {
        mid = (l + r) / 2;
        int cnt = 0, now = 0;
        int pre = 0;
        rep(i, N) {
            
            //どの部分もmid以上の長さになるように切るための
            //最大回数(=cnt)
            //cntがk以上なら、k回の分割ですべての部分をmid以上にできる
            if(A[i]-pre >= mid) {
                cnt++;
                if(cnt==K) {
                    pre = A[i];
                    break;
                }
                now = 0;
                pre = A[i];
            } else {
                now = A[i]-pre;
            }
        }

        //cout << mid << endl;
        if(cnt>=K && L-pre>=mid) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << endl;

    return 0;
}