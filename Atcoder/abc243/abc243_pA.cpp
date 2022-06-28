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

int n,a,b,c;
signed main(){
    cin>>n>>a>>b>>c;
    n%=(a+b+c);
    if(n-=a,n<0) return cout<<'F',0;
    if(n-=b,n<0) return cout<<'M',0;
    if(n-=c,n<0) return cout<<'T',0;
}
