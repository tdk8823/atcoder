#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, a) for (int i = 0; i < (a); i++ )

typedef long long ll;
 
const int INF = 1001001001;
const double PI=acos(-1);

const int MOD = 1000000007;
using mint = modint1000000007;

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<ll>> A;
    rep(i,M) {
        int a,b,cost;
        cin >> a >> b >> cost;
        a--,b--;
        A.push_back({cost,a,b});
    }

    // edgeをコストが小さい順にソート
    sort(A.begin(),A.end());
    dsu d(N);
    
    ll total_cost = 0;
    vector<int> edge_list;

    // 閉路を作らないようなら（＝新たに加える頂点同士がまだ連結でないなら）edgeを追加
    rep(i,M) {
        ll a,b,cost;
        cost = A[i][0];
        a    = A[i][1];
        b    = A[i][2];

        if (d.same(a,b)) {
            continue;
        }
        else {
            d.merge(a,b);
            total_cost += cost;
            edge_list.push_back(i);
        }
    }
    cout << total_cost << endl;
}
