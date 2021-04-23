#include<bits/stdc++.h>
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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)
 
int dp[205][205][105],m,n,a,b,c,d,ans=0;
inline int ret(int i,int x,int y){
    return (i*a+x*b+c*y)%d;
}
int main(){
    //oi;
    cin>>m>>n>>a>>b>>c>>d;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                dp[i][j][k]=max({dp[i-1][j-1][k-1]+ret(k-1,i-1,j-1),dp[i-1][j][k],dp[i][j-1][k]});
            }
        }
    }
    cout<<dp[m][m][n]<<"\n";
//    system("pause");
    return 0;
}
