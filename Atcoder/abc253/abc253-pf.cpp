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
#define endl "\n"

const int z=200005;
struct qwq{int opt,x,y,k;}query[z];
int n,m,q,id,ansid[z];
ll bit[z],ans[z];
void add(int x,int v){
    for(;x<=m;x+=lb(x)) bit[x]+=v;
}
ll qry(int x){
    ll res=0;
    for(;x;x-=lb(x)) res+=bit[x];
    return res;
}
vector<pii> sub[z];
pii last[z];
signed main(){valder
    cin>>n>>m>>q;
    for(int i=1;i<=q;++i){
        cin>>query[i].opt>>query[i].x>>query[i].y;
        if(query[i].opt==1) 
            cin>>query[i].k;
        else if(query[i].opt==2)
            last[query[i].x]={i,query[i].y};
        else{
            ans[++id]=last[query[i].x].S;
            sub[last[query[i].x].F].em(id,query[i].y);
            ansid[i]=id;
        }
    }
    for(int i=1;i<=q;++i){
        if(query[i].opt==1){
            add(query[i].x,query[i].k);
            add(query[i].y+1,-query[i].k);
        }else if(query[i].opt==2){
            for(auto &j:sub[i])
                ans[j.F]-=qry(j.S);
        }else{
            ans[ansid[i]]+=qry(query[i].y);
        }
    }
    for(int i=1;i<=id;++i) cout<<ans[i]<<endl;
}
