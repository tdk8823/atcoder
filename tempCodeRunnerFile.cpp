#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, a) for (int i = 0; i < (a); i++ )

typedef long long ll;
 
const int INF = 1001001001;
const double PI = acos(-1);

const int MOD = 1000000007;
using mint = modint1000000007;
//using mint = modint998244353;

int main(){
    int N;
    cin >> N;
    vector<pair<int,string>> A;
    rep(i,N) {
        string S;
        cin >> S;
        A.push_back(make_pair(S.size(),S));
    }
    sort(A.begin(),A.end());
    ll ans = 0;
    map<deque<char>,map<char,int>> M;
    rep(i,N) {
        string S = A[i].second;
        deque<char> SS;
        rep(j,S.size()) {
            SS.push_back(S[j]);
        }
        set<char> tmp;
        rep(j,S.size()) {
            SS.pop_front();
            tmp.insert(S[j]);
            if (M.count(SS)) {
                for (auto p:M[SS]) {
                    if (tmp.count(p.first)) {
                        ans += M[SS][p.first];
                    }
                }
            }
        }
        deque<char> re;
        rep(j,S.size()-1) {
            re.push_back(S[i+1]);
        }
        M[re][S[0]]++;
    }
    cout << ans << endl;

}
