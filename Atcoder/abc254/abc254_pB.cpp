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

ll n,f[35][35];
signed main(){valder
    f[0][0]=1;
    for(int i=1;i<=30;++i) f[i][0]=1;
    for(int i=1;i<=30;++i)
        for(int j=1;j<=i;++j) f[i][j]=f[i-1][j-1]+f[i-1][j];
    cin>>n;
    for(int i=0;i<n;++i)
        for(int j=0;j<=i;++j)
            cout<<f[i][j]<<" \n"[j==i];
}
