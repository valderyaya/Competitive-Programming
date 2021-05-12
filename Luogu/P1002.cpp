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

ll dp[30][30],ma[30][30]={},n,m,x,y,dx[]={2,1,-1,-2,-2,-1,1,2},dy[]={1,2,2,1,-1,-2,-2,-1};
int main(){
    //oi;
    cin>>n>>m>>x>>y;n++;m++;x++;y++;
    dp[1][1]=ma[x][y]=1;
    REP(i,8) ma[x+dx[i]][y+dy[i]]=1;
    REP1(i,1,n){
        REP1(j,1,m){
            if(ma[i][j]) continue;
            dp[i][j]=max(dp[i][j],dp[i-1][j]+dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<"\n";
    //system("pause");
    return 0;
}
