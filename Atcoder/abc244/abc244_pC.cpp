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

int n,x;
bitset<2005> vis;
signed main(){valder
    cin>>n;
    n=2*n+1;
    vis[1]=1;
    cout<<1<<endl;
    while(cin>>x){
        if(x==0) break;
        vis[x]=1;
        for(int i=1;i<=n;++i) if(!vis[i]){
            cout<<i<<endl;
            vis[i]=1;
            break;
        }
    }
}
