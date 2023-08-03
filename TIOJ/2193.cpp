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

struct qwq{
    int x,c,t;
    bool operator<(const qwq &p)const{
        return c==p.c?t<p.t:c<p.c;
    }
}a[1005];
int n;
int cal(int x){
    int r=0;
    while(x) r+=x&1,x>>=1;
    return r;
}
signed main(){StarBurstStream
    cin>>n;
    REP(i,n){
        cin>>a[i].x;
        a[i].c = cal(a[i].x);
        a[i].t=i; 
    }
    sort(a,a+n);
    REP(i,n) cout<<a[i].x<<' ';
    return 0;
}
