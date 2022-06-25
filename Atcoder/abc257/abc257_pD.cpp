#pragma GCC optimize("O2")
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

ll n,ans=1e10;
struct qwq{ll x,y,c;}a[205];
ll dis(ll i,ll j){return abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);}
bitset<205> vis;
ll ck(ll x, ll mid){
    queue<ll> q;
    q.emplace(x);
    vis.reset();
    ll cnt=1; vis[x]=1;
    while(!q.empty()){
        x=q.front(); q.pop();
        REP1(i,1,n) if(!vis[i]){
            if(a[x].c*mid>=dis(x,i)){
                vis[i]=1;
                q.emplace(i);
                ++cnt;
                if(cnt==n) return 1;
            }
        }
    }
    return cnt==n;
}
ll cal(ll x){
    ll l=1,r=1e10,mid,res;
    while(l<r){
        mid=l+r>>1;
        if(ck(x,mid)) res=mid,r=mid;
        else l=mid+1;
    }
    return res;
}
signed main(){valder
    cin>>n;
    for(int i=1;i<=n;++i)  cin>>a[i].x>>a[i].y>>a[i].c;
    REP1(i,1,n)
        ans=min(ans,cal(i));
    cout<<ans;
}
