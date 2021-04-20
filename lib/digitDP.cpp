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

// https://qiita.com/pinokions009/items/1e98252718eeeeb5c9ab

int main(){
    string N = "123";
    vector<int> A;
    rep(i,N.size()) {
        A.push_back(N[i]-'0');
    }
    int dp[100][2][2];
    memset(dp,0,sizeof(dp)); 
    dp[0][0][0] = 1;
    rep(i,N.size()){
        rep(smaller, 2) {
            rep(j,2) {
                for(int x = 0; x <= (smaller ? 9 : A[i]); x++){
                    dp[i + 1][smaller || x < A[i]][j || x == 3] += dp[i][smaller][j];          
                }
            }
        }
    }

  cout << dp[N.size()][0][1] + dp[N.size()][1][1] << endl;
}
