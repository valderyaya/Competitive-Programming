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

const int z=2e5+5;
int t,n,tot,q,pre[z],nxt[z],val[z],mp[z],head=2e5+3,tail=2e5+4;
void ins(int x, int tp){
    int p = pre[x = mp[x]], nx = nxt[x];
    nxt[p] = nx, pre[nx] = p;
    if(tp){
        p = pre[tail];
        nxt[p] = x;
        pre[x] = p;
        nxt[x] = tail;
        pre[tail] = x;
    }else{
        p = nxt[head];
        nxt[head] = x;
        pre[x] = head;
        nxt[x] = p;
        pre[p] = x;
    }
}
void build(int x){
    int now = head, nx; tot=0;
    REP1(i,1,n){
        val[mp[i]=++tot]=i;
        pre[tot] = now;
        nxt[now] = tot;
        now = tot;
    }
    nxt[now]=tail;
    pre[tail] = now;
}
signed main(){StarBurstStream
    cin>>t;
    char c;
    int x;
    while(t--){
        cin>>n>>q;
        build(n);
        while(q--) cin>>c>>x, ins(x,c=='T');
        for(x = nxt[head];x!=tail;x=nxt[x]) cout<<val[x]<<' ';
        cout<<"\n";
    }
}
