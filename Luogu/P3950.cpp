#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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
#define wait system("pause");

const int z=300005;
int n,m,seg[z<<2],top[z],dfn[z],tot=0,fa[z],sz[z],son[z],dep[z],u[z],vz[z];
vector<int> v[z];
void dfs(int x){
    sz[x]=1;
    for(auto &i:v[x]){
        if(dep[i]) continue;
        dep[i]=dep[x]+1;fa[i]=x;
        dfs(i);
        sz[x]+=sz[i];
        if(sz[i]>sz[son[x]]) son[x]=i;
    }
}
void dfs2(int x,int t){
    top[x]=t;
    dfn[x]=++tot;
    if(son[x]) dfs2(son[x],t);
    for(auto &i:v[x])
        if(i!=fa[x]&&i!=son[x]) dfs2(i,i);
}
//---------------------------------
void modify(int l,int r,int x,int rt,int val){
    if(l==r) return seg[rt]+=val,void();
    int mid=l+r>>1;
    if(x<=mid) modify(l,mid,x,rt<<1,val);
    else modify(mid+1,r,x,rt<<1|1,val);
    seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}
int query(int l,int r,int ql,int qr,int rt){
    if(ql>qr) return 0;
    if(ql<=l&&r<=qr) return seg[rt];
    int mid=l+r>>1,sum=0;
    if(ql<=mid) sum+=query(l,mid,ql,qr,rt<<1);
    if(qr>mid) sum+=query(mid+1,r,ql,qr,rt<<1|1);
    return sum;
}
//--------------------
int que(int a,int b){
    int s=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        s+=query(1,n,dfn[top[a]],dfn[a],1);
        a=fa[top[a]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    s+=query(1,n,dfn[a]+1,dfn[b],1);
    return s;
}
int main(){Rosario
    cin>>n>>m;
    char c;
    int a,b,cnt=0;
    REP(i,n-1) cin>>a>>b,v[a].em(b),v[b].em(a);
    dep[1]=1;dfs(1);dfs2(1,1);
    while(m--){
        cin>>c;
        if(c=='Q'){
            cin>>a>>b;
            a=que(a,b);
            cout<<(a?"No":"Yes")<<"\n";
        }else if(c=='U'){
            cin>>a;
            modify(1,n,max(dfn[vz[a]],dfn[u[a]]),1,-1);
        }else cin>>u[++cnt]>>vz[cnt],modify(1,n,max(dfn[u[cnt]],dfn[vz[cnt]]),1,1);
    }
//    wait
    return 0;
}
