#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
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

struct qwq{int x,y,id;}a[1005];
int n,X,Y,Z;
vector<int> ans;
signed main(){StarBurstStream
    cin>>n>>X>>Y>>Z;
    for(int i=0;i<n;++i) cin>>a[i].x;
    for(int i=0;i<n;++i) cin>>a[i].y,a[i].id=i+1;
    sort(a,a+n,[&](qwq ft, qwq se){return ft.x!=se.x?ft.x>se.x:ft.id<se.id;});
    for(int i=0;i<X;++i) ans.em(a[i].id);
    
    sort(a+X,a+n,[&](qwq ft, qwq se){return ft.y!=se.y?ft.y>se.y:ft.id<se.id;});
    for(int i=X;i<min(X+Y,n);++i) ans.em(a[i].id);
    
    if(X+Y>=n) return 0;
    sort(a+X+Y,a+n,[&](qwq ft, qwq se){return ft.x+ft.y!=se.x+se.y?ft.x+ft.y>se.x+se.y:ft.id<se.id;});
    for(int i=X+Y;i<min(n,X+Y+Z);++i) ans.em(a[i].id);
    sort(ALL(ans));
    for(auto &i:ans) cout<<i<<"\n";
}
