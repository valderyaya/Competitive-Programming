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
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair


int n,cnt;
bitset<2501> v[2501];
signed main(){StarBurstStream
    cin>>n;
    for(int x,y,i=0;i<n;++i){
        cin>>x;
        while(x--) cin>>y, v[i][y]=1;
    }
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            if((v[i]&v[j]).any()) ++cnt;
    cout<<cnt<<"\n";
    return 0;
}
