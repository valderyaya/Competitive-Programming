#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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

int n,now=1,pr[200005],in[200005],idx[200005],f;
pii ans[200005];
int dfs(int l,int r){
    if(f==-1) return f;
    if(l>r) return 0;
    //cout<<pr[now]<<endl;
    if(l==r){
        if(pr[now]!=in[l]) return f=-1;
        return pr[now++];
    }
    int cur=pr[now++];
    ans[cur].F=dfs(l,idx[cur]-1);
    ans[cur].S=dfs(idx[cur]+1,r);
    return cur;
}
signed main(){//valder
    cin>>n;
    REP1(i,1,n) cin>>pr[i];
    REP1(i,1,n) cin>>in[i],idx[in[i]]=i;
    if(pr[1]!=1) return cout<<-1,0;
    dfs(1,n);
    if(f==-1)  return cout<<f,0; 
    for(int i=1;i<=n;++i) cout<<ans[i].F<<' '<<ans[i].S<<"\n";
    return 0;
}
