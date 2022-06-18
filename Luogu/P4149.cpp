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

const int z=2e5+5;
int w[z<<1],h[z],cnt,p[z<<1],nxt[z<<1],sum,mx[z],sz[z],rt,n,k,ans=1e9;
bool vis[z];
void add(int u,int v,int we){
    nxt[++cnt]=h[u];
    w[cnt]=we;
    p[cnt]=v;
    h[u]=cnt;
}
void calrt(int x,int pa){
    sz[x]=1, mx[x]=0;
    for(int i=h[x];i;i=nxt[i])
        if(p[i]!=pa&&!vis[p[i]]){
            calrt(p[i],x);
            sz[x]+=sz[p[i]];
            mx[x]=max(mx[x],sz[p[i]]);
        }
    mx[x]=max(mx[x],sum-mx[x]);
    if(mx[rt]>mx[x]) rt=x;
}
int dd[z],tag[1000005],id,cp[z];
queue<int> tg;
void caldis(int x,int pa,int dis,int c){
    if(dis>k) return;
    dd[++id]=dis, cp[id]=c;
    for(int i=h[x];i;i=nxt[i])
        if(p[i]!=pa&&!vis[p[i]])
            caldis(p[i],x,dis+w[i],c+1);
}
void dfs(int x,int pa){
    vis[x]=1; tag[0]=0;
    for(int i=h[x];i;i=nxt[i])
        if(!vis[p[i]]&&p[i]!=pa){
            caldis(p[i],x,w[i],1);
            REP1(j,1,id) ans=min(ans,tag[k-dd[j]]+cp[j]);
            REP1(j,1,id) tag[dd[j]]=min(tag[dd[j]],cp[j]),tg.emplace(dd[j]);
            id=0;
        }
    while(!tg.empty()) tag[tg.front()]=1e9,tg.pop();
    for(int i=h[x];i;i=nxt[i])
        if(!vis[p[i]]&&p[i]!=pa){
            sum=sz[p[i]];
            mx[rt=0]=1e9;
            calrt(p[i],x);
            calrt(rt,-1);
            dfs(rt,-1);
        }
}
signed main(){Rosario
    REP1(i,1,1000000) tag[i]=1e9;
    cin>>n>>k; sum=n;
    for(int x,y,we,i=1;i<n;++i){
        cin>>x>>y>>we; ++x,++y;
        add(x,y,we), add(y,x,we);
    }
    mx[rt=0]=1e9;
    calrt(1,-1);
    calrt(rt,-1);
    dfs(rt,-1);
    cout<<(ans==1e9?-1:ans)<<"\n";
    return 0;
}
