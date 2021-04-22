//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int inf=1e9;
int k,n,m,sx,sy,a[2][305][305],now=1,prv=0;
char mp[305][305];
void max_(int &x,int y){
    if(x<y) x=y;
}
void print(int x){
    REP1(i,1,n) REP1(j,1,m) cout<<a[x][i][j]<<" \n"[j==m];
}
int main(){Rosario
    cin>>n>>m>>sx>>sy;
    REP1(i,1,n) REP1(j,1,m) cin>>mp[i][j],a[prv][i][j]=-inf;
    cin>>k; a[prv][sx][sy]=0;
    for(int x,y;k;k--){
        cin>>x>>y;
        REP1(i,1,n) REP1(j,1,m) a[now][i][j]=-inf;
        REP1(i,1,n) REP1(j,1,m){
            if(x==1){
                for(int p=0;p<=y&&i-p>0&&mp[i-p][j]=='.';++p) max_(a[now][i-p][j],a[prv][i][j]+p);
            }else if(x==2){
                for(int p=0;p<=y&&i+p<=n&&mp[i+p][j]=='.';++p) max_(a[now][i+p][j],a[prv][i][j]+p);
            }else if(x==3){
                for(int p=0;p<=y&&j-p>0&&mp[i][j-p]=='.';++p) max_(a[now][i][j-p],a[prv][i][j]+p);
            }else {
                for(int p=0;p<=y&&j+p<=m&&mp[i][j+p]=='.';++p) max_(a[now][i][j+p],a[prv][i][j]+p);
            }
        }
        swap(prv,now);
        //print(prv);
    }
    int ans=0;
    REP1(i,1,n) REP1(j,1,m) ans=max(ans,a[prv][i][j]);
    cout<<ans<<"\n";
    return 0;
}
// 1 4
// 4 2
// 2 3
