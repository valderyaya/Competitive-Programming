//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const int z=1e5+5,zz=2e5+5;
vector<int> seg[z<<2];
int u[zz],v[zz],n,m,k,pa[z<<1],rk[z<<1];
stack<pii> st;
int fin(int x){
    while(x^pa[x]) x=pa[x];
    return x;
}
void merge(int x,int y){
    if(x==y) return;
    if(rk[x]>rk[y]) x^=y^=x^=y;
    st.emplace(mkp(x,rk[x]==rk[y]?1:0));
    pa[x]=y; rk[y]+= rk[x]==rk[y]?1:0;
}
void modify(int l,int r,int ql,int qr,int rt,int x){
    if(ql<=l&&r<=qr) return seg[rt].em(x),void();
    int mid=l+r>>1;
    if(ql<=mid) modify(l,mid,ql,qr,rt<<1,x);
    if(qr>mid) modify(mid+1,r,ql,qr,rt<<1|1,x);
}
void dfs(int l,int r,int rt){
    int ck=1,now=st.size(),mid=l+r>>1;
    for(auto &i:seg[rt]){
        int x=fin(u[i]),y=fin(v[i]);
        if(x==y){
            REP1(j,l,r) cout<<"No\n";
            ck=0; break;
        }
        merge(fin(u[i]+n),y); merge(x,fin(n+v[i]));
    }
    if(ck){
        if(l==r) cout<<"Yes\n";
        else dfs(l,mid,rt<<1),dfs(mid+1,r,rt<<1|1);
    }
    while(st.size()>now) rk[pa[st.top().F]]-=st.top().S,pa[st.top().F]=st.top().F,st.pop();
}
int main(){Rosario
    cin>>n>>m>>k; int l,r;
    REP1(i,1,m) cin>>u[i]>>v[i]>>l>>r,modify(1,n,l+1,r,1,i);
    REP1(i,1,n<<1) pa[i]=i;
    dfs(1,k,1);
    return 0;
}
