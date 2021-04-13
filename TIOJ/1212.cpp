#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
#define lb(x) (x&-x)

int n,m,dp[505][505];
int main(){
    Rosario
    int a,b;
	while(cin>>n>>m,n){
        REP1(i,1,n) REP1(j,1,n) dp[i][j]=1e9;
        REP(i,m) cin>>a>>b,dp[a][b]=1;
        REP1(k,1,n){
            REP1(i,1,n){
                REP1(j,1,n) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
        a=1e9;
        REP1(i,1,n) a=min(a,dp[i][i]);
        cout<<(a==1e9?0:a)<<"\n"; 
    }
//    system("pause");
    return 0;
}
