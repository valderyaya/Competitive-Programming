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

ll n,t,k;
string s;
char qry(char c,ll x){return (c-'A'+x)%3+'A';}
char dfs(ll x,ll y){
    if(x==0) return s[y];
    if(y==0) return qry(s[0],x);
    return qry(dfs(x-1,y/2),y%2+1);
}
signed main(){valder
    cin>>s>>n;
    while(n--){
        cin>>t>>k;
        cout<<dfs(t,k-1)<<"\n";
    }
}
