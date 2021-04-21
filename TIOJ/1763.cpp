//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------------\n";

int n,a[151][151],ans=1e9,mx,mi,dx[]={1,0,0,-1},dy[]={0,1,-1,0},on[401]={},num[25000],cnt=0;
bool vis[151][151];
queue<pii> q;
bool bfs(int l,int r){
    if(!(l<=a[0][0]&&a[0][0]<=r&&l<=a[n-1][n-1]&&a[n-1][n-1]<=r)) return 0;
    REP(i,n) REP(j,n) vis[i][j]=0;
    while(!q.empty()) q.pop();
    q.emplace(mkp(0,0));
    pii w;int x,y;vis[0][0]=1;
    while(!q.empty()){
        w=q.front();q.pop();
        mx=max(mx,a[w.F][w.S]);
        mi=min(mi,a[w.F][w.S]);
        REP(i,4){
            x=w.F+dx[i],y=w.S+dy[i];
            if(x<0||x>=n||y<0||y>=n) continue;
            if(!vis[x][y]&&l<=a[x][y]&&a[x][y]<=r) q.emplace(mkp(x,y)),vis[x][y]=1;
        }
    }
    return vis[n-1][n-1];
}

int main(){Rosario
    cin>>n;
    REP(i,n) REP(j,n) cin>>a[i][j],num[cnt++]=a[i][j];
    sort(num,num+cnt);
    REP(i,cnt){
        if(on[num[i]]) continue;
        int l=i,r=cnt-1;
        while(l<r){
            int mid=l+r>>1;
            if(mx=0,mi=1e9,bfs(num[i],num[mid])) r=mid,ans=min(ans,mx-mi);
            else l=mid+1;
        }
        on[num[i]]=1;
    }
    cout<<ans<<"\n";
//    system("pause");
    return 0;
}
