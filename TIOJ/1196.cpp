#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>

int dp[15][15],n;
char m[15][15];
int main(){
    //oi;
    cin>>n;
    REP1(i,1,n){dp[i][0]=dp[0][i]=-1e9;}
    REP1(i,1,n){
        REP1(j,1,n) cin>>m[i][j];
    }
    m[n][n]='0';
    REP1(i,1,n){
        REP1(j,1,n){
            if(m[i][j]=='A') dp[i][j]=0;
            else if(m[i][j]=='X') dp[i][j]=-1e9;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j])+m[i][j]-'0';
        }
    }
    if(dp[n][n]>=0) cout<<dp[n][n]<<"\n";
    else cout<<"X\n";
//    system("pause");
    return 0;
}
