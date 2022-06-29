//#pragma GCC optimize("O2")
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


int a,b,c,x;
signed main(){
    cin>>a>>b>>c>>x;
    if(x<=a) return cout<<1,0;
    if(x>b) return cout<<0,0;
    cout<<fixed<<setprecision(9)<<((double)(c)/(b-a));
}
