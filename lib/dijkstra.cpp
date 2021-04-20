#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef long long ll;
//typedef pair<ll,ll> P;

//const int INF = 1001001001;
const long long INF = 2e18;
const int MOD = 1000000007;
const double PI=acos(-1);


//-------------------------------------------------ABC35D
struct edge{ll to, cost;};
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    for(int i=0; i<V; i++){
      d[i] = INF;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    for(int i=0; i<V; i++){
      d[i] = INF;
    }
    d[s] = 0;
    
    //first:dist from start, second:next v
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>> > que;
    
    que.push(make_pair(0,s));
    while(!que.empty()){
      auto p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(make_pair(d[e.to],e.to));
        }
      }
    }
  }
};

int main() {
    // 2頂点がつながっていない場合、dはINF=2e18となる

    ll N,M,T;
    cin >> N >> M >>T;
    ll A[N];
    rep(i,N) {
        cin >> A[i];
    }
    graph g1(N),g2(N);

    rep(i,M) {
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        g1.add_edge(a,b,c);
        g2.add_edge(b,a,c);
    }

    g1.dijkstra(0);
    g2.dijkstra(0);

    ll ans = 0;
    rep(i,N) {
        if (T - (g1.d[i] + g2.d[i])<0) continue;
        ans = max(ans,(T - (g1.d[i] + g2.d[i]))*A[i]);
    }
    cout << ans << endl;


}