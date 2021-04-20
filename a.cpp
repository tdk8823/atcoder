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

struct Node{
    int c; //文字に対応した数字（'a'を引いた値）
    bool accept;  // ここで終わる文字列が存在（今回それは高々1つ）
    vector<int> nextid; // 自分から辺が張られる頂点番号(26文字に対応)
    Node(int c):c(c),accept(false){
      nextid.assign(26,-1);// -1 : 文字('a' + i)に対応する文字に辺がはられていない
    }
};

int main(){
    int N;
    cin >> N;
    vector<pair<int,string>> A;
    rep(i,N) {
        string S;
        cin >> S;
        reverse(S.begin(),S.end());
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());

    vector<Node> g;

}
