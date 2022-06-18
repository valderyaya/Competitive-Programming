// luogu-judger-enable-o2
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);


ll dp[31][31];
int main(){
    oi;
    int n,m;
    cin>>n>>m;
    dp[1][n]=dp[1][2]=1;
    REP1(i,2,m){
        REP1(j,1,n){
            dp[i][j]=(j==1?dp[i-1][n]:dp[i-1][j-1])+(j==n?dp[i-1][1]:dp[i-1][j+1]);
        }
    }
    cout<<dp[m][1];
//    system("pause");
    return 0;
}
