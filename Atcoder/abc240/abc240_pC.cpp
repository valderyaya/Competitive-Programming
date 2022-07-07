//#pragma GCC optimize("O2")
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

int n,m,a,b,f[101][10201];
signed main(){StarBurstStream
    cin>>n>>m;
    f[0][0]=1;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        for(int j=0;j<m;++j) 
            if(f[i][j]){
                f[i+1][j+a]=1;
                f[i+1][j+b]=1;
            }
    }
    cout<<(f[n][m]?"Yes":"No");
}
