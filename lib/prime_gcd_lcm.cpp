#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);
using mint = modint1000000007;
//using mint = modint998244353;
//----------------------------------------------------------------

vector<pair<ll,ll>> prime_factorize(ll n) {
    vector<pair<ll, ll> > res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

ll gcd(ll a, ll b) {
   if (a%b == 0) {
       return(b);
   }
   else {
       return(gcd(b, a%b));
   }
}

ll lcm(ll a, ll b) {
   ll tmp = max(a,b)/gcd(a,b);
   return min(a,b)*tmp;   
}

ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

vector<ll> divisor(ll a) {
    vector<ll> res;
    ll now = 1;
    while(now*now<=a) {
        if (a%now==0) {
            res.push_back(now);
            if (now!=a/now) {
                res.push_back(a/now);
            }
        }
        now++;
    }
    sort(res.begin(),res.end());
    return res;
}

int main(){

    auto F = prime_factorize(57);
    for (int i=0; i<F.size(); i++) {
        cout << F[i].first << " " << F[i].second << endl;
    }
    cout << endl;

    auto D = divisor(57);
    rep(i,D.size()) {
        cout << D[i] << " ";
    }
    cout << endl << endl;

    ll a=12, b=4;
    cout << "最大公約数:" << gcd(a, b) << endl;
    cout << "最小公倍数:" << lcm(a, b) << endl;

    // ax + by = gcd(a,b)
    ll x,y;
    a = 111;
    b = 30;
    extGCD(a,b,x,y);
    cout << x << " " << y << endl;
}
