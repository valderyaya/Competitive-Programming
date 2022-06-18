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

int n,m,dx[]={0,1,-1,0},dy[]={1,0,0,-1},a[110][110],o[110][110],ans=1e9;
void dfs(int x,int y,int cnt,bool f){
    if(x<1||x>n||y<1||y>n) return;
    if(cnt>=o[x][y]) return;
    o[x][y]=cnt;
    if(x==n&&y==n) return ans=min(ans,cnt),void();
    REP(i,4){
        int px=x+dx[i],py=y+dy[i];
        if(a[px][py]){
            if(a[x][y]==a[px][py]) dfs(px,py,cnt,0);
            else dfs(px,py,cnt+1,0);
        }else if(!f){
            a[px][py]=a[x][y];
            dfs(px,py,cnt+2,1);
            a[px][py]=0;
        } 
    }
}
signed main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) REP1(j,1,m) o[i][j]=1e9;
    for(int x,y,c;m;--m){
        cin>>x>>y>>c;
        a[x][y]=c+1;
    }
    dfs(1,1,0,0);
    cout<<(ans==1e9?-1:ans)<<"\n";
    return 0;
}
