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

int r,c,a[3][3];
signed main(){valder
    cin>>r>>c;
    REP1(i,1,2) REP1(j,1,2) cin>>a[i][j];
    cout<<a[r][c]<<"\n";
}
