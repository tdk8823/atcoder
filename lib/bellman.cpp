#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, a) for (int i = 0; i < (a); i++ )

typedef long long ll;
 
const ll INF = 1e18;
const double PI=acos(-1);

const int MOD = 1000000007;
using mint = modint1000000007;
//using mint = modint998244353;

// 負の閉路がある場合はINFを返す
vector<ll> bellman(vector<vector<pair<ll,ll>>>&B, int s) {
    vector<ll> dist(B.size(),INF);
    dist[s] = 0;
    int cnt = 0;
    while(1) {
        bool update = false;
        rep(i,B.size()) {
            rep(j,B[i].size()) {
                ll now,next,cost;
                now = i;
                next = B[i][j].first;
                cost = B[i][j].second;
                if (dist[now]!=INF && dist[next]>dist[now]+cost) {
                    dist[next] = dist[now]+cost;
                    update = true;
                    
                }
            }
        }
        cnt++;
        if (!update) {
            break;
        }
        // 更新回数が頂点数-1を超えたので、負の閉路がある
        if (cnt>dist.size()-1) {
            rep(i,dist.size()) {
                dist[i] = INF;
            }
            break;
        }
    }

    return dist;
}

int main(){
    int N,M;
    cin >> N >> M ;
    vector<vector<pair<ll,ll>>> A(N,vector<pair<ll,ll>>());
    rep(i,M) {
        ll a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        A[a].push_back(make_pair(b,-c));
    }
    auto dist = bellman(A,0);
    if (dist[N-1]==INF) {
        cout << "inf" << endl;
    }
    else {
        cout << -dist[N-1] << endl;
    }


}
