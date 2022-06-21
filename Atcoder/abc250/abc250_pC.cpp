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

int n,q,pos[200005],ans[200005];
signed main(){valder
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        ans[i]=i;
        pos[i]=i;
    }
    for(int x;q--;){
        cin>>x;
        if(pos[x]==n) x=ans[pos[x]-1];
        int num=ans[pos[x]+1],t=pos[x];
        swap(ans[pos[x]],ans[pos[x]+1]);
        pos[x]=pos[num];
        pos[num]=t;
    }
    for(int i=1;i<=n;++i) cout<<ans[i]<<' ';
}
