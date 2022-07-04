#pragma GCC optimize("O2")
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

ll n,ans;
bitset<3001> g[3001];
string s[3001];
signed main(){StarBurstStream
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s[i];
        for(int j=i+1;j<n;++j) if(s[i][j]=='1') g[i][j]=1;
    }
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            if(g[i][j]) ans+=(g[i]&g[j]).count();
    cout<<ans;
}
