//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

#define int ll
const int z=1001;
int dis[101][101],b[z][z],s[z][z],n,m,k,l,r,w[z][z],Ds[z][z],cnt[z],dd[101],ans;
queue<int> q;
bitset<z> vis;
bool ck(int mid){
    while(!q.empty()) q.pop();
    REP1(i,1,n) REP1(j,1,n) Ds[i][j]=w[i][j]-dis[i][j]*mid;
    vis.reset();
    memset(dd,0,sizeof(dd));
    REP1(i,1,n) vis[i]=cnt[i]=1, q.emplace(i);
    while(!q.empty()){
        int x=q.front(); q.pop(); vis[x]=0;
        REP1(i,1,n){
            if(dis[x][i]>=1e9) continue;
            if(dd[x]+Ds[x][i]>=dd[i]){
                dd[i]=dd[x]+Ds[x][i];
                cnt[i]=cnt[x]+1;
                if(cnt[i]>n+1) return 1;
                if(!vis[i]) vis[i]=1,q.emplace(i);
            }
        }
    }
    return 0;
}
signed main(){StarBurstStream
    cin>>n>>m>>k;
    REP1(i,1,n) REP1(j,1,n) dis[i][j]=(1e9);
    REP1(i,1,n) REP1(j,1,k) cin>>b[i][j]>>s[i][j];
    REP1(l,1,k) REP1(i,1,n) REP1(j,1,n) if(b[i][l]!=-1&&s[j][l]!=-1){
        w[i][j]=max(w[i][j],s[j][l]-b[i][l]);
        r=max(r,w[i][j]);
    }
    for(int x,y,c,i=0;i<m;++i){
        cin>>x>>y>>c;
        dis[x][y]=min(dis[x][y],c);
    }
    REP1(k,1,n) REP1(i,1,n) REP1(j,1,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(l<=r){
        int mid=l+r>>1;
        if(ck(mid)) ans=max(ans,mid),l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<"\n";
}
