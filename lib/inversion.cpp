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
    ll N;
    cin >> N;
    vector<ll> A(N);

    // 0-indexed
    rep(i,N) {
        cin >> A[i];
    }

    ll ans = 0;
    fenwick_tree<ll> bit(N);
    for(ll a : A){
        ans += bit.sum(a, N);
        bit.add(a, 1);
    }
    cout << ans << endl;
}
